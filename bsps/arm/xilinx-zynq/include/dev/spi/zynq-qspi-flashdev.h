/*
 * Copyright (C) 2024 Aaron Nyholm
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS AS IS
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _ZYNQ_QSPI_FLASHDEV_H
#define _ZYNQ_QSPI_FLASHDEV_H

#include <dev/flash/flashdev.h>
#include <dev/spi/zynq-qspi-flash.h>

#define ZQSPI_FLASH_MAX_REGIONS ((size_t)32)

/*
 * @brief Initializes a flash device using zynq qspi flash
 * driver. The flash device is not registered in this call.
 * If an rtems_flashdev is created using zqspi_flash_init it must be
 * destroyed using xqspi_flash_destroy.
 *
 * @param[in] zqspiflash A initialised zqspiflash device to wrap.
 *
 * @retval A pointer to the rtems_flashdev.
 * @retval NULL on failure.
*/
rtems_flashdev* zqspi_flashdev_init(zqspiflash *bmdriver);

/*
 * @brief Destroys a rtems_flashdev initialised with zqspi_flash_init.
 * If an rtems_flashdev is created using zqspi_flash_init it must be
 * destroyed using zqspi_flash_destroy. The zqspiflash originally passed in
 * is untouched.
 *
 * @param[in] flash The flashdev to destroy
*/
void zqspi_flashdev_destroy(rtems_flashdev* flash);

/*
 * @brief Struct allocating memory space for flash regions. Used by
 * rtems_flashdev to store region allocations.
 */
typedef struct zqspi_flash_region_table {
  rtems_flashdev_region zqspi_flash_regions[ZQSPI_FLASH_MAX_REGIONS];
  uint32_t zqspi_flash_bit_allocator;
} zqspi_flash_region_table;

#endif /* _ZYNQ_QSPI_FLASHDEV_H */
