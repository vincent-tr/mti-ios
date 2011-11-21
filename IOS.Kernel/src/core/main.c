/*
 * main.c
 *
 *  Created on: 13 nov. 2011
 *      Author: pumbawoman
 */

#include <drivers/console.h>
#include <boot/boot.h>

__attribute__((noreturn)) void main(unsigned long magic, struct multiboot_info *mbaddr)
{
	console_setup();

	console_write_string("Hello world!");
	console_write_string_warning("Hello world!");
	console_write_string_error("Hello world!");

	while(1);
}
