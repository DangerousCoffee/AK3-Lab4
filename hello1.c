/*
 * Copyright (c) 2017, GlobalLogic Ukraine LLC
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *    This product includes software developed by the GlobalLogic.
 * 4. Neither the name of the GlobalLogic nor the
 *    names of its contributors may be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY GLOBALLOGIC UKRAINE LLC ``AS IS`` AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL GLOBALLOGIC UKRAINE LLC BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "hello1.h"

MODULE_AUTHOR("Dremov A. K.");
MODULE_DESCRIPTION("Programming on Linux kernel");
MODULE_LICENSE("Dual BSD/GPL");

module_param(count, uint, 0444);
MODULE_PARM_DESC(count, "Defines how many times a string will be printed");
static int print_hello(uint count)
{
	uint i;

	for (i = 0; i < count; i++)
		pr_info("Hello, world!\n");
	
	return 0;
}

EXPORT_SYMBOL(print_hello);

static int __init my_init(void)
{
	pr_info("Loading module...\n");

	if (count == 0 || (count >= 5 && count <= 10)) {
		pr_warn("Stop! You're going to break it!\n");
	} else if (count > 10) {
		pr_err("Its broken now. Are you happy?\n");
		return -EINVAL;
	}

	return print_hello(count);
}

static void __exit my_exit(void)
{
	pr_info("Unloading module...\n");
}

module_init(my_init);
module_exit(my_exit);
