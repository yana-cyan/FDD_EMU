// =========================================================================================
// PC-6001,PC-8001,PC-8801,PC-9801系の外付け[1D][2D]のFDDｴﾐｭﾚｰﾀです。(詳細はﾀﾌﾞ"x"で)
// =========================================================================================
// -----------------------------------------------------------------------------------------
// 組み込むﾗｲﾌﾞﾗﾘ
// -----------------------------------------------------------------------------------------
// [ｽｹｯﾁ]-[ﾗｲﾌﾞﾗﾘをｲﾝｸﾙｰﾄﾞ]
#include <SD.h>                  // [標準ﾗｲﾌﾞﾗﾘ]SDｶｰﾄﾞの読書き
// -----------------------------------------------------------------------------------------
// [ｽｹｯﾁ]-[ﾗｲﾌﾞﾗﾘをｲﾝｸﾙｰﾄﾞ]
#include <EEPROM.h>              // [標準ﾗｲﾌﾞﾗﾘ]EEPROMの読書き
// -----------------------------------------------------------------------------------------
// [ﾂｰﾙ]-[ﾗｲﾌﾞﾗﾘを管理] から組込む。(ｺﾝﾊﾟｲﾙとArduino MEGA2560書込みの為)
#include <MsTimer2.h>            // ﾀｲﾏｰ割り込み(Ver,1.1.0)
// -----------------------------------------------------------------------------------------
// [ﾂｰﾙ]-[ﾗｲﾌﾞﾗﾘを管理] から組込む。(ｺﾝﾊﾟｲﾙとArduino MEGA2560書込みの為)
// Adafruit_BusIO, Adafruit_GFX_Library も組込む。
#include <MCUFRIEND_kbv.h>       // Mcufriend style display shield(Ver,2.9.9)
MCUFRIEND_kbv DSP;               // hard-wired for UNO shields anyway.
// -----------------------------------------------------------------------------------------
// [ﾂｰﾙ]-[ﾗｲﾌﾞﾗﾘを管理] から組込む。(ｺﾝﾊﾟｲﾙとArduino MEGA2560書込みの為)
#include <TouchScreen.h>         // Adafruit_TouchScreen(Ver,1.1.1)
// -----------------------------------------------------------------------------------------
// https://github.com/Tamakichi/Arduino-misakiUTF16
// ﾀﾞｳﾝﾛｰﾄﾞし、解凍したら [ドキュメント]\Ardoino\libraries に入れる。(ｺﾝﾊﾟｲﾙとArduino MEGA2560書込みの為)
#include <misakiUTF16.h>         // 美咲ﾌｫﾝﾄﾄﾞﾗｲﾊﾞ by たま吉さん
// -----------------------------------------------------------------------------------------


////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
// ﾀｯﾁｽｸﾘｰﾝ /////////////////////////////////////////////////////////////////////////////////
//TouchScreen TS = TouchScreen(XP, YP, XM, YM, 300);
// =========================================================================================
// (A)
// 基板に書いてある[3.5" TFT LCD Shield]の書式がゴシック体なら、こっち？
// [KUMAN SCSA-1][LCDwiki MAR3501]等はこっちを使う
// ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
//TouchScreen TS = TouchScreen(8, A3, A2, 9, 300);
//#define YPXM_PORT B00001100           // A2, A3
// =========================================================================================
// (B)
// 基板に書いてある[3.5" TFT LCD Shield]の書式がゴシック体じゃないなら、こっち？
// ﾗﾍﾞﾙに(Touch:Yes)と(SKU:MAR3502)が書いてあるものはこっちを使う
// ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
  TouchScreen TS = TouchScreen(6, A1, A2, 7, 300);
  #define YPXM_PORT B00000110           // A1, A2
// =========================================================================================
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////


// -----------------------------------------------------------------------------------------
// 定数定義
// -----------------------------------------------------------------------------------------
#define LF 0x0A     // Ascii(改行)(Line Feed)
#define CR 0x0D     // Ascii(復帰)(Carriage Return)
#define SD_CS 53    // D53 pin(SD card Chip Select)

#define PC_DAV  B00010000 // PL4/PC0(Data Valia)    : ﾃﾞｰﾀが有効
#define PC_RFD  B00100000 // PL5/PC1(Ready For Data): ﾃﾞｰﾀの準備完了
#define PC_DAC  B01000000 // PL6/PC2(Data Accepted) : ﾃﾞｰﾀの受け取り終了
#define PC_ATN  B10000000 // PL7/PC3(Attention)     : 1=次はｺﾏﾝﾄﾞ、0=次はﾃﾞｰﾀ
// HIGH
#define FD_DAV  B00000001 // PL0/PC4(Data Valia)    : ﾃﾞｰﾀが有効
#define FD_RFD  B00000010 // PL1/PC5(Ready For Data): ﾃﾞｰﾀの準備完了
#define FD_DAC  B00000100 // PL2/PC6(Data Accepted) : ﾃﾞｰﾀの受け取り終了
// LOW
#define FD_DAVL B11111110 // PL0/PC4(Data Valia)    : ﾃﾞｰﾀが有効
#define FD_RFDL B11111101 // PL1/PC5(Ready For Data): ﾃﾞｰﾀの準備完了
#define FD_DACL B11111011 // PL2/PC6(Data Accepted) : ﾃﾞｰﾀの受け取り終了

#define LED_PIN    13
#define BUZZER_PIN 38

// 画面
#define DTS_LEFT  920                        // X座標=0のﾀｯﾁｽｸﾘｰﾝの値
#define DTS_RIGHT 160                        // X座標=320のﾀｯﾁｽｸﾘｰﾝの値
#define DTS_UP    960                        // Y座標=0のﾀｯﾁｽｸﾘｰﾝの値
#define DTS_DOWN  160                        // Y座標=480のﾀｯﾁｽｸﾘｰﾝの値
#define MINPRESSURE 10
#define MAXPRESSURE 1000

// B1111100000000000 -> 赤
// B0000011111100000 -> 緑
// B0000000000011111 -> 青
#define BLACK           0x0000
#define BLUE            0x001F
#define RED             0xF800
#define DARK_RED        0xA000
#define GREEN           0x07E0
#define DARK_GREEN      0x47E8
#define YELLOW_GREEN    0x83E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0
#define WHITE           0xFFFF
#define GRAY            0xC618
#define DARK_GRAY       0x4108
#define SKY_BLUE        0x03FF
#define PURPLE          0xF810
#define ORENGE          0xFA00
#define PINK            0xFA1F
#define BROWN           0x7940
#define DARK_BROWN      0x58E0
#define IVORY           0xFB94
#define OLIVE           0xE780
#define JP_SKIN         0xFF90
#define JP_SKIN_SHADOW  0xE70E

// 入力画面の座標(0,0,319,479)[縦長]
// 四角形:(x1, y1, x2, y2)
#define TITLE_SQ      0,0,319,29                // 画面ﾀｲﾄﾙ
#define BEFORE_SQ     5,30,240,34               // 前の明細
#define DETAIL_SQ     5,66,240,128              // 選択された明細
#define AFTOR_SQ      5,196,240,34              // 後の明細
#define SL_UP_SQ      246,66,64,63              // 選択ﾎﾞﾀﾝ(上)
#define SL_DWN_SQ     246,131,64,63             // 選択ﾎﾞﾀﾝ(下)
#define EMU_SQ        10,240,145,45             //【ｴﾐｭﾚｰﾀ】ﾎﾞﾀﾝ
#define CHANGE_SQ     165,240,145,45            //【FD差替え】ﾎﾞﾀﾝ
#define PROTECT_SQ    10,295,145,45             //【ﾗｲﾄﾌﾟﾛﾃｸﾄ】ﾎﾞﾀﾝ
#define OUTPUT_SQ     165,295,145,45            //【ｲﾒｰｼﾞ出力】ﾎﾞﾀﾝ
#define CANCEL_SQ     10,350,93,45              //【中止】ﾎﾞﾀﾝ
#define GO_SQ         216,350,93,45             //【実行】ﾎﾞﾀﾝ
#define CONFIRM_SQ    10,350,300,45             // 確定ｴﾘｱ
#define MSG_SQ        0,400,319,79              // ﾒｯｾｰｼﾞ欄
#define MSG_4_SQ      0,460,319,19              // ﾒｯｾｰｼﾞ4行目
#define LIST_SQ       0,30,319,310              // ﾘｽﾄ欄
#define LIST2_SQ      0,30,319,330              // ﾘｽﾄ欄2

// 文字列:(x, y, csize)
#define TITLE_ST      10,10,2                   // 画面ﾀｲﾄﾙ "FDD Emulator [NEC 1D,2D]",
#define BEFORE_ST     10,40,3                   // 前の明細
#define DETAIL_ST     10,76,3                   // 選択された明細
#define ATT_1_ST      10,110,2                  // 選択された明細の属性1(attribute)
#define ATT_2_ST      10,135,2                  // 選択された明細の属性2(attribute)
#define ATT_3_ST      10,160,2                  // 選択された明細の属性3(attribute)
#define AFTOR_ST      10,206,3                  // 後の明細
#define SL_UP_ST      265,85,4                  // 選択ﾎﾞﾀﾝ(▲)
#define SL_DWN_ST     265,150,4                 // 選択ﾎﾞﾀﾝ(▼)
#define EMU_ST        36,257,2                  //【ｴﾐｭﾚｰﾀ】ﾎﾞﾀﾝ "エミュレータ",
#define CHANGE_ST     188,257,2                 //【FD差替え】ﾎﾞﾀﾝ "ＦＤ差しかえ",
#define PROTECT_ST    20,312,2                  //【ﾗｲﾄﾌﾟﾛﾃｸﾄ】ﾎﾞﾀﾝ "ライトプロテクト",
#define OUTPUT_ST     188,312,2                 //【ｲﾒｰｼﾞ出力】ﾎﾞﾀﾝ "イメージ出力",
#define CANCEL_ST     35,362,3                  //【中止】ﾎﾞﾀﾝ "中止",
#define GO_ST         235,362,3                 //【実行】ﾎﾞﾀﾝ "実行",
#define MSG_1_ST      5,402,2                   // ﾒｯｾｰｼﾞ1行目
#define MSG_2_ST      5,422,2                   // ﾒｯｾｰｼﾞ2行目
#define MSG_3_ST      5,442,2                   // ﾒｯｾｰｼﾞ3行目
#define MSG_4_ST      5,462,2                   // ﾒｯｾｰｼﾞ4行目

// FDDｲﾒｰｼﾞ画面の座標(0,0,479,319)[横長]
// 四角形(Square):(x1, y1, x2, y2)
// 円形(Circle):(x, y, r)
#define PC80S31_SQ    5,5,230,304               // PC80S31の輪郭
#define DRIVE1_SQ     8,8,74,298                // FDD1の輪郭
#define D1_LED_SQ     25,250,10,25              // FDD1のLED
#define D1_INS_SQ     37,45,14,250              // FDD1の挿入口(Insert)
#define D1_SLIT_SQ    40,55,8,230               // FDD1の細い隙間
#define D1_OTLT_SQ    18,130,52,70              // FDD1の取出し口(Outlet)
#define D1_AXIS_CR    25,130,10                 // FDD1の軸
#define D1_LVR_H_SQ   32,125,43,10              // FDD1のﾚﾊﾞｰ(水平)
#define D1_LVR_V_SQ   20,81,10,43               // FDD1のﾚﾊﾞｰ(垂直)
#define D1_ERS_H_SQ   32,125,1,10               // FDD1の軸とﾚﾊﾞｰの間の線を消す(水平)(Erase)
#define D1_ERS_V_SQ   20,123,10,1               // FDD1の軸とﾚﾊﾞｰの間の線を消す(垂直)(Erase)
#define D1_LABEL_ST   15,25,1                   // FDD1のﾗﾍﾞﾙ "ドライブ１",
#define DRIVE2_SQ     88,8,74,298               // FDD2の輪郭
#define D2_LED_SQ     105,250,10,25             // FDD2のLED
#define D2_INS_SQ     117,45,14,250             // FDD2の挿入口(Insert)
#define D2_SLIT_SQ    120,55,8,230              // FDD2の細い隙間
#define D2_OTLT_SQ    98,130,52,70              // FDD2の取出し口(Outlet)
#define D2_AXIS_CR    105,130,10                // FDD2の軸
#define D2_LVR_H_SQ   112,125,43,10             // FDD2のﾚﾊﾞｰ(水平)
#define D2_LVR_V_SQ   100,81,10,43              // FDD2のﾚﾊﾞｰ(垂直)
#define D2_ERS_H_SQ   112,125,1,10              // FDD2の軸とﾚﾊﾞｰの間の線を消す(水平)(Erase)
#define D2_ERS_V_SQ   100,123,10,1              // FDD2の軸とﾚﾊﾞｰの間の線を消す(垂直)(Erase)
#define D2_LABEL_ST   95,25,1                   // FDD2のﾗﾍﾞﾙ "ドライブ２",
#define S31_PW_DS_SQ  185,70,35,35              // PC80S31の電源ｽｲｯﾁ表示
#define S31_PW_SW_SQ  188,88,30,15              // PC80S31の電源ｽｲｯﾁ
#define S31_PW_LP_SQ  185,40,10,20              // PC80S31の電源ﾗﾝﾌﾟ
#define PC80S32_SQ    245,5,230,304             // PC80S32の輪郭
#define DRIVE3_SQ     248,8,74,298              // FDD3の輪郭
#define D3_LED_SQ     265,250,10,25             // FDD3のLED
#define D3_INS_SQ     277,45,14,250             // FDD3の挿入口(Insert)
#define D3_SLIT_SQ    280,55,8,230              // FDD3の細い隙間
#define D3_OTLT_SQ    258,130,52,70             // FDD3の取出し口(Outlet)
#define D3_AXIS_CR    265,130,10                // FDD3の軸
#define D3_LVR_H_SQ   272,125,43,10             // FDD3のﾚﾊﾞｰ(水平)
#define D3_LVR_V_SQ   260,81,10,43              // FDD3のﾚﾊﾞｰ(垂直)
#define D3_ERS_H_SQ   272,125,1,10              // FDD3の軸とﾚﾊﾞｰの間の線を消す(水平)(Erase)
#define D3_ERS_V_SQ   260,123,10,1              // FDD3の軸とﾚﾊﾞｰの間の線を消す(垂直)(Erase)
#define D3_LABEL_ST   255,25,1                  // FDD3のﾗﾍﾞﾙ "ドライブ３",
#define DRIVE4_SQ     328,8,74,298              // FDD4の輪郭
#define D4_LED_SQ     345,250,10,25             // FDD4のLED
#define D4_INS_SQ     357,45,14,250             // FDD4の挿入口(Insert)
#define D4_SLIT_SQ    360,55,8,230              // FDD4の細い隙間
#define D4_OTLT_SQ    338,130,52,70             // FDD4の取出し口(Outlet)
#define D4_AXIS_CR    345,130,10                // FDD4の軸
#define D4_LVR_H_SQ   352,125,43,10             // FDD4のﾚﾊﾞｰ(水平)
#define D4_LVR_V_SQ   340,81,10,43              // FDD4のﾚﾊﾞｰ(垂直)
#define D4_ERS_H_SQ   352,125,1,10              // FDD2の軸とﾚﾊﾞｰの間の線を消す(水平)(Erase)
#define D4_ERS_V_SQ   340,123,10,1              // FDD2の軸とﾚﾊﾞｰの間の線を消す(垂直)(Erase)
#define D4_LABEL_ST   335,25,1                  // FDD4のﾗﾍﾞﾙ "ドライブ４",
#define S32_PW_DS_SQ  425,70,35,35              // PC80S32の電源ｽｲｯﾁ表示
#define S32_PW_SW_SQ  428,88,30,15              // PC80S32の電源ｽｲｯﾁ
#define S32_PW_LP_SQ  425,40,10,20              // PC80S32の電源ﾗﾝﾌﾟ

// 最大件数
#define MAX_FILE  64                            // File_TBLの最大件数([FD_IN]ﾌｫﾙﾀﾞｰ内の最大ﾌｧｲﾙ数)
#define MAX_FILE2 65                            // File_TBLの最後に"********.***"を付ける時の為


// -----------------------------------------------------------------------------------------
// ｸﾞﾛｰﾊﾞﾙ変数定義
// -----------------------------------------------------------------------------------------
// 時間計測 ------------------------------------------------------------
unsigned long Start_Time1 = 0;          // 開始時刻1
unsigned long Start_Time2 = 0;          // 開始時刻2
unsigned long Wait_time1  = 0;          // 待ち時間1
unsigned long Wait_time2  = 0;          // 待ち時間2
// 文字列関連 ------------------------------------------------------------
unsigned int Str_length;                // 文字数
char Edit_Str[64];                      // 文字列編集用
char Short_Str[32];                     // 短い文字列編集用
char Copy_Str[13];                      // ｺﾋﾟｰされた文字列の一部
long Str_DEC;                           // 文字列から変換された数値(10進数0-999999999)
char DEC_Str[10];                       // 数値から変換された文字列(10進数0-999999999)
int Comp_sts;                           // sort比較結果(Comparison status)

// UI ------------------------------------------------------------
boolean EMU_start_flg = false;          // FDDｴﾐｭﾚｰﾀが開始されているか?
boolean EMU_practicable_flg = false;    // FDDｴﾐｭﾚｰﾀ実行可能か？(SDｶｰﾄﾞに[EMU]ﾎﾙﾀﾞｰがあるか?)
byte loop_cnt;                          // UI開始確認用
int Select_No;                          // 選択番号
byte Yes_No = 0;                        // UI

// 画面 ------------------------------------------------------------
int Th_X;                               // ﾀｯﾁ座標(X, Y)
int Th_Y;                               // ﾀｯﾁ座標(X, Y)
int TS_LEFT;                            // X座標=0のﾀｯﾁｽｸﾘｰﾝの値(回転してない時の)
int TS_RIGHT;                           // X座標=320のﾀｯﾁｽｸﾘｰﾝの値(回転してない時の)
int TS_UP;                              // Y座標=0のﾀｯﾁｽｸﾘｰﾝの値(回転してない時の)
int TS_DOWN;                            // Y座標=480のﾀｯﾁｽｸﾘｰﾝの値(回転してない時の)
byte Scr_Angle = 2;                     // 1=90度右に回転,2=180度,3=270度,0=0度
boolean Touch_flg = false;              // 画面に触った
boolean Initial_state = false;          // 初期状態(initial state)
boolean Drive_flg = false;              // ﾄﾞﾗｲﾌﾞを明細に出すか？(ｽｸﾛｰﾙに必要)
byte FD_Function = 0;                   // FDｲﾒｰｼﾞﾌｧｲﾙに対しての機能
byte FD_No;                             // 選択したFile_TBLの番号( 0 ～ File_count )
byte Drv_No;                            // 選択したﾄﾞﾗｲﾌﾞ番号(0-3)

// SD ------------------------------------------------------------
char File_TBL[MAX_FILE2][13];           // ﾌｧｲﾙ名のﾘｽﾄ
char File_Name[13];                     // FDｲﾒｰｼﾞﾌｧｲﾙ名
// ﾌｧｲﾙｻｲｽﾞ( d88(1D 35ﾄﾗｯｸ):153008 byte, (1D 40ﾄﾗｯｸ):174768 byte, (2D):348848 byte,
//          ﾌﾟﾚｰﾝｲﾒｰｼﾞ(1D 35ﾄﾗｯｸ):143360 byte,(1D 40ﾄﾗｯｸ):163840 byte, (2D):327680 byte )
unsigned long File_Size;
unsigned int File_count;                // ﾌｧｲﾙ数
const char DUMMY_Name[13] = "********.***";// ﾄﾞﾗｲﾌﾞからFD取出し用
char Drv_FD_Name[4][13];                // ﾄﾞﾗｲﾌﾞに紐づいたFDｲﾒｰｼﾞﾌｧｲﾙ名
char Wrt_FD_Name[14];                   // 書込み用FDｲﾒｰｼﾞﾌｧｲﾙ名 + '\n'
byte FD_drv_No;                         // そのFDｲﾒｰｼﾞﾌｧｲﾙが入ったﾄﾞﾗｲﾌﾞ番号
char Path_String[28];                   // ﾊﾟｽ文字列               /EMU/CONFIG/FD/XXXXXXXX.YYY
char Track_path[33];                    // ﾊﾟｽ文字列+ﾄﾗｯｸﾌｧｲﾙ名     /EMU/FD/XXXXXXXX.YYY/TRACKnn.BIN
char Sector_path[21];                   // ﾊﾟｽ文字列+ｾｸﾀﾌｧｲﾙ名      /EMU/VM/SECTORnn.BIN
char FD_IN_path[20];                    // ﾊﾟｽ文字列+FDｲﾒｰｼﾞﾌｧｲﾙ名  /FD_IN/XXXXXXXX.YYY
char OUTPUT_path[21];                   // ﾊﾟｽ文字列+FDｲﾒｰｼﾞﾌｧｲﾙ名  /FD_OUT/XXXXXXXX.YYY
char FD_info[5];                        // FDｲﾒｰｼﾞﾌｧｲﾙ情報
// ﾌｫｰﾏｯﾄ区分(1:d88(1D 35ﾄﾗｯｸ), 2:d88(1D 40ﾄﾗｯｸ), 3:d88(2D), 4:予備)
// ﾌｫｰﾏｯﾄ区分(5:ﾌﾟﾚｰﾝｲﾒｰｼﾞ(1D 35ﾄﾗｯｸ), 6:ﾌﾟﾚｰﾝｲﾒｰｼﾞ(1D 40ﾄﾗｯｸ), 7:ﾌﾟﾚｰﾝｲﾒｰｼﾞ(2D), 8:予備)
// ﾌｫｰﾏｯﾄ区分(9:対象外)
byte FD_format;
byte FD_protect;                        // 書込み保護(ﾗｲﾄﾌﾟﾛﾃｸﾄ)(0:なし, 1:あり)
byte FD_update;                         // 更新区分(0:なし, 1:あり)
byte FD_output;                         // 出力区分(0:なし, 1:あり)
byte FD_info_TBL[MAX_FILE2][4];         // FDｲﾒｰｼﾞﾌｧｲﾙ情報ﾃｰﾌﾞﾙ

// ﾊﾞｯﾌｧｰ ------------------------------------------------------------
byte RW_Buffer[4][256];                 // 読み書きﾊﾞｯﾌｧｰ
byte Drive_cnt;                         // ﾄﾞﾗｲﾌﾞ番号(0-3)
byte Track_cnt;                         // ﾄﾗｯｸ番号(0-79)
byte Block_cnt;                         // ﾌﾞﾛｯｸ番号(0-3)( 4ｾｸﾀ = 1ﾌﾞﾛｯｸ )
byte Sector_cnt;                        // ｾｸﾀ番号(1-16)
byte Byte_cnt;                          // ｾｸﾀ内の何ﾊﾞｲﾄ目(0-255)を処理しているのか
byte RW_Sector_cnt;                     // 読み書きｾｸﾀ処理件数
unsigned long File_address;             // FDｲﾒｰｼﾞの何ﾊﾞｲﾄ目を処理しているのか

//送受信制御 ------------------------------------------------------------
byte PINL_BK;                           // PC3～PC0 のﾊﾞｯｸｱｯﾌﾟ
byte PINL_BK2 = 0;                      // PC3～PC0 のﾊﾞｯｸｱｯﾌﾟの1世代前
byte Snd_data_Buffer = 0;               // 送信ﾃﾞｰﾀﾊﾞｯﾌｧｰ
byte Rcv_data;                          // PA7～PA0 のﾊﾞｯｸｱｯﾌﾟ
boolean Rcv_data_flg = false;           // true : PCから後続ﾃﾞｰﾀあり

// 実行制御 ------------------------------------------------------------
byte Comm_sts = 0;            // 0: ｺﾏﾝﾄﾞ無し、1:ｺﾏﾝﾄﾞｾｯﾄ、2:ﾊﾟﾗﾒｰﾀｾｯﾄ、3:ﾃﾞｰﾀｾｯﾄ、9:ｺﾏﾝﾄﾞ終了
byte Comm_type = 0;                     // ｺﾏﾝﾄﾞ種別
byte Comm_BK = 0;                       // 前のｺﾏﾝﾄﾞ種別
byte Comm_para[7];                      // ｺﾏﾝﾄﾞのﾊﾟﾗﾒｰﾀ
byte para_cnt = 0;                      // 次は何番目のﾊﾟﾗﾒｰﾀか
byte VM_Drive = 9;                      // ﾄﾞﾗｲﾌﾞ番号,ﾄﾗｯｸ番号が変わったら
byte VM_Track = 99;                     // ﾄﾗｯｸﾌｧｲﾙを出力する為の制御切れ用
boolean Trk_Fil_flg = false;            // ﾄﾗｯｸﾌｧｲﾙ出力待ちか？
//boolean Format_flg = false;             // ﾌｫｰﾏｯﾄ途中か？

// 実際のﾊﾟﾗﾒｰﾀ ------------------------------------------------------------
byte Sector_qt;                         // ｾｸﾀの数量(Sector quantity)(MAX:16)
byte Drive_No;                          // ﾄﾞﾗｲﾌﾞ番号(0-3)
byte Track_No;                          // ﾄﾗｯｸ番号(0-79)
byte Sector_No;                         // ｾｸﾀ番号(1-16)
byte Drive_sou;                         // copy source Drive
byte Track_sou;                         // copy source Track
byte Sector_sou;                        // copy source Sector
byte Drive_dest;                        // copy destination Drive
byte Track_dest;                        // copy destination Track
byte Sector_dest;                       // copy destination Sector
byte Mode_data;                         // ﾓｰﾄﾞﾃﾞｰﾀ(送受信ﾃﾞｰﾀ)
byte Result_status = B10000000;         // ﾚｻﾞﾙﾄ・ｽﾃｰﾀｽ(送信ﾃﾞｰﾀ)
byte Drive_status = B11111111;          // ﾄﾞﾗｲﾌﾞ・ｽﾃｰﾀｽ(送信ﾃﾞｰﾀ)
byte H_address;                         // 転送ｱﾄﾞﾚｽ上位
byte L_address;                         // 転送ｱﾄﾞﾚｽ下位
byte H_Number;                          // 転送ﾊﾞｲﾄ数上位
byte L_Number;                          // 転送ﾊﾞｲﾄ数下位

// 何番目のﾊﾟﾗﾒｰﾀが最後か(そのｺﾏﾝﾄﾞのﾊﾟﾗﾒｰﾀの数) ------------------------------------------------------------
byte para_end[]   = {0, 4, 4, 0, 7, 1,  0, 0, 0, 4, 0,
                        4, 4, 2, 6, 6,  0, 4, 0, 0, 1,
                        4, 4, 1, 0, 0,  0, 0, 2, 3, 1};

/* ｺﾏﾝﾄﾞに対応するか
byte Comm_ON[]    = {0, 1, 1, 1, 1, 1,  1, 1, 0, 0, 0,
                        0, 0, 0, 0, 0,  0, 1, 1, 0, 0,
                        0, 0, 1, 1, 0,  0, 0, 0, 0, 0};
*/
/* ｺﾏﾝﾄﾞにﾃﾞｰﾀが付いているか
byte Comm_data[]  = {0, 1, 0, 0, 0, 0,  0, 0, 0, 0, 1,
                        0, 1, 0, 0, 0,  0, 1, 0, 0, 0,
                        0, 1, 0, 0, 0,  0, 0, 0, 0, 0};
*/
/* ｺﾏﾝﾄﾞに返信が必要か
byte Comm_rtrn[]  = {0, 0, 0, 0, 0, 0,  1, 1, 1, 1, 0,
                        1, 0, 0, 0, 0,  0, 0, 0, 1, 1,
                        1, 0, 0, 1, 0,  0, 0, 0, 0, 1};
*/

// 初期処理 ------------------------------------------------------------------------------------------
void setup() {
  // 入出力設定(1で出力 0 で入力(High Impedance))
  DDRA   = B00000000; // PA7～PA0(PA7～PA0) : INPUT
  DDRC   = B11111111;                                         // PB7～PB0(PC7～PC0) : OUTPUT
  PORTC  = B00000000;                                         // PB7～PB0(PC7～PC0) : LOW
  DDRL   = B00001111; // PC3～PC0(PL7～PL4) : INPUT            // PC7～PC4(PL3～PL0) : OUTPUT
  PORTL &= B11110000;                                         // PC7～PC4(PL3～PL0) : LOW

  pinMode(LED_PIN, OUTPUT);                                   // FDｱｸｾｽ時の点滅用
  pinMode(BUZZER_PIN, OUTPUT);                                // FDｱｸｾｽ時のﾌﾞｻﾞｰ入切用
  MsTimer2::set(5, Driving_sound);                            // 5msごと(FDD駆動音)

//Serial.begin(9600);                                         // 9600bpsでﾎﾟｰﾄを開く
  Serial.begin(115200);                                       // 115200bpsでﾎﾟｰﾄを開く
//Serial.begin(230400);                                       // 230400bpsでﾎﾟｰﾄを開く   // debug
  delay(1000);
//Serial.println(F("Serial.begin(115200);"));                 // F():Flashﾒﾓﾘｰに文字列DATAが入る

// -----------------------------------------------------------------------------------------
  Serial_Start_msg();                                         // ｼﾘｱﾙ開始ﾒｯｾｰｼﾞ
  Calibration_EEPROM_read();                                  // EEPROMからﾀｯﾁｸﾘｰﾝのｷｬﾘﾌﾞﾚｰｼｮﾝ設定を読込む

  DSP.reset();                                                // 画面初期化(MCUFRIEND)
  uint16_t ID = DSP.readID();                                 // 画面初期化(MCUFRIEND)
  DSP.begin(ID);                                              // 画面初期化(MCUFRIEND)

  if (SD.begin(SD_CS) == false) {                             //SDカードの読み込み
    Error_MSG_SD_init();                                      // ｴﾗｰﾒｯｾｰｼﾞ(SDカードの初期読込みができない)
  }
  EMU_check_rtn();                                            // SDｶｰﾄﾞに[EMU]ﾎﾙﾀﾞｰがあるかﾁｪｯｸ
  if (EMU_practicable_flg == true) {                          // FDDｴﾐｭﾚｰﾀ実行可能か？(SDｶｰﾄﾞに[EMU]ﾎﾙﾀﾞｰがあるか?)
    VM_clear_rtn();                                           // /EMU/VM内をｸﾘｱする
    Touch_Init_Screen();                                      // 設定初期画面(ﾀｯﾁｽｸﾘｰﾝ)
    System_check_rtn();                                       // ｼｽﾃﾑﾃﾞｰﾀﾁｪｯｸ&削除
    FD_info_batch();                                          // FDｲﾒｰｼﾞﾌｧｲﾙ情報作成(一括)
    Drv_fd_link_load();                                       // ﾄﾞﾗｲﾌﾞ・FDｲﾒｰｼﾞ紐づけﾌｧｲﾙ読込み
    Serial_Function_print();                                  // ｼﾘｱﾙ機能選択印字
    if (Drv_FD_Name[0][0] != '*') {
      FD_info_TBL_NM_read(Drv_FD_Name[0]);                    // FD_No取得の為
    } else {
      FD_No = 0;
    }
    Touch_Init_Detail_set();                                  // 設定初期画面明細領域ｾｯﾄ(ﾀｯﾁｽｸﾘｰﾝ)
  } else {
    Serial_SD_Init_msg();                                     // SDｶｰﾄﾞ準備ﾒｯｾｰｼﾞ(ｼﾘｱﾙ)
    Touch_SD_Init_rtn();                                      // SDｶｰﾄﾞ準備(ﾀｯﾁｽｸﾘｰﾝ)
  }
  Start_Time1 = millis();                                     // ms単位の時間計測
  Start_Time2 = millis();                                     // ms単位の時間計測
}


// 主処理 --------------------------------------------------------------------------------------------
void loop() {
////////////////////////////////////////////////////////////////////////////////////
/// ﾕｰｻﾞｰｲﾝﾀｰﾌｪｰｽ(UI)待ち ////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
  loop_cnt++;
  if (loop_cnt == 0) {                                        // 256回のﾙｰﾌﾟに1回
    Wait_time1 = millis() - Start_Time1;                      // 経過時間
    if (Wait_time1 > 50) {                                    // 50msごとに
      Start_Time1 = millis();                                 // ms単位の時間計測
      if (Serial.available() > 0) {                           // ｼﾘｱﾙ受信ﾃﾞｰﾀがあるか?
        Serial_UI_rtn();                                      // ｼﾘｱﾙUI処理
      }
      Get_touch();                                            // ﾀｯﾁの取得
      if (Touch_flg == true) {                                // 画面に触った
        Touch_UI_main();                                      // ﾀｯﾁｽｸﾘｰﾝUI処理
      }
    }
////////////////////////////////////////////////////////////////////////////////////
/// ｺﾏﾝﾄﾞ実行後処理 //////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
    Wait_time2 = millis() - Start_Time2;                      // 経過時間
    if ((Wait_time2 > 100) && (Wait_time2 < 110)) {           // 通信が一段落して100ms後に
//    Track_file_write(File_Name, Track_cnt);                 // ﾄﾗｯｸﾌｧｲﾙ書込み
      Track_file_write();                                     // ﾄﾗｯｸﾌｧｲﾙ書込み
    }
  }
////////////////////////////////////////////////////////////////////////////////////
/// ﾚﾄﾛPCとの通信とｺﾏﾝﾄﾞ実行 //////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
  if (EMU_start_flg == true) {                               // FDDｴﾐｭﾚｰﾀが開始されているか?
    PINL_BK  = PINL >> 4;                                    // PC3～PC0 のﾊﾞｯｸｱｯﾌﾟ
    if (PINL_BK2 != PINL_BK) {                               // PC3～PC0 に変化があった場合
      Cont_sign_choice();                                    // 制御信号選択(ｺﾏﾝﾄﾞ実行へ)
      PINL_BK2 = PINL_BK;                                    // PC3～PC0 のﾊﾞｯｸｱｯﾌﾟの1世代前
      Start_Time2 = millis();                                // ms単位の時間計測
    }
  }
}


//
