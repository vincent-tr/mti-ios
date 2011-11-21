/*
 * ioports.h
 *
 *  Created on: 20 nov. 2011
 *      Author: pumbawoman
 */

#ifndef __IOS_IOPORTS_H__
#define __IOS_IOPORTS_H__

/**
 * @ioports.h
 *
 * Intel-specific I/O space access routines.
 */

/* This macro allows to write to an I/O port */
#define outb(value, port)                                       \
  __asm__ volatile (                                            \
        "outb %b0,%w1"                                          \
        ::"a" (value),"Nd" (port)                               \
        )                                                       \

// read one byte from port
#define inb(port)                                               \
({                                                              \
  unsigned char _v;                                             \
  __asm__ volatile (                                            \
        "inb %w1,%0"                                            \
        :"=a" (_v)                                              \
        :"Nd" (port)                                            \
        );                                                      \
  _v;                                                           \
})

#endif /* __IOS_IOPORTS_H__ */
