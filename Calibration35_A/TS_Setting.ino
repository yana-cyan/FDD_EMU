////////////////////////////////////////////////////////////////////////////////////////////
/// ﾃﾞｰﾀ部 //////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
const char Data_TS_Setting[11][64] PROGMEM = {
"＊＊＊タッチパネル補正＊＊＊",
"順番に４すみの四角（□）の中心を",
"タッチペンでおしてください。",
"□□□ 左上 □□□",
"□□□ 右上 □□□",
"□□□ 右下 □□□",
"□□□ 左下 □□□",
"■■■■ 終りました。■■■■",
"パソコンを見てください。",
"ＡｒｄｕｉｎｏＩＤＥのシリアルモニタを出し",
"通信速度を１１５２００ｂｐｓにしてください"
};
const char * const Str_TS_Setting[] PROGMEM = {
Data_TS_Setting[0],
Data_TS_Setting[1],
Data_TS_Setting[2],
Data_TS_Setting[3],
Data_TS_Setting[4],
Data_TS_Setting[5],
Data_TS_Setting[6],
Data_TS_Setting[7],
Data_TS_Setting[8],
Data_TS_Setting[9],
Data_TS_Setting[10]
};


////////////////////////////////////////////////////////////////////////////////////////////
/// 処理部 //////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
// ﾀｯﾁｸﾘｰﾝのｷｬﾘﾌﾞﾚｰｼｮﾝ設定 ------------------------------------------------
void Touch_Screen_Setting() {

  // ﾀｯﾁｽｸﾘｰﾝの初期化
  DSP.reset();                                                // 画面初期化(MCUFRIEND)
  uint16_t ID = DSP.readID();                                 // 画面初期化(MCUFRIEND)
  DSP.begin(ID);                                              // 画面初期化(MCUFRIEND)
  DSP.setRotation(1);                                         // 1=90度右に回転：2=180度：3=270度
  DSP.fillScreen(BLACK);

  strcpy_P(Edit_Str, pgm_read_word(&(Str_TS_Setting[9])));
  KNJ_print(Edit_Str, 30, 125, 2, WHITE);              // "ＡｒｄｕｉｎｏＩＤＥのシリアルモニタを出し"
  strcpy_P(Edit_Str, pgm_read_word(&(Str_TS_Setting[10])));
  KNJ_print(Edit_Str, 30, 145, 2, WHITE);              // "通信速度を１１５２００ｂｐｓにしてください"

  EEPROM_read_check();                             // EEPROMからﾀｯﾁﾊﾟﾈﾙのｷｬﾘﾌﾞﾚｰｼｮﾝ設定を読込む
  
  byte _GO = Yes_No;

  if (_GO == 1) {
    Calibration_Setting();                         // ﾀｯﾁｸﾘｰﾝでｷｬﾘﾌﾞﾚｰｼｮﾝ設定をする
  }
  Touch_Screen_test();                             // ﾀｯﾁｽｸﾘｰﾝのﾃｽﾄ

  if (_GO == 1) {
    Saving_Calibration_data();                     // ｷｬﾘﾌﾞﾚｰｼｮﾝ設定ﾃﾞｰﾀの保存
  }
}


// EEPROMからﾀｯﾁｸﾘｰﾝのｷｬﾘﾌﾞﾚｰｼｮﾝ設定を読込む ------------------------------------------------
void EEPROM_read_check() {

  byte int_LowByte, int_HighByte;
  // 0x10-0x11:TS_LEFT
  int_LowByte = EEPROM.read(0x10);
  int_HighByte = EEPROM.read(0x11);
  TS_LEFT = int_HighByte * 256 + int_LowByte;
  // 0x12-0x13:TS_RIGHT
  int_LowByte = EEPROM.read(0x12);
  int_HighByte = EEPROM.read(0x13);
  TS_RIGHT = int_HighByte * 256 + int_LowByte;
  // 0x14-0x15:TS_UP
  int_LowByte = EEPROM.read(0x14);
  int_HighByte = EEPROM.read(0x15);
  TS_UP = int_HighByte * 256 + int_LowByte;
  // 0x16-0x17:TS_DOWN
  int_LowByte = EEPROM.read(0x16);
  int_HighByte = EEPROM.read(0x17);
  TS_DOWN = int_HighByte * 256 + int_LowByte;
  if ((TS_LEFT > 0) && (TS_LEFT < 2000)) {
    line_asterisk();
    Serial.println(F("*** TS_xxxxxx ﾊ ﾀｯﾁ ｻﾞﾋｮｳ(x,y) ｦ ﾊﾝﾃｲ ｽﾙﾀﾒﾉ ｻｲｼｮｳﾁ ｻｲﾀﾞｲﾁ ﾃﾞｽ｡"));
    Serial.println(F("*** Arduino MEGA2560 ACｱﾀﾞﾌﾟﾀｰ ﾉ ｻｼｺﾐｸﾞﾁ ｶﾞ ｱﾙ ｶﾞﾒﾝ ﾉ ｶﾄﾞ ｦ (x,y)=(0,0) ﾄｼﾏｽ｡"));
    line_asterisk();
    Serial.print(F("*** TS_LEFT (x =   0) : "));Serial.println(TS_LEFT, DEC);
    Serial.print(F("*** TS_RIGHT(x = 320) : "));Serial.println(TS_RIGHT, DEC);
    Serial.print(F("*** TS_UP   (y =   0) : "));Serial.println(TS_UP, DEC);
    Serial.print(F("*** TS_DOWN (y = 480) : "));Serial.println(TS_DOWN, DEC);
    line_asterisk();
    Serial.println(F("*** Arduino MEGA2560 ﾉ EEPROM 0x10-0x17 ﾆ"));
    Serial.println(F("*** ﾀｯﾁﾊﾟﾈﾙ ﾎｾｲ ﾃﾞｰﾀ ｶﾞ ﾎｿﾞﾝ ｻﾚﾃｲﾏｽ｡"));
    line_asterisk();
    Serial.println(F("*** ﾀｯﾁﾊﾟﾈﾙ ﾎｾｲ ﾃﾞｰﾀ ｻｸｾｲ ｦ ｻｲﾄﾞ ｼﾏｽｶ ? ( 1: Yes , 0: No )"));
    line_asterisk();

    Judgment_of_Yes();                                        // Yes判定
  }
}


// ﾀｯﾁｸﾘｰﾝでｷｬﾘﾌﾞﾚｰｼｮﾝ設定をする ------------------------------------------------
void Calibration_Setting() {

  Calibration_Setting_start();
  Calibration_Setting_1();
  Calibration_Setting_2();
  Calibration_Setting_3();
  Calibration_Setting_0();
  Calibration_Setting_end();
}


// ﾀｯﾁｸﾘｰﾝでｷｬﾘﾌﾞﾚｰｼｮﾝ設定をする ------------------------------------------------
void Calibration_Setting_start() {

  // ﾀｯﾁｽｸﾘｰﾝの初期化
//DSP.reset();                                                // 画面初期化(MCUFRIEND)
//uint16_t ID = DSP.readID();                                 // 画面初期化(MCUFRIEND)
//DSP.begin(ID);                                              // 画面初期化(MCUFRIEND)
//DSP.setRotation(1);                                         // 1=90度右に回転：2=180度：3=270度
//Scr_Width = DSP.width();
//Scr_Height = DSP.height();
  DSP.fillScreen(BLACK);
  DSP.fillRoundRect(50, 50, 380, 40, 5, SKY_BLUE);
  strcpy_P(Edit_Str, pgm_read_word(&(Str_TS_Setting[0])));
  KNJ_print(Edit_Str, 70, 60, 3, BLACK);                      // "＊＊＊タッチパネル補正＊＊＊"
  line_asterisk();
  Serial.println(F("************ ﾀｯﾁﾊﾟﾈﾙ ﾎｾｲ(ILI9486 320X480) ***************"));
  Serial.println(F("ｼﾞｭﾝﾊﾞﾝ ﾆ 4 ｽﾐ ﾉ ｼｶｸ ﾉ ﾁｭｳｼﾝ ｦ ﾀｯﾁﾍﾟﾝ ﾃﾞ 1 ｶｲ ｵｼﾃ ｸﾀﾞｻｲ｡"));
  Serial.println(F("ﾀｯﾁﾊﾟﾈﾙ ﾉ ﾋﾀﾞﾘｳｴ ｶﾗ ﾊｼﾞﾒﾏｽ｡"));
  Serial.println(F("Arduino ﾄ PC ﾄｦ ｺｳｺﾞ ﾆ ｿｳｻ ｼﾃｸﾀﾞｻｲ｡"));
  Serial.println(F("(((((((((((((((((((( Enter ﾃﾞ ｼﾞｯｺｳ )))))))))))))))))))))"));
  line_asterisk();

  Judgment_of_Yes();                                          // Yes判定
  
  strcpy_P(Edit_Str, pgm_read_word(&(Str_TS_Setting[1])));
  KNJ_print(Edit_Str, 60, 95, 3, WHITE);                      // "順番に４すみの四角（□）の中心を"
  strcpy_P(Edit_Str, pgm_read_word(&(Str_TS_Setting[2])));
  KNJ_print(Edit_Str, 60, 125, 3, WHITE);                     // "タッチペンでおしてください。"
  DSP.fillRect(0, 0, 10, 10, WHITE);
  DSP.fillRoundRect(50, 190, 380, 50, 5, WHITE);
  strcpy_P(Edit_Str, pgm_read_word(&(Str_TS_Setting[3])));
  KNJ_print(Edit_Str, 70, 200, 4, BLACK);                     // "□□□ 左上 □□□"
}


// ﾀｯﾁｸﾘｰﾝでｷｬﾘﾌﾞﾚｰｼｮﾝ設定をする ------------------------------------------------
void Calibration_Setting_1() {

  while (true) {

    Get_Calibration(1);                                       // ﾀｯﾁｸﾘｰﾝX軸Y軸の値

    line_asterisk();
    Serial.println(F("ﾀｯﾁﾊﾟﾈﾙ ﾉ ﾐｷﾞｳｴ ﾆ ｲﾄﾞｳ ｼﾏｽｶ ? ( 1: Yes , 0: No )"));

    Judgment_of_Yes();                                        // Yes判定
    if (Yes_No == 1) {
      DSP.fillRect(0, 0, 10, 10, BROWN);
      DSP.fillRect(469, 0, 10, 10, WHITE);
      DSP.fillRoundRect(50, 190, 380, 50, 5, WHITE);
      strcpy_P(Edit_Str, pgm_read_word(&(Str_TS_Setting[4])));
      KNJ_print(Edit_Str, 70, 200, 4, BLACK);                 // "□□□ 右上 □□□"
      break;
    }
  }
}


// ﾀｯﾁｸﾘｰﾝでｷｬﾘﾌﾞﾚｰｼｮﾝ設定をする ------------------------------------------------
void Calibration_Setting_2() {

  while (true) {

    Get_Calibration(2);                                       // ﾀｯﾁｸﾘｰﾝX軸Y軸の値

    line_asterisk();
    Serial.println(F("ﾀｯﾁﾊﾟﾈﾙ ﾉ ﾐｷﾞｼﾀ ﾆ ｲﾄﾞｳ ｼﾏｽｶ ? ( 1: Yes , 0: No )"));

    Judgment_of_Yes();                                        // Yes判定
    if (Yes_No == 1) {
      DSP.fillRect(469, 0, 10, 10, BROWN);
      DSP.fillRect(469, 309, 10, 10, WHITE);
      DSP.fillRoundRect(50, 190, 380, 50, 5, WHITE);
      strcpy_P(Edit_Str, pgm_read_word(&(Str_TS_Setting[5])));
      KNJ_print(Edit_Str, 70, 200, 4, BLACK);                 // "□□□ 右下 □□□"
      break;
    }
  }
}


// ﾀｯﾁｸﾘｰﾝでｷｬﾘﾌﾞﾚｰｼｮﾝ設定をする ------------------------------------------------
void Calibration_Setting_3() {

  while (true) {

    Get_Calibration(3);                                       // ﾀｯﾁｸﾘｰﾝX軸Y軸の値

    line_asterisk();
    Serial.println(F("ﾀｯﾁﾊﾟﾈﾙ ﾉ ﾋﾀﾞﾘｼﾀ ﾆ ｲﾄﾞｳ ｼﾏｽｶ ? ( 1: Yes , 0: No )"));

    Judgment_of_Yes();                                        // Yes判定
    if (Yes_No == 1) {
      DSP.fillRect(469, 309, 10, 10, BROWN);
      DSP.fillRect(0, 309, 10, 10, WHITE);
      DSP.fillRoundRect(50, 190, 380, 50, 5, WHITE);
      strcpy_P(Edit_Str, pgm_read_word(&(Str_TS_Setting[6])));
      KNJ_print(Edit_Str, 70, 200, 4, BLACK);                 // "□□□ 左下 □□□"
      break;
    }
  }
}


// ﾀｯﾁｸﾘｰﾝでｷｬﾘﾌﾞﾚｰｼｮﾝ設定をする ------------------------------------------------
void Calibration_Setting_0() {

  while (true) {

    Get_Calibration(0);                                       // ﾀｯﾁｸﾘｰﾝX軸Y軸の値

    line_asterisk();
    Serial.println(F("ｼｭｳﾘｮｳ ｼﾏｽｶ ? ( 1: Yes , 0: No )"));

    Judgment_of_Yes();                                        // Yes判定
    if (Yes_No == 1) {
      DSP.fillRect(0, 309, 10, 10, BROWN);
      DSP.fillRoundRect(50, 190, 380, 50, 5, WHITE);
      strcpy_P(Edit_Str, pgm_read_word(&(Str_TS_Setting[7])));
      KNJ_print(Edit_Str, 60, 205, 3, BLACK);                 // "■■■■ 終りました。■■■■"
      break;
    }
  }
}


// ﾀｯﾁｸﾘｰﾝでｷｬﾘﾌﾞﾚｰｼｮﾝ設定をする ------------------------------------------------
void Calibration_Setting_end() {

  float fl_X, fl_Y;
  
  TS_LEFT  = ( P_X[0] + P_X[3] ) / 2;
  TS_RIGHT = ( P_X[1] + P_X[2] ) / 2;
  TS_UP    = ( P_Y[0] + P_Y[1] ) / 2;
  TS_DOWN  = ( P_Y[2] + P_Y[3] ) / 2;

  // 10ﾄﾞｯﾄの四角の中心を押しているのでX座標補正
  fl_X      = TS_LEFT - TS_RIGHT;
  fl_X      = fl_X * 5 / 320;
  TS_LEFT  += fl_X;
  fl_X      = TS_RIGHT - TS_LEFT;
  fl_X      = fl_X * 5 / 320;
  TS_RIGHT += fl_X;
  // 10ﾄﾞｯﾄの四角の中心を押しているのでY座標補正
  fl_Y      = TS_UP - TS_DOWN;
  fl_Y      = 5 * fl_Y / 480;
  TS_UP    += fl_Y;
  fl_Y      = TS_DOWN - TS_UP;
  fl_Y      = 5 * fl_Y / 480;
  TS_DOWN  += fl_Y;

  line_asterisk();
  Serial.println(F("*** TS_xxxxxx ﾊ ﾀｯﾁ ｻﾞﾋｮｳ(x,y) ｦ ﾊﾝﾃｲ ｽﾙﾀﾒﾉ ｻｲｼｮｳﾁ ｻｲﾀﾞｲﾁ ﾃﾞｽ｡"));
  Serial.println(F("*** Arduino MEGA2560 ACｱﾀﾞﾌﾟﾀｰ ﾉ ｻｼｺﾐｸﾞﾁ ｶﾞ ｱﾙ ｶﾞﾒﾝ ﾉ ｶﾄﾞ ｦ (x,y)=(0,0) ﾄｼﾏｽ｡"));
  line_asterisk();
  Serial.print(F("*** TS_LEFT (x =   0) : "));Serial.println(TS_LEFT, DEC);
  Serial.print(F("*** TS_RIGHT(x = 320) : "));Serial.println(TS_RIGHT, DEC);
  Serial.print(F("*** TS_UP   (y =   0) : "));Serial.println(TS_UP, DEC);
  Serial.print(F("*** TS_DOWN (y = 480) : "));Serial.println(TS_DOWN, DEC);
  line_asterisk();
  Serial.println(F("*** ﾀｯﾁﾊﾟﾈﾙ ﾎｾｲ ﾃﾞｰﾀ ｶﾞ ｻｸｾｲ ｻﾚﾏｼﾀ｡"));
  line_asterisk();

  DSP.fillRoundRect(50, 250, 380, 50, 5, YELLOW);
  strcpy_P(Edit_Str, pgm_read_word(&(Str_TS_Setting[8])));
  KNJ_print(Edit_Str, 60, 265, 3, BLACK);                     // "パソコンを見てください。"
}


// ﾀｯﾁｽｸﾘｰﾝのﾃｽﾄ ------------------------------------------------
void Touch_Screen_test() {

  int i;
  line_asterisk();
  Serial.println(F("ﾀｯﾁﾊﾟﾈﾙ ﾃﾞ ﾃｽﾄ ｦ ｼﾏｽｶ ? ( 1: Yes , 0: No )"));
  line_asterisk();

  Judgment_of_Yes();                                          // Yes判定
  if (Yes_No == 1) {
    line_asterisk();
    Serial.println(F("ﾀｯﾁﾊﾟﾈﾙ ﾆ ﾀｯﾁﾍﾟﾝ ﾃﾞ ﾅﾆｶ ｶｲﾃ ｶｸﾆﾝ ｼﾃｸﾀﾞｻｲ｡"));
    line_asterisk();

    // 試しにﾀｯﾁﾊﾟﾈﾙにﾀｯﾁﾍﾟﾝで線を引く
    touch_pen_free_hand();
  }
}


// ｷｬﾘﾌﾞﾚｰｼｮﾝ設定ﾃﾞｰﾀの保存 ------------------------------------------------
void Saving_Calibration_data() {

  int i;
  line_asterisk();
//Serial.println(F("EEPROM 0x10-0x17 ﾆ ﾀｯﾁﾊﾟﾈﾙ ﾎｾｲ ﾃﾞｰﾀ ｦ ﾎｿﾞﾝ ｼﾏｽｶ ?"));
  Serial.println(F("ﾀｯﾁﾊﾟﾈﾙ ﾎｾｲ ﾃﾞｰﾀ ｦ ﾎｿﾞﾝ ｼﾏｽｶ ? ( 1: Yes , 0: No )"));
  line_asterisk();

  Judgment_of_Yes();                                          // Yes判定
  if (Yes_No == 1) {

    // EEPROMにﾀｯﾁｸﾘｰﾝのｷｬﾘﾌﾞﾚｰｼｮﾝ設定を書込む
    Calibration_EEPROM_write();

    // EEPROMからﾀｯﾁｸﾘｰﾝのｷｬﾘﾌﾞﾚｰｼｮﾝ設定を読込む
    Calibration_EEPROM_read();
    
    line_asterisk();
    Serial.println(F("*** ﾎｿﾞﾝ ｻﾚﾀ EEPROM 0x10-0x17 ﾉ ﾅｲﾖｳ"));
    line_asterisk();
    Serial.print(F("*** TS_LEFT (x =   0) : "));Serial.println(TS_LEFT, DEC);
    Serial.print(F("*** TS_RIGHT(x = 320) : "));Serial.println(TS_RIGHT, DEC);
    Serial.print(F("*** TS_UP   (y =   0) : "));Serial.println(TS_UP, DEC);
    Serial.print(F("*** TS_DOWN (y = 480) : "));Serial.println(TS_DOWN, DEC);
    line_asterisk();
    Serial.println(F("*** TS_xxxxxx ﾊ ﾀｯﾁ ｻﾞﾋｮｳ(x,y) ｦ ﾊﾝﾃｲ ｽﾙﾀﾒﾉ ｻｲｼｮｳﾁ ｻｲﾀﾞｲﾁ ﾃﾞｽ｡"));
    Serial.println(F("*** Arduino MEGA2560 ACｱﾀﾞﾌﾟﾀｰ ﾉ ｻｼｺﾐｸﾞﾁ ｶﾞ ｱﾙ ｶﾞﾒﾝ ﾉ ｶﾄﾞ ｦ (x,y)=(0,0) ﾄｼﾏｽ｡"));
    line_asterisk();
  } else {
    line_asterisk();
    Serial.println(F("### ｷｬﾝｾﾙ ｻﾚﾏｼﾀ｡"));
    line_asterisk();
 }
  line_asterisk();
  Serial.println(F("*** ｼｮﾘ ﾊ ｼｭｳﾘｮｳ ｼﾏｼﾀ｡"));
  line_asterisk();
}


// ﾀｯﾁｸﾘｰﾝX軸Y軸の値 ------------------------------------------------
void Get_Calibration(int i) {
  
  while (true) {
    TSPoint p = TS.getPoint();
    DDRF |= YPXM_PORT;
    if (p.z > MINPRESSURE && p.z < MAXPRESSURE) {
      P_X[i] = p.x;
      P_Y[i] = p.y;
Serial.print(" p.x = "); Serial.print(p.x, DEC);   // debug
Serial.print("\tp.y = "); Serial.print(p.y, DEC);  // debug
Serial.print("\tp.z = "); Serial.println(p.z, DEC);// debug
      return;
    }
//  delay (50);
  }
}


// EEPROMのｱﾄﾞﾚｽ(0x10-0x17)を使ってﾀｯﾁﾊﾟﾈﾙのｷｬﾘﾌﾞﾚｰｼｮﾝ設定を保存する
// EEPROMにﾀｯﾁｸﾘｰﾝのｷｬﾘﾌﾞﾚｰｼｮﾝ設定を書込む ------------------------------------------------
void Calibration_EEPROM_write() {

  // 0x10-0x11:TS_LEFT
  EEPROM.write(0x10, lowByte(TS_LEFT));
  EEPROM.write(0x11, highByte(TS_LEFT));
  // 0x12-0x13:TS_RIGHT
  EEPROM.write(0x12, lowByte(TS_RIGHT));
  EEPROM.write(0x13, highByte(TS_RIGHT));
  // 0x14-0x15:TS_UP
  EEPROM.write(0x14, lowByte(TS_UP));
  EEPROM.write(0x15, highByte(TS_UP));
  // 0x16-0x17:TS_DOWN
  EEPROM.write(0x16, lowByte(TS_DOWN));
  EEPROM.write(0x17, highByte(TS_DOWN));
}


//
