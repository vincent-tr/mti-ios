/*
 * console.h
 *
 *  Created on: 20 nov. 2011
 *      Author: pumbawoman
 */

#ifndef __IOS_CONSOLE_H__
#define __IOS_CONSOLE_H__

extern void console_setup();
extern void console_write_char(char c);
extern void console_write_string(const char *str);
extern void console_write_char_warning(char c);
extern void console_write_string_warning(const char *str);
extern void console_write_char_error(char c);
extern void console_write_string_error(const char *str);

#endif /* __IOS_CONSOLE_H__ */
