// 入力画面の座標(0,0,319,479)[縦長]
#define SELECT_SQ     0,0,319,30         //  選択ｴﾘｱ
#define PAINT_SQ      0,31,319,448
//  絵画ｴﾘｱ
#define COLOR_ST      30,5,3             // 【色】ﾎﾞﾀﾝ "色",
#define PSIZE_ST      99,5,3             // 【太さ】ﾎﾞﾀﾝ "太さ",
#define ERASE_ST      178,5,3            // 【消す】ﾎﾞﾀﾝ "消す",
#define END_ST        257,5,3            // 【終り】ﾎﾞﾀﾝ "終り",
#define COLOR_SQ      5,0,73,30          // 【色】ﾎﾞﾀﾝ
#define PSIZE_SQ      84,0,73,30         // 【太さ】ﾎﾞﾀﾝ
#define ERASE_SQ      163,0,73,30        // 【消す】ﾎﾞﾀﾝ
#define END_SQ        242,0,73,30        // 【終り】ﾎﾞﾀﾝ
#define BLACK_ST      15,5,3             // 【黒】ﾎﾞﾀﾝ "黒",
#define GRAY_ST       55,5,3             // 【灰】ﾎﾞﾀﾝ "灰",
#define WHITE_ST      95,5,3             // 【白】ﾎﾞﾀﾝ "白",
#define RED_ST        135,5,3            // 【赤】ﾎﾞﾀﾝ "赤",
#define GREEN_ST      175,5,3            // 【緑】ﾎﾞﾀﾝ "緑",
#define BLUE_ST       215,5,3            // 【青】ﾎﾞﾀﾝ "青",
#define YELLOW_ST     255,5,3            // 【黄】ﾎﾞﾀﾝ "黄",
#define PINK_ST       295,5,3            // 【桜】ﾎﾞﾀﾝ "桜",
#define BLACK_SQ      0,0,39,30          // 【黒】ﾎﾞﾀﾝ
#define GRAY_SQ       40,0,39,30         // 【灰】ﾎﾞﾀﾝ
#define WHITE_SQ      80,0,39,30         // 【白】ﾎﾞﾀﾝ
#define RED_SQ        120,0,39,30        // 【赤】ﾎﾞﾀﾝ
#define GREEN_SQ      160,0,39,30        // 【緑】ﾎﾞﾀﾝ
#define BLUE_SQ       200,0,39,30        // 【青】ﾎﾞﾀﾝ
#define YELLOW_SQ     240,0,39,30        // 【黄】ﾎﾞﾀﾝ
#define PINK_SQ       280,0,39,30        // 【桜】ﾎﾞﾀﾝ
#define POINT1_ST     15,5,3             // 【極細】ﾎﾞﾀﾝ "極細",
#define POINT2_ST     80,5,3             // 【細字】ﾎﾞﾀﾝ "細字",
#define POINT3_ST     145,5,3            // 【中字】ﾎﾞﾀﾝ "中字",
#define POINT4_ST     210,5,3            // 【太字】ﾎﾞﾀﾝ "太字",
#define POINT5_ST     275,5,3            // 【極太】ﾎﾞﾀﾝ "極太",
#define POINT1_SQ     0,0,60,30          // 【極細】ﾎﾞﾀﾝ
#define POINT2_SQ     65,0,60,30         // 【細字】ﾎﾞﾀﾝ
#define POINT3_SQ     130,0,60,30        // 【中字】ﾎﾞﾀﾝ
#define POINT4_SQ     195,0,60,30        // 【太字】ﾎﾞﾀﾝ
#define POINT5_SQ     260,0,60,30        // 【極太】ﾎﾞﾀﾝ

////////////////////////////////////////////////////////////////////////////////////////////
/// ﾌﾗｯｼｭﾒﾓﾘ･ﾃﾞｰﾀ部 //////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
// 固定文字列 ---------------------------------------------
const char Data_Fixed_str2[17][32] PROGMEM = {
"色",        // [0]
"太さ",      // [1]
"消す",      // [2]
"終り",      // [3]
"黒",        // [4]
"灰",        // [5]
"白",        // [6]
"赤",        // [7]
"緑",        // [8]
"青",        // [9]
"黄",        // [10]
"桜",        // [11]
"極細",      // [12]
"細字",      // [13]
"中字",      // [14]
"太字",      // [15]
"極太"       // [16]
};
const char * const Str_Fixed_str2[] PROGMEM = {
Data_Fixed_str2[0],
Data_Fixed_str2[1],
Data_Fixed_str2[2],
Data_Fixed_str2[3],
Data_Fixed_str2[4],
Data_Fixed_str2[5],
Data_Fixed_str2[6],
Data_Fixed_str2[7],
Data_Fixed_str2[8],
Data_Fixed_str2[9],
Data_Fixed_str2[10],
Data_Fixed_str2[11],
Data_Fixed_str2[12],
Data_Fixed_str2[13],
Data_Fixed_str2[14],
Data_Fixed_str2[15],
Data_Fixed_str2[16]
};


////////////////////////////////////////////////////////////////////////////////////////////
/// 処理部 //////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
int16_t color_code;
int16_t crt_color;                    // current_color
boolean flg_color; 
int16_t crt_pen;                      // current_pen
boolean flg_pen;


// ﾀｯﾁﾍﾟﾝ ------------------------------------------------
void touch_pen_free_hand() {
//Serial.println(F("touch_pen_free_hand()"));                      // debug
  DSP.reset();                                                // 画面初期化(MCUFRIEND)
  uint16_t ID = DSP.readID();                                 // 画面初期化(MCUFRIEND)
  DSP.begin(ID);                                              // 画面初期化(MCUFRIEND)
  Scr_Angle = 2;                                              // 1=90度右に回転：2=180度：3=270度
  DSP.setRotation(Scr_Angle);                                 // 1=90度右に回転：2=180度：3=270度
  DSP.fillScreen(WHITE);

  show_main_menu();                                           // 主ﾒﾆｭｰ

  DSP.fillRect(PAINT_SQ, WHITE);
  crt_color = BLACK;
  crt_pen = 3;
  flg_color = false;
  flg_pen = false;

  while (true) {

    Get_touch();                                              // ﾀｯﾁの取得
    uint16_t MENU_Area = Th_Y - crt_pen;
    if (MENU_Area > 30) {
      if ((flg_color  == true) || (flg_pen  == true)) {
        show_main_menu();                                     // 主ﾒﾆｭｰ
        flg_color = false;
        flg_pen = false;
      }
      DSP.fillCircle(Th_X, Th_Y, crt_pen, crt_color);
      continue;                                               // whileに戻る
    }
    if (Th_Y <= 30) {
      if (flg_color  == true) {
        select_color();                                       // 色選択
      } else if (flg_pen  == true) {
        select_pen_size();                                    // 太さ選択
      }
      if ((flg_color == false) && (flg_pen == false)) {
        Touch_check(COLOR_SQ);                                // 【色】ﾎﾞﾀﾝ
        if (Touch_flg  == true) {
          show_color_select_menu();                           // 色選択ﾒﾆｭｰ
          flg_color = true;
        }
        Touch_check(PSIZE_SQ);                                // 【太さ】ﾎﾞﾀﾝ
        if (Touch_flg  == true) {
          show_pen_size_select_menu();                        // 太さ選択ﾒﾆｭｰ
          flg_pen = true;
        }
        Touch_check(ERASE_SQ);                                // 【消す】ﾎﾞﾀﾝ
        if (Touch_flg  == true) {
          DSP.fillRect(PAINT_SQ, WHITE);
        }
        Touch_check(END_SQ);                                  // 【終り】ﾎﾞﾀﾝ
        if (Touch_flg  == true) {
          DSP.fillScreen(WHITE);
          return;
        }
      }
    }
  }
}


// 色選択 ------------------------------------------------
void select_color() {
//Serial.println(F("select_color()"));                        // debug

  switch (color_code) {                                       // 色選択解除
  case 0:                                                     // 【黒】ﾎﾞﾀﾝ
    strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[4])));
    KNJ_print(Short_Str, BLACK_ST, WHITE);
    break;
  case 1:                                                     // 【灰】ﾎﾞﾀﾝ
    strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[5])));
    KNJ_print(Short_Str, GRAY_ST, WHITE);
    break;
  case 2:                                                     // 【白】ﾎﾞﾀﾝ
    strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[6])));
    KNJ_print(Short_Str, WHITE_ST, BLACK);
    break;
  case 3:                                                     // 【赤】ﾎﾞﾀﾝ
    strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[7])));
    KNJ_print(Short_Str, RED_ST, WHITE);
    break;
  case 4:                                                     // 【緑】ﾎﾞﾀﾝ
    strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[8])));
    KNJ_print(Short_Str, GREEN_ST, WHITE);
    break;
  case 5:                                                     // 【青】ﾎﾞﾀﾝ
    strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[9])));
    KNJ_print(Short_Str, BLUE_ST, WHITE);
    break;
  case 6:                                                     // 【黄】ﾎﾞﾀﾝ
    strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[10])));
    KNJ_print(Short_Str, YELLOW_ST, BLACK);
    break;
  case 7:                                                     // 【桜】ﾎﾞﾀﾝ
    strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[11])));
    KNJ_print(Short_Str, PINK_ST, WHITE);
  }
  if (Th_X < 160) {
    select_color_before();                                    // 色選択(前)
  } else {
    select_color_after();                                     // 色選択(後)
  }
}


// 色選択(前) ------------------------------------------------
void select_color_before() {
//Serial.println(F("select_color_before()"));                 // debug

  Touch_check(BLACK_SQ);                                      // 【黒】ﾎﾞﾀﾝ
  if (Touch_flg == true) {
    strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[4])));
    KNJ_print(Short_Str, BLACK_ST, RED);
    crt_color = BLACK;
    color_code = 0;
    return;
  }
  Touch_check(GRAY_SQ);                                       // 【灰】ﾎﾞﾀﾝ
  if (Touch_flg == true) {
    strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[5])));
    KNJ_print(Short_Str, GRAY_ST, RED);
    crt_color = GRAY;
    color_code = 1;
    return;
  }
  Touch_check(WHITE_SQ);                                      // 【白】ﾎﾞﾀﾝ
  if (Touch_flg == true) {
    strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[6])));
    KNJ_print(Short_Str, WHITE_ST, RED);
    crt_color = WHITE;
    color_code = 2;
    return;
  }
  Touch_check(RED_SQ);                                        // 【赤】ﾎﾞﾀﾝ
  if (Touch_flg == true) {
    strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[7])));
    KNJ_print(Short_Str, RED_ST, BLACK);
    crt_color = RED;
    color_code = 3;
  }
}


// 色選択(後) ------------------------------------------------
void select_color_after() {
//Serial.println(F("select_color_after()"));                  // debug

  Touch_check(GREEN_SQ);                                      // 【緑】ﾎﾞﾀﾝ
  if (Touch_flg == true) {
    strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[8])));
    KNJ_print(Short_Str, GREEN_ST, BLACK);
    crt_color = GREEN;
    color_code = 4;
    return;
  }
  Touch_check(BLUE_SQ);                                       // 【青】ﾎﾞﾀﾝ
  if (Touch_flg == true) {
    strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[9])));
    KNJ_print(Short_Str, BLUE_ST, BLACK);
    crt_color = BLUE;
    color_code = 5;
    return;
  }
  Touch_check(YELLOW_SQ);                                     // 【黄】ﾎﾞﾀﾝ
  if (Touch_flg == true) {
    strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[10])));
    KNJ_print(Short_Str, YELLOW_ST, RED);
    crt_color = YELLOW;
    color_code = 6;
    return;
  }
  Touch_check(PINK_SQ);                                       // 【桜】ﾎﾞﾀﾝ
  if (Touch_flg == true) {
    strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[11])));
    KNJ_print(Short_Str, PINK_ST, BLACK);
    crt_color = PINK;
    color_code = 7;
  }
}


// 太さ選択 ------------------------------------------------
void select_pen_size() {
//Serial.println(F("select_pen_size()"));                     // debug

  switch (crt_pen) {                                          // 太さ選択解除
  case 1:                                                     // 【極細】ﾎﾞﾀﾝ
    strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[12])));
    KNJ_print(Short_Str, POINT1_ST, GREEN);
    break;
  case 2:                                                     // 【細字】ﾎﾞﾀﾝ
    strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[13])));
    KNJ_print(Short_Str, POINT2_ST, GREEN);
    break;
  case 3:                                                     // 【中字】ﾎﾞﾀﾝ
    strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[14])));
    KNJ_print(Short_Str, POINT3_ST, GREEN);
    break;
  case 4:                                                     // 【太字】ﾎﾞﾀﾝ
    strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[15])));
    KNJ_print(Short_Str, POINT4_ST, GREEN);
    break;
  case 5:                                                     // 【極太】ﾎﾞﾀﾝ
    strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[16])));
    KNJ_print(Short_Str, POINT5_ST, GREEN);
  }
  Touch_check(POINT1_SQ);                                     // 【極細】ﾎﾞﾀﾝ
  if (Touch_flg == true) {
    strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[12])));
    KNJ_print(Short_Str, POINT1_ST, RED);
    crt_pen = 1;
    return;
  }
  Touch_check(POINT2_SQ);                                     // 【細字】ﾎﾞﾀﾝ
  if (Touch_flg == true) {
    strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[13])));
    KNJ_print(Short_Str, POINT2_ST, RED);
    crt_pen = 2;
    return;
  }
  Touch_check(POINT3_SQ);                                     // 【中字】ﾎﾞﾀﾝ
  if (Touch_flg == true) {
    strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[14])));
    KNJ_print(Short_Str, POINT3_ST, RED);
    crt_pen = 3;
    return;
  }
  Touch_check(POINT4_SQ);                                     // 【太字】ﾎﾞﾀﾝ
  if (Touch_flg == true) {
    strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[15])));
    KNJ_print(Short_Str, POINT4_ST, RED);
    crt_pen = 4;
    return;
  }
  Touch_check(POINT5_SQ);                                     // 【極太】ﾎﾞﾀﾝ
  if (Touch_flg == true) {
    strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[16])));
    KNJ_print(Short_Str, POINT5_ST, RED);
    crt_pen = 5;
  }
}


// 色選択ﾒﾆｭｰ ------------------------------------------------
void show_color_select_menu() {
//Serial.println(F("show_color_select_menu()"));                 // debug
  DSP.fillRect(SELECT_SQ, WHITE);                                // 選択ｴﾘｱ
  // 【黒】ﾎﾞﾀﾝ
  DSP.fillRoundRect(BLACK_SQ, 3, BLACK);
  strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[4])));
  KNJ_print(Short_Str, BLACK_ST, WHITE);
  // 【灰】ﾎﾞﾀﾝ
  DSP.fillRoundRect(GRAY_SQ, 3, GRAY);
  strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[5])));
  KNJ_print(Short_Str, GRAY_ST, WHITE);
  // 【白】ﾎﾞﾀﾝ
  DSP.fillRoundRect(WHITE_SQ, 3, WHITE);
  strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[6])));
  KNJ_print(Short_Str, WHITE_ST, BLACK);
  // 【赤】ﾎﾞﾀﾝ
  DSP.fillRoundRect(RED_SQ, 3, RED);
  strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[7])));
  KNJ_print(Short_Str, RED_ST, WHITE);
  // 【緑】ﾎﾞﾀﾝ
  DSP.fillRoundRect(GREEN_SQ, 3, GREEN);
  strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[8])));
  KNJ_print(Short_Str, GREEN_ST, WHITE);
  // 【青】ﾎﾞﾀﾝ
  DSP.fillRoundRect(BLUE_SQ, 3, BLUE);
  strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[9])));
  KNJ_print(Short_Str, BLUE_ST, WHITE);
  // 【黄】ﾎﾞﾀﾝ
  DSP.fillRoundRect(YELLOW_SQ, 3, YELLOW);
  strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[10])));
  KNJ_print(Short_Str, YELLOW_ST, BLACK);
  // 【桜】ﾎﾞﾀﾝ
  DSP.fillRoundRect(PINK_SQ, 3, PINK);
  strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[11])));
  KNJ_print(Short_Str, PINK_ST, WHITE);

  color_code = 9;
}


// 太さ選択ﾒﾆｭｰ ------------------------------------------------
void show_pen_size_select_menu() {
//Serial.println(F("show_pen_size_select_menu()"));              // debug
  DSP.fillRect(SELECT_SQ, WHITE);                                // 選択ｴﾘｱ
  // 【極細】ﾎﾞﾀﾝ
  DSP.fillRoundRect(POINT1_SQ, 3, GRAY);
  strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[12])));
  KNJ_print(Short_Str, POINT1_ST, GREEN);
  // 【細字】ﾎﾞﾀﾝ
  DSP.fillRoundRect(POINT2_SQ, 3, GRAY);
  strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[13])));
  KNJ_print(Short_Str, POINT2_ST, GREEN);
  // 【中字】ﾎﾞﾀﾝ
  DSP.fillRoundRect(POINT3_SQ, 3, GRAY);
  strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[14])));
  KNJ_print(Short_Str, POINT3_ST, GREEN);
  // 【太字】ﾎﾞﾀﾝ
  DSP.fillRoundRect(POINT4_SQ, 3, GRAY);
  strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[15])));
  KNJ_print(Short_Str, POINT4_ST, GREEN);
  // 【極太】ﾎﾞﾀﾝ
  DSP.fillRoundRect(POINT5_SQ, 3, GRAY);
  strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[16])));
  KNJ_print(Short_Str, POINT5_ST, GREEN);

  crt_pen = 9;
}


// 主ﾒﾆｭｰ ------------------------------------------------
void show_main_menu() {
//Serial.println(F("show_main_menu()"));                         // debug
  DSP.fillRect(SELECT_SQ, WHITE);                                //  選択ｴﾘｱ
  // 【色】ﾎﾞﾀﾝ
  DSP.fillRoundRect(COLOR_SQ,3, RED);
  strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[0])));
  KNJ_print(Short_Str, COLOR_ST, BLACK);
  // 【太さ】ﾎﾞﾀﾝ
  DSP.fillRoundRect(PSIZE_SQ,3, GREEN);
  strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[1])));
  KNJ_print(Short_Str, PSIZE_ST, BLACK);
  // 【消す】ﾎﾞﾀﾝ
  DSP.fillRoundRect(ERASE_SQ,3, BLUE);
  strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[2])));
  KNJ_print(Short_Str, ERASE_ST, BLACK);
  // 【終り】ﾎﾞﾀﾝ
  DSP.fillRoundRect(END_SQ,3, MAGENTA);
  strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_str2[3])));
  KNJ_print(Short_Str, END_ST, BLACK);
 }


//
