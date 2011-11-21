/*
 * console.c
 *
 *  Created on: 20 nov. 2011
 *      Author: pumbawoman
 */

#include <drivers/console.h>
#include <drivers/ioports.h>

/**
 * x86 video attributes
 * See http://webster.cs.ucr.edu/AoA/DOS/ch23/CH23-1.html
 */
/* Normal and Dark/Light foreground */
#define ATTR_FG_BLACK     0
#define ATTR_FG_DKGRAY    8
#define ATTR_FG_BLUE      1
#define ATTR_FG_LTBLUE    9
#define ATTR_FG_GREEN     2
#define ATTR_FG_LTGREEN   10
#define ATTR_FG_CYAN      3
#define ATTR_FG_LTCYAN    11
#define ATTR_FG_RED       4
#define ATTR_FG_LTRED     12
#define ATTR_FG_MAGENTA   5
#define ATTR_FG_LTMAGENTA 13
#define ATTR_FG_BROWN     6
#define ATTR_FG_YELLOW    14
#define ATTR_FG_LTGRAY    7
#define ATTR_FG_WHITE     15
/* Background */
#define ATTR_BG_BLACK     (0 << 4)
#define ATTR_BG_BLUE      (1 << 4)
#define ATTR_BG_GREEN     (2 << 4)
#define ATTR_BG_CYAN      (3 << 4)
#define ATTR_BG_RED       (4 << 4)
#define ATTR_BG_MAGENTA   (5 << 4)
#define ATTR_BG_BROWN     (6 << 4)
#define ATTR_BG_LTGRAY    (7 << 4)
/* Blinking */
#define ATTR_FG_BLINKING  (1 << 7)

#define ATTR_NORMAL (ATTR_FG_LTGRAY | ATTR_BG_BLACK)
#define ATTR_WARNING (ATTR_FG_YELLOW | ATTR_BG_BLACK)
#define ATTR_ERROR (ATTR_FG_RED | ATTR_BG_BLACK)

/* The text video memory starts at address 0xB8000. Odd bytes are the
 ASCII value of the character, even bytes are attribute for the
 preceding character. */
#define VIDEO_START_ADDRESS   0xb8000

/* Console screen size */
#define LINES   25
#define COLUMNS 80

#define EMPTY_CHAR ' '
#define TAB_SIZE 4

#if TAB_SIZE >= COLUMNS
#error "TAB_SIZE >= COLUMNS"
#endif

/** The structure of a character element in the video memory. @see
 http://webster.cs.ucr.edu/AoA DOS edition chapter 23 */
struct video_char
{
	union
	{
		struct
		{
			char character;
			unsigned char attribute;
		};
		unsigned short value;
	};
}__attribute__ ((packed));

static volatile struct video_char * const video =
		(struct video_char *) VIDEO_START_ADDRESS;

static int cursor = 0;

static void write_spaces(int count);
static void scroll_line();
static void write_char_pos(char c, unsigned char attr, int pos);
static void write_char(char c, unsigned char attr);

#define write_line() (write_spaces(COLUMNS - (cursor % COLUMNS)))
#define write_tab() (write_spaces(TAB_SIZE - ((cursor % COLUMNS) % TAB_SIZE)))

void write_spaces(int count)
{
	if (cursor + count == LINES * COLUMNS)
		scroll_line();
	for (int i = 0; i < count; ++i)
		write_char_pos(EMPTY_CHAR, ATTR_NORMAL, cursor++);
}

void scroll_line()
{
	if (cursor < COLUMNS)
		return;

	/* copie des lignes vers le haut */
	for (int line = 0; line < LINES - 1; ++line)
	{
		for (int col = 0; col < COLUMNS; ++col)
		{
			video[line * COLUMNS + col].value =
					video[(line + 1) * COLUMNS + col].value;
		}
	}

	/* on écrase la ligne en bas */
	for (int col = 0; col < COLUMNS; ++col)
	{
		int line = LINES - 1;
		write_char_pos(EMPTY_CHAR, ATTR_NORMAL, line * COLUMNS + col);
	}

	/* déplacement du curseur vers le haut */
	cursor -= COLUMNS;
}

void write_char_pos(char c, unsigned char attr, int pos)
{
	video[pos].attribute = attr;
	video[pos].character = c;
}

void console_setup()
{
	/*
	 * Hide cursor. @see Ralf Brown's interrupt (and port) list
	 * http://www-2.cs.cmu.edu/~ralf/files.html
	 */
#define CRT_REG_INDEX 0x3d4
#define CRT_REG_DATA  0x3d5

	/* CRT index port => ask for access to register 0xa ("cursor
	 start") */
	outb(0x0a, CRT_REG_INDEX);

	/* (RBIL Tables 708 & 654) CRT Register 0xa => bit 5 = cursor OFF */
	outb(1 << 5, CRT_REG_DATA);

	for (int i = 0; i < LINES * COLUMNS; ++i)
		write_char_pos(EMPTY_CHAR, ATTR_NORMAL, i);
}

void write_char(char c, unsigned char attr)
{
	switch (c)
	{
	case '\n':
		write_line();
		break;

	case '\t':
		write_tab();
		break;

	default:
		if (cursor + 1 == LINES * COLUMNS)
			scroll_line();
		write_char_pos(c, attr, cursor++);
		break;
	}
}

void console_write_char(char c)
{
	write_char(c, ATTR_NORMAL);
}

void console_write_string(const char *str)
{
	for (const char *s = str; *s; ++s)
		write_char(*s, ATTR_NORMAL);
}

void console_write_char_warning(char c)
{
	write_char(c, ATTR_WARNING);
}

void console_write_string_warning(const char *str)
{
	for (const char *s = str; *s; ++s)
		write_char(*s, ATTR_WARNING);
}

void console_write_char_error(char c)
{
	write_char(c, ATTR_ERROR);
}

void console_write_string_error(const char *str)
{
	for (const char *s = str; *s; ++s)
		write_char(*s, ATTR_ERROR);
}
