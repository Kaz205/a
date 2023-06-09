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

#ifndef _WBM_LINK_DESCRIPTOR_RING_H_
#define _WBM_LINK_DESCRIPTOR_RING_H_
#if !defined(__ASSEMBLER__)
#endif

#include "buffer_addr_info.h"
#define NUM_OF_DWORDS_WBM_LINK_DESCRIPTOR_RING 2


struct wbm_link_descriptor_ring {
#ifndef WIFI_BIT_ORDER_BIG_ENDIAN
             struct   buffer_addr_info                                          desc_addr_info;
#else
             struct   buffer_addr_info                                          desc_addr_info;
#endif
};


/* Description		DESC_ADDR_INFO

			Consumer: WBM
			Producer: WBM
			
			Details of the physical address of the buffer + source buffer
			 owner +  some SW meta data
			All modules getting this link descriptor address info, shall
			 keep all the 64 bits in this descriptor together and eventually
			 all 64 bits shall be given back to WBM when the link descriptor
			 is released.
*/


/* Description		BUFFER_ADDR_31_0

			Address (lower 32 bits) of the MSDU buffer OR MSDU_EXTENSION
			 descriptor OR Link Descriptor
			
			In case of 'NULL' pointer, this field is set to 0
			<legal all>
*/

#define WBM_LINK_DESCRIPTOR_RING_DESC_ADDR_INFO_BUFFER_ADDR_31_0_OFFSET             0x00000000
#define WBM_LINK_DESCRIPTOR_RING_DESC_ADDR_INFO_BUFFER_ADDR_31_0_LSB                0
#define WBM_LINK_DESCRIPTOR_RING_DESC_ADDR_INFO_BUFFER_ADDR_31_0_MSB                31
#define WBM_LINK_DESCRIPTOR_RING_DESC_ADDR_INFO_BUFFER_ADDR_31_0_MASK               0xffffffff


/* Description		BUFFER_ADDR_39_32

			Address (upper 8 bits) of the MSDU buffer OR MSDU_EXTENSION
			 descriptor OR Link Descriptor
			
			In case of 'NULL' pointer, this field is set to 0
			<legal all>
*/

#define WBM_LINK_DESCRIPTOR_RING_DESC_ADDR_INFO_BUFFER_ADDR_39_32_OFFSET            0x00000004
#define WBM_LINK_DESCRIPTOR_RING_DESC_ADDR_INFO_BUFFER_ADDR_39_32_LSB               0
#define WBM_LINK_DESCRIPTOR_RING_DESC_ADDR_INFO_BUFFER_ADDR_39_32_MSB               7
#define WBM_LINK_DESCRIPTOR_RING_DESC_ADDR_INFO_BUFFER_ADDR_39_32_MASK              0x000000ff


/* Description		RETURN_BUFFER_MANAGER

			Consumer: WBM
			Producer: SW/FW
			
			In case of 'NULL' pointer, this field is set to 0
			
			Indicates to which buffer manager the buffer OR MSDU_EXTENSION
			 descriptor OR link descriptor that is being pointed to 
			shall be returned after the frame has been processed. It
			 is used by WBM for routing purposes.
			
			<enum 0 WBM_IDLE_BUF_LIST> This buffer shall be returned
			 to the WMB buffer idle list
			<enum 1 WBM_CHIP0_IDLE_DESC_LIST> This buffer shall be returned
			 to the WBM idle link descriptor idle list, where the chip
			 0 WBM is chosen in case of a multi-chip config
			<enum 2 WBM_CHIP1_IDLE_DESC_LIST> This buffer shall be returned
			 to the chip 1 WBM idle link descriptor idle list
			<enum 3 WBM_CHIP2_IDLE_DESC_LIST> This buffer shall be returned
			 to the chip 2 WBM idle link descriptor idle list
			<enum 12 WBM_CHIP3_IDLE_DESC_LIST> This buffer shall be 
			returned to chip 3 WBM idle link descriptor idle list
			<enum 4 FW_BM> This buffer shall be returned to the FW
			<enum 5 SW0_BM> This buffer shall be returned to the SW, 
			ring 0
			<enum 6 SW1_BM> This buffer shall be returned to the SW, 
			ring 1
			<enum 7 SW2_BM> This buffer shall be returned to the SW, 
			ring 2
			<enum 8 SW3_BM> This buffer shall be returned to the SW, 
			ring 3
			<enum 9 SW4_BM> This buffer shall be returned to the SW, 
			ring 4
			<enum 10 SW5_BM> This buffer shall be returned to the SW, 
			ring 5
			<enum 11 SW6_BM> This buffer shall be returned to the SW, 
			ring 6
			
			<legal 0-12>
*/

#define WBM_LINK_DESCRIPTOR_RING_DESC_ADDR_INFO_RETURN_BUFFER_MANAGER_OFFSET        0x00000004
#define WBM_LINK_DESCRIPTOR_RING_DESC_ADDR_INFO_RETURN_BUFFER_MANAGER_LSB           8
#define WBM_LINK_DESCRIPTOR_RING_DESC_ADDR_INFO_RETURN_BUFFER_MANAGER_MSB           11
#define WBM_LINK_DESCRIPTOR_RING_DESC_ADDR_INFO_RETURN_BUFFER_MANAGER_MASK          0x00000f00


/* Description		SW_BUFFER_COOKIE

			Cookie field exclusively used by SW. 
			
			In case of 'NULL' pointer, this field is set to 0
			
			HW ignores the contents, accept that it passes the programmed
			 value on to other descriptors together with the physical
			 address 
			
			Field can be used by SW to for example associate the buffers
			 physical address with the virtual address
			The bit definitions as used by SW are within SW HLD specification
			
			
			NOTE1:
			The three most significant bits can have a special meaning
			 in case this struct is embedded in a TX_MPDU_DETAILS STRUCT, 
			and field transmit_bw_restriction is set
			
			In case of NON punctured transmission:
			Sw_buffer_cookie[19:17] = 3'b000: 20 MHz TX only
			Sw_buffer_cookie[19:17] = 3'b001: 40 MHz TX only
			Sw_buffer_cookie[19:17] = 3'b010: 80 MHz TX only
			Sw_buffer_cookie[19:17] = 3'b011: 160 MHz TX only
			Sw_buffer_cookie[19:17] = 3'b101: 240 MHz TX only
			Sw_buffer_cookie[19:17] = 3'b100: 320 MHz TX only
			Sw_buffer_cookie[19:18] = 2'b11: reserved
			
			In case of punctured transmission:
			Sw_buffer_cookie[19:16] = 4'b0000: pattern 0 only
			Sw_buffer_cookie[19:16] = 4'b0001: pattern 1 only
			Sw_buffer_cookie[19:16] = 4'b0010: pattern 2 only
			Sw_buffer_cookie[19:16] = 4'b0011: pattern 3 only
			Sw_buffer_cookie[19:16] = 4'b0100: pattern 4 only
			Sw_buffer_cookie[19:16] = 4'b0101: pattern 5 only
			Sw_buffer_cookie[19:16] = 4'b0110: pattern 6 only
			Sw_buffer_cookie[19:16] = 4'b0111: pattern 7 only
			Sw_buffer_cookie[19:16] = 4'b1000: pattern 8 only
			Sw_buffer_cookie[19:16] = 4'b1001: pattern 9 only
			Sw_buffer_cookie[19:16] = 4'b1010: pattern 10 only
			Sw_buffer_cookie[19:16] = 4'b1011: pattern 11 only
			Sw_buffer_cookie[19:18] = 2'b11: reserved
			
			Note: a punctured transmission is indicated by the presence
			 of TLV TX_PUNCTURE_SETUP embedded in the scheduler TLV
			
			<legal all>
*/

#define WBM_LINK_DESCRIPTOR_RING_DESC_ADDR_INFO_SW_BUFFER_COOKIE_OFFSET             0x00000004
#define WBM_LINK_DESCRIPTOR_RING_DESC_ADDR_INFO_SW_BUFFER_COOKIE_LSB                12
#define WBM_LINK_DESCRIPTOR_RING_DESC_ADDR_INFO_SW_BUFFER_COOKIE_MSB                31
#define WBM_LINK_DESCRIPTOR_RING_DESC_ADDR_INFO_SW_BUFFER_COOKIE_MASK               0xfffff000



#endif   // WBM_LINK_DESCRIPTOR_RING
