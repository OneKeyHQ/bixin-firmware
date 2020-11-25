/*
 * This file is part of the Trezor project, https://trezor.io/
 *
 * Copyright (C) 2014 Pavol Rusnak <stick@satoshilabs.com>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __LAYOUT2_H__
#define __LAYOUT2_H__

#include "bignum.h"
#include "bitmaps.h"
#include "chinese.h"
#include "coins.h"
#include "layout.h"
#include "trezor.h"

#include "messages-bitcoin.pb.h"
#include "messages-crypto.pb.h"
#include "messages-nem.pb.h"

#define DISP_BUFSIZE (2048)
#define DISP_PAGESIZE (96)

extern void *layoutLast;

#if DEBUG_LINK
#define layoutSwipe oledClear
#else
#define layoutSwipe oledSwipeLeft
#endif

// prompt info display
#define DISP_NOT_ACTIVE 0x01  // Not Activated
#define DISP_NEED_BACKUP 0x02
#define DISP_BACKUP_ONLY 0x03

extern const char *ui_prompt_sign_trans[2];
extern const char *ui_prompt_wakingup[2];
extern const char *ui_prompt_updating[2];
extern const char *ui_prompt_current_pin[2];
extern const char *ui_prompt_input_pin[2];
extern const char *ui_prompt_new_pin[2];
extern const char *ui_prompt_new_pin_ack[2];
extern const char *ui_prompt_seed_pin[2];
extern const char *ui_prompt_seed_pin_ack[2];
extern const char *ui_prompt_singing[2];
extern const char *ui_prompt_verifying[2];

void layoutDialogSwipe(const BITMAP *icon, const char *btnNo,
                       const char *btnYes, const char *desc, const char *line1,
                       const char *line2, const char *line3, const char *line4,
                       const char *line5, const char *line6);
void layoutProgressSwipe(const char *desc, int permil);

void layoutScreensaver(void);
void layoutHome(void);
void layoutConfirmOutput(const CoinInfo *coin, const TxOutputType *out);
void layoutConfirmOmni(const uint8_t *data, uint32_t size);
void layoutConfirmOpReturn(const uint8_t *data, uint32_t size);
void layoutConfirmTx(const CoinInfo *coin, uint64_t amount_out,
                     uint64_t amount_fee);
void layoutFeeOverThreshold(const CoinInfo *coin, uint64_t fee);
void layoutChangeCountOverThreshold(uint32_t change_count);
void layoutSignMessage(const uint8_t *msg, uint32_t len);
void layoutVerifyAddress(const CoinInfo *coin, const char *address);
void layoutVerifyMessage(const uint8_t *msg, uint32_t len);
void layoutCipherKeyValue(bool encrypt, const char *key);
void layoutEncryptMessage(const uint8_t *msg, uint32_t len, bool signing);
void layoutDecryptMessage(const uint8_t *msg, uint32_t len,
                          const char *address);
void layoutResetWord(const char *word, int pass, int word_pos, bool last);
void layoutAddress(const char *address, const char *desc, bool qrcode,
                   bool ignorecase, const uint32_t *address_n,
                   size_t address_n_count, bool address_is_account);
void layoutPublicKey(const uint8_t *pubkey);
void layoutXPUB(const char *xpub, int index, int page, bool ours);
void layoutSignIdentity(const IdentityType *identity, const char *challenge);
void layoutDecryptIdentity(const IdentityType *identity);
void layoutU2FDialog(const char *verb, const char *appname);

void layoutNEMDialog(const BITMAP *icon, const char *btnNo, const char *btnYes,
                     const char *desc, const char *line1, const char *address);
void layoutNEMTransferXEM(const char *desc, uint64_t quantity,
                          const bignum256 *multiplier, uint64_t fee);
void layoutNEMNetworkFee(const char *desc, bool confirm, const char *fee1_desc,
                         uint64_t fee1, const char *fee2_desc, uint64_t fee2);
void layoutNEMTransferMosaic(const NEMMosaicDefinition *definition,
                             uint64_t quantity, const bignum256 *multiplier,
                             uint8_t network);
void layoutNEMTransferUnknownMosaic(const char *namespace, const char *mosaic,
                                    uint64_t quantity,
                                    const bignum256 *multiplier);
void layoutNEMTransferPayload(const uint8_t *payload, size_t length,
                              bool encrypted);
void layoutNEMMosaicDescription(const char *description);
void layoutNEMLevy(const NEMMosaicDefinition *definition, uint8_t network);

void layoutCosiCommitSign(const uint32_t *address_n, size_t address_n_count,
                          const uint8_t *data, uint32_t len, bool final_sign);

void layoutConfirmAutoLockDelay(uint32_t delay_ms);

const char **split_message(const uint8_t *msg, uint32_t len, uint32_t rowlen);
const char **split_message_hex(const uint8_t *msg, uint32_t len);
void Disp_Page(const BITMAP *icon, const char *btnNo, const char *btnYes,
               const char *desc, uint8_t *pucInfoBuf, uint16_t usLen);

void layoutHomeInfo(void);
void vDisp_PromptInfo(uint8_t ucIndex, bool ucMode);

void layoutButtonNoAdapter(const char *btnNo, const BITMAP *icon);
void layoutButtonYesAdapter(const char *btnYes, const BITMAP *icon);
void layoutDialogAdapter(const BITMAP *icon, const char *btnNo,
                         const char *btnYes, const char *desc,
                         const char *line1, const char *line2,
                         const char *line3, const char *line4);
void layoutDialogCenterAdapter(const BITMAP *icon, const char *btnNo,
                               const char *btnYes, const char *desc,
                               const char *line1, const char *line2,
                               const char *line3, const char *line4);
void layoutProgressAdapter(const char *desc, int permil);

void layoutDialogSwipeAdapter(const BITMAP *icon, const char *btnNo,
                              const char *btnYes, const char *desc,
                              const char *line1, const char *line2,
                              const char *line3, const char *line4);
void layoutDialogSwipeCenterAdapter(const BITMAP *icon, const char *btnNo,
                                    const char *btnYes, const char *desc,
                                    const char *line1, const char *line2,
                                    const char *line3, const char *line4);

#endif
