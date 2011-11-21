/*
 * multiboot.h
 *
 *  Created on: 19 nov. 2011
 *      Author: pumbawoman
 */

#ifndef __IOS_MULTIBOOT_H__
#define __IOS_MULTIBOOT_H__

/* The magic number for the Multiboot header.  */
#define MULTIBOOT_HEADER_MAGIC		0x1BADB002

/* The flags for the Multiboot header.  */
#define MULTIBOOT_HEADER_FLAGS		0x00010003

/* The magic number passed by a Multiboot-compliant boot loader.  */
#define MULTIBOOT_BOOTLOADER_MAGIC	0x2BADB002

/* The size of our stack (16KB).  */
#define MULTIBOOT_STACK_SIZE	        0x4000

#define MULTIBOOT_CMDLINE 4
#define MULTIBOOT_MODS 8

/* C symbol format. HAVE_ASM_USCORE is defined by configure.  */
#ifdef HAVE_ASM_USCORE
# define EXT_C(sym)			_ ## sym
#else
# define EXT_C(sym)			sym
#endif

#ifndef ASM_SOURCE
/* Do not include here in boot.S.  */



/* Types.  */

/* The Multiboot header.  */
struct multiboot_header
{
  unsigned long magic;
  unsigned long flags;
  unsigned long checksum;
  unsigned long header_addr;
  unsigned long load_addr;
  unsigned long load_end_addr;
  unsigned long bss_end_addr;
  unsigned long entry_addr;
};

/* The symbol table for a.out.  */
struct aout_symbol_table
{
  unsigned long tabsize;
  unsigned long strsize;
  unsigned long addr;
  unsigned long reserved;
};

/* The section header table for ELF.  */
struct elf_section_header_table
{
  unsigned long num;
  unsigned long size;
  unsigned long addr;
  unsigned long shndx;
};

/* The Multiboot information.  */
struct multiboot_info
{
  unsigned long flags;
  unsigned long mem_lower;
  unsigned long mem_upper;
  unsigned long boot_device;
  unsigned long cmdline;
  unsigned long mods_count;
  unsigned long mods_addr;
  union
  {
    struct aout_symbol_table aout_sym;
    struct elf_section_header_table elf_sec;
  } u;
  unsigned long mmap_length;
  unsigned long mmap_addr;
  unsigned long drives_length;
  unsigned long drives_addr;
};

/* The module structure.  */
struct module
{
  unsigned long mod_start;
  unsigned long mod_end;
  unsigned long string;
  unsigned long reserved;
};

/* The memory map. Be careful that the offset 0 is base_addr_low
   but no size.  */
struct memory_map
{
  unsigned long size;
  unsigned long base_addr_low;
  unsigned long base_addr_high;
  unsigned long length_low;
  unsigned long length_high;
  unsigned long type;
};

#endif // ASM_SOURCE

#endif /* __IOS_MULTIBOOT_H__ */
