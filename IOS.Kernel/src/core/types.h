/*
 * types.h
 *
 *  Created on: 21 nov. 2011
 *      Author: pumbawoman
 */

#ifndef __IOS_TYPES_H__
#define __IOS_TYPES_H__

#define NULL ((void*)0)

typedef enum { false=0, true } bool;

typedef unsigned int size_t;
typedef int ptrdiff_t;
typedef void *ptr_t;

#define offsetof (type,member) ((size_t)(&(((NULL)type)->member)))

#endif /* __IOS_TYPES_H__ */
