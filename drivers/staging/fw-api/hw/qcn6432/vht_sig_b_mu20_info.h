/*
 * Copyright (c) 2023 Qualcomm Innovation Center, Inc. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _VHT_SIG_B_MU20_INFO_H_
#define _VHT_SIG_B_MU20_INFO_H_
#if !defined(__ASSEMBLER__)
#endif

#define NUM_OF_DWORDS_VHT_SIG_B_MU20_INFO 1


struct vht_sig_b_mu20_info {
#ifndef WIFI_BIT_ORDER_BIG_ENDIAN
             uint32_t length                                                  : 16, // [15:0]
                      mcs                                                     :  4, // [19:16]
                      tail                                                    :  6, // [25:20]
                      mu_user_number                                          :  3, // [28:26]
                      reserved_0                                              :  3; // [31:29]
#else
             uint32_t reserved_0                                              :  3, // [31:29]
                      mu_user_number                                          :  3, // [28:26]
                      tail                                                    :  6, // [25:20]
                      mcs                                                     :  4, // [19:16]
                      length                                                  : 16; // [15:0]
#endif
};


/* Description		LENGTH

			VHT-SIG-B Length (in units of 4 octets) = ceiling (LENGTH/4) 
			 
			<legal all>
*/

#define VHT_SIG_B_MU20_INFO_LENGTH_OFFSET                                           0x00000000
#define VHT_SIG_B_MU20_INFO_LENGTH_LSB                                              0
#define VHT_SIG_B_MU20_INFO_LENGTH_MSB                                              15
#define VHT_SIG_B_MU20_INFO_LENGTH_MASK                                             0x0000ffff


/* Description		MCS

			Modulation as described in vht_sig_a mcs field 
			<legal 0-11>
*/

#define VHT_SIG_B_MU20_INFO_MCS_OFFSET                                              0x00000000
#define VHT_SIG_B_MU20_INFO_MCS_LSB                                                 16
#define VHT_SIG_B_MU20_INFO_MCS_MSB                                                 19
#define VHT_SIG_B_MU20_INFO_MCS_MASK                                                0x000f0000


/* Description		TAIL

			Used to terminate the trellis of the convolutional decoder.
			
			<legal all>
*/

#define VHT_SIG_B_MU20_INFO_TAIL_OFFSET                                             0x00000000
#define VHT_SIG_B_MU20_INFO_TAIL_LSB                                                20
#define VHT_SIG_B_MU20_INFO_TAIL_MSB                                                25
#define VHT_SIG_B_MU20_INFO_TAIL_MASK                                               0x03f00000


/* Description		MU_USER_NUMBER

			Not part of VHT-SIG-B.
			Mapping from user number (BFer hardware specific) to mu_user_number. 
			The reader is directed to the previous chapter (User Number) 
			for a definition of the terms user and mu_user.  
			<legal 0-3>
*/

#define VHT_SIG_B_MU20_INFO_MU_USER_NUMBER_OFFSET                                   0x00000000
#define VHT_SIG_B_MU20_INFO_MU_USER_NUMBER_LSB                                      26
#define VHT_SIG_B_MU20_INFO_MU_USER_NUMBER_MSB                                      28
#define VHT_SIG_B_MU20_INFO_MU_USER_NUMBER_MASK                                     0x1c000000


/* Description		RESERVED_0

			<legal 0>
*/

#define VHT_SIG_B_MU20_INFO_RESERVED_0_OFFSET                                       0x00000000
#define VHT_SIG_B_MU20_INFO_RESERVED_0_LSB                                          29
#define VHT_SIG_B_MU20_INFO_RESERVED_0_MSB                                          31
#define VHT_SIG_B_MU20_INFO_RESERVED_0_MASK                                         0xe0000000



#endif   // VHT_SIG_B_MU20_INFO
