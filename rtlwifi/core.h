/******************************************************************************
 *
 * Copyright(c) 2009-2012  Realtek Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * The full GNU General Public License is included in this distribution in the
 * file called LICENSE.
 *
 * Contact Information:
 * wlanfae <wlanfae@realtek.com>
 * Realtek Corporation, No. 2, Innovation Road II, Hsinchu Science Park,
 * Hsinchu 300, Taiwan.
 *
 * Larry Finger <Larry.Finger@lwfinger.net>
 *
 *****************************************************************************/

#ifndef __RTL_CORE_H__
#define __RTL_CORE_H__

#define RTL_SUPPORTED_FILTERS		\
	( FIF_ALLMULTI | FIF_CONTROL | \
	FIF_OTHER_BSS | \
	FIF_FCSFAIL | \
	FIF_BCN_PRBRESP_PROMISC)

#define DM_DIG_THRESH_HIGH		40
#define DM_DIG_THRESH_LOW		35
#define DM_FALSEALARM_THRESH_LOW	400
#define DM_FALSEALARM_THRESH_HIGH	1000

#define DM_DIG_MAX			0x3e
#define DM_DIG_MIN			0x1e
#define DM_DIG_MAX_AP			0x32
#define DM_DIG_BACKOFF_MAX		12
#define DM_DIG_BACKOFF_MIN		-4
#define DM_DIG_BACKOFF_DEFAULT		10

enum cck_packet_detection_threshold {
	CCK_PD_STAGE_LOWRSSI = 0,
	CCK_PD_STAGE_HIGHRSSI = 1,
	CCK_FA_STAGE_LOW = 2,
	CCK_FA_STAGE_HIGH = 3,
	CCK_PD_STAGE_MAX = 4,
};

enum dm_dig_ext_port_alg_e {
	DIG_EXT_PORT_STAGE_0 = 0,
	DIG_EXT_PORT_STAGE_1 = 1,
	DIG_EXT_PORT_STAGE_2 = 2,
	DIG_EXT_PORT_STAGE_3 = 3,
	DIG_EXT_PORT_STAGE_MAX = 4,
};

enum dm_dig_connect_e {
	DIG_STA_DISCONNECT,
	DIG_STA_CONNECT,
	DIG_STA_BEFORE_CONNECT,
	DIG_MULTISTA_DISCONNECT,
	DIG_MULTISTA_CONNECT,
	DIG_AP_DISCONNECT,
	DIG_AP_CONNECT,
	DIG_AP_ADD_STATION,
	DIG_CONNECT_MAX
};

extern const struct ieee80211_ops rtl_ops;
void rtl_fw_cb(const struct firmware *firmware, void *context);
void rtl_wowlan_fw_cb(const struct firmware *firmware, void *context);
void rtl_addr_delay(u32 addr);
void rtl_rfreg_delay(struct ieee80211_hw *hw, enum radio_path rfpath, u32 addr,
		     u32 mask, u32 data);
void rtl_bb_delay(struct ieee80211_hw *hw, u32 addr, u32 data);
int rtl_mac80211_init(struct ieee80211_hw *hw);
void rtl_mac80211_deinit(struct ieee80211_hw *hw);
bool rtl_cmd_send_packet(struct ieee80211_hw *hw, struct sk_buff *skb);
void rtl_tx_status(struct ieee80211_hw *hw, struct sk_buff *skb);
bool rtl_btc_status_false(void);
void rtl_dm_diginit(struct ieee80211_hw *hw, u32 cur_igval);

#endif
