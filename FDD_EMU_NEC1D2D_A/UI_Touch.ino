////////////////////////////////////////////////////////////////////////////////////////////
/// ﾌﾗｯｼｭﾒﾓﾘ･ﾃﾞｰﾀ部 //////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
// root内のﾃﾞｨﾚｸﾄﾘとﾌｧｲﾙを表示(ﾀｯﾁｸﾘｰﾝ) ---------------------------------------------
// 固定文字列 ---------------------------------------------
const char Data_Screen_string[24][32] PROGMEM = {
"エミュレータ",               // [0]
"ＦＤ差しかえ",               // [1]
"ライトプロテクト",            // [2]
"イメージ出力",               // [3]
"中止",                      // [4]
"次へ",                      // [5]
"実行",                      // [6]
"ドライブ１",                 // [7]
"ドライブ２",                 // [8]
"ドライブ３",                 // [9]
"ドライブ４",                 // [10]
"FDD Emulator [NEC 1D,2D]", // [11]
"ライトプロテクトなし",        // [12]
"ライトプロテクトあり",        // [13]
"［データ修正あり］",          // [14]
"［未出力］",                 // [15]
"［    ］",                  // [16]
"［       ］",               // [17]
"［出力済］",                 // [18]
"［    ］",                  // [19]
"[ﾄﾞﾗｲﾌﾞNo,",                // [20]
"] ",                       // [21]
"▲",                       // [22]
"▼"                        // [23]
};
const char * const Str_Screen_string[] PROGMEM = {
Data_Screen_string[0],
Data_Screen_string[1],
Data_Screen_string[2],
Data_Screen_string[3],
Data_Screen_string[4],
Data_Screen_string[5],
Data_Screen_string[6],
Data_Screen_string[7],
Data_Screen_string[8],
Data_Screen_string[9],
Data_Screen_string[10],
Data_Screen_string[11],
Data_Screen_string[12],
Data_Screen_string[13],
Data_Screen_string[14],
Data_Screen_string[15],
Data_Screen_string[16],
Data_Screen_string[17],
Data_Screen_string[18],
Data_Screen_string[19],
Data_Screen_string[20],
Data_Screen_string[21],
Data_Screen_string[22],
Data_Screen_string[23]
};


const char Data_Screen_string2[2][64] PROGMEM = {
"使えないＦＤフォーマットです。",
"ドライブからＦＤ取出し用です。"
};
const char * const Str_Screen_string2[] PROGMEM = {
Data_Screen_string2[0],
Data_Screen_string2[1]
};


////////////////////////////////////////////////////////////////////////////////////////////
/// 処理部 //////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
// ﾀｯﾁの取得 ------------------------------------------------
void Get_touch() {
  Touch_flg = false;                                         // 画面に触ってない
  TSPoint p = TS.getPoint();
  //DDRF |= B00001100;                  // pinMode(A2, OUTPUT), pinMode(A3, OUTPUT)
  //DDRF |= B00000110;                  // pinMode(A1, OUTPUT), pinMode(A2, OUTPUT)
  DDRF |= YPXM_PORT;
  if (p.z > MINPRESSURE && p.z < MAXPRESSURE) {
      switch (Scr_Angle) {                                   // 1=90度右に回転,2=180度,3=270度,0=0度
//    case 0:
//      Th_X = map(p.x, TS_LEFT, TS_RIGHT, 0, 320);
//      Th_Y = map(p.y, TS_UP, TS_DOWN, 0, 480);
//      break;
//    case 1:
//      Th_X = map(p.y, TS_UP, TS_DOWN, 0, 480);
//      Th_Y = map(p.x, TS_RIGHT, TS_LEFT, 0, 320);
//      break;
      case 2:
        Th_X = map(p.x, TS_RIGHT, TS_LEFT, 0, 320);
        Th_Y = map(p.y, TS_DOWN, TS_UP, 0, 480);
        break;
      case 3:
        Th_X = map(p.y, TS_DOWN, TS_UP, 0, 480);
        Th_Y = map(p.x, TS_LEFT, TS_RIGHT, 0, 320);
      }
    if ((Th_X > 0) && (Th_Y > 0)) {
//Serial.print(F("Th_X = "));Serial.print(Th_X);             // debug
//Serial.print(F("  Th_Y = "));Serial.println(Th_Y);         // debug
      Touch_flg = true;                                      // 画面に触った
      return;
    }
  }
}


// そのﾎﾞﾀﾝが押されたかﾁｪｯｸ ------------------------------------------------
void Touch_check(int X1, int Y1, int X2, int Y2) {

  int X3 = X1 + X2;
  int Y3 = Y1 + Y2;
  
  if ((Th_X == 0) || (Th_Y == 0)) {
    Touch_flg = false;
    return;
  }
  if (((X1 <= Th_X)&&(Th_X <= X3))&&((Y1 <= Th_Y)&&(Th_Y <= Y3))) {
    Touch_flg = true;
  } else {
    Touch_flg = false;
  }
}


// EEPROMからﾀｯﾁｸﾘｰﾝのｷｬﾘﾌﾞﾚｰｼｮﾝ設定を読込む ------------------------------------------------
void Calibration_EEPROM_read() {

  byte byte_LowByte, byte_HighByte;
  int int_LowByte, int_HighByte;
  // 0x10-0x11:TS_LEFT
  byte_LowByte  = EEPROM.read(0x10);
  byte_HighByte = EEPROM.read(0x11);
  int_LowByte   = byte_LowByte;
  int_HighByte  = byte_HighByte;
  TS_LEFT = int_HighByte * 256 + int_LowByte;
  if (TS_LEFT == 0) {
    TS_LEFT = DTS_LEFT;
  }
  // 0x12-0x13:TS_RIGHT
  byte_LowByte  = EEPROM.read(0x12);
  byte_HighByte = EEPROM.read(0x13);
  int_LowByte   = byte_LowByte;
  int_HighByte  = byte_HighByte;
  TS_RIGHT = int_HighByte * 256 + int_LowByte;
  if (TS_RIGHT == 0) {
    TS_RIGHT = DTS_RIGHT;
  }
  // 0x14-0x15:TS_UP
  byte_LowByte  = EEPROM.read(0x14);
  byte_HighByte = EEPROM.read(0x15);
  int_LowByte   = byte_LowByte;
  int_HighByte  = byte_HighByte;
  TS_UP = int_HighByte * 256 + int_LowByte;
  if (TS_UP == 0) {
    TS_UP = DTS_UP;
  }
  // 0x16-0x17:TS_DOWN
  byte_LowByte  = EEPROM.read(0x16);
  byte_HighByte = EEPROM.read(0x17);
  int_LowByte   = byte_LowByte;
  int_HighByte  = byte_HighByte;
  TS_DOWN = int_HighByte * 256 + int_LowByte;
  if (TS_DOWN == 0) {
    TS_DOWN = DTS_DOWN;
  }
}


// ﾀｯﾁｽｸﾘｰﾝUI主処理 ------------------------------------------------
void Touch_UI_main() {
//Serial.println(F("Touch_UI_main();"));

//Serial.print(F("EMU_start_flg       = "));Serial.println(EMU_start_flg);// debug
//Serial.print(F("Initial_state       = "));Serial.println(Initial_state);// debug
//Serial.print(F("EMU_practicable_flg = "));Serial.println(EMU_practicable_flg);// debug

  if (EMU_start_flg == true) {                               // FDDｴﾐｭﾚｰﾀが開始されているか?
    Touch_drive_select_rtn();                                // FDDｴﾐｭﾚｰﾀ画像でﾄﾞﾗｲﾌﾞ選択
  } else {
    Select_detail_up_rtn();                                  // 明細選択(上)
    Select_detail_down_rtn();                                // 明細選択(下)

    if (Initial_state == true) {                             // 初期状態(initial state)
      FDD_Emulator_check();                                  // FDDｴﾐｭﾚｰﾀ画像
      Touch_FD_change_pre();                                 // ﾄﾞﾗｲﾌﾞでFDｲﾒｰｼﾞを交換(準備)
      Touch_FD_protect_pre();                                // FDｲﾒｰｼﾞを書込み保護(ﾗｲﾄﾌﾟﾛﾃｸﾄ)(準備)
      Touch_FD_output_pre();                                 // FDｲﾒｰｼﾞを出力(準備)
    } else {                                                 // 確認状態
      Touch_CANCEL_rtn();                                    //【中止】ﾎﾞﾀﾝ
      Touch_GO_rtn();                                        //【実行】ﾎﾞﾀﾝ
    }
  }
}


// FDDｴﾐｭﾚｰﾀ画像でﾄﾞﾗｲﾌﾞ選択 ------------------------------------------------
void Touch_drive_select_rtn() {
//Serial.println(F("Touch_drive_select_rtn();"));

  Touch_check(DRIVE1_SQ);                                    // FDD1の輪郭
  if (Touch_flg == true) {
    Drv_No  = 0;
    Touch_drive_select_rtn_contents();                       // FDDｴﾐｭﾚｰﾀ画像でﾄﾞﾗｲﾌﾞ選択(内容)
    return;
  }
  Touch_check(DRIVE2_SQ);                                    // FDD2の輪郭
  if (Touch_flg == true) {
    Drv_No  = 1;
    Touch_drive_select_rtn_contents();                       // FDDｴﾐｭﾚｰﾀ画像でﾄﾞﾗｲﾌﾞ選択(内容)
    return;
  }
  Touch_check(DRIVE3_SQ);                                    // FDD3の輪郭
  if (Touch_flg == true) {
    Drv_No  = 2;
    Touch_drive_select_rtn_contents();                       // FDDｴﾐｭﾚｰﾀ画像でﾄﾞﾗｲﾌﾞ選択(内容)
    return;
  }
  Touch_check(DRIVE4_SQ);                                    // FDD4の輪郭
  if (Touch_flg == true) {
    Drv_No  = 3;
    Touch_drive_select_rtn_contents();                       // FDDｴﾐｭﾚｰﾀ画像でﾄﾞﾗｲﾌﾞ選択(内容)
  }
}


// FDDｴﾐｭﾚｰﾀ画像でﾄﾞﾗｲﾌﾞ選択(内容) ------------------------------------------------
void Touch_drive_select_rtn_contents() {
//Serial.println(F("Touch_drive_select_rtn_contents();"));

  FD_info_TBL_NM_read(Drv_FD_Name[Drv_No]);                  // FD_No取得の為
  EMU_start_flg  = false;                                    // FDDｴﾐｭﾚｰﾀが開始されているか?
  FD_Function = 1;                                           // 処理機能
  Initial_state = false;                                     // 初期状態じゃない
  Drive_flg = false;                                         // ﾄﾞﾗｲﾌﾞを明細に出すか(false:出さない)
  Touch_Init_Screen();                                       // 設定初期画面(ﾀｯﾁｽｸﾘｰﾝ)
  Touch_FD_change_pre_contents();                            // ﾄﾞﾗｲﾌﾞでFDｲﾒｰｼﾞを交換(準備の内容)
}


// 明細選択(上) ------------------------------------------------
void Select_detail_up_rtn() {
//Serial.println(F("Select_detail_up_rtn();"));

  Touch_check(SL_UP_SQ);                                     // 選択ﾎﾞﾀﾝ(上)
  if (Touch_flg == false) {
    return;
  }
  if (Drive_flg == true) {                                   // ﾄﾞﾗｲﾌﾞを明細に出すか(true:出す)
    if (Drv_No == 0) {
      Drv_No = 3;
    } else {
      Drv_No--;
    }
//  Detail_area_Drive_set(Drv_No);                           // 明細領域にﾄﾞﾗｲﾌﾞ情報ｾｯﾄ
    Detail_area_Drive_set();                                 // 明細領域にﾄﾞﾗｲﾌﾞ情報ｾｯﾄ
  } else {
    if (FD_No == 0) {
      FD_No = File_count;
    } else {
      FD_No--;
    }
//  Detail_area_FD_set(FD_No);                               // 明細領域にFDｲﾒｰｼﾞﾌｧｲﾙｾｯﾄ
    Detail_area_FD_set();                                    // 明細領域にFDｲﾒｰｼﾞﾌｧｲﾙｾｯﾄ
  }
}


// 明細選択(下) ------------------------------------------------
void Select_detail_down_rtn() {
//Serial.println(F("Select_detail_down_rtn();"));

  Touch_check(SL_DWN_SQ);                                    // 選択ﾎﾞﾀﾝ(下)
  if (Touch_flg == false) {
    return;
  }
  if (Drive_flg == true) {                                   // ﾄﾞﾗｲﾌﾞを明細に出すか(true:出す)
    if (Drv_No == 3) {
      Drv_No = 0;
    } else {
      Drv_No++;
    }
//  Detail_area_Drive_set(Drv_No);                           // 明細領域にﾄﾞﾗｲﾌﾞ情報ｾｯﾄ
    Detail_area_Drive_set();                                 // 明細領域にﾄﾞﾗｲﾌﾞ情報ｾｯﾄ
  } else {
    if (FD_No == File_count) {
      FD_No = 0;
    } else {
      FD_No++;
    }
//  Detail_area_FD_set(FD_No);                               // 明細領域にFDｲﾒｰｼﾞﾌｧｲﾙｾｯﾄ
    Detail_area_FD_set();                                    // 明細領域にFDｲﾒｰｼﾞﾌｧｲﾙｾｯﾄ
  }
}


// ﾄﾞﾗｲﾌﾞでFDｲﾒｰｼﾞを交換(準備) ------------------------------------------------
void Touch_FD_change_pre() {
//Serial.println(F("Touch_FD_change_pre();"));

  Touch_check(CHANGE_SQ);                                    //【FD差替え】ﾎﾞﾀﾝ
  if (Touch_flg == false) {
    return;
  }
  Insert_File_Name(File_TBL[FD_No]);                         // ﾌｧｲﾙ名
  FD_info_TBL_read(FD_No);                                   // FDｲﾒｰｼﾞﾌｧｲﾙ情報読込み 
  if ((FD_format == 9) && (File_Name[0] != '*')) {           // ﾌｫｰﾏｯﾄ区分(9:対象外)
    Warning_MSG_format();                                    // 警告ﾒｯｾｰｼﾞ(ﾌｫｰﾏｯﾄ区分(9:対象外))
    return;
  }
  FD_Function = 1;                                           // 処理機能
  Initial_state = false;                                     // 初期状態じゃない
  Drive_flg = true;                                          // ﾄﾞﾗｲﾌﾞを明細に出すか(true:出す)

  Touch_FD_change_pre_contents();                            // ﾄﾞﾗｲﾌﾞでFDｲﾒｰｼﾞを交換(準備の内容)
}


// ﾄﾞﾗｲﾌﾞでFDｲﾒｰｼﾞを交換(準備の内容) ------------------------------------------------
void Touch_FD_change_pre_contents() {
//Serial.println(F("Touch_FD_change_pre_contents();"));

  DSP.fillRoundRect(CHANGE_SQ, 3, YELLOW);                   //【FD差替え】ﾎﾞﾀﾝ
  strcpy_P(Short_Str, pgm_read_word(&(Str_Screen_string[1])));
  KNJ_print(Short_Str, CHANGE_ST, BLACK);
  if (Drive_flg == true) {                                   // ﾄﾞﾗｲﾌﾞを明細に出すか(true:出す)
//  Detail_area_Drive_set(Drv_No);                           // 明細領域にﾄﾞﾗｲﾌﾞ情報ｾｯﾄ
    Detail_area_Drive_set();                                 // 明細領域にﾄﾞﾗｲﾌﾞ情報ｾｯﾄ
    MSG_CHANGE_select();                                     // ﾒｯｾｰｼﾞ(FD差替え選択案内)
  } else {
//  Detail_area_FD_set(FD_No);                               // 明細領域にFDｲﾒｰｼﾞﾌｧｲﾙｾｯﾄ
    Detail_area_FD_set();                                    // 明細領域にFDｲﾒｰｼﾞﾌｧｲﾙｾｯﾄ
    MSG_Drive_select();                                      // ﾒｯｾｰｼﾞ(FD差替え選択案内)
  }
  Confirm_area_set();                                        // 確定ｴﾘｱ【中止】【実行】ﾎﾞﾀﾝ
}


// FDｲﾒｰｼﾞを書込み保護(ﾗｲﾄﾌﾟﾛﾃｸﾄ)(準備) ------------------------------------------------
void Touch_FD_protect_pre() {
//Serial.println(F("Touch_FD_protect_pre();"));

  Touch_check(PROTECT_SQ);                                   //【ﾗｲﾄﾌﾟﾛﾃｸﾄ】ﾎﾞﾀﾝ
  if (Touch_flg == false) {
    return;
  }
  Insert_File_Name(File_TBL[FD_No]);                         // ﾌｧｲﾙ名
  FD_info_TBL_read(FD_No);                                   // FDｲﾒｰｼﾞﾌｧｲﾙ情報読込み 
  if (File_Name[0] == '*') {
    Warning_MSG_DUMMY_Name();                         // 警告ﾒｯｾｰｼﾞ("********.***"はﾄﾞﾗｲﾌﾞからFD取出し用)
    return;
  }
  if (FD_format == 9) {                                      // ﾌｫｰﾏｯﾄ区分(9:対象外)
    Warning_MSG_format();                                    // 警告ﾒｯｾｰｼﾞ(ﾌｫｰﾏｯﾄ区分(9:対象外))
    return;
  }
  FD_Function = 2;                                           // 処理機能
  Initial_state = false;                                     // 初期状態じゃない
  Drive_flg = false;                                         // ﾄﾞﾗｲﾌﾞを明細に出すか(false:出さない)

  DSP.fillRoundRect(PROTECT_SQ, 3, YELLOW);                  //【ﾗｲﾄﾌﾟﾛﾃｸﾄ】ﾎﾞﾀﾝ
  strcpy_P(Short_Str, pgm_read_word(&(Str_Screen_string[2])));
  KNJ_print(Short_Str, PROTECT_ST, BLACK);
  Confirm_area_set();                                        // 確定ｴﾘｱ【中止】【実行】ﾎﾞﾀﾝ

  MSG_PROTECT_select();                                      // ﾒｯｾｰｼﾞ(ﾗｲﾄﾌﾟﾛﾃｸﾄ選択案内)
}


// FDｲﾒｰｼﾞを出力(準備) ------------------------------------------------
void Touch_FD_output_pre() {
//Serial.println(F("Touch_FD_output_pre();"));

  Touch_check(OUTPUT_SQ);                                    //【ｲﾒｰｼﾞ出力】ﾎﾞﾀﾝ
  if (Touch_flg == false) {
    return;
  }
  Insert_File_Name(File_TBL[FD_No]);                         // ﾌｧｲﾙ名
  FD_info_TBL_read(FD_No);                                   // FDｲﾒｰｼﾞﾌｧｲﾙ情報読込み 
  if (File_Name[0] == '*') {
    Warning_MSG_DUMMY_Name();                         // 警告ﾒｯｾｰｼﾞ("********.***"はﾄﾞﾗｲﾌﾞからFD取出し用)
    return;
  }
  if (FD_format == 9) {                                      // ﾌｫｰﾏｯﾄ区分(9:対象外)
    Warning_MSG_format();                                    // 警告ﾒｯｾｰｼﾞ(ﾌｫｰﾏｯﾄ区分(9:対象外))
    return;
  }
  FD_Function = 3;                                           // 処理機能
  Initial_state = false;                                     // 初期状態じゃない
  Drive_flg = false;                                         // ﾄﾞﾗｲﾌﾞを明細に出すか(false:出さない)

  DSP.fillRoundRect(OUTPUT_SQ, 3, YELLOW);                   //【ｲﾒｰｼﾞ出力】ﾎﾞﾀﾝ
  strcpy_P(Short_Str, pgm_read_word(&(Str_Screen_string[3])));
  KNJ_print(Short_Str, OUTPUT_ST, BLACK);

  Confirm_area_set();                                        // 確定ｴﾘｱ【中止】【実行】ﾎﾞﾀﾝ

  MSG_OUTPUT_select();                                       // ﾒｯｾｰｼﾞ(ｲﾒｰｼﾞ出力選択案内)
}


//【中止】ﾎﾞﾀﾝ ------------------------------------------------
void Touch_CANCEL_rtn() {
//Serial.println(F("Touch_CANCEL_rtn();"));

  Touch_check(CANCEL_SQ);                                    //【中止】ﾎﾞﾀﾝ
  if (Touch_flg == false) {
    return;
  }
  Touch_Reset_Screen();                                      // 初期画面に戻す(ﾀｯﾁｽｸﾘｰﾝ)

//Detail_area_FD_set(FD_No);                                 // 明細領域にFDｲﾒｰｼﾞﾌｧｲﾙｾｯﾄ
  Detail_area_FD_set();                                      // 明細領域にFDｲﾒｰｼﾞﾌｧｲﾙｾｯﾄ

  MSG_Init();                                                // ﾒｯｾｰｼﾞ(機能選択案内)
}


//【実行】ﾎﾞﾀﾝ ------------------------------------------------
void Touch_GO_rtn() {
//Serial.println(F("Touch_GO_rtn();"));

  Touch_check(GO_SQ);                                        //【実行】ﾎﾞﾀﾝ
  if (Touch_flg == false) {
    return;
  }
  switch (FD_Function) {
  case 1:
    Touch_FD_change_rtn();                                   // ﾄﾞﾗｲﾌﾞでFDｲﾒｰｼﾞを交換
    return;
  case 2:
    Touch_FD_protect_rtn();                                  // FDｲﾒｰｼﾞを書込み保護(ﾗｲﾄﾌﾟﾛﾃｸﾄ)
    return;
  case 3:
    Touch_FD_output_rtn();                                   // FDｲﾒｰｼﾞを出力
    return;
  }
  if (EMU_practicable_flg == false) {                 // FDDｴﾐｭﾚｰﾀ実行可能か？(SDｶｰﾄﾞに[EMU]ﾎﾙﾀﾞｰがあるか?)
    DSP.fillRect(CONFIRM_SQ, GRAY);                          // 確定ｴﾘｱ
    MSG_SD_Init_wait();                                      // ﾒｯｾｰｼﾞ(SDｶｰﾄﾞ準備案内)
    Directory_making_rtn();                                  // ﾃﾞｨﾚｸﾄﾘを作成
    Drv_fd_link_use_bundle();                                // ﾄﾞﾗｲﾌﾞにFDｲﾒｰｼﾞ紐づけﾌｧｲﾙ作成(一括)
    WORK0000_IMG_create(5);                                  // /FD_IN/WK1D0000.IMGを作成
    WORK0000_IMG_create(7);                                  // /FD_IN/WK2D0000.IMGを作成
    readme_txt_create();                                     // readme.txt作成
    MSG_FD_set();                                            // ﾘｽﾄへﾒｯｾｰｼﾞ出力(FDｲﾒｰｼﾞﾌｧｲﾙｾｯﾄ案内)
    Waiting_for_reset();                                     // 処理中止
  }
}


// ﾄﾞﾗｲﾌﾞでFDｲﾒｰｼﾞを交換 ------------------------------------------------
void Touch_FD_change_rtn() {
//Serial.println(F("Touch_FD_change_rtn();"));

  Drive_cnt = Drv_No;
//Serial.print(F("Drv_FD_Name[0] : "));Serial.println(Drv_FD_Name[0]);
//Serial.print(F("Drv_FD_Name[1] : "));Serial.println(Drv_FD_Name[1]);
//Serial.print(F("Drv_FD_Name[2] : "));Serial.println(Drv_FD_Name[2]);
//Serial.print(F("Drv_FD_Name[3] : "));Serial.println(Drv_FD_Name[3]);
//Serial.print(F("File_Name : "));Serial.println(File_Name);
//Serial.print(F("Drive_cnt : "));Serial.println(Drive_cnt);
//Drv_fd_link_crt(File_Name, Drive_cnt);                     // ﾄﾞﾗｲﾌﾞにFDｲﾒｰｼﾞ紐づけﾌｧｲﾙ作成
  Drv_fd_link_crt();                                         // ﾄﾞﾗｲﾌﾞにFDｲﾒｰｼﾞ紐づけﾌｧｲﾙ作成
//Serial.print(F("Drv_FD_Name[0] : "));Serial.println(Drv_FD_Name[0]);
//Serial.print(F("Drv_FD_Name[1] : "));Serial.println(Drv_FD_Name[1]);
//Serial.print(F("Drv_FD_Name[2] : "));Serial.println(Drv_FD_Name[2]);
//Serial.print(F("Drv_FD_Name[3] : "));Serial.println(Drv_FD_Name[3]);

  FD_info_TBL_NM_read(Drv_FD_Name[Drv_No]);                  // FD_No取得の為

  Touch_Reset_Screen();                                      // 初期画面に戻す(ﾀｯﾁｽｸﾘｰﾝ)

//Detail_area_FD_set(FD_No);                                 // 明細領域にFDｲﾒｰｼﾞﾌｧｲﾙｾｯﾄ
  Detail_area_FD_set();                                      // 明細領域にFDｲﾒｰｼﾞﾌｧｲﾙｾｯﾄ

  MSG_CHANGE_end();                                          // ﾒｯｾｰｼﾞ(FD差替え終了)
}


// FDｲﾒｰｼﾞを書込み保護(ﾗｲﾄﾌﾟﾛﾃｸﾄ) ------------------------------------------------
void Touch_FD_protect_rtn() {
//Serial.println(F("Touch_FD_protect_rtn();"));

  Insert_File_Name(File_TBL[FD_No]);                         // ﾌｧｲﾙ名
  FD_info_TBL_read(FD_No);                                   // FDｲﾒｰｼﾞﾌｧｲﾙ情報読込み 
  if (FD_protect == 0) {                                     // 書込み保護(ﾗｲﾄﾌﾟﾛﾃｸﾄ)(0:なし, 1:あり)
    // FDｲﾒｰｼﾞﾌｧｲﾙ情報を更新(ｲﾒｰｼﾞﾌｧｲﾙ名, 書込み保護, 更新区分, 出力区分)
//  FD_info_rewrite(File_Name, 1, 9, 9);                     // 書込み保護(ﾗｲﾄﾌﾟﾛﾃｸﾄ)(1:あり)
    FD_info_rewrite(1, 9, 9);                                // 書込み保護(ﾗｲﾄﾌﾟﾛﾃｸﾄ)(1:あり)
    FD_info_TBL_rewrite(FD_No, 1, 9, 9);                     // 書込み保護(ﾗｲﾄﾌﾟﾛﾃｸﾄ)(1:あり)
  } else if (FD_protect == 1) {
    // FDｲﾒｰｼﾞﾌｧｲﾙ情報を更新(ｲﾒｰｼﾞﾌｧｲﾙ名, 書込み保護, 更新区分, 出力区分)
//  FD_info_rewrite(File_Name, 0, 9, 9);                     // 書込み保護(ﾗｲﾄﾌﾟﾛﾃｸﾄ)(0:なし)
    FD_info_rewrite(0, 9, 9);                                // 書込み保護(ﾗｲﾄﾌﾟﾛﾃｸﾄ)(0:なし)
    FD_info_TBL_rewrite(FD_No, 0, 9, 9);                     // 書込み保護(ﾗｲﾄﾌﾟﾛﾃｸﾄ)(0:なし)
  }

  Touch_Reset_Screen();                                      // 初期画面に戻す(ﾀｯﾁｽｸﾘｰﾝ)

//Detail_area_FD_set(FD_No);                                 // 明細領域にFDｲﾒｰｼﾞﾌｧｲﾙｾｯﾄ
  Detail_area_FD_set();                                      // 明細領域にFDｲﾒｰｼﾞﾌｧｲﾙｾｯﾄ

  MSG_PROTECT_end();                                         // ﾒｯｾｰｼﾞ(ﾗｲﾄﾌﾟﾛﾃｸﾄ終了)
}


// FDｲﾒｰｼﾞを出力 ------------------------------------------------
void Touch_FD_output_rtn() {
//Serial.println(F("Touch_FD_output_rtn();"));

  Insert_File_Name(File_TBL[FD_No]);                         // ﾌｧｲﾙ名
  FD_info_TBL_read(FD_No);                                   // FDｲﾒｰｼﾞﾌｧｲﾙ情報読込み 

  DSP.fillRect(CONFIRM_SQ, GRAY);                            // 確定ｴﾘｱ

  MSG_OUTPUT_wait();                                         // ﾒｯｾｰｼﾞ(処理実行中案内)

  // ﾌｫｰﾏｯﾄ区分(1:d88(1D 35ﾄﾗｯｸ), 2:d88(1D 40ﾄﾗｯｸ), 3:d88(2D), 4:予備)
  if ((FD_format >= 1) && (FD_format <= 4)) {
//  D88_write_rtn(File_Name, FD_format);
    D88_write_rtn(FD_format);
  }
  // ﾌｫｰﾏｯﾄ区分(5:ﾌﾟﾚｰﾝｲﾒｰｼﾞ(1D 35ﾄﾗｯｸ), 6:ﾌﾟﾚｰﾝｲﾒｰｼﾞ(1D 40ﾄﾗｯｸ), 7:ﾌﾟﾚｰﾝｲﾒｰｼﾞ(2D), 8:予備)
  if ((FD_format >= 5) && (FD_format <= 8)) {
//  Plane_img_write_rtn(File_Name, FD_format);
    Plane_img_write_rtn(FD_format);
  }
  // FDｲﾒｰｼﾞﾌｧｲﾙ情報を更新(ｲﾒｰｼﾞﾌｧｲﾙ名, 書込み保護, 更新区分, 出力区分)
//FD_info_rewrite(File_Name, 9, 0, 1);                       // FDｲﾒｰｼﾞﾌｧｲﾙ情報を更新
  FD_info_rewrite(9, 0, 1);                                  // FDｲﾒｰｼﾞﾌｧｲﾙ情報を更新
  FD_info_TBL_rewrite(FD_No, 9, 0, 1);                       // FDｲﾒｰｼﾞﾌｧｲﾙ情報ﾃｰﾌﾞﾙを更新

  Touch_Reset_Screen();                                      // 初期画面に戻す(ﾀｯﾁｽｸﾘｰﾝ)

//Detail_area_FD_set(FD_No);                                 // 明細領域にFDｲﾒｰｼﾞﾌｧｲﾙｾｯﾄ
  Detail_area_FD_set();                                      // 明細領域にFDｲﾒｰｼﾞﾌｧｲﾙｾｯﾄ

  MSG_OUTPUT_end();                                          // ﾒｯｾｰｼﾞ(FDｲﾒｰｼﾞ出力終了)
}


// 初期画面に戻す(ﾀｯﾁｽｸﾘｰﾝ) ------------------------------------------------
void Touch_Reset_Screen() {
//Serial.println(F("Touch_Reset_Screen();"));

  FD_Function = 0;                                           // 処理機能
  Initial_state = true;                                      // 初期状態
  Drive_flg = false;                                         // ﾄﾞﾗｲﾌﾞを明細に出すか(false:出さない)

  DSP.fillRoundRect(CHANGE_SQ, 3, GREEN);                    //【FD差替え】ﾎﾞﾀﾝ
  DSP.fillRoundRect(PROTECT_SQ, 3, GREEN);                   //【ﾗｲﾄﾌﾟﾛﾃｸﾄ】ﾎﾞﾀﾝ
  DSP.fillRoundRect(OUTPUT_SQ, 3, GREEN);                    //【ｲﾒｰｼﾞ出力】ﾎﾞﾀﾝ

  strcpy_P(Short_Str, pgm_read_word(&(Str_Screen_string[1])));
  KNJ_print(Short_Str, CHANGE_ST, BLACK);
  strcpy_P(Short_Str, pgm_read_word(&(Str_Screen_string[2])));
  KNJ_print(Short_Str, PROTECT_ST, BLACK);
  strcpy_P(Short_Str, pgm_read_word(&(Str_Screen_string[3])));
  KNJ_print(Short_Str, OUTPUT_ST, BLACK);

  DSP.fillRect(CONFIRM_SQ, GRAY);                            // 確定ｴﾘｱ
}


// 設定初期画面(ﾀｯﾁｽｸﾘｰﾝ) ------------------------------------------------
void Touch_Init_Screen() {
//Serial.println(F("Touch_Init_Screen();"));

  Scr_Angle = 2;                                             // 1=90度右に回転,2=180度,3=270度,0=0度
  DSP.setRotation(Scr_Angle);

  DSP.fillScreen(GRAY);
  // 入力ﾌｫｰﾑの作成
  // 画面名
  DSP.fillRect(TITLE_SQ, BLACK);
  strcpy_P(Short_Str, pgm_read_word(&(Str_Screen_string[11])));
  ANK_print(Short_Str, TITLE_ST, WHITE);                     // "FDD Emulator [NEC 1D,2D]"

  // 明細領域ｾｯﾄ
  DSP.fillRoundRect(SL_UP_SQ, 3, GREEN);
  DSP.fillRoundRect(SL_DWN_SQ, 3, GREEN);
  strcpy_P(Short_Str, pgm_read_word(&(Str_Screen_string[22])));
  KNJ_print(Short_Str, SL_UP_ST, BLACK);                     // 選択ﾎﾞﾀﾝ(▲)
  strcpy_P(Short_Str, pgm_read_word(&(Str_Screen_string[23])));
  KNJ_print(Short_Str, SL_DWN_ST, BLACK);                    // 選択ﾎﾞﾀﾝ(▼)

  // ﾎﾞﾀﾝの枠
  DSP.fillRoundRect(EMU_SQ, 3, GREEN);
  DSP.fillRoundRect(CHANGE_SQ, 3, GREEN);
  DSP.fillRoundRect(PROTECT_SQ, 3, GREEN);
  DSP.fillRoundRect(OUTPUT_SQ, 3, GREEN);
  strcpy_P(Short_Str, pgm_read_word(&(Str_Screen_string[0])));
  KNJ_print(Short_Str, EMU_ST, BLACK);
  strcpy_P(Short_Str, pgm_read_word(&(Str_Screen_string[1])));
  KNJ_print(Short_Str, CHANGE_ST, BLACK);
  strcpy_P(Short_Str, pgm_read_word(&(Str_Screen_string[2])));
  KNJ_print(Short_Str, PROTECT_ST, BLACK);
  strcpy_P(Short_Str, pgm_read_word(&(Str_Screen_string[3])));
  KNJ_print(Short_Str, OUTPUT_ST, BLACK);
}


// 設定初期画面明細領域ｾｯﾄ(ﾀｯﾁｽｸﾘｰﾝ) ------------------------------------------------
void Touch_Init_Detail_set() {
//Serial.println(F("Touch_Init_Detail_set();"));

  // 明細領域ｾｯﾄ
  if (EMU_start_flg == false) {                              // FDDｴﾐｭﾚｰﾀが開始されているか?
    File_TBL_create();                                       // [FD_IN]ﾌｫﾙﾀﾞｰのﾌｧｲﾙﾘｽﾄ作成
    Insert_File_TBL(DUMMY_Name, File_count);                 // File_TBL[]に文字列を挿入する(FDなし用)
//for ( int cnt = 0 ; cnt <= File_count ; cnt++ ) {            // debug
//Serial.print(F("File_TBL["));Serial.print(cnt, DEC);         // debug
//Serial.print(F("] = "));Serial.println(File_TBL[cnt]);       // debug
//}//debug
//  Detail_area_FD_set(FD_No);                               // 明細領域にFDｲﾒｰｼﾞﾌｧｲﾙｾｯﾄ
    Detail_area_FD_set();                                    // 明細領域にFDｲﾒｰｼﾞﾌｧｲﾙｾｯﾄ
  }
  Initial_state = true;                                      // 初期状態(initial state)
  MSG_Init();                                                // ﾒｯｾｰｼﾞ(機能選択案内)
}


// 確定ｴﾘｱ【中止】【実行】ﾎﾞﾀﾝｾｯﾄ ------------------------------------------------
void Confirm_area_set() {
//Serial.println(F("Confirm_area_set();"));

  DSP.fillRect(CONFIRM_SQ, GRAY);                            // 確定ｴﾘｱ

  DSP.fillRoundRect(CANCEL_SQ, 3, GREEN);                    //【中止】ﾎﾞﾀﾝ
  strcpy_P(Short_Str, pgm_read_word(&(Str_Screen_string[4])));
  KNJ_print(Short_Str, CANCEL_ST, BLACK);

  DSP.fillRoundRect(GO_SQ, 3, GREEN);                        //【実行】ﾎﾞﾀﾝ
  strcpy_P(Short_Str, pgm_read_word(&(Str_Screen_string[6])));
  KNJ_print(Short_Str, GO_ST, BLACK);
}


// 明細領域にFDｲﾒｰｼﾞﾌｧｲﾙｾｯﾄ ------------------------------------------------
//void Detail_area_FD_set(int FD_No) {
void Detail_area_FD_set() {
//Serial.print(F("Detail_area_FD_set( "));Serial.print(Detail_No);// debug
//Serial.println(F(" );"));//debug
  int Before_No, After_No, Plus_No;

  DSP.fillRect(BEFORE_SQ, WHITE);
  DSP.fillRect(DETAIL_SQ, WHITE);
  DSP.fillRect(AFTOR_SQ, WHITE);
  
  // 前の明細(FDｲﾒｰｼﾞﾌｧｲﾙ名)
  if (FD_No == 0) {
    Before_No = File_count;
  } else {
    Before_No = FD_No - 1;
  }
//Serial.print(F("Before_No           : "));Serial.println(Before_No);// debug
//Serial.print(F("File_TBL[Before_No] : "));Serial.println(File_TBL[Before_No]);// debug
  Insert_File_Name(File_TBL[Before_No]);                     // ﾌｧｲﾙ名
  ANK_print(File_Name, BEFORE_ST, BLACK);                    // 前の明細(FDｲﾒｰｼﾞﾌｧｲﾙ名)

  // 後の明細(FDｲﾒｰｼﾞﾌｧｲﾙ名)
  if (FD_No == File_count) {
    After_No = 0;
  } else {
    After_No = FD_No + 1;
  }
//Serial.print(F("After_No            : "));Serial.println(After_No);// debug
//Serial.print(F("File_TBL[After_No]  : "));Serial.println(File_TBL[After_No]);// debug
  Insert_File_Name(File_TBL[After_No]);                      // ﾌｧｲﾙ名
  ANK_print(File_Name, AFTOR_ST, BLACK);                     // 後の明細(FDｲﾒｰｼﾞﾌｧｲﾙ名)

  // 選択された明細(FDｲﾒｰｼﾞﾌｧｲﾙ名)+属性1-3
//Serial.print(F("FD_No           : "));Serial.println(Detail_No);// debug
//Serial.print(F("File_TBL[FD_No] : "));Serial.println(File_TBL[Detail_No]);// debug
  Insert_File_Name(File_TBL[FD_No]);                         // ﾌｧｲﾙ名
  FD_info_TBL_read(FD_No);                                   // FDｲﾒｰｼﾞﾌｧｲﾙ情報読込み 
//FD_link_drv(File_Name);                                    // FDｲﾒｰｼﾞﾌｧｲﾙに紐づけされたﾄﾞﾗｲﾌﾞ番号
  FD_link_drv();                                             // FDｲﾒｰｼﾞﾌｧｲﾙに紐づけされたﾄﾞﾗｲﾌﾞ番号
  ANK_print(File_Name, DETAIL_ST, BLACK);                    // 選択された明細(FDｲﾒｰｼﾞﾌｧｲﾙ名)
  if (FD_protect == 0) {                                     // 書込み保護(ﾗｲﾄﾌﾟﾛﾃｸﾄ)(0:なし, 1:あり)
//  KNJ_print("ライトプロテクトなし", ATT_1_ST, BLACK);         // 選択された明細の属性1(attribute)
  strcpy_P(Short_Str, pgm_read_word(&(Str_Screen_string[12])));
  KNJ_print(Short_Str, ATT_1_ST, BLACK);                     // 選択された明細の属性1(attribute)
  } else if (FD_protect == 1) {
//  KNJ_print("ライトプロテクトあり", ATT_1_ST, BLACK);         // 選択された明細の属性1(attribute)
  strcpy_P(Short_Str, pgm_read_word(&(Str_Screen_string[13])));
  KNJ_print(Short_Str, ATT_1_ST, BLACK);                     // 選択された明細の属性1(attribute)
  }
  if (FD_update == 1) {                                      // 更新区分(0:なし, 1:あり)
//  Insert_Edit_Str("［データ修正あり］");
    strcpy_P(Edit_Str, pgm_read_word(&(Str_Screen_string[14])));
    if (FD_output == 0) {                                    // 出力区分(0:なし, 1:あり)
//    Connect_Edit_Str("［未出力］");                          // Edit_Strに文字列を連結する
      strcpy_P(Short_Str, pgm_read_word(&(Str_Screen_string[15])));
      Connect_Edit_Str(Short_Str);                           // Edit_Strに文字列を連結する
    } else {
//    Connect_Edit_Str("［    ］");                           // Edit_Strに文字列を連結する
      strcpy_P(Short_Str, pgm_read_word(&(Str_Screen_string[16])));
      Connect_Edit_Str(Short_Str);                           // Edit_Strに文字列を連結する
    }
  } else {
//  Insert_Edit_Str("［       ］");
    strcpy_P(Edit_Str, pgm_read_word(&(Str_Screen_string[17])));
    if (FD_output == 1) {                                   // 出力区分(0:なし, 1:あり)
//    Connect_Edit_Str("［出力済］");                         // Edit_Strに文字列を連結する
      strcpy_P(Short_Str, pgm_read_word(&(Str_Screen_string[18])));
      Connect_Edit_Str(Short_Str);                          // Edit_Strに文字列を連結する
    } else {
//    Connect_Edit_Str("［    ］");                          // Edit_Strに文字列を連結する
      strcpy_P(Short_Str, pgm_read_word(&(Str_Screen_string[19])));
      Connect_Edit_Str(Short_Str);                          // Edit_Strに文字列を連結する
    }
  }
  KNJ_print(Edit_Str, ATT_2_ST, BLACK);                     // 選択された明細の属性2(attribute)
  if (FD_drv_No != 9) {                                     // ﾄﾞﾗｲﾌﾞ番号(9:対象外)
//  Insert_Edit_Str("[ﾄﾞﾗｲﾌﾞNo,");
    strcpy_P(Edit_Str, pgm_read_word(&(Str_Screen_string[20])));
    Plus_No = FD_drv_No + 1;                                // ﾄﾞﾗｲﾌﾞ番号は内部的には0-3で、外部的には1-4
    DEC_Str_conversion(Plus_No);                            // 数値を文字列に変換する
    Connect_Edit_Str(DEC_Str);                              // Edit_Strに文字列を連結する
//  Connect_Edit_Str("] ");                                 // Edit_Strに文字列を連結する
    strcpy_P(Short_Str, pgm_read_word(&(Str_Screen_string[21])));
    Connect_Edit_Str(Short_Str);                            // Edit_Strに文字列を連結する
    ANK_print(Edit_Str, ATT_3_ST, BLACK);                   // 選択された明細の属性3(attribute)
  } else if (File_Name[0] == '*') {
//  Insert_Edit_Str("ドライブからＦＤ取出し用です。");
    strcpy_P(Edit_Str, pgm_read_word(&(Str_Screen_string2[1])));
    KNJ_print(Edit_Str, ATT_3_ST, BLACK);                   // 選択された明細の属性3(attribute)
  } else if (FD_format == 9) {                              // ﾌｫｰﾏｯﾄ区分(9:対象外)
//  Insert_Edit_Str("使えないＦＤフォーマットです。");
    strcpy_P(Edit_Str, pgm_read_word(&(Str_Screen_string2[0])));
    KNJ_print(Edit_Str, ATT_3_ST, BLACK);                   // 選択された明細の属性3(attribute)
  }
}


// 明細領域にﾄﾞﾗｲﾌﾞ情報ｾｯﾄ ------------------------------------------------
//void Detail_area_Drive_set(int Drv_No) {
void Detail_area_Drive_set() {
//Serial.print(F("Detail_area_Drive_set( "));Serial.print(Detail_No);//debug
//Serial.println(F(" );"));//debug
  int Before_No, After_No, Plus_No;
  
  DSP.fillRect(BEFORE_SQ, WHITE);
  DSP.fillRect(DETAIL_SQ, WHITE);
  DSP.fillRect(AFTOR_SQ, WHITE);
  
  // 前の明細(ﾄﾞﾗｲﾌﾞ番号)(FDｲﾒｰｼﾞﾌｧｲﾙ名)
  if (Drv_No == 0) {
    Before_No = 3;
  } else {
    Before_No = Drv_No - 1;
  }
//Insert_Edit_Str("[ﾄﾞﾗｲﾌﾞNo,");
  strcpy_P(Edit_Str, pgm_read_word(&(Str_Screen_string[20])));
  Plus_No = Before_No + 1;                                   // ﾄﾞﾗｲﾌﾞ番号は内部的には0-3で、外部的には1-4
  DEC_Str_conversion(Plus_No);                               // 数値を文字列に変換する
  Connect_Edit_Str(DEC_Str);                                 // Edit_Strに文字列を連結する
//Connect_Edit_Str("] ");                                    // Edit_Strに文字列を連結する
  strcpy_P(Short_Str, pgm_read_word(&(Str_Screen_string[21])));
  Connect_Edit_Str(Short_Str);                               // Edit_Strに文字列を連結する
  ANK_print(Edit_Str, BEFORE_ST, BLACK);                     // 前の明細(ﾄﾞﾗｲﾌﾞ番号)(FDｲﾒｰｼﾞﾌｧｲﾙ名)

  // 後の明細(ﾄﾞﾗｲﾌﾞ番号)(FDｲﾒｰｼﾞﾌｧｲﾙ名)
  if (Drv_No == 3) {
    After_No = 0;
  } else {
    After_No = Drv_No + 1;
  }
//Insert_Edit_Str("[ﾄﾞﾗｲﾌﾞNo,");
  strcpy_P(Edit_Str, pgm_read_word(&(Str_Screen_string[20])));
  Plus_No = After_No + 1;                                    // ﾄﾞﾗｲﾌﾞ番号は内部的には0-3で、外部的には1-4
  DEC_Str_conversion(Plus_No);                               // 数値を文字列に変換する
  Connect_Edit_Str(DEC_Str);                                 // Edit_Strに文字列を連結する
//Connect_Edit_Str("] ");                                    // Edit_Strに文字列を連結する
  strcpy_P(Short_Str, pgm_read_word(&(Str_Screen_string[21])));
  Connect_Edit_Str(Short_Str);                               // Edit_Strに文字列を連結する
  ANK_print(Edit_Str, AFTOR_ST, BLACK);                      // 後の明細(ﾄﾞﾗｲﾌﾞ番号)(FDｲﾒｰｼﾞﾌｧｲﾙ名)

  // 選択された明細(ﾄﾞﾗｲﾌﾞ番号)+属性1-3
//Insert_Edit_Str("[ﾄﾞﾗｲﾌﾞNo,");
  strcpy_P(Edit_Str, pgm_read_word(&(Str_Screen_string[20])));
  Plus_No = Drv_No + 1;                                      // ﾄﾞﾗｲﾌﾞ番号は内部的には0-3で、外部的には1-4
  DEC_Str_conversion(Plus_No);                               // 数値を文字列に変換する
  Connect_Edit_Str(DEC_Str);                                 // Edit_Strに文字列を連結する
//Connect_Edit_Str("] ");                                    // Edit_Strに文字列を連結する
  strcpy_P(Short_Str, pgm_read_word(&(Str_Screen_string[21])));
  Connect_Edit_Str(Short_Str);                               // Edit_Strに文字列を連結する
  ANK_print(Edit_Str, DETAIL_ST, BLACK);                     // 選択された明細(ﾄﾞﾗｲﾌﾞ番号)

  ANK_print(Drv_FD_Name[Drv_No], ATT_1_ST, BLACK);           // 選択された明細の属性1(attribute)

  FD_info_TBL_NM_read(Drv_FD_Name[Drv_No]);                  // FDｲﾒｰｼﾞﾌｧｲﾙ情報ﾃｰﾌﾞﾙ読込み(名前検索)
  if (FD_protect == 0) {                                     // 書込み保護(ﾗｲﾄﾌﾟﾛﾃｸﾄ)(0:なし, 1:あり)
//  KNJ_print("ライトプロテクトなし", ATT_2_ST, BLACK);         // 選択された明細の属性2(attribute)
 strcpy_P(Short_Str, pgm_read_word(&(Str_Screen_string[12])));
  KNJ_print(Short_Str, ATT_2_ST, BLACK);                     // 選択された明細の属性1(attribute)
   } else if (FD_protect == 1) {
//  KNJ_print("ライトプロテクトあり", ATT_2_ST, BLACK);         // 選択された明細の属性2(attribute)
  strcpy_P(Short_Str, pgm_read_word(&(Str_Screen_string[13])));
  KNJ_print(Short_Str, ATT_2_ST, BLACK);                     // 選択された明細の属性1(attribute)
  }
  if (FD_update == 1) {                                      // 更新区分(0:なし, 1:あり)
//  Insert_Edit_Str("［データ修正あり］");
    strcpy_P(Edit_Str, pgm_read_word(&(Str_Screen_string[14])));
    if (FD_output == 0) {                                    // 出力区分(0:なし, 1:あり)
//    Connect_Edit_Str("［未出力］");                          // Edit_Strに文字列を連結する
      strcpy_P(Short_Str, pgm_read_word(&(Str_Screen_string[15])));
      Connect_Edit_Str(Short_Str);                           // Edit_Strに文字列を連結する
    } else {
//    Connect_Edit_Str("［    ］");                           // Edit_Strに文字列を連結する
      strcpy_P(Short_Str, pgm_read_word(&(Str_Screen_string[16])));
      Connect_Edit_Str(Short_Str);                           // Edit_Strに文字列を連結する
    }
  } else {
//  Insert_Edit_Str("［       ］");
    strcpy_P(Edit_Str, pgm_read_word(&(Str_Screen_string[17])));
    if (FD_output == 1) {                                    // 出力区分(0:なし, 1:あり)
//    Connect_Edit_Str("［出力済］");                          // Edit_Strに文字列を連結する
      strcpy_P(Short_Str, pgm_read_word(&(Str_Screen_string[18])));
      Connect_Edit_Str(Short_Str);                           // Edit_Strに文字列を連結する
    } else {
//    Connect_Edit_Str("［    ］");                          // Edit_Strに文字列を連結する
      strcpy_P(Short_Str, pgm_read_word(&(Str_Screen_string[19])));
      Connect_Edit_Str(Short_Str);                           // Edit_Strに文字列を連結する
    }
  }
  KNJ_print(Edit_Str, ATT_3_ST, BLACK);                      // 選択された明細の属性3(attribute)
}


// FDDｴﾐｭﾚｰﾀ画像 ------------------------------------------------
void FDD_Emulator_check() {
// アクセスランプ
// 　スタンバイ状態の時には２０％の明るさで点灯します
// 　ドライブのアクセスをしている時には１００％の明るさで点灯します
//
// 　ただしドライブ４まで拡張している場合
// 　ドライブ４はスタンバイ状態でも１００％近い明るさで点灯します
// 　ドライブ１～３のアクセスランプが消えているときがドライブ４のアクセス中となります。

  Touch_check(EMU_SQ);                                       //【ｴﾐｭﾚｰﾀ】ﾎﾞﾀﾝ
  if (Touch_flg == false) {
    return;
  }
  EMU_start_flg = true;                                      // FDDｴﾐｭﾚｰﾀを開始
  FD_Function = 0;                                           // 処理機能
  Initial_state = true;                                      // 初期状態じゃない
  Drive_flg = false;                                         // ﾄﾞﾗｲﾌﾞを明細に出すか(false:出さない)
  FDD_Emulator_rtn();                                        // FDDｴﾐｭﾚｰﾀ画像
}


// FDDｴﾐｭﾚｰﾀ画像 ------------------------------------------------
void FDD_Emulator_rtn() {
// アクセスランプ
// 　スタンバイ状態の時には２０％の明るさで点灯します
// 　ドライブのアクセスをしている時には１００％の明るさで点灯します
//
// 　ただしドライブ４まで拡張している場合
// 　ドライブ４はスタンバイ状態でも１００％近い明るさで点灯します
// 　ドライブ１～３のアクセスランプが消えているときがドライブ４のアクセス中となります。

  Scr_Angle = 3;                                             // 1=90度右に回転,2=180度,3=270度,0=0度
  DSP.setRotation(Scr_Angle);

  DSP.fillScreen(DARK_GRAY);
  // PC-80S31, PC-80S32 のﾚﾊﾞｰ以外を描く
  DSP.fillRoundRect(PC80S31_SQ, 3, JP_SKIN);                 // PC80S31の輪郭
  DSP.fillRoundRect(PC80S32_SQ, 3, JP_SKIN);                 // PC80S32の輪郭

  DSP.drawRect(DRIVE1_SQ, BLACK);                            // FDD1の輪郭(線)
  DSP.drawRect(DRIVE2_SQ, BLACK);
  DSP.drawRect(DRIVE3_SQ, BLACK);
  DSP.drawRect(DRIVE4_SQ, BLACK);

  DSP.drawRect(D1_OTLT_SQ, BLACK);                           // FDD1の取出し口(線)
  DSP.drawRect(D2_OTLT_SQ, BLACK);
  DSP.drawRect(D3_OTLT_SQ, BLACK);
  DSP.drawRect(D4_OTLT_SQ, BLACK);

  DSP.fillCircle(D1_AXIS_CR, JP_SKIN);                       // FDD1の軸(面)
  DSP.fillCircle(D2_AXIS_CR, JP_SKIN);
  DSP.fillCircle(D3_AXIS_CR, JP_SKIN);
  DSP.fillCircle(D4_AXIS_CR, JP_SKIN);

  DSP.drawCircle(D1_AXIS_CR, BLACK);                         // FDD1の軸(線)
  DSP.drawCircle(D2_AXIS_CR, BLACK);
  DSP.drawCircle(D3_AXIS_CR, BLACK);
  DSP.drawCircle(D4_AXIS_CR, BLACK);

  DSP.fillRect(D1_INS_SQ, JP_SKIN_SHADOW);                   // FDD1の挿入口(面)
  DSP.fillRect(D2_INS_SQ, JP_SKIN_SHADOW);
  DSP.fillRect(D3_INS_SQ, JP_SKIN_SHADOW);
  DSP.fillRect(D4_INS_SQ, JP_SKIN_SHADOW);

  DSP.fillRect(D1_SLIT_SQ, BLACK);                           // FDD1の細い隙間(面)
  DSP.fillRect(D2_SLIT_SQ, BLACK);
  DSP.fillRect(D3_SLIT_SQ, BLACK);
  DSP.fillRect(D4_SLIT_SQ, BLACK);

  strcpy_P(Short_Str, pgm_read_word(&(Str_Screen_string[7])));
  KNJ_print(Short_Str, D1_LABEL_ST, BLACK);              // FDD1のﾗﾍﾞﾙ
  strcpy_P(Short_Str, pgm_read_word(&(Str_Screen_string[8])));
  KNJ_print(Short_Str, D2_LABEL_ST, BLACK);
  strcpy_P(Short_Str, pgm_read_word(&(Str_Screen_string[9])));
  KNJ_print(Short_Str, D3_LABEL_ST, BLACK);
  strcpy_P(Short_Str, pgm_read_word(&(Str_Screen_string[10])));
  KNJ_print(Short_Str, D4_LABEL_ST, BLACK);

  DSP.drawRect(S31_PW_DS_SQ, BLACK);                         // PC80S31の電源ｽｲｯﾁ表示
  DSP.drawRect(S32_PW_DS_SQ, BLACK);                         // PC80S32の電源ｽｲｯﾁ表示

  DSP.fillRect(S31_PW_SW_SQ, DARK_BROWN);                    // PC80S31の電源ｽｲｯﾁ
  DSP.fillRect(S32_PW_SW_SQ, DARK_BROWN);                    // PC80S32の電源ｽｲｯﾁ

  DSP.fillRect(S31_PW_LP_SQ, GREEN);                         // PC80S31の電源ﾗﾝﾌﾟ
  DSP.fillRect(S32_PW_LP_SQ, GREEN);                         // PC80S32の電源ﾗﾝﾌﾟ

  DSP.drawRect(S31_PW_LP_SQ, BLACK);                         // PC80S31の電源ﾗﾝﾌﾟ
  DSP.drawRect(S32_PW_LP_SQ, BLACK);                         // PC80S32の電源ﾗﾝﾌﾟ

  for ( int drv = 0 ; drv <= 3 ; drv++ ) {
    if (Drv_FD_Name[drv][0] == '*') {
      // ﾚﾊﾞｰを開く(ｱｸｾｽﾗﾝﾌﾟは黒)
      switch (drv) {
      case 0:
        DSP.fillRect(D1_LVR_V_SQ, JP_SKIN);                  // FDD1のﾚﾊﾞｰ(垂直)(面)
        DSP.drawRect(D1_LVR_V_SQ, BLACK);                    // FDD1のﾚﾊﾞｰ(垂直)(線)
        DSP.fillRect(D1_ERS_V_SQ, JP_SKIN);                  // FDD1の軸とﾚﾊﾞｰの間の線を消す(垂直)
        DSP.fillRect(D1_LED_SQ, BLACK);                      // FDD1のLED(面)
        break;
      case 1:
        DSP.fillRect(D2_LVR_V_SQ, JP_SKIN);                  // FDD2のﾚﾊﾞｰ(垂直)(面)
        DSP.drawRect(D2_LVR_V_SQ, BLACK);                    // FDD2のﾚﾊﾞｰ(垂直)(線)
        DSP.fillRect(D2_ERS_V_SQ, JP_SKIN);                  // FDD2の軸とﾚﾊﾞｰの間の線を消す(垂直)(
        DSP.fillRect(D2_LED_SQ, BLACK);                      // FDD2のLED(面)
        break;
      case 2:
        DSP.fillRect(D3_LVR_V_SQ, JP_SKIN);                  // FDD3のﾚﾊﾞｰ(垂直)(面)
        DSP.drawRect(D3_LVR_V_SQ, BLACK);                    // FDD3のﾚﾊﾞｰ(垂直)(線)
        DSP.fillRect(D3_ERS_V_SQ, JP_SKIN);                  // FDD3の軸とﾚﾊﾞｰの間の線を消す(垂直)
        DSP.fillRect(D3_LED_SQ, BLACK);                      // FDD3のLED(面)
        break;
      case 3:
        DSP.fillRect(D4_LVR_V_SQ, JP_SKIN);                  // FDD4のﾚﾊﾞｰ(垂直)(面)
        DSP.drawRect(D4_LVR_V_SQ, BLACK);                    // FDD4のﾚﾊﾞｰ(垂直)(線)
        DSP.fillRect(D4_ERS_V_SQ, JP_SKIN);                  // FDD4の軸とﾚﾊﾞｰの間の線を消す(垂直)
        DSP.fillRect(D4_LED_SQ, BLACK);                      // FDD4のLED(面)
      }
    } else {
      // ﾚﾊﾞｰを閉じる(ｱｸｾｽﾗﾝﾌﾟは20%の明るさ)
      switch (drv) {
      case 0:
        DSP.fillRect(D1_LVR_H_SQ, JP_SKIN);                  // FDD1のﾚﾊﾞｰ(水平)(面)
        DSP.drawRect(D1_LVR_H_SQ, BLACK);                    // FDD1のﾚﾊﾞｰ(水平)(線)
        DSP.fillRect(D1_ERS_H_SQ, JP_SKIN);                  // FDD1の軸とﾚﾊﾞｰの間の線を消す(水平)
        DSP.fillRect(D1_LED_SQ, DARK_RED);                   // FDD1のLED(面)
        break;
      case 1:
        DSP.fillRect(D2_LVR_H_SQ, JP_SKIN);                  // FDD2のﾚﾊﾞｰ(水平)(面)
        DSP.drawRect(D2_LVR_H_SQ, BLACK);                    // FDD2のﾚﾊﾞｰ(水平)(線)
        DSP.fillRect(D2_ERS_H_SQ, JP_SKIN);                  // FDD2の軸とﾚﾊﾞｰの間の線を消す(水平)
        DSP.fillRect(D2_LED_SQ, DARK_RED);                   // FDD2のLED(面)
        break;
      case 2:
        DSP.fillRect(D3_LVR_H_SQ, JP_SKIN);                  // FDD3のﾚﾊﾞｰ(水平)(面)
        DSP.drawRect(D3_LVR_H_SQ, BLACK);                    // FDD3のﾚﾊﾞｰ(水平)(線)
        DSP.fillRect(D3_ERS_H_SQ, JP_SKIN);                  // FDD2の軸とﾚﾊﾞｰの間の線を消す(水平)
        DSP.fillRect(D3_LED_SQ, DARK_RED);                   // FDD3のLED(面)
        break;
      case 3:
        DSP.fillRect(D4_LVR_H_SQ, JP_SKIN);                  // FDD4のﾚﾊﾞｰ(水平)(面)
        DSP.drawRect(D4_LVR_H_SQ, BLACK);                    // FDD4のﾚﾊﾞｰ(水平)(線)
        DSP.fillRect(D4_ERS_H_SQ, JP_SKIN);                  // FDD4の軸とﾚﾊﾞｰの間の線を消す(水平)
        DSP.fillRect(D4_LED_SQ, DARK_RED);                   // FDD4のLED(面)
      }
    }
  }
}


// SDｶｰﾄﾞ準備(ﾀｯﾁｽｸﾘｰﾝ) ------------------------------------------------
void Touch_SD_Init_rtn() {

  Scr_Angle = 2;                                             // 1=90度右に回転,2=180度,3=270度,0=0度
  DSP.setRotation(Scr_Angle);
  DSP.fillScreen(GRAY);
  // 入力ﾌｫｰﾑの作成
  // 画面名
  DSP.fillRect(TITLE_SQ, BLACK);
  strcpy_P(Short_Str, pgm_read_word(&(Str_Screen_string[11])));
  ANK_print(Short_Str, TITLE_ST, WHITE);                    // "FDD Emulator(NEC 2D(1D))"

  // 明細領域ｾｯﾄ
  DSP.fillRect(LIST_SQ, WHITE);
  Touch_root_Path_List();                                   // ﾊﾟｽ内のﾃﾞｨﾚｸﾄﾘとﾌｧｲﾙをﾘｽﾄ表示(ﾀｯﾁｸﾘｰﾝ)
 
  // ﾎﾞﾀﾝの枠
  DSP.fillRoundRect(GO_SQ, 3, GREEN);
  strcpy_P(Short_Str, pgm_read_word(&(Str_Screen_string[6])));
  KNJ_print(Short_Str, GO_ST, BLACK);
  Initial_state = false;                                    // 初期状態じゃない

  MSG_SD_Init();                                            // ﾒｯｾｰｼﾞ(SDｶｰﾄﾞ準備案内)
}


//
