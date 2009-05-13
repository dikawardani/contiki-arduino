/**
 * \addtogroup cfs
 * @{
 */

/*
 * Copyright (c) 2008, Swedish Institute of Computer Science
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * This file is part of the Contiki operating system.
 *
 */

#ifndef CFS_COFFEE_H
#define CFS_COFFEE_H

#include "cfs.h"

/**
 * \file
 *	Header for the Coffee file system.
 * \author
 * 	Nicolas Tsiftes <nvt@sics.se>
 *
 * \name Functions called from application programs
 * @{
 */

/**
 * \brief Reserve space for a file.
 * \param name The filename.
 * \param size The size of the file.
 * \return 0 on success, -1 on failure.
 *
 * Coffee uses sequential page structures for files. The sequential 
 * structure can be reserved with a certain size. If no reservation
 * has been done, files will be set to a default size once opened for
 * the first time.
 */
int cfs_coffee_reserve(const char *name, cfs_offset_t size);

/**
 * \brief Configure the on-demand log file.
 * \param file
 * \param log_size
 * \param log_entry_size
 * \return 0 on success, -1 on failure.
 *
 * When file data is first modified, Coffee creates a micro log for the
 * file. The micro log stores a table of modifications where each record
 * is of log_entry_size.
 */
int cfs_coffee_configure_log(const char *file, unsigned log_size,
                             unsigned log_entry_size);

/**
 * \brief Format the storage area assigned to Coffee.
 * \return 0 on success, -1 on failure.
 *
 * Coffee formats the underlying storage by setting all bits to zero.
 * This operation is required prior to using Coffee for the first time
 * in a system.
 */
int cfs_coffee_format(void);

/**
 * \brief Gives information about memory that must not be altered during
 * CFS-based checkpointing operations.
 * \param size
 * \return A pointer to the protected memory.
 *
 * This function returns the protected memory pointer and writes its size
 * to the given parameter. Mainly used by sensornet checkpointing to protect
 * the coffee state during CFS-based checkpointing operations.
 */
void *cfs_coffee_get_protected_mem(unsigned *size);


/** @} */
/** @} */

#endif /* !COFFEE_H */