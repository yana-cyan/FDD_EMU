// 制御信号選択 ---------------------------------------------
void Cont_sign_choice() {
  byte PINL_BK_0, PINL_BK_1, PINL_BK_2, PINL_BK_3;
  byte PINL_BK2_0, PINL_BK2_1, PINL_BK2_2, PINL_BK2_3;
  PINL_BK_0  = PINL_BK & B00000001;
  PINL_BK_1  = PINL_BK & B00000010;
  PINL_BK_1  = PINL_BK_1 >> 1;
  PINL_BK_2  = PINL_BK & B00000100;
  PINL_BK_2  = PINL_BK_2 >> 2;
  PINL_BK_3  = PINL_BK & B00001000;
  PINL_BK_3  = PINL_BK_3 >> 3;
  PINL_BK2_0 = PINL_BK2 & B00000001;
  PINL_BK2_1 = PINL_BK2 & B00000010;
  PINL_BK2_1 = PINL_BK2_1 >> 1;
  PINL_BK2_2 = PINL_BK2 & B00000100;
  PINL_BK2_2 = PINL_BK2_2 >> 2;
  PINL_BK2_3 = PINL_BK2 & B00001000;
  PINL_BK2_3 = PINL_BK2_3 >> 3;

  if ((PINL_BK_0 == 1) && (PINL_BK2_0 == 0)) {
    PC_DAV_RS_rtn();                // RISING(上昇)
    return;
  }
  if ((PINL_BK_1 == 1) && (PINL_BK2_1 == 0)) {
    PC_RFD_RS_rtn();                                          // RISING(上昇)
    return;
  }
  if ((PINL_BK_2 == 1) && (PINL_BK2_2 == 0)) {
    PC_DAC_RS_rtn();                                          // RISING(上昇)
    return;
  }
  if ((PINL_BK_3 == 1) && (PINL_BK2_3 == 0)) {
    PC_ATN_RS_rtn();                                          // RISING(上昇)
    return;
  }
  if ((PINL_BK_0 == 0) && (PINL_BK2_0 == 1)) {
    PC_DAV_FL_rtn();                                          // FALLING(下降)
    return;
  }
  if ((PINL_BK_2 == 0) && (PINL_BK2_2 == 1)) {
    PC_DAC_FL_rtn();                                          // FALLING(下降)
  }
}


// PC0ﾋﾟﾝ RISING ---------------------------------------------
// PC_DAV  B00000001 // PL4/PC0(Data Valia)    : ﾃﾞｰﾀが有効
void PC_DAV_RS_rtn() {
  // PD0～PD3 相手がいない時のｺﾞｰｽﾄ対策
  if (PINL_BK  == B00001111) { 
    return;
  }
  Rcv_data = PINA;                                            // PCからﾃﾞｰﾀ受信(PA7～PA0 のﾊﾞｯｸｱｯﾌﾟ)

  // FD_RFD  B00000010 // PL1/PC5(Ready For Data): ﾃﾞｰﾀの準備完了
  PORTL &= FD_RFDL;                                           // FD_RFD : HIGH -> LOW

  // 受信ﾃﾞｰﾀを処理する
  Data_rcv_rtn();

  // FD_DAC  B00000100 // PL2/PC6(Data Accepted) : ﾃﾞｰﾀの受け取り終了
  PORTL |= FD_DAC;                                            // FD_DAC : LOW -> HIGH
}


// PC1ﾋﾟﾝ RISING ---------------------------------------------
// PC_RFD  B00000010 // PL5/PC1(Ready For Data): ﾃﾞｰﾀの準備完了
void PC_RFD_RS_rtn() {
  // PD0～PD3 相手がいない時のｺﾞｰｽﾄ対策
  if (PINL_BK  == B00001111) { 
    return;
  }
  Data_snd_rtn();                                             // 送信ﾃﾞｰﾀを用意する
  
  // FD_DAV  B00000001 // PL0/PC4(Data Valia)    : ﾃﾞｰﾀが有効
  PORTL |= FD_DAV;                                            // FD_DAV : LOW -> HIGH
}


// PC2ﾋﾟﾝ RISING ---------------------------------------------
// PC_DAC  B00000100 // PL6/PC2(Data Accepted) : ﾃﾞｰﾀの受け取り終了
void PC_DAC_RS_rtn() {
  // PD0～PD3 相手がいない時のｺﾞｰｽﾄ対策
  if (PINL_BK  == B00001111) { 
    return;
  }
  // ｾﾝﾄﾞﾃﾞｰﾀ・ｺﾏﾝﾄﾞ(高速転送時)
  if ((Comm_type == 18) && (Comm_sts == 3)) {
    Command18_rtn();
    PORTC = Snd_data_Buffer;                                  // ﾃﾞｰﾀ送信(PC7～PC0)
  }
  // FD_DAV  B00000001 // PL0/PC4(Data Valia)    : ﾃﾞｰﾀが有効
  PORTL &= FD_DAVL;                                           // FD_DAV : HIGH -> LOW
}


// PC3ﾋﾟﾝ RISING ---------------------------------------------
// PC_ATN  B00001000 // PL7/PC3(Attention)     : 1=次はｺﾏﾝﾄﾞ、0=次はﾃﾞｰﾀ
void PC_ATN_RS_rtn() {
  // PD0～PD3 相手がいない時のｺﾞｰｽﾄ対策
  if (PINL_BK  == B00001111) { 
    return;
  }

  Comm_sts = 1;                        // 0: ｺﾏﾝﾄﾞ無し、1:ｺﾏﾝﾄﾞｾｯﾄ、2:ﾊﾟﾗﾒｰﾀｾｯﾄ、3:ﾃﾞｰﾀｾｯﾄ、9:ｺﾏﾝﾄﾞ終了

  // FD_RFD  B00000010 // PL1/PC5(Ready For Data): ﾃﾞｰﾀの準備完了
  PORTL |= FD_RFD;                                            // FD_RFD : LOW -> HIGH
}


// PC0ﾋﾟﾝ FALLING ---------------------------------------------
// PC_DAV  B00000001 // PL4/PC0(Data Valia)    : ﾃﾞｰﾀが有効
void PC_DAV_FL_rtn() {
  // PD0～PD3 相手がいない時のｺﾞｰｽﾄ対策
  if (PINL_BK  == B00001111) { 
    return;
  }
  // ﾗｲﾄﾃﾞｨｽｸ・ｺﾏﾝﾄﾞ(高速転送)
  // Comm_sts = 3:ﾃﾞｰﾀｾｯﾄ
  // Byte_cnt > 0 は最後のﾊﾟﾗﾒｰﾀがRW_Buffer[0][0]にｾｯﾄされないようにする為
  if ((Comm_type == 17) && (Comm_sts == 3) && (Byte_cnt > 0)) {
    Rcv_data = PINA;                                          // PCからﾃﾞｰﾀ受信(PA7～PA0 のﾊﾞｯｸｱｯﾌﾟ)
    Command17_rtn();
  }
  // FD_DAC  B00000100 // PL2/PC6(Data Accepted) : ﾃﾞｰﾀの受け取り終了
  PORTL &= FD_DACL;                                           // FD_DAC : HIGH -> LOW

  if (Rcv_data_flg == true) {                                 // true : PCから後続ﾃﾞｰﾀあり
    // FD_RFD  B00000010 // PL1/PC5(Ready For Data): ﾃﾞｰﾀの準備完了
    PORTL |= FD_RFD;                                          // FD_RFD : LOW -> HIGH
  }
}


// PC2ﾋﾟﾝ FALLING ---------------------------------------------
// PC_DAC  B00000100 // PL6/PC2(Data Accepted) : ﾃﾞｰﾀの受け取り終了
void PC_DAC_FL_rtn() {
  // PD0～PD3 相手がいない時のｺﾞｰｽﾄ対策
  if (PINL_BK  == B00001111) { 
    return;
  }
  // 送信終了
}


// 受信ﾃﾞｰﾀを処理する ---------------------------------------------
void Data_rcv_rtn() {

  // ｺﾏﾝﾄﾞだけで実行できるならここでする
  switch (Comm_sts) {               // 0: ｺﾏﾝﾄﾞ無し、1:ｺﾏﾝﾄﾞｾｯﾄ、2:ﾊﾟﾗﾒｰﾀｾｯﾄ、3:ﾃﾞｰﾀｾｯﾄ、9:ｺﾏﾝﾄﾞ終了
  case 0:                                                     // ｺﾏﾝﾄﾞ無し
    break;
  case 1:                                                     // ｺﾏﾝﾄﾞｾｯﾄ
    // ｺﾏﾝﾄﾞに必要なﾊﾟﾗﾒｰﾀをｾｯﾄする準備
    Comm_set_rtn();
//Serial.println("Comm_set_rtn(); END");
    break;
  case 2:                                                     // ﾊﾟﾗﾒｰﾀｾｯﾄ
    if ((para_end[Comm_type] > 0) && (para_end[Comm_type] >= para_cnt)) {
//Serial.print(F("ﾊﾟﾗﾒｰﾀ : "));Serial.println(Rcv_data);         // debug
      Comm_para[para_cnt] = Rcv_data;           // ｺﾏﾝﾄﾞのﾊﾟﾗﾒｰﾀ
      para_cnt++;
    }
    if (para_end[Comm_type] == para_cnt) {
      // ﾊﾟﾗﾒｰﾀ・ｾｯﾄ & 実行
      Para_set_rtn();
    }
    break;
  case 3:                                                     // ﾃﾞｰﾀｾｯﾄ
    switch (Comm_type) {                                      // ｺﾏﾝﾄﾞ種別
    case 1:                                                   // ﾗｲﾄﾃﾞｨｽｸ・ｺﾏﾝﾄﾞ
      Command01_rtn();
      break;
    case 10:                                                  // ﾎﾟｰﾄ・ｱｳﾄﾌﾟｯﾄ・ｺﾏﾝﾄﾞ
      Command10_rtn();
      break;
    case 12:                                                  // ﾚｼｰﾌﾞ・ﾒﾓﾘﾃﾞｰﾀ・ｺﾏﾝﾄﾞ
      Command12_rtn();
      break;
    case 17:                                                  // ﾗｲﾄﾃﾞｨｽｸ・ｺﾏﾝﾄﾞ(高速転送)
      Command17_rtn();
      break;
    case 22:                                                  // ﾚｼｰﾌﾞ・ﾒﾓﾘﾃﾞｰﾀ・ｺﾏﾝﾄﾞ(高速転送)
      Command22_rtn();
    }
  }
}


// 送信ﾃﾞｰﾀを用意する ---------------------------------------------
void Data_snd_rtn() {

  switch (Comm_type) {                                        // ｺﾏﾝﾄﾞ種別
  case 3:                                                     // ｾﾝﾄﾞﾃﾞｰﾀ・ｺﾏﾝﾄﾞ
    Command03_rtn();
    break;
  case 6:                                                     // ﾚｻﾞﾙﾄ・ｽﾃｰﾀｽ・ｺﾏﾝﾄﾞ
    Command06_rtn();
    break;
  case 7:                                                     // ﾄﾞﾗｲﾌﾞ・ｽﾃｰﾀｽ・ｺﾏﾝﾄﾞ
    Command07_rtn();
    break;
  case 8:                                                     // ﾃｽﾄﾒﾓﾘ・ｺﾏﾝﾄﾞ
    Command08_rtn();
    break;
  case 9:                                                     // ｾﾝﾄﾞ・ﾒﾓﾘﾃﾞｰﾀ・ｺﾏﾝﾄﾞ
    Command09_rtn();
    break;
  case 11:                                                    // ｾﾝﾄﾞ・ﾒﾓﾘﾃﾞｰﾀ・ｺﾏﾝﾄﾞ
    Command11_rtn();
    break;
  case 18:                                                    // ｾﾝﾄﾞﾃﾞｰﾀ・ｺﾏﾝﾄﾞ(高速転送)
    Command18_rtn();
    break;
  case 19:                                                    // ｴﾗｰｽﾃｰﾀｽ・ｺﾏﾝﾄﾞ
    Command19_rtn();
    break;
//case 20:                                                    // ﾃﾞﾊﾞｲｽｽﾃｰﾀｽ・ｺﾏﾝﾄﾞ
//  Command20_rtn();
//  break;
  case 21:                                                    // ｾﾝﾄﾞ・ﾒﾓﾘﾃﾞｰﾀ・ｺﾏﾝﾄﾞ(高速転送)
    Command21_rtn();
    break;
//case 24:                                                    // ｾﾝﾄﾞ・ﾓｰﾄﾞﾃﾞｰﾀ・ｺﾏﾝﾄﾞ
//  Command24_rtn();
  }
  PORTC = Snd_data_Buffer;                                    // ﾃﾞｰﾀ送信(PC7～PC0)
}


// ｺﾏﾝﾄﾞに必要なﾊﾟﾗﾒｰﾀをｾｯﾄする準備 ---------------------------------------------
void Comm_set_rtn() {
  Comm_BK = Comm_type;                                        // 前のｺﾏﾝﾄﾞ種別
  Comm_type = Rcv_data;                                       // ｺﾏﾝﾄﾞ種別
//Serial.print(F("Comm_type -> "));Serial.println(Comm_type);   // debug
  if (Comm_type > 30) {
    return;
  }
  para_cnt = 0;                                               // 今は何番目のﾊﾟﾗﾒｰﾀか

  if (para_end[Comm_type] == 0) {                             // そのｺﾏﾝﾄﾞのﾊﾟﾗﾒｰﾀの数
    Rcv_data_flg = false;                                     // false : PCから後続ﾃﾞｰﾀなし
  } else {
    Rcv_data_flg = true;                                      // true  : PCから後続ﾃﾞｰﾀあり
    Comm_sts = 2;                      // 0: ｺﾏﾝﾄﾞ無し、1:ｺﾏﾝﾄﾞｾｯﾄ、2:ﾊﾟﾗﾒｰﾀｾｯﾄ、3:ﾃﾞｰﾀｾｯﾄ、9:ｺﾏﾝﾄﾞ終了
  }
  // ｺﾏﾝﾄﾞだけで実行できるならここでする
  switch (Comm_type) {                                        // ｺﾏﾝﾄﾞ種別
   case 3:                                                    // ｾﾝﾄﾞﾃﾞｰﾀ・ｺﾏﾝﾄﾞ開始
    Command03_start();                                        // 読み書ﾊﾞｯﾌｧｰを送信する前処理
    break;
  case 18:                                                    // ｾﾝﾄﾞﾃﾞｰﾀ・ｺﾏﾝﾄﾞ開始(高速転送)
    Command18_start();
  }
}


// ﾊﾟﾗﾒｰﾀ・ｾｯﾄ & 実行 ---------------------------------------------
// ｺﾏﾝﾄﾞやﾊﾟﾗﾒｰﾀが揃ったら分かりやすい変数にし実行する
void Para_set_rtn() {

  switch (Comm_type) {                                        // ｺﾏﾝﾄﾞ種別
  case 1:                                                     // ﾗｲﾄﾃﾞｨｽｸ・ｺﾏﾝﾄﾞ開始
    Sector_qt = Comm_para[0];
    Drive_No  = Comm_para[1];
    Track_No  = Comm_para[2];
    Sector_No = Comm_para[3];
    Command01_start();
    break;
  case 2:                                                     // ﾘｰﾄﾞﾃﾞｨｽｸ・ｺﾏﾝﾄﾞ
    Sector_qt = Comm_para[0];
    Drive_No  = Comm_para[1];
    Track_No  = Comm_para[2];
    Sector_No = Comm_para[3];
    Command02_rtn();
    break;
  case 4:                                                     // ｺﾋﾟｰ・ｺﾏﾝﾄﾞ
    Sector_qt   = Comm_para[0];
    Drive_sou   = Comm_para[1];
    Track_sou   = Comm_para[2];
    Sector_sou  = Comm_para[3];
    Drive_dest  = Comm_para[4];
    Track_dest  = Comm_para[5];
    Sector_dest = Comm_para[6];
    Command04_rtn();
    break;
  case 5:                                                     // ﾌｫｰﾏｯﾄ・ｺﾏﾝﾄﾞ
    Drive_No  = Comm_para[0];
    Command05_rtn();
    break;
  case 9:                                                     // ｾﾝﾄﾞ・ﾒﾓﾘﾃﾞｰﾀ・ｺﾏﾝﾄﾞ
    H_address = Comm_para[0];
    L_address = Comm_para[1];
    H_Number  = Comm_para[2];
    L_Number  = Comm_para[3];
    Command09_rtn();
    break;
  case 11:                                                    // ｾﾝﾄﾞ・ﾒﾓﾘﾃﾞｰﾀ・ｺﾏﾝﾄﾞ
    H_address = Comm_para[0];
    L_address = Comm_para[1];
    H_Number  = Comm_para[2];
    L_Number  = Comm_para[3];
    Command11_rtn();
    break;
  case 17:                                                    // ﾗｲﾄﾃﾞｨｽｸ・ｺﾏﾝﾄﾞ開始(高速転送)
    Sector_qt = Comm_para[0];
    Drive_No  = Comm_para[1];
    Track_No  = Comm_para[2];
    Sector_No = Comm_para[3];
    Command17_start();
    break;
  case 20:                                                    // ﾃﾞﾊﾞｲｽｽﾃｰﾀｽ・ｺﾏﾝﾄﾞ
    Drive_No  = Comm_para[0];
    Command20_rtn();
    break;
  case 24:                                                    // ｾﾝﾄﾞ・ﾓｰﾄﾞﾃﾞｰﾀ・ｺﾏﾝﾄﾞ
    Mode_data = Comm_para[0];
    Command24_rtn();
  }
}


//
