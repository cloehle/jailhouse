/*
 * Jailhouse, a Linux-based partitioning hypervisor
 *
 * Copyright (c) ARM Limited, 2014
 * Copyright (c) Siemens AG, 2014
 *
 * Authors:
 *  Jean-Philippe Brucker <jean-philippe.brucker@arm.com>
 *  Jan Kiszka <jan.kiszka@siemens.com>
 *
 * This work is licensed under the terms of the GNU GPL, version 2.  See
 * the COPYING file in the top-level directory.
 */

#include <asm/uart-8250-dw.h>

/* All the helpers are in the header, to make them re-usable by the inmates */
void uart_chip_init(struct uart_chip *chip)
{
	chip->wait = uart_wait;
	chip->busy = uart_busy;
	chip->write = uart_write;

	uart_init(chip);
}
