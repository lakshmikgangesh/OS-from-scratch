#include "framebuffer.h"
#include "serial.h"
#include "memory_segments.h"
#include "interrupts.h"
#include "io.h"
#include "keyboard.h"

char myname[] = "First text in OS by Lakshmi KG and Nihal Mubeen";
char name2[] = "Hello World";
char sent[] = "Type your input here: ";

/** kmain:
 *  The main function the kernel calls before it goes into an infinite loop
 */
 void kmain() {
 	
 	fb_write(myname, sizeof(myname));
 	serial_write(name2, sizeof(name2));
 	serial_write(sent, sizeof(sent));
 	fb_move_cursor(6*80);
 	fb_write(sent,sizeof(sent));
 	
 	
 	segments_install_gdt();
 	interrupts_install_idt();
 }
