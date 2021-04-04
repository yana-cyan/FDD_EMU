////////////////////////////////////////////////////////////////////////////////////////////
/// ﾌﾗｯｼｭﾒﾓﾘ･ﾃﾞｰﾀ部 //////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
// N60-拡張BASICのFAT部分 ---------------------------------------------
const char N60_FAT[] PROGMEM = {
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};

// N-BASIC(DISK BASIC)のFAT部分 ---------------------------------------------
const char N_FAT[] PROGMEM = {
0xFE, 0xFE, 0xFF, 0xFF, 0xFE, 0xFE, 0xFF, 0xFF, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};

// root内のﾃﾞｨﾚｸﾄﾘとﾌｧｲﾙを表示(ﾀｯﾁｸﾘｰﾝ) ---------------------------------------------
const char Data_root_list_header[3][64] PROGMEM = {
"********************************",
"* SDｶｰﾄﾞ ﾉ ﾌｫﾙﾀﾞｰ(ﾌｧｲﾙ) (byte) *",
"* ( [SYSTEM~1] ﾀﾞｹﾅﾗ ｶﾗﾃﾞｽ )   *"
};
const char * const Str_root_list_header[] PROGMEM = {
Data_root_list_header[0],
Data_root_list_header[1],
Data_root_list_header[2]
};


// ﾃﾞｨﾚｸﾄﾘとﾌｧｲﾙのﾊﾟｽ ---------------------------------------------
const char Data_Fixed_path[22][32] PROGMEM = {
"/FD_IN",                        // [0]
"/FD_OUT",                       // [1]
"/EMU",                          // [2]
"/EMU/CONFIG",                   // [3]
"/EMU/CONFIG/FD",                // [4]
"/EMU/VM",                       // [5]
"/EMU/FD",                       // [6]
"/EMU/D88",                      // [7]
"/FD_IN/",                       // [8]
"/FD_IN/WK2D0000.IMG",           // [9]
"/FD_OUT/",                      // [10]
"/EMU/CONFIG/FD/",               // [11]
"/EMU/FD/",                      // [12]
"/EMU/VM/SECTOR",                // [13]
"/EMU/CONFIG/FD_IMG.LST",        // [14]
"/EMU/CONFIG/DRV_FD.USE",        // [15]
"/EMU/D88/",                     // [16]
"/TRACK",                        // [17]
".BIN",                          // [18]
"/FD_IN/WK1D0000.IMG",           // [19]
"/EMU/VM/TRACK.BIN",             // [20]
"/readme.txt"                    // [21]
};
const char * const Str_Fixed_path[] PROGMEM = {
Data_Fixed_path[0],
Data_Fixed_path[1],
Data_Fixed_path[2],
Data_Fixed_path[3],
Data_Fixed_path[4],
Data_Fixed_path[5],
Data_Fixed_path[6],
Data_Fixed_path[7],
Data_Fixed_path[8],
Data_Fixed_path[9],
Data_Fixed_path[10],
Data_Fixed_path[11],
Data_Fixed_path[12],
Data_Fixed_path[13],
Data_Fixed_path[14],
Data_Fixed_path[15],
Data_Fixed_path[16],
Data_Fixed_path[17],
Data_Fixed_path[18],
Data_Fixed_path[19],
Data_Fixed_path[20],
Data_Fixed_path[21]
};


// 固定文字列 ---------------------------------------------
const char Data_Fixed_string[3][32] PROGMEM = {
" ( ",
" byte ) ",
"ﾌｫﾙﾀﾞｰ"
};
const char * const Str_Fixed_string[] PROGMEM = {
Data_Fixed_string[0],
Data_Fixed_string[1],
Data_Fixed_string[2]
};


// readme.txt ---------------------------------------------
const char Data_readme_txt[77][256] PROGMEM = {
"-----------------------------------------------------------------------------------------------------\n",
"SDｶｰﾄﾞについて\n",
"-----------------------------------------------------------------------------------------------------\n",
"SDｶｰﾄﾞの中に[FD_IN],[FD_OUT],[EMU]ﾌｫﾙﾀﾞが新たに出来ています｡\n",
"[FD_IN]ﾌｫﾙﾀﾞに使いたいFDｲﾒｰｼﾞﾌｧｲﾙを入れます｡(最大で６４個入ります｡)\n",
"[FD_OUT]ﾌｫﾙﾀﾞは修正したFDｲﾒｰｼﾞﾌｧｲﾙを取出すのに使います｡\n",
"[EMU]ﾌｫﾙﾀﾞにはｼｽﾃﾑに必要なﾌｧｲﾙが入っています｡\n",
"\n",
"使えるFDｲﾒｰｼﾞﾌｧｲﾙ形式は、拡張子[D88] と、ﾌﾟﾚｰﾝｲﾒｰｼﾞ(拡張子[DSK][IMG]等)です｡\n",
"(1D 35ﾄﾗｯｸ)(1D 40ﾄﾗｯｸ)(2D 80ﾄﾗｯｸ)に対応しています｡\n",
"(1D 35ﾄﾗｯｸ) = 35ﾄﾗｯｸ x 片面 x 16ｾｸﾀ x 256 byte\n",
"(1D 40ﾄﾗｯｸ) = 40ﾄﾗｯｸ x 片面 x 16ｾｸﾀ x 256 byte\n",
"(2D 80ﾄﾗｯｸ) = 40ﾄﾗｯｸ x 両面 x 16ｾｸﾀ x 256 byte\n",
"[d88]     (1D 35ﾄﾗｯｸ)は、ﾌｧｲﾙｻｲｽﾞ:150KB( 153008 byte )です｡\n",
"[d88]     (1D 40ﾄﾗｯｸ)は、ﾌｧｲﾙｻｲｽﾞ:171KB( 174768 byte )です｡\n",
"[d88]     (2D 80ﾄﾗｯｸ)は、ﾌｧｲﾙｻｲｽﾞ:341KB( 348848 byte )です｡\n",
"ﾌﾟﾚｰﾝｲﾒｰｼﾞ(1D 35ﾄﾗｯｸ)は、ﾌｧｲﾙｻｲｽﾞ:140KB( 143360 byte )です｡\n",
"ﾌﾟﾚｰﾝｲﾒｰｼﾞ(1D 40ﾄﾗｯｸ)は、ﾌｧｲﾙｻｲｽﾞ:160KB( 163840 byte )です｡\n",
"ﾌﾟﾚｰﾝｲﾒｰｼﾞ(2D 80ﾄﾗｯｸ)は、ﾌｧｲﾙｻｲｽﾞ:320KB( 327680 byte )です｡\n",
"ﾌｧｲﾙｻｲｽﾞが、1 byteでも違うとｼｽﾃﾑは認識しません｡\n",
"[FD_IN]ﾌｫﾙﾀﾞにFDｲﾒｰｼﾞﾌｧｲﾙを入れる前に、ｴｸｽﾌﾟﾛｰﾗでﾌﾟﾛﾊﾟﾃｨを見て確認して下さい｡\n",
"\n",
"ﾌｧｲﾙ名は、8+3(8文字 + '.' + 拡張子([D88][DSK][IMG]等))です｡\n",
"[FD_IN]ﾌｫﾙﾀﾞ内にﾌｫﾙﾀﾞを作ってもｼｽﾃﾑは認識しません｡\n",
"\n",
"[FD_IN]ﾌｫﾙﾀﾞに空のFDｲﾒｰｼﾞﾌｧｲﾙが出来ています｡\n",
"[WK1D0000.IMG]はﾌﾟﾚｰﾝｲﾒｰｼﾞ(1D 35ﾄﾗｯｸ)を「N60-拡張BASIC」で書込めるようにﾌｫｰﾏｯﾄ済です｡\n",
"[WK2D0000.IMG]はﾌﾟﾚｰﾝｲﾒｰｼﾞ(2D 80ﾄﾗｯｸ)を「N-BASIC(DISK BASIC)」で書込めるようにﾌｫｰﾏｯﾄ済です｡\n",
"空のFDｲﾒｰｼﾞﾌｧｲﾙはｺﾋﾟｰして使って下さい｡\n",
"\n",
"-----------------------------------------------------------------------------------------------------\n",
"操作方法について(Serial)\n",
"-----------------------------------------------------------------------------------------------------\n",
"1:[FDDｴﾐｭﾚｰﾀ ｷﾄﾞｳ]: FDDｴﾐｭﾚｰﾀを起動します｡\n",
"\n",
"2:[FDｲﾒｰｼﾞ ｻｼｶｴ]  : FDﾄﾞﾗｲﾌﾞのFDｲﾒｰｼﾞﾌｧｲﾙを差替えます｡\n",
"                    [********.***]はFDｲﾒｰｼﾞﾌｧｲﾙがｾｯﾄされていない状態を示します｡\n",
"\n",
"3:[ﾗｲﾄﾌﾟﾛﾃｸﾄ ﾍﾝｺｳ]: FDｲﾒｰｼﾞﾌｧｲﾙのﾗｲﾄﾌﾟﾛﾃｸﾄを掛けたり、外したりします｡\n",
"                    FDｲﾒｰｼﾞﾌｧｲﾙの初期状態では、ﾗｲﾄﾌﾟﾛﾃｸﾄが掛かっています｡\n",
"\n",
"4:[FDｲﾒｰｼﾞ ｼｭﾂﾘｮｸ]: [FD_OUT]ﾌｫﾙﾀﾞに修正されたFDｲﾒｰｼﾞが出力されます｡\n",
"                    (1D 35ﾄﾗｯｸ)のFDｲﾒｰｼﾞﾌｧｲﾙで15秒、(2D 80ﾄﾗｯｸ)のFDｲﾒｰｼﾞﾌｧｲﾙで30秒掛かります｡\n",
"                    FDｲﾒｰｼﾞﾌｧｲﾙにﾚﾄﾛPCから書込みした場合、[EMU]ﾌｫﾙﾀﾞ内に差分ﾃﾞｰﾀが作られます｡\n",
"                    [FD_IN]ﾌｫﾙﾀﾞのFDｲﾒｰｼﾞﾌｧｲﾙと[EMU]ﾌｫﾙﾀﾞ内の差分ﾃﾞｰﾀで一つのFDｲﾒｰｼﾞﾌｧｲﾙに戻します｡\n",
"\n",
"ArduinoIDEのｼﾘｱﾙﾓﾆﾀやﾀｰﾐﾅﾙｿﾌﾄ(Tera Term等)は、通信速度を115200bpsにして下さい｡\n",
"\n",
"-----------------------------------------------------------------------------------------------------\n",
"操作方法について(Touch Screen)\n",
"-----------------------------------------------------------------------------------------------------\n",
"【エミュレータ】    : FDDｴﾐｭﾚｰﾀを起動します｡\n",
"                      FDﾄﾞﾗｲﾌﾞの画像に変わり、ｱｸｾｽﾗﾝﾌﾟが点滅し、駆動音がします｡\n",
"\n",
"【ＦＤ差しかえ】    : FDﾄﾞﾗｲﾌﾞのFDｲﾒｰｼﾞを差替えます｡\n",
"                     【▲】【▼】でFDｲﾒｰｼﾞﾌｧｲﾙを選び、【ＦＤ差しかえ】ﾎﾞﾀﾝを押します｡\n",
"                      次に【▲】【▼】でFDﾄﾞﾗｲﾌﾞを選びます｡\n",
"                     【実行】ﾎﾞﾀﾝで差替えられます｡【中止】ﾎﾞﾀﾝでｷｬﾝｾﾙされます｡\n",
"                      [********.***]はFDｲﾒｰｼﾞﾌｧｲﾙがｾｯﾄされていない状態を示します｡\n",
"\n",
"                      ﾚﾄﾛPC操作中にFDの差替えをする場合があります｡ その時はFDD画像の対象ﾄﾞﾗｲﾌﾞを押します｡\n",
"                      ｴﾐｭﾚｰﾀは終了し、押された1～4のﾄﾞﾗｲﾌﾞが選ばれた【ＦＤ差しかえ】の設定画面になります｡\n",
"                      ﾄﾞﾗｲﾌﾞが選ばれていますので、後、FDｲﾒｰｼﾞﾌｧｲﾙを選択し、【実行】ﾎﾞﾀﾝで差替えられます｡\n",
"                     【エミュレータ】ﾎﾞﾀﾝを押し、FDDｴﾐｭﾚｰﾀを起動します｡ ﾚﾄﾛPCで続きの操作をします｡\n",
"\n",
"【ライトプロテクト】: FDｲﾒｰｼﾞﾌｧｲﾙのﾗｲﾄﾌﾟﾛﾃｸﾄを掛けたり、外したりします｡\n",
"                     【▲】【▼】でFDｲﾒｰｼﾞﾌｧｲﾙを選び、【ライトプロテクト】ﾎﾞﾀﾝを押します｡\n",
"                     【実行】ﾎﾞﾀﾝでﾗｲﾄﾌﾟﾛﾃｸﾄが切替えられます｡【中止】ﾎﾞﾀﾝでｷｬﾝｾﾙされます｡\n",
"                      FDｲﾒｰｼﾞの初期状態では、ﾗｲﾄﾌﾟﾛﾃｸﾄが掛かっています｡\n",
"\n",
"【イメージ出力】    : [FD_OUT]ﾌｫﾙﾀﾞに修正されたFDｲﾒｰｼﾞﾌｧｲﾙが出力されます｡\n",
"                     【▲】【▼】でFDｲﾒｰｼﾞﾌｧｲﾙを選び、【イメージ出力】ﾎﾞﾀﾝを押します｡\n",
"                     【実行】ﾎﾞﾀﾝで処理が始まります｡【中止】ﾎﾞﾀﾝでｷｬﾝｾﾙされます｡\n",
"                      (1D 35ﾄﾗｯｸ)のFDｲﾒｰｼﾞﾌｧｲﾙで15秒、(2D 80ﾄﾗｯｸ)のFDｲﾒｰｼﾞﾌｧｲﾙで30秒掛かります｡\n",
"                      FDｲﾒｰｼﾞﾌｧｲﾙにﾚﾄﾛPCから書込みした場合、[EMU]ﾌｫﾙﾀﾞ内に差分ﾃﾞｰﾀが作られます｡\n",
"                      [FD_IN]ﾌｫﾙﾀﾞのFDｲﾒｰｼﾞﾌｧｲﾙと[EMU]ﾌｫﾙﾀﾞ内の差分ﾃﾞｰﾀで一つのFDｲﾒｰｼﾞﾌｧｲﾙにします｡\n",
"\n"
};
const char * const Str_readme_txt[] PROGMEM = {
Data_readme_txt[0],
Data_readme_txt[1],
Data_readme_txt[2],
Data_readme_txt[3],
Data_readme_txt[4],
Data_readme_txt[5],
Data_readme_txt[6],
Data_readme_txt[7],
Data_readme_txt[8],
Data_readme_txt[9],
Data_readme_txt[10],
Data_readme_txt[11],
Data_readme_txt[12],
Data_readme_txt[13],
Data_readme_txt[14],
Data_readme_txt[15],
Data_readme_txt[16],
Data_readme_txt[17],
Data_readme_txt[18],
Data_readme_txt[19],
Data_readme_txt[20],
Data_readme_txt[21],
Data_readme_txt[22],
Data_readme_txt[23],
Data_readme_txt[24],
Data_readme_txt[25],
Data_readme_txt[26],
Data_readme_txt[27],
Data_readme_txt[28],
Data_readme_txt[29],
Data_readme_txt[30],
Data_readme_txt[31],
Data_readme_txt[32],
Data_readme_txt[33],
Data_readme_txt[34],
Data_readme_txt[35],
Data_readme_txt[36],
Data_readme_txt[37],
Data_readme_txt[38],
Data_readme_txt[39],
Data_readme_txt[40],
Data_readme_txt[41],
Data_readme_txt[42],
Data_readme_txt[43],
Data_readme_txt[44],
Data_readme_txt[45],
Data_readme_txt[46],
Data_readme_txt[47],
Data_readme_txt[48],
Data_readme_txt[49],
Data_readme_txt[50],
Data_readme_txt[51],
Data_readme_txt[52],
Data_readme_txt[53],
Data_readme_txt[54],
Data_readme_txt[55],
Data_readme_txt[56],
Data_readme_txt[57],
Data_readme_txt[58],
Data_readme_txt[59],
Data_readme_txt[60],
Data_readme_txt[61],
Data_readme_txt[62],
Data_readme_txt[63],
Data_readme_txt[64],
Data_readme_txt[65],
Data_readme_txt[66],
Data_readme_txt[67],
Data_readme_txt[68],
Data_readme_txt[69],
Data_readme_txt[70],
Data_readme_txt[71],
Data_readme_txt[72],
Data_readme_txt[73],
Data_readme_txt[74],
Data_readme_txt[75],
Data_readme_txt[76]
};


////////////////////////////////////////////////////////////////////////////////////////////
/// 処理部 //////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
// SDｶｰﾄﾞを読込み ---------------------------------------------
//void SD_card_read(char * File_Name, byte Track_cnt, byte Sector_cnt, byte TBL_cnt) {
void SD_card_read(byte TBL_cnt) {
//Serial.println(F("SD_card_read();"));
unsigned long Sector_num = Sector_cnt;                       // ｾｸﾀ番号(1-16)

  FD_access_rtn(true);                                       // FDｱｸｾｽ(LEDと作動音)

//Track_path_Generate(File_Name, Track_cnt);                 // ﾊﾟｽ+差分ﾄﾗｯｸﾌｧｲﾙ名生成
  Track_path_Generate();                                     // ﾊﾟｽ+差分ﾄﾗｯｸﾌｧｲﾙ名生成

  if (SD.exists(Track_path) == true) {
    File Input_File = SD.open(Track_path, FILE_READ);
    File_Size = Input_File.size();
    if (File_Size == 256) {
      File_address = 0;
    } else {
      File_address = ( Sector_num - 1 ) * 0x100;
    }
    Input_File.seek(File_address);
    Input_File.read(RW_Buffer[TBL_cnt], 256);
    if (Input_File == false) {
      delay(3000);
      Input_File.seek(File_address);
      Input_File.read(RW_Buffer[TBL_cnt], 256);
      if (Input_File == false) {
        Serial.println(Track_path);
        Error_MSG_System();                                  // ｴﾗｰﾒｯｾｰｼﾞ(ｼｽﾃﾑ異常)
      }
    }
    Input_File.close();
  } else {
//  Insert_Edit_Str("/FD_IN/");
    strcpy_P(Edit_Str, pgm_read_word(&(Str_Fixed_path[8])));
    Connect_Edit_Str(File_Name);                             // Edit_Strに文字列を連結する
    Insert_FD_IN_path(Edit_Str);
//  FD_info_read(File_Name);                                 // FDｲﾒｰｼﾞﾌｧｲﾙ情報読込み 
    FD_info_read();                                          // FDｲﾒｰｼﾞﾌｧｲﾙ情報読込み 
//  FD_read(Track_cnt, Sector_cnt, TBL_cnt);                 // FDｲﾒｰｼﾞﾌｧｨﾙを読込み
    FD_read(TBL_cnt);                                        // FDｲﾒｰｼﾞﾌｧｨﾙを読込み
  }

  FD_access_rtn(false);                                      // FDｱｸｾｽ(LEDと作動音)
//RW_Buffer_print();                                           // debug
}


// FDｲﾒｰｼﾞﾌｧｨﾙを読込み ---------------------------------------------
//void FD_read(byte Track_cnt, byte Sector_cnt, byte TBL_cnt) {
void FD_read(byte TBL_cnt) {
//Serial.println(F("FD_read();"));
unsigned long Track_num  = Track_cnt;                        // ﾄﾗｯｸ番号(0-79)
unsigned long Sector_num = Sector_cnt;                       // ｾｸﾀ番号(1-16)

  File Input_File = SD.open(FD_IN_path, FILE_READ);
  if (Input_File == false) {
    Error_MSG_File_read_open(FD_IN_path);                    // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙが読込みﾓｰﾄﾞで開けない)
  }
  // ﾌｫｰﾏｯﾄ区分(1:d88(1D 35ﾄﾗｯｸ), 2:d88(1D 40ﾄﾗｯｸ), 3:d88(2D), 4:予備)
  if ((FD_format >= 1) && (FD_format <= 4)) {
    File_address = ( Track_num * 0x10 + Sector_num - 1 ) * 0x110 + 0x2B0 + 0x10;

  // ﾌｫｰﾏｯﾄ区分(5:ﾌﾟﾚｰﾝｲﾒｰｼﾞ(1D 35ﾄﾗｯｸ), 6:ﾌﾟﾚｰﾝｲﾒｰｼﾞ(1D 40ﾄﾗｯｸ), 7:ﾌﾟﾚｰﾝｲﾒｰｼﾞ(2D), 8:予備)
  } else if ((FD_format >= 5) && (FD_format <= 8)) {
    File_address = ( Track_num * 0x10 + Sector_num - 1 ) * 0x100;
  } else {
    Serial.print("FD_format = ");Serial.println(FD_format);
    Error_MSG_System();                                      // ｴﾗｰﾒｯｾｰｼﾞ(ｼｽﾃﾑ異常)
  }
  Input_File.seek(File_address);
  Input_File.read(RW_Buffer[TBL_cnt], 256);
  if (Input_File == false) {
    delay(3000);
    Input_File.seek(File_address);
    Input_File.read(RW_Buffer[TBL_cnt], 256);
    if (Input_File == false) {
      Serial.println(FD_IN_path);
      Error_MSG_System();                                    // ｴﾗｰﾒｯｾｰｼﾞ(ｼｽﾃﾑ異常)
    }
  }
  Input_File.close();
}


// SDｶｰﾄﾞ書込み ---------------------------------------------
//void SD_card_write(byte Sector_cnt) {
void SD_card_write() {
//Serial.println(F("SD_card_write();"));
//Serial.print(F("Sector_cnt : "));Serial.println(Sector_cnt); // debug

  FD_access_rtn(true);                                       // FDｱｸｾｽ(LEDと作動音)

//Sector_path_Generate(Sector_cnt);                          // ﾊﾟｽ+差分ｾｸﾀﾌｧｲﾙ名生成
  Sector_path_Generate();                                    // ﾊﾟｽ+差分ｾｸﾀﾌｧｲﾙ名生成

  // ﾌｧｲﾙがある場合は、そのﾌｧｲﾙを削除
  if (SD.exists(Sector_path) == true) {
    SD.remove(Sector_path);
  }
  // 空のﾌｧｲﾙを作る(Sector_path)
  Zero_Sector_path_create();

  // 空のﾌｧｲﾙに追加書き
  File Output_File = SD.open(Sector_path, FILE_WRITE);
  if (Output_File == false) {
    Serial.println(F("SD_card_write();"));
    Serial.print(F("Sector_cnt : "));Serial.println(Sector_cnt);
    Error_MSG_File_write_open(Sector_path);                  // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙが書込みﾓｰﾄﾞで開けない)
  }
  Output_File.write(RW_Buffer[0], 256);                      // SDｶｰﾄﾞにﾃﾞｰﾀ書込み
  if (Output_File == false) {
    Error_MSG_File_write(Sector_path);                       // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙ書込みができない)
  }
  Output_File.flush();
  Output_File.close();

  Trk_Fil_flg = true;                                        // ﾄﾗｯｸﾌｧｲﾙ出力待ちか？
  VM_Drive = Drive_cnt;                                      // ﾄﾞﾗｲﾌﾞ番号,ﾄﾗｯｸ番号が変わったら
  VM_Track = Track_cnt;                                      // ﾄﾗｯｸﾌｧｲﾙを出力する為の制御切れ用

  FD_access_rtn(false);                                      // FDｱｸｾｽ(LEDと作動音)
}


// ﾄﾗｯｸﾌｧｲﾙ書込み ---------------------------------------------
//void Track_file_write(byte VM_Drive, byte VM_Track) {
void Track_file_write() {
//Serial.println(F("Track_file_write();"));
  if (Trk_Fil_flg == false) {                                // ﾄﾗｯｸﾌｧｲﾙ出力待ちか？
    return;
  }
  byte Drive_BK = Drive_cnt;
  byte Track_BK = Track_cnt;
  Drive_cnt = VM_Drive;
  Track_cnt = VM_Track;
  Insert_File_Name(Drv_FD_Name[VM_Drive]);                   // ﾌｧｲﾙ名

  FD_access_rtn(true);                                       // FDｱｸｾｽ(LEDと作動音)

//Track_file_copy(File_Name, Track_cnt);                     // 更新前のﾄﾗｯｸﾌｧｲﾙを/EMU/VM内にｺﾋﾟｰする
  Track_file_copy();                                         // 更新前のﾄﾗｯｸﾌｧｲﾙを/EMU/VM内にｺﾋﾟｰする

//Track_file_create(File_Name, Track_cnt);                   // ﾄﾗｯｸﾌｧｲﾙを作る
  Track_file_create();                                       // ﾄﾗｯｸﾌｧｲﾙを作る

  Delete_Sector_file();                                      // ｾｸﾀﾌｧｲﾙを削除する

  Trk_Fil_flg = false;                                       // ﾄﾗｯｸﾌｧｲﾙ出力待ちか？
  Drive_cnt = Drive_BK;
  Track_cnt = Track_BK;
  Insert_File_Name(Drv_FD_Name[Drive_cnt]);                  // ﾌｧｲﾙ名

  FD_access_rtn(false);                                      // FDｱｸｾｽ(LEDと作動音)

//Serial.println(F("Track_file_write(end);"));                 // debug
}                   


// 更新前のﾄﾗｯｸﾌｧｲﾙを/EMU/VM内にｺﾋﾟｰする ---------------------------------------------
//void Track_file_copy(char * File_Name, byte Track_cnt) {
void Track_file_copy() {
//Serial.println(F("Track_file_copy();"));
  unsigned long Sector_num;                                  // File_address計算用ｾｸﾀ番号(1-16)
  boolean Track_flg = false;                                 // ﾄﾗｯｸﾌｧｲﾙがあるか？

//Insert_Edit_Str("/FD_IN/");
  strcpy_P(Edit_Str, pgm_read_word(&(Str_Fixed_path[8])));
  Connect_Edit_Str(File_Name);                               // Edit_Strに文字列を連結する
  Insert_FD_IN_path(Edit_Str);
//Serial.print(F("FD_IN_path : "));Serial.println(FD_IN_path); // debug
//FD_info_read(File_Name);                                   // FDｲﾒｰｼﾞﾌｧｲﾙ情報読込み 
  FD_info_read();                                            // FDｲﾒｰｼﾞﾌｧｲﾙ情報読込み 

//Track_path_Generate(File_Name, Track_cnt);                 // ﾊﾟｽ+差分ﾄﾗｯｸﾌｧｲﾙ名生成
  Track_path_Generate();                                     // ﾊﾟｽ+差分ﾄﾗｯｸﾌｧｲﾙ名生成
//Serial.print(F("Track_path : "));Serial.println(Track_path); // debug

  if (SD.exists(Track_path) == true) {
    Track_flg = true;                                        // ﾄﾗｯｸﾌｧｲﾙがあるか？
  }

//Insert_Edit_Str("/EMU/VM/TRACK.BIN");
  strcpy_P(Edit_Str, pgm_read_word(&(Str_Fixed_path[20])));
  Insert_OUTPUT_path(Edit_Str);
//Serial.print(F("OUTPUT_path : "));Serial.println(OUTPUT_path); // debug

  // ﾌｧｲﾙがある場合は、そのﾌｧｲﾙを削除
  if (SD.exists(OUTPUT_path) == true) {
    SD.remove(OUTPUT_path);
  }
  Zero_OUTPUT_path_create();                                 // 空のﾌｧｲﾙを作る(Path_String)

  for ( Block_cnt = 0 ; Block_cnt <= 3 ; Block_cnt++ ) {
    if (Track_flg == true) {
      // ｾｸﾀﾌｧｲﾙを4つ読込み
      for ( int cnt = 0 ; cnt <= 3 ; cnt++ ) {
        Sector_num = Block_cnt * 4 + cnt + 1;
        Sector_cnt = Sector_num;
        File Input_File = SD.open(Track_path, FILE_READ);
        if (Input_File == false) {
          Error_MSG_File_read_open(Track_path);              // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙが読込みﾓｰﾄﾞで開けない)
        }
        File_address = ( Sector_num - 1 ) * 0x100;
        Input_File.seek(File_address);
        Input_File.read(RW_Buffer[cnt], 256);
        if (Input_File == false) {
          delay(3000);
          Input_File.seek(File_address);
          Input_File.read(RW_Buffer[cnt], 256);
          if (Input_File == false) {
            Serial.println(Track_path);
            Error_MSG_System();                              // ｴﾗｰﾒｯｾｰｼﾞ(ｼｽﾃﾑ異常)
          }
        }
        Input_File.close();
      }
    } else {
      for ( int cnt = 0 ; cnt <= 3 ; cnt++ ) {
        Sector_num = Block_cnt * 4 + cnt + 1;
        Sector_cnt = Sector_num;
//      FD_read(Track_cnt, Sector_cnt, TBL_cnt);             // FDｲﾒｰｼﾞﾌｧｨﾙを読込み
        FD_read(cnt);                                        // FDｲﾒｰｼﾞﾌｧｨﾙを読込み
      }
    }
    // ｾｸﾀが4つのﾌﾞﾛｯｸ ( 1024 byte )書込み
    for ( int cnt = 0 ; cnt <= 3 ; cnt++ ) {
      File Output_File = SD.open(OUTPUT_path, FILE_WRITE);
      if (Output_File == false) {
        Serial.println(F("Track_file_copy();"));
        Error_MSG_File_write_open(OUTPUT_path);              // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙが書込みﾓｰﾄﾞで開けない)
      }
      Output_File.write(RW_Buffer[cnt], 256);                // SDｶｰﾄﾞにﾃﾞｰﾀ書込み
      if (Output_File == false) {
        Error_MSG_File_write(OUTPUT_path);                   // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙ書込みができない)
      }
      Output_File.flush();
      Output_File.close();
    }
  }
}


// ﾄﾗｯｸﾌｧｲﾙを作る ---------------------------------------------
//void Track_file_create(char * File_Name, byte Track_cnt) {
void Track_file_create() {
//Serial.println(F("Track_file_create();"));
  unsigned long Sector_num;                                  // File_address計算用ｾｸﾀ番号(1-16)

// /EMU/FD/FDｲﾒｰｼﾞﾌｧｲﾙ名/TRACKnn.BIN
//Track_path_Generate(File_Name, Track_cnt);                 // ﾊﾟｽ+差分ﾄﾗｯｸﾌｧｲﾙ名生成
  Track_path_Generate();                                     // ﾊﾟｽ+差分ﾄﾗｯｸﾌｧｲﾙ名生成
//Serial.print(F("Track_path : "));Serial.println(Track_path); // debug

  // ﾌｧｲﾙがある場合は、そのﾌｧｲﾙを削除
  if (SD.exists(Track_path) == true) {
    SD.remove(Track_path);
  }
  Zero_Track_path_create();                                  // 空のﾌｧｲﾙを作る(Track_path)

  for ( Block_cnt = 0 ; Block_cnt <= 3 ; Block_cnt++ ) {
    // ｾｸﾀﾌｧｲﾙを4つ読込み
    for ( int cnt = 0 ; cnt <= 3 ; cnt++ ) {
      Sector_num = Block_cnt * 4 + cnt + 1;
      Sector_cnt = Sector_num;
//    Sector_path_Generate(Sector_cnt);                      // ﾊﾟｽ+差分ｾｸﾀﾌｧｲﾙ名生成
      Sector_path_Generate();                                // ﾊﾟｽ+差分ｾｸﾀﾌｧｲﾙ名生成
      if (SD.exists(Sector_path) == true) {
        File Input_File = SD.open(Sector_path, FILE_READ);
        if (Input_File == false) {
          Serial.println(F("Track_file_create();"));
          Error_MSG_File_read_open(Sector_path);             // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙが読込みﾓｰﾄﾞで開けない)
        }
        Input_File.read(RW_Buffer[cnt], 256);
        if (Input_File == false) {
          delay(3000);
          Input_File.seek(File_address);
          Input_File.read(RW_Buffer[cnt], 256);
          if (Input_File == false) {
            Serial.println(Sector_path);
            Error_MSG_System();                              // ｴﾗｰﾒｯｾｰｼﾞ(ｼｽﾃﾑ異常)
          }
        }
        Input_File.close();
      } else {
        if (SD.exists(OUTPUT_path) == true) {
          File Input_File2 = SD.open(OUTPUT_path, FILE_READ);
          if (Input_File2 == false) {
            Error_MSG_File_read_open(OUTPUT_path);           // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙが読込みﾓｰﾄﾞで開けない)
          }
          File_address = ( Sector_num - 1 ) * 0x100;
          Input_File2.seek(File_address);
          Input_File2.read(RW_Buffer[cnt], 256);
          if (Input_File2 == false) {
            delay(3000);
            Input_File2.seek(File_address);
            Input_File2.read(RW_Buffer[cnt], 256);
            if (Input_File2 == false) {
              Serial.println(OUTPUT_path);
              Error_MSG_System();                            // ｴﾗｰﾒｯｾｰｼﾞ(ｼｽﾃﾑ異常)
            }
          }
          Input_File2.close();
        } else {
//        FD_info_read(File_Name);                           // FDｲﾒｰｼﾞﾌｧｲﾙ情報読込み 
          FD_info_read();                                    // FDｲﾒｰｼﾞﾌｧｲﾙ情報読込み 
//        FD_read(Track_cnt, Sector_cnt, TBL_cnt);           // FDｲﾒｰｼﾞﾌｧｨﾙを読込み
          FD_read(cnt);                                      // FDｲﾒｰｼﾞﾌｧｨﾙを読込み
        }
      }
    }
    // ｾｸﾀが4つのﾌﾞﾛｯｸ ( 1024 byte )書込み
    for ( int cnt = 0 ; cnt <= 3 ; cnt++ ) {
      File Output_File = SD.open(Track_path, FILE_WRITE);
      if (Output_File == false) {
        Serial.println(F("Track_file_create();"));
        Error_MSG_File_write_open(Track_path);               // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙが書込みﾓｰﾄﾞで開けない)
      }
      Output_File.write(RW_Buffer[cnt], 256);                // SDｶｰﾄﾞにﾃﾞｰﾀ書込み
      if (Output_File == false) {
        Error_MSG_File_write(Track_path);                    // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙ書込みができない)
      }
      Output_File.flush();
      Output_File.close();
    }
  }
}


// ﾄﾗｯｸﾌｧｲﾙが存在するのを確認して、ｾｸﾀﾌｧｲﾙを削除する ---------------------------------------------
void Delete_Sector_file() {
//Serial.println(F("Delete_Sector_file();"));

  if (SD.exists(Track_path) == true) {
    VM_clear_rtn();                                          // /EMU/VM内をｸﾘｱする
  } else {
    Serial.println(Track_path);
    Error_MSG_System();                                      // ｴﾗｰﾒｯｾｰｼﾞ(ｼｽﾃﾑ異常)
  } 
}


// /EMU/VMのｾｸﾀﾌｧｲﾙを削除する ---------------------------------------------
void VM_clear_rtn() {
//Serial.println(F("VM_clear_rtn();"));

  for ( Sector_cnt = 1 ; Sector_cnt <= 16 ; Sector_cnt++ ) {
  //Sector_path_Generate(Sector_cnt);                        // ﾊﾟｽ+差分ｾｸﾀﾌｧｲﾙ名生成
    Sector_path_Generate();                                  // ﾊﾟｽ+差分ｾｸﾀﾌｧｲﾙ名生成

    // ﾌｧｲﾙがある場合は、そのﾌｧｲﾙを削除
    if (SD.exists(Sector_path) == true) {
      SD.remove(Sector_path);
    }
  }
  // "/EMU/VM/TRACK.BIN"がある場合は、そのﾌｧｲﾙを削除
  if (SD.exists(OUTPUT_path) == true) {
    SD.remove(OUTPUT_path);
  }
}


// ﾌｫｰﾏｯﾄ ---------------------------------------------
// SD書込みﾊﾞｯﾌｧｰを0xFFにして、/EMU/FD/FDｲﾒｰｼﾞﾌｧｲﾙ名/にﾄﾗｯｸﾌｧｲﾙを80個作る
//void Format_rtn(char * File_Name) {
void Format_rtn() {
//Serial.println(F("Format_rtn();"));
  int Last_Track;

  FD_info_TBL_NM_read(File_Name);                            // FDｲﾒｰｼﾞﾌｧｲﾙ情報ﾃｰﾌﾞﾙ読込み(名前検索)

  switch (FD_format) {                                       // ｺﾏﾝﾄﾞ種別
  case 1:                                                    // 1:d88(1D 35ﾄﾗｯｸ)
    Last_Track = 34;
    break;
  case 2:                                                    // 2:d88(1D 40ﾄﾗｯｸ)
    Last_Track = 39;
    break;
  case 3:                                                    // 3:d88(2D 80ﾄﾗｯｸ)
    Last_Track = 79;
    break;
  case 5:                                                    // 5:ﾌﾟﾚｰﾝｲﾒｰｼﾞ(1D 35ﾄﾗｯｸ)
    Last_Track = 34;
    break;
  case 6:                                                    // 6:ﾌﾟﾚｰﾝｲﾒｰｼﾞ(1D 40ﾄﾗｯｸ)
    Last_Track = 39;
    break;
  case 7:                                                    // 7:ﾌﾟﾚｰﾝｲﾒｰｼﾞ(2D 80ﾄﾗｯｸ)
    Last_Track = 79;
    break;
  default:
    Serial.print("FD_format = ");Serial.println(FD_format);
    Error_MSG_System();                                      // ｴﾗｰﾒｯｾｰｼﾞ(ｼｽﾃﾑ異常)
  }
//digitalWrite(LED_PIN, HIGH);
  FD_access_rtn(true);                                       // FDｱｸｾｽ(LEDと作動音)

  for ( int i = 0 ; i < 256 ; i++ ) {
    RW_Buffer[0][i] = 0xFF;
  }
  for ( Track_cnt = 0 ; Track_cnt <= Last_Track ; Track_cnt++ ) {

//  Track_path_Generate(File_Name, Track_cnt);               // ﾊﾟｽ+差分ﾄﾗｯｸﾌｧｲﾙ名生成
    Track_path_Generate();                                   // ﾊﾟｽ+差分ﾄﾗｯｸﾌｧｲﾙ名生成
//Serial.print(F("Track_path : "));Serial.println(Track_path); // debug
    // ﾌｧｲﾙがある場合は、そのﾌｧｲﾙを削除
    if (SD.exists(Track_path) == true) {
      SD.remove(Track_path);
    }
    Zero_Track_path_create();                                // 空のﾌｧｲﾙを作る(Track_path)

    File Output_File = SD.open(Track_path, FILE_WRITE);
    if (Output_File == false) {
      Serial.println(F("Format_rtn();"));
      Error_MSG_File_write_open(Track_path);                 // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙが書込みﾓｰﾄﾞで開けない)
    }
    Output_File.write(RW_Buffer[0], 256);                    // ｲﾒｰｼﾞﾌｧｲﾙ書込み
    if (Output_File == false) {
      Error_MSG_File_write(Track_path);                      // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙ書込みができない)
    }
    Output_File.close();
  }
//digitalWrite(LED_PIN, LOW);
  FD_access_rtn(false);                                      // FDｱｸｾｽ(LEDと作動音)
//Serial.println(F("Format_rtn(end);"));
}


/* ｸｲｯｸ･ﾌｫｰﾏｯﾄ ---------------------------------------------
// /EMU/FD/FDｲﾒｰｼﾞﾌｧｲﾙ名/にﾃﾞｨﾚｸﾄﾘやFATの入ったﾄﾗｯｸﾌｧｲﾙを1個作る
//void Quick_Format_rtn(char * File_Name) {
void Quick_Format_rtn() {
//Serial.println(F("Quick_Format_rtn();"));

//digitalWrite(LED_PIN, HIGH);
  FD_access_rtn(true);                                       // FDｱｸｾｽ(LEDと作動音)

  for ( int i = 0 ; i < 256 ; i++ ) {
    RW_Buffer[0][i] = 0xFF;
    RW_Buffer[1][i] = 0x00;
    RW_Buffer[2][i] = pgm_read_byte_near(N60_FAT + i);       // 1byte読み込み
    RW_Buffer[3][i] = pgm_read_byte_near(N_FAT + i);         // 1byte読み込み
  }
//Serial.println(F("Format_rtn();"));
  FD_info_TBL_NM_read(File_Name);                            // FDｲﾒｰｼﾞﾌｧｲﾙ情報ﾃｰﾌﾞﾙ読込み(名前検索)

//(1D 35ﾄﾗｯｸ)(1D 40ﾄﾗｯｸ)を「N60-拡張BASIC」で書込めるようにｸｲｯｸ･ﾌｫｰﾏｯﾄ
//if ((FD_format == 1) || (FD_format == 2) || (FD_format == 5) || (FD_format == 6)) {
//(1D 35ﾄﾗｯｸ)を「N60-拡張BASIC」で書込めるようにｸｲｯｸ･ﾌｫｰﾏｯﾄ
  if ((FD_format == 1) || (FD_format == 5)) {
    Track_cnt = 18;
//  Track_path_Generate(File_Name, Track_cnt);               // ﾊﾟｽ+差分ﾄﾗｯｸﾌｧｲﾙ名生成
    Track_path_Generate();                                   // ﾊﾟｽ+差分ﾄﾗｯｸﾌｧｲﾙ名生成
    if (SD.exists(Track_path) == true) {                     // ﾌｧｲﾙがある場合は、そのﾌｧｲﾙを削除
      SD.remove(Track_path);
    }
    Zero_Track_path_create();                                // 空のﾌｧｲﾙを作る(Track_path)
    File Output_File = SD.open(Track_path, FILE_WRITE);
    if (Output_File == false) {
      Serial.println(F("Quick_Format_rtn();"));
      Error_MSG_File_write_open(Track_path);                 // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙが書込みﾓｰﾄﾞで開けない)
    }
    for ( Sector_cnt = 1 ; Sector_cnt <= 16 ; Sector_cnt++ ) {
      if ((Sector_cnt >= 1) && (Sector_cnt <= 12)) {
        Output_File.write(RW_Buffer[0], 256);                // ｲﾒｰｼﾞﾌｧｲﾙ書込み
      } else if (Sector_cnt == 13) {
        Output_File.write(RW_Buffer[1], 256);                // ｲﾒｰｼﾞﾌｧｲﾙ書込み
      } else if (Sector_cnt >= 14) {
        Output_File.write(RW_Buffer[2], 256);                // ｲﾒｰｼﾞﾌｧｲﾙ書込み
      }
      if (Output_File == false) {
        Error_MSG_File_write(Track_path);                    // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙ書込みができない)
      }
    }
    Output_File.close();
//(2D 80ﾄﾗｯｸ)を「N-BASIC(DISK BASIC)」で書込めるようにｸｲｯｸ･ﾌｫｰﾏｯﾄ
//} else if ((FD_format == 3) || (FD_format == 7)) {
//(1D 40ﾄﾗｯｸ)(2D 80ﾄﾗｯｸ)を「N-BASIC(DISK BASIC)」で書込めるようにｸｲｯｸ･ﾌｫｰﾏｯﾄ
  } else if ((FD_format == 2) || (FD_format == 3) || (FD_format == 6) || (FD_format == 7)) {
    Track_cnt = 37;
//  Track_path_Generate(File_Name, Track_cnt);               // ﾊﾟｽ+差分ﾄﾗｯｸﾌｧｲﾙ名生成
    Track_path_Generate();                                   // ﾊﾟｽ+差分ﾄﾗｯｸﾌｧｲﾙ名生成
    if (SD.exists(Track_path) == true) {                     // ﾌｧｲﾙがある場合は、そのﾌｧｲﾙを削除
      SD.remove(Track_path);
    }
    Zero_Track_path_create();                                // 空のﾌｧｲﾙを作る(Track_path)
    File Output_File2 = SD.open(Track_path, FILE_WRITE);
    if (Output_File2 == false) {
      Serial.println(F("Quick_Format_rtn();"));
      Error_MSG_File_write_open(Track_path);                 // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙが書込みﾓｰﾄﾞで開けない)
    }
    for ( Sector_cnt = 1 ; Sector_cnt <= 16 ; Sector_cnt++ ) {
      if ((Sector_cnt >= 1) && (Sector_cnt <= 12)) {
        Output_File2.write(RW_Buffer[0], 256);               // ｲﾒｰｼﾞﾌｧｲﾙ書込み
      } else if (Sector_cnt == 13) {
        Output_File2.write(RW_Buffer[1], 256);               // ｲﾒｰｼﾞﾌｧｲﾙ書込み
      } else if (Sector_cnt >= 14) {
        Output_File2.write(RW_Buffer[3], 256);               // ｲﾒｰｼﾞﾌｧｲﾙ書込み
      }
      if (Output_File2 == false) {
        Error_MSG_File_write(Track_path);                    // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙ書込みができない)
      }
    }
    Output_File2.close();
  }
//digitalWrite(LED_PIN, LOW);
  FD_access_rtn(false);                                      // FDｱｸｾｽ(LEDと作動音)
//Serial.println(F("Format_rtn(end);"));
}
*/

// root内のﾃﾞｨﾚｸﾄﾘとﾌｧｲﾙを表示(ｼﾘｱﾙ) ---------------------------------------------
void Serial_root_Path_List() {
//Serial.println("Serial_root_Path_List();");
  char * root_pash = "/\0";
//Serial.print(F("root_pash = "));Serial.println(root_pash);
  S_line_asterisk();
//Serial.println(F("********************************"));
  Serial.println(F("* SDｶｰﾄﾞ ﾉ ﾌｫﾙﾀﾞｰ(ﾌｧｲﾙ) (byte)   *"));
  Serial.println(F("* ( [SYSTEM~1] ﾀﾞｹﾅﾗ ｶﾗﾃﾞｽ｡ )    *"));
  S_line_asterisk();

  File Target_Holder = SD.open(root_pash);                   // ﾃﾞｨﾚｸﾄﾘのﾌｧｲﾙにｱｸｾｽ
  while(true) {
    File Input_File = Target_Holder.openNextFile();          // ﾃﾞｨﾚｸﾄﾘやﾌｧｲﾙを順にｵｰﾌﾟﾝする
    if (Input_File == false) {                               // これ以上ﾌｧｲﾙがない場合
      break;
    }
//  File_Name = Input_File.name();
    Insert_File_Name(Input_File.name());
    Serial.print(File_Name);
    String_length(File_Name);                                // 文字列の長さを求める
    Space_print(File_Name);                                  // 空白で文字列の長さを揃える
    Serial.print(F(" ( "));
    File_Size = Input_File.size();
    Serial.print(File_Size);
    Serial.print(F(" byte ) "));
    if (Input_File.isDirectory()) {                          //ﾃﾞｨﾚｸﾄﾘの場合
      Serial.print(F("ﾌｫﾙﾀﾞｰ"));
    }
    Serial.println();
  }
}


// root内のﾃﾞｨﾚｸﾄﾘとﾌｧｲﾙを表示(ﾀｯﾁｸﾘｰﾝ) ---------------------------------------------
void Touch_root_Path_List() {
//Serial.println("Touch_root_Path_List();");
  char * root_pash = "/\0";
  int cnt = 0;

//Serial.println(F("********************************"));
//Serial.println(F("* SDｶｰﾄﾞ ﾉ ﾌｫﾙﾀﾞｰ(ﾌｧｲﾙ) (byte)   *"));
//Serial.println(F("* ( [SYSTEM~1] ﾀﾞｹﾅﾗ ｶﾗﾃﾞｽ｡ )    *"));
//Serial.println(F("********************************"));
//Insert_Edit_Str(S_LINE_AST);
  strcpy_P(Edit_Str, pgm_read_word(&(Str_root_list_header[0])));
  ANK_print(Edit_Str, 5, 12 * 0 + 40, 1, BLACK);             // ﾘｽﾄ欄に印字(ANK)
  strcpy_P(Edit_Str, pgm_read_word(&(Str_root_list_header[1])));
  ANK_print(Edit_Str, 5, 12 * 1 + 40, 1, BLACK);             // ﾘｽﾄ欄に印字(ANK)
  strcpy_P(Edit_Str, pgm_read_word(&(Str_root_list_header[2])));
  ANK_print(Edit_Str, 5, 12 * 2 + 40, 1, BLACK);             // ﾘｽﾄ欄に印字(ANK)
  strcpy_P(Edit_Str, pgm_read_word(&(Str_root_list_header[0])));
  ANK_print(Edit_Str, 5, 12 * 3 + 40, 1, BLACK);             // ﾘｽﾄ欄に印字(ANK)

  File Target_Holder = SD.open(root_pash);                   // ﾃﾞｨﾚｸﾄﾘのﾌｧｲﾙにｱｸｾｽ
  for ( cnt = 4 ; cnt < 16 ; cnt++ ) {
    File Input_File = Target_Holder.openNextFile();          // ﾃﾞｨﾚｸﾄﾘやﾌｧｲﾙを順にｵｰﾌﾟﾝする
    if (Input_File == false) {                               // これ以上ﾌｧｲﾙがない場合
      break;
    }
    Insert_Edit_Str(Input_File.name());
//  Connect_Edit_Str(" ( ");                                 // Edit_Strに文字列を連結する
    strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_string[0])));
    Connect_Edit_Str(Short_Str);                             // Edit_Strに文字列を連結する
    File_Size = Input_File.size();
    DEC_Str_conversion(File_Size);                           // 数値を文字列に変換する
    Connect_Edit_Str(DEC_Str);                               // Edit_Strに文字列を連結する
//  Connect_Edit_Str(" byte ) ");                            // Edit_Strに文字列を連結する
    strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_string[1])));
    Connect_Edit_Str(Short_Str);                             // Edit_Strに文字列を連結する
    if (Input_File.isDirectory()) {                          // ﾃﾞｨﾚｸﾄﾘの場合
//    Connect_Edit_Str("ﾌｫﾙﾀﾞｰ");                             // Edit_Strに文字列を連結する
      strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_string[2])));
      Connect_Edit_Str(Short_Str);                           // Edit_Strに文字列を連結する
    }
    ANK_print(Edit_Str, 5, 12 * cnt + 40, 1, BLACK);         // ﾘｽﾄ欄に印字(ANK)
  }
}


// ﾃﾞｨﾚｸﾄﾘを作成 ---------------------------------------------
void Directory_making_rtn() {
//Serial.println("Directory_making_rtn();");

  // FDｲﾒｰｼﾞﾌｧｲﾙ用ﾃﾞｨﾚｸﾄﾘを作成
//SD.mkdir("/FD_IN");                                        // ﾃﾞｨﾚｸﾄﾘの作成
  strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_path[0])));
  SD.mkdir(Short_Str);                                       // ﾃﾞｨﾚｸﾄﾘの作成

  // FDｲﾒｰｼﾞﾌｧｲﾙを取出すﾃﾞｨﾚｸﾄﾘを作成
//SD.mkdir("/FD_OUT");                                       // ﾃﾞｨﾚｸﾄﾘの作成
  strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_path[1])));
  SD.mkdir(Short_Str);                                       // ﾃﾞｨﾚｸﾄﾘの作成

  // ｼｽﾃﾑが使うﾃﾞｨﾚｸﾄﾘを作成
//SD.mkdir("/EMU");                                          // ﾃﾞｨﾚｸﾄﾘの作成
  strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_path[2])));
  SD.mkdir(Short_Str);                                       // ﾃﾞｨﾚｸﾄﾘの作成

  // 設定情報ﾃﾞｨﾚｸﾄﾘを作成
//SD.mkdir("/EMU/CONFIG");                                   // ﾃﾞｨﾚｸﾄﾘの作成
  strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_path[3])));
  SD.mkdir(Short_Str);                                       // ﾃﾞｨﾚｸﾄﾘの作成

  // FDｲﾒｰｼﾞﾌｧｲﾙの情報ﾃﾞｨﾚｸﾄﾘを作成
//SD.mkdir("/EMU/CONFIG/FD");                                // ﾃﾞｨﾚｸﾄﾘの作成
  strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_path[4])));
  SD.mkdir(Short_Str);                                       // ﾃﾞｨﾚｸﾄﾘの作成

  // 更新されたｾｸﾀ(ｾｸﾀﾌｧｲﾙ)用のﾃﾞｨﾚｸﾄﾘを作成
//SD.mkdir("/EMU/VM");                                       // ﾃﾞｨﾚｸﾄﾘの作成
  strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_path[5])));
  SD.mkdir(Short_Str);                                       // ﾃﾞｨﾚｸﾄﾘの作成

  // 更新されたﾄﾗｯｸ(ﾄﾗｯｸﾌｧｲﾙ)用のﾃﾞｨﾚｸﾄﾘを作成
//SD.mkdir("/EMU/FD");                                       // ﾃﾞｨﾚｸﾄﾘの作成
  strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_path[6])));
  SD.mkdir(Short_Str);                                       // ﾃﾞｨﾚｸﾄﾘの作成

  // 出力処理で使うD88のﾍｯﾀﾞﾌｧｲﾙ用ﾃﾞｨﾚｸﾄﾘを作成
//SD.mkdir("/EMU/D88");                                      // ﾃﾞｨﾚｸﾄﾘの作成
  strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_path[7])));
  SD.mkdir(Short_Str);                                       // ﾃﾞｨﾚｸﾄﾘの作成
}


// /FD_IN内のﾌｧｲﾙﾘｽﾄ作成 ---------------------------------------------
void File_TBL_create() {
//Serial.println(F("File_TBL_create();"));
  File_count = 0;                                            // ﾌｧｲﾙ数

  Initialize_File_TBL();                                     // File_TBL[]を初期化する
  
//Insert_Path_String("/FD_IN");
  strcpy_P(Path_String, pgm_read_word(&(Str_Fixed_path[0])));

  File Target_Holder = SD.open(Path_String);

  while(true) {
    File Input_File = Target_Holder.openNextFile();
    if (Input_File == false) {                               // これ以上ﾌｧｲﾙがない場合
      if (File_count == 0) {                                 // ﾌｧｲﾙがない
        Warning_MSG_FD_img();                                // 警告ﾒｯｾｰｼﾞ(FDｲﾒｰｼﾞﾌｧｲﾙが読込みできない)
      }
      break;
    }
    if (File_count > MAX_FILE) {                             // ﾌｧｲﾙが最大件数になった場合
      Warning_MSG_Max_file();                                // 警告ﾒｯｾｰｼﾞ([FD_IN]ﾌｫﾙﾀﾞｰの最大ﾌｧｲﾙ数ｵｰﾊﾞｰ)
      break;
    }
    if (Input_File.isDirectory() == false) {                 // ﾃﾞｨﾚｸﾄﾘではない場合
      Insert_File_TBL(Input_File.name(), File_count);        // File_TBL[]に文字列を挿入する
      File_count++;                                          // ﾌｧｲﾙ数
    }
  }
  Target_Holder.close();

  File_TBL_sort();                                           // ﾌｧｲﾙﾘｽﾄをASCiiｺｰﾄﾞで昇順にする

  FD_info_TBL_create();                                      // FDｲﾒｰｼﾞﾌｧｲﾙ情報ﾃｰﾌﾞﾙ作成

  // ｼｽﾃﾑ的には使わない仕様になったけど、このﾃｷｽﾄﾌｧｲﾙは一覧でわかりやすいので残しておく
  File_TBL_save();                                           // SDｶｰﾄﾞにﾌｧｲﾙﾘｽﾄ書込み
}


// /EMU/CONFIG/FD内のﾌｧｲﾙﾘｽﾄ作成 ---------------------------------------------
void File_TBL_create2() {
//Serial.println(F("File_TBL_create2();"));
  File_count = 0;                                            // ﾌｧｲﾙ数

  Initialize_File_TBL();                                     // File_TBL[]を初期化する
  
//Insert_Path_String("/EMU/CONFIG/FD");
  strcpy_P(Path_String, pgm_read_word(&(Str_Fixed_path[4])));

  File Target_Holder = SD.open(Path_String);

  while(true) {
    File Input_File = Target_Holder.openNextFile();
    if (Input_File == false) {                               // これ以上ﾌｧｲﾙがない場合
      break;
    }
    if (File_count > MAX_FILE) {                             // ﾌｧｲﾙが最大件数になった場合
      break;
    }
    if (Input_File.isDirectory() == false) {                 // ﾃﾞｨﾚｸﾄﾘではない場合
      Insert_File_TBL(Input_File.name(), File_count);        // File_TBL[]に文字列を挿入する
      File_count++;                                          // ﾌｧｲﾙ数
    }
  }
  Target_Holder.close();

  File_TBL_sort();                                           // ﾌｧｲﾙﾘｽﾄをASCiiｺｰﾄﾞで昇順にする
}


// ﾌｧｲﾙﾘｽﾄをASCiiｺｰﾄﾞで昇順にする ---------------------------------------------
void File_TBL_sort() {
//Serial.println(F("File_TBL_sort();"));
// ﾊﾞﾌﾞﾙｿｰﾄ(基本交換法)でする
  if (File_count < 2) {
    return;
  }
  char File_Name_a[13];                                      // FDｲﾒｰｼﾞﾌｧｲﾙ名比較用a
  char File_Name_b[13];                                      // FDｲﾒｰｼﾞﾌｧｲﾙ名比較用b
  int LP1_cnt, LP2_cnt;                                      // 繰り返し回数
  int cnt, i, j, k, l;
  int a_len, b_len, len;
  byte byte_a, byte_b;
  LP1_cnt = File_count - 2;
  for ( i = 0 ; i <= LP1_cnt ; i++ ){
    LP2_cnt = LP1_cnt - i;
    for ( j = 0 ; j <= LP2_cnt ; j++ ){
      k = j + 1;
      // 文字ｺｰﾄﾞで比較する
      String_length(File_TBL[j]);
      a_len = Str_length;
      String_length(File_TBL[k]);
      b_len = Str_length;
      if ((a_len == 0) || (b_len == 0)) {
        break;
      }
      if (a_len < b_len) {
        len = a_len;
      } else {
        len = b_len;
      }
      for ( l = 0 ; l <= len ; l++ ) {
        byte_a = byte(File_TBL[j][l]);
        byte_b = byte(File_TBL[k][l]);
        if (byte_a > byte_b) {
          for ( cnt = 0 ; cnt <= 12 ; cnt++ ){
            File_Name_a[cnt] = File_TBL[j][cnt];
            File_Name_b[cnt] = File_TBL[k][cnt];
          }
          Insert_File_TBL(File_Name_b, j);                   // File_TBL[]に文字列を挿入する
          Insert_File_TBL(File_Name_a, k);                   // File_TBL[]に文字列を挿入する
          break;
        } else if (byte_a < byte_b) {
          break;
        }
      }
    }
  }
}


// SDｶｰﾄﾞにﾌｧｲﾙﾘｽﾄ書込み ---------------------------------------------
void File_TBL_save() {
//Serial.println(F("File_TBL_save();"));
  // ﾌｧｲﾙがある場合は、そのﾌｧｲﾙを削除
  // /EMU/CONFIG/FD_IMG.LST <- 登録してあるFDｲﾒｰｼﾞﾌｧｲﾙの一覧(MAX:64)
//Insert_Path_String("/EMU/CONFIG/FD_IMG.LST");
  strcpy_P(Path_String, pgm_read_word(&(Str_Fixed_path[14])));
  if (SD.exists(Path_String) == true) {
    SD.remove(Path_String);
  }
  if (File_count == 0) {
    return;
  }
  // 空のﾌｧｲﾙを作る(Path_String)
  Zero_Path_String_create();

  // 空のﾌｧｲﾙに追加書き
  while(true) {
    File Output_File = SD.open(Path_String, FILE_WRITE);
    if (Output_File == false) {
      Serial.println(F("File_TBL_save();"));
      Error_MSG_File_write_open(Path_String);                // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙが書込みﾓｰﾄﾞで開けない)
    } else {
      for ( int i = 0 ; i < File_count ; i++ ) {
        Insert_Wrt_FD_Name(File_TBL[i]);                     // 書込み用FDｲﾒｰｼﾞﾌｧｲﾙ名 + '\n'
        Output_File.write(Wrt_FD_Name);                      // SDｶｰﾄﾞにﾃﾞｰﾀ書込み
        if (Output_File == false) {
          Error_MSG_File_write(Path_String);                 // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙ書込みができない)
        }
      }
      Output_File.close();
      break;
    }
  }
}


// FDｲﾒｰｼﾞﾌｧｲﾙ情報作成(一括) ---------------------------------------------
void FD_info_batch() {
//Serial.println(F("FD_info_batch();"));
//Insert_Path_String("/FD_IN");
  strcpy_P(Path_String, pgm_read_word(&(Str_Fixed_path[0])));
  File Target_Holder = SD.open(Path_String);

  while(true) {
    File Input_File = Target_Holder.openNextFile();
    if (Input_File == false) {                               // これ以上ﾌｧｲﾙがない場合
      break;
    }
    if (Input_File.isDirectory() == false) {                 // ﾃﾞｨﾚｸﾄﾘではない場合
      Insert_File_Name(Input_File.name());                   // File_Name(8+'.'+3)
//Serial.print(F("File_Name : "));Serial.println(File_Name);   // debug
      File_Size = Input_File.size();
//    FD_info_create(File_Name, File_Size);                  // 新しいFDｲﾒｰｼﾞﾌｧｲﾙ関連作成
      FD_info_create();                                      // 新しいFDｲﾒｰｼﾞﾌｧｲﾙ関連作成
    }
  }
}


// 新しいFDｲﾒｰｼﾞﾌｧｲﾙ関連作成 ---------------------------------------------
// 新しいFDｲﾒｰｼﾞﾌｧｲﾙがあったら、
// ﾃﾞｨﾚｸﾄﾘ作成 /EMU/FD/FDｲﾒｰｼﾞﾌｧｲﾙ名/TRACKnn.BIN
// ﾌｧｲﾙ作成 /EMU/CONFIG/FD/FDｲﾒｰｼﾞﾌｧｲﾙ名 <- 0: ﾌｫｰﾏｯﾄ, 1: 更新区分, 2: 出力区分
// この2つを用意する
//void FD_info_create(char * File_Name, unsigned long File_Size) {
void FD_info_create() {
//Serial.println(F("FD_info_create();"));

  if (File_Name[0] == '*') {
    return;
  }
//Insert_Edit_Str("/EMU/FD/");
  strcpy_P(Edit_Str, pgm_read_word(&(Str_Fixed_path[12])));
  Connect_Edit_Str(File_Name);                               // Edit_Strに文字列を連結する
  Insert_Path_String(Edit_Str);
//Serial.print(F("Path_String(A) : "));Serial.println(Path_String);// debug

  if (SD.exists(Path_String) == false) {                     // ﾃﾞｨﾚｸﾄﾘがない場合は、そのﾃﾞｨﾚｸﾄﾘの作成
    SD.mkdir(Path_String);                                   // ﾃﾞｨﾚｸﾄﾘの作成
  }

//Insert_Edit_Str("/EMU/CONFIG/FD/");
  strcpy_P(Edit_Str, pgm_read_word(&(Str_Fixed_path[11])));
  Connect_Edit_Str(File_Name);                               // Edit_Strに文字列を連結する
  Insert_Path_String(Edit_Str);
//Serial.print(F("Path_String(B) : "));Serial.println(Path_String);// debug

  // ﾌｧｲﾙがない場合は、そのﾌｧｲﾙを作る
  if (SD.exists(Path_String) == false) {

    if (File_Size == 153008) {
      Insert_FD_info("1100");                                // 1:d88(1D 35ﾄﾗｯｸ)
    } else if (File_Size == 174768) {
      Insert_FD_info("2100");                                // 2:d88(1D 40ﾄﾗｯｸ)
    } else if (File_Size == 348848) {
      Insert_FD_info("3100");                                // 3:d88(2D)
    } else if (File_Size == 143360) {
      Insert_FD_info("5100");                                // 5:ﾌﾟﾚｰﾝｲﾒｰｼﾞ(1D 35ﾄﾗｯｸ)
    } else if (File_Size == 163840) {
      Insert_FD_info("6100");                                // 6:ﾌﾟﾚｰﾝｲﾒｰｼﾞ(1D 40ﾄﾗｯｸ)
    } else if (File_Size == 327680) {
      Insert_FD_info("7100");                                // 7:ﾌﾟﾚｰﾝｲﾒｰｼﾞ(2D)
    } else {
      Insert_FD_info("9900");                                // 9:対象外
    }
    // 空のﾌｧｲﾙを作る(Path_String)
    Zero_Path_String_create();
  
    digitalWrite(LED_PIN, HIGH);

    // 空のﾌｧｲﾙに追加書き
    File Output_File = SD.open(Path_String, FILE_WRITE);
    if (Output_File == false) {
      Serial.println(F("FD_info_create();"));
      Error_MSG_File_write_open(Path_String);                // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙが書込みﾓｰﾄﾞで開けない)
    }
    Output_File.print(FD_info);                              // SDｶｰﾄﾞにﾃﾞｰﾀ書込み
    if (Output_File == false) {
      Error_MSG_File_write(Path_String);                     // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙ書込みができない)
    }
    Output_File.close();

    digitalWrite(LED_PIN, LOW);
    
//Serial.print(F("sysyem create : "));
//Serial.println(File_Name);
  }
}


// FDｲﾒｰｼﾞﾌｧｲﾙ情報読込み ---------------------------------------------
//void FD_info_read(char * File_Name) {
void FD_info_read() {
//Serial.println(F("FD_info_read();"));
  FD_format  = 9;                                            // ﾌｫｰﾏｯﾄ区分(9:対象外)
  FD_protect = 9;                                            // 書込み保護(ﾗｲﾄﾌﾟﾛﾃｸﾄ)(0:なし, 1:あり)
  FD_update  = 9;                                            // 更新区分(0:なし, 1:あり)
  FD_output  = 9;                                            // 出力区分(0:なし, 1:あり)
  if (File_Name[0] == '*') {
    return;
  }
//Insert_Edit_Str("/EMU/CONFIG/FD/");
  strcpy_P(Edit_Str, pgm_read_word(&(Str_Fixed_path[11])));
  Connect_Edit_Str(File_Name);                               // Edit_Strに文字列を連結する
  Insert_Path_String(Edit_Str);

  digitalWrite(LED_PIN, HIGH);

  File Input_File = SD.open(Path_String, FILE_READ);
  if (Input_File == false) {
    Error_MSG_File_read_open(Path_String);                   // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙが読込みﾓｰﾄﾞで開けない)
  } else {
    for ( int i = 0 ; i < 4 ; i++ ) {
      FD_info[i] = Input_File.read();                        // ﾃﾞｰﾀ読込み
    }
    Input_File.close();

    digitalWrite(LED_PIN, LOW);
  }
  // ﾌｫｰﾏｯﾄ区分(1:d88(1D), 2:d88(2D), 3:ﾌﾟﾚｰﾝｲﾒｰｼﾞ, 9:対象外)
  FD_format  = byte(FD_info[0]) - 0x30;              // Asciiｺｰﾄﾞは'0'～'9'が0x30～0x39になっている

  // 書込み保護(ﾗｲﾄﾌﾟﾛﾃｸﾄ)(0:なし, 1:あり)
  FD_protect = byte(FD_info[1]) - 0x30;              // Asciiｺｰﾄﾞは'0'～'9'が0x30～0x39になっている

  // 更新区分(0:なし, 1:あり)
  FD_update  = byte(FD_info[2]) - 0x30;              // Asciiｺｰﾄﾞは'0'～'9'が0x30～0x39になっている

  // 出力区分(0:なし, 1:あり)
  FD_output  = byte(FD_info[3]) - 0x30;              // Asciiｺｰﾄﾞは'0'～'9'が0x30～0x39になっている
}


// FDｲﾒｰｼﾞﾌｧｲﾙ情報を更新 ---------------------------------------------
  // (ｲﾒｰｼﾞﾌｧｲﾙ名, 更新区分, 出力区分)、
//void FD_info_rewrite(char * File_Name, byte _protect, byte _update, byte _output) {
void FD_info_rewrite(byte _protect, byte _update, byte _output) {
//Serial.println(F("FD_info_rewrite();"));

  if (File_Name[0] == '*') {
    return;
  }
  digitalWrite(LED_PIN, HIGH);
  
//FD_info_read(File_Name);                                   // FDｲﾒｰｼﾞﾌｧｲﾙ情報読込み
  FD_info_read();                                            // FDｲﾒｰｼﾞﾌｧｲﾙ情報読込み
//Serial.print(FD_info);
//Serial.print(F(" -> "));

  if (_protect < 9) {
    FD_info[1] = _protect + 0x30;                    // Asciiｺｰﾄﾞは'0'～'9'が0x30～0x39になっている
  }
  if (_update  < 9) {
    FD_info[2] = _update  + 0x30;                    // Asciiｺｰﾄﾞは'0'～'9'が0x30～0x39になっている
  }
  if (_output  < 9) {
    FD_info[3] = _output  + 0x30;                    // Asciiｺｰﾄﾞは'0'～'9'が0x30～0x39になっている
  }
//Serial.println(FD_info);

//Insert_Edit_Str("/EMU/CONFIG/FD/");
  strcpy_P(Edit_Str, pgm_read_word(&(Str_Fixed_path[11])));
  Connect_Edit_Str(File_Name);                               // Edit_Strに文字列を連結する
  Insert_Path_String(Edit_Str);
//Serial.println(Path_String);

  // ﾌｧｲﾙがある場合は、そのﾌｧｲﾙを削除
  if (SD.exists(Path_String) == true) {
    SD.remove(Path_String);
  }
  // 空のﾌｧｲﾙを作る(Path_String)
  Zero_Path_String_create();
  
  // 空のﾌｧｲﾙに追加書き
  File Output_File = SD.open(Path_String, FILE_WRITE);
  if (Output_File == false) {
    Serial.println(F("FD_info_rewrite();"));
    Error_MSG_File_write_open(Path_String);                  // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙが書込みﾓｰﾄﾞで開けない)
  }
  Output_File.println(FD_info);                              // SDｶｰﾄﾞにﾃﾞｰﾀ書込み
  if (Output_File == false) {
    Error_MSG_File_write(Path_String);                       // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙ書込みができない)
  }
  Output_File.close();

  digitalWrite(LED_PIN, LOW);
}


// FDｲﾒｰｼﾞﾌｧｲﾙ情報ﾃｰﾌﾞﾙ作成 ---------------------------------------------
void FD_info_TBL_create() {
//Serial.println(F("FD_info_TBL_set();"));

  char WK_char;
  
  digitalWrite(LED_PIN, HIGH);

  for ( int cnt = 0 ; cnt < File_count ; cnt++ ) {
//  Insert_Edit_Str("/EMU/CONFIG/FD/");
    strcpy_P(Edit_Str, pgm_read_word(&(Str_Fixed_path[11])));
    Connect_Edit_Str(File_TBL[cnt]);                         // Edit_Strに文字列を連結する
    Insert_Path_String(Edit_Str);

    File Input_File = SD.open(Path_String, FILE_READ);
    if (Input_File == false) {
      Error_MSG_File_read_open(Path_String);                 // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙが読込みﾓｰﾄﾞで開けない)
    } else {
      for ( int i = 0 ; i < 4 ; i++ ) {
        WK_char = Input_File.read();                         // ﾃﾞｰﾀ読込み
        FD_info_TBL[cnt][i] = byte(WK_char) - 0x30;
      }
    }
    Input_File.close();
  }
  digitalWrite(LED_PIN, LOW);
}


// FDｲﾒｰｼﾞﾌｧｲﾙ情報ﾃｰﾌﾞﾙ読込み ---------------------------------------------
void FD_info_TBL_read(int cnt) {
//Serial.println(F("FD_info_TBL_read();"));
  FD_format  = 9;                                            // ﾌｫｰﾏｯﾄ区分(9:対象外)
  FD_protect = 9;                                            // 書込み保護(ﾗｲﾄﾌﾟﾛﾃｸﾄ)(0:なし, 1:あり)
  FD_update  = 9;                                            // 更新区分(0:なし, 1:あり)
  FD_output  = 9;                                            // 出力区分(0:なし, 1:あり)
  if (File_TBL[cnt][0] == '*') {
    return;
  }
  // ﾌｫｰﾏｯﾄ区分(1:d88(1D), 2:d88(2D), 3:ﾌﾟﾚｰﾝｲﾒｰｼﾞ, 9:対象外)
  FD_format  = FD_info_TBL[cnt][0];

  // 書込み保護(ﾗｲﾄﾌﾟﾛﾃｸﾄ)(0:なし, 1:あり)
  FD_protect = FD_info_TBL[cnt][1];

  // 更新区分(0:なし, 1:あり)
  FD_update  = FD_info_TBL[cnt][2];

  // 出力区分(0:なし, 1:あり)
  FD_output  = FD_info_TBL[cnt][3];
}


// FDｲﾒｰｼﾞﾌｧｲﾙ情報ﾃｰﾌﾞﾙ読込み(名前検索) ---------------------------------------------
void FD_info_TBL_NM_read(char * FD_Name) {
//Serial.println(F("FD_info_TBL_NM_read();"));
  FD_format  = 9;                                            // ﾌｫｰﾏｯﾄ区分(9:対象外)
  FD_protect = 9;                                            // 書込み保護(ﾗｲﾄﾌﾟﾛﾃｸﾄ)(0:なし, 1:あり)
  FD_update  = 9;                                            // 更新区分(0:なし, 1:あり)
  FD_output  = 9;                                            // 出力区分(0:なし, 1:あり)
  FD_No      = File_count;                                   // 選択したFile_TBLの番号( 0 ～ File_count )
  if (FD_Name[0] == '*') {
    return;
  }
  for ( int cnt = 0 ; cnt <= File_count ; cnt++ ) {
    String_compareTo(File_TBL[cnt], FD_Name);                // 文字列を文字ｺｰﾄﾞで比較する
    if (Comp_sts == 0) {                                     // 文字列を比較して同じだったら
      FD_format  = FD_info_TBL[cnt][0];                      // ﾌｫｰﾏｯﾄ区分
      FD_protect = FD_info_TBL[cnt][1];                      // 書込み保護(ﾗｲﾄﾌﾟﾛﾃｸﾄ)(0:なし, 1:あり)
      FD_update  = FD_info_TBL[cnt][2];                      // 更新区分(0:なし, 1:あり)
      FD_output  = FD_info_TBL[cnt][3];                      // 出力区分(0:なし, 1:あり)
      FD_No      = cnt;                                      // 選択したFile_TBLの番号( 0 ～ File_count )
      break;
    }
  }
}


// FDｲﾒｰｼﾞﾌｧｲﾙ情報ﾃｰﾌﾞﾙを更新 ---------------------------------------------
  // (ｲﾒｰｼﾞﾌｧｲﾙ名, 更新区分, 出力区分)、
void FD_info_TBL_rewrite(int cnt, byte _protect, byte _update, byte _output) {
//Serial.println(F("FD_info_rewrite();"));

  if (File_TBL[cnt][0] == '*') {
    return;
  }
  // 書込み保護(ﾗｲﾄﾌﾟﾛﾃｸﾄ)(0:なし, 1:あり)
  if (_protect < 9) {
    FD_info_TBL[cnt][1] = _protect;
  }
  // 更新区分(0:なし, 1:あり)
  if (_update  < 9) {
    FD_info_TBL[cnt][2] = _update;
  }
  // 出力区分(0:なし, 1:あり)
  if (_output  < 9) {
    FD_info_TBL[cnt][3] = _output;
  }
}


// ﾄﾞﾗｲﾌﾞにFDｲﾒｰｼﾞ紐づけﾌｧｲﾙ作成(一括) ---------------------------------------------
// /EMU/CONFIG/DRV_FD.USE <- FDｲﾒｰｼﾞﾌｧｲﾙ一覧(4行)(0-3ﾄﾞﾗｲﾌﾞ対応したFDｲﾒｰｼﾞﾌｧｲﾙ名)
void Drv_fd_link_use_bundle() {
//Serial.println(F("Drv_fd_link_use_bundle();"));

  digitalWrite(LED_PIN, HIGH);

//Insert_Path_String("/EMU/CONFIG/DRV_FD.USE");
  strcpy_P(Path_String, pgm_read_word(&(Str_Fixed_path[15])));
  // ﾌｧｲﾙがある場合は、そのﾌｧｲﾙを削除
  if (SD.exists(Path_String) == true) {
    SD.remove(Path_String);
  }
  // 空のﾌｧｲﾙを作る(Path_String)
  Zero_Path_String_create();

  // 空のﾌｧｲﾙに追加書き
  File Output_File = SD.open(Path_String, FILE_WRITE);
  if (Output_File == false) {
    Serial.println(F("Drv_fd_link_use_bundle();"));
    Error_MSG_File_write_open(Path_String);                  // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙが書込みﾓｰﾄﾞで開けない)
  }
  for ( int i = 0 ; i <= 3 ; i++ ) {
    Insert_Wrt_FD_Name(DUMMY_Name);                          // 書込み用FDｲﾒｰｼﾞﾌｧｲﾙ名 + '\n'
    Output_File.write(Wrt_FD_Name);                          // SDｶｰﾄﾞにﾃｷｽﾄ書込み
    if (Output_File == false) {
      Error_MSG_File_write(Path_String);                     // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙ書込みができない)
    }
  }
  Output_File.close();

  digitalWrite(LED_PIN, LOW);
}


// ﾄﾞﾗｲﾌﾞにFDｲﾒｰｼﾞ紐づけﾌｧｲﾙ作成 ---------------------------------------------
// /EMU/CONFIG/DRV_FD.USE <- FDｲﾒｰｼﾞﾌｧｲﾙ一覧(4行)(0-3ﾄﾞﾗｲﾌﾞ対応したFDｲﾒｰｼﾞﾌｧｲﾙ名)
//void Drv_fd_link_crt(char * File_Name, byte Drive_cnt) {
void Drv_fd_link_crt() {
//Serial.println(F("Drv_fd_link_crt();"));

  int i;
  // 前のﾄﾞﾗｲﾌﾞに付いていたﾌｧｲﾙ名を消去
  for ( i = 0 ; i <= 3 ; i++ ) {
//  if (Drv_FD_Name[i] == File_Name) {
    String_compareTo(Drv_FD_Name[i], File_Name);             // 文字列を文字ｺｰﾄﾞで比較する
    if (Comp_sts == 0) {                                     // 文字列を比較して同じだったら
//    Drv_FD_Name[i] = DUMMY_Name;
      Insert_Drv_FD_Name(DUMMY_Name, i);                     // Drv_FD_Name[]に文字列を挿入する
    }
  }
// 対象ﾄﾞﾗｲﾌﾞにFDｲﾒｰｼﾞﾌｧｲﾙ名を紐づけ設定
  Insert_Drv_FD_Name(File_Name, Drive_cnt);                  // Drv_FD_Name[]に文字列を挿入する

//Insert_Path_String("/EMU/CONFIG/DRV_FD.USE");
  strcpy_P(Path_String, pgm_read_word(&(Str_Fixed_path[15])));
  // ﾌｧｲﾙがある場合は、そのﾌｧｲﾙを削除
  if (SD.exists(Path_String) == true) {
        SD.remove(Path_String);
  }
  // 空のﾌｧｲﾙを作る(Path_String)
  Zero_Path_String_create();

  digitalWrite(LED_PIN, HIGH);

  // 空のﾌｧｲﾙに追加書き
  File Output_File = SD.open(Path_String, FILE_WRITE);
  if (Output_File == false) {
    Serial.println(F("Drv_fd_link_crt();"));
    Error_MSG_File_write_open(Path_String);                  // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙが書込みﾓｰﾄﾞで開けない)
  }
  for ( i = 0 ; i <= 3 ; i++ ) {
    Insert_Wrt_FD_Name(Drv_FD_Name[i]);                      // 書込み用FDｲﾒｰｼﾞﾌｧｲﾙ名 + '\n'
    Output_File.write(Wrt_FD_Name);                          // SDｶｰﾄﾞにﾃｷｽﾄ書込み
    if (Output_File == false) {
      Error_MSG_File_write(Path_String);                     // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙ書込みができない)
    }
  }
  Output_File.close();

  digitalWrite(LED_PIN, LOW);
}


// ﾄﾞﾗｲﾌﾞ・FDｲﾒｰｼﾞ紐づけﾌｧｲﾙ読込み ---------------------------------------------
// /EMU/CONFIG/DRV_FD.USE <- FDｲﾒｰｼﾞﾌｧｲﾙ一覧(4行)(0-3ﾄﾞﾗｲﾌﾞ対応したFDｲﾒｰｼﾞﾌｧｲﾙ名)
void Drv_fd_link_load() {
//Serial.println(F("Drv_fd_link_load();"));
  digitalWrite(LED_PIN, HIGH);
  
  Insert_Path_String("/EMU/CONFIG/DRV_FD.USE");
  strcpy_P(Path_String, pgm_read_word(&(Str_Fixed_path[15])));
  File Input_File = SD.open(Path_String, FILE_READ);
  if (Input_File == false) {
    Error_MSG_File_read_open(Path_String);                   // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙが読込みﾓｰﾄﾞで開けない)
  }
  for ( int i = 0 ; i <= 3 ; i++ ) {
    for ( int j = 0 ; j <= 12 ; j++ ) {
      Drv_FD_Name[i][j] = Input_File.read();                 // ﾃﾞｰﾀ読込み
      if (Drv_FD_Name[i][j] == '\n') {
        Drv_FD_Name[i][j] = NULL;
        break;
      }
    }
  }
  Input_File.close();

  digitalWrite(LED_PIN, LOW);
}


// FDｲﾒｰｼﾞﾌｧｲﾙに紐づけされたﾄﾞﾗｲﾌﾞ番号 ---------------------------------------------
//void FD_link_drv(char * File_Name) {
void FD_link_drv() {
//Serial.println(F(" FD_link_drv();"));
// /EMU/CONFIG/DRV_FD.USE <- FDｲﾒｰｼﾞﾌｧｲﾙ一覧(4行)(0-3ﾄﾞﾗｲﾌﾞ対応したFDｲﾒｰｼﾞﾌｧｲﾙ名)

  FD_drv_No = 9;                                             // そのFDｲﾒｰｼﾞﾌｧｲﾙが入ったﾄﾞﾗｲﾌﾞ番号

  if (File_Name[0] == '*') {
    return;
  }
  for ( int i = 0 ; i < 4 ; i++ ) {
    String_compareTo(Drv_FD_Name[i], File_Name);             // 文字列を文字ｺｰﾄﾞで比較する
    if (Comp_sts == 0) {                                     // 文字列を比較して同じだったら
      FD_drv_No = i;
      break;
    }
  }
}


// FDｲﾒｰｼﾞ(d88)を出力 ---------------------------------------------
// 153008 = 0x2b0(ﾍｯﾀﾞ) + 35(ﾄﾗｯｸ数) x 1(面) x 16(ｾｸﾀ/ﾄﾗｯｸ) x (0x10(ｾｸﾀﾍｯﾀﾞ) + 0x100(ｾｸﾀﾃﾞｰﾀ))
// 174768 = 0x2b0(ﾍｯﾀﾞ) + 40(ﾄﾗｯｸ数) x 1(面) x 16(ｾｸﾀ/ﾄﾗｯｸ) x (0x10(ｾｸﾀﾍｯﾀﾞ) + 0x100(ｾｸﾀﾃﾞｰﾀ))
// 348848 = 0x2b0(ﾍｯﾀﾞ) + 40(ﾄﾗｯｸ数) x 2(面) x 16(ｾｸﾀ/ﾄﾗｯｸ) x (0x10(ｾｸﾀﾍｯﾀﾞ) + 0x100(ｾｸﾀﾃﾞｰﾀ))
//void D88_write_rtn(char * File_Name) {
void D88_write_rtn(byte _format) {
//Serial.println(F("D88_write_rtn();"));

  boolean Track_file_flg = false;                            // ﾄﾗｯｸﾌｧｲﾙがあるか
  byte Last_Track;
  if (_format == 1) {
    Last_Track = 34;
  } else if (_format == 2) {
    Last_Track = 39;
  } else if (_format == 3) {
    Last_Track = 79;
  } else {
    Serial.print("FD_format = ");Serial.println(FD_format);
    Error_MSG_System();                                      // ｴﾗｰﾒｯｾｰｼﾞ(ｼｽﾃﾑ異常)
  }
//Insert_Edit_Str("/FD_IN/");
  strcpy_P(Edit_Str, pgm_read_word(&(Str_Fixed_path[8])));
  Connect_Edit_Str(File_Name);                               // Edit_Strに文字列を連結する
  Insert_FD_IN_path(Edit_Str);

//Insert_Edit_Str("/FD_OUT/");
  strcpy_P(Edit_Str, pgm_read_word(&(Str_Fixed_path[10])));
  Connect_Edit_Str(File_Name);                               // Edit_Strに文字列を連結する
  Insert_OUTPUT_path(Edit_Str);

//Insert_Edit_Str("/EMU/D88/");
  strcpy_P(Edit_Str, pgm_read_word(&(Str_Fixed_path[16])));
  Connect_Edit_Str(File_Name);                               // Edit_Strに文字列を連結する
  Insert_Path_String(Edit_Str);

  if (SD.exists(Path_String) == false) {
    D88_headerfile_create1();                                // /EMU/D88/ﾍｯﾀﾞﾌｧｲﾙ生成1
    D88_headerfile_create2();                                // /EMU/D88/ﾍｯﾀﾞﾌｧｲﾙ生成2
  }
  digitalWrite(LED_PIN, HIGH);

  // ﾌｧｲﾙがある場合は、そのﾌｧｲﾙを削除
  if (SD.exists(OUTPUT_path) == true) {
    SD.remove(OUTPUT_path);
  }
  Zero_OUTPUT_path_create();                                 // 空のﾌｧｲﾙを作る(OUTPUT_path)

  D88_header_write_rtn1();                                   // ﾍｯﾀﾞの書込み1(0x2b0)(688byte)
  D88_header_write_rtn2();                                   // ﾍｯﾀﾞの書込み2(0x2b0)(688byte)

  for ( Track_cnt = 0 ; Track_cnt <= Last_Track ; Track_cnt++ ) {
//  Track_path_Generate(File_Name, Track_cnt);               // ﾊﾟｽ+差分ﾄﾗｯｸﾌｧｲﾙ名生成
    Track_path_Generate();                                   // ﾊﾟｽ+差分ﾄﾗｯｸﾌｧｲﾙ名生成
    Track_file_flg = SD.exists(Track_path);                  // ﾄﾗｯｸﾌｧｲﾙがあるか
    for ( Block_cnt = 0 ; Block_cnt <= 3 ; Block_cnt++ ) {
      if (Track_file_flg == true) {
//      Track_file_read(Block_cnt);                          // ﾄﾗｯｸﾌｧｲﾙ読込み
        Track_file_read();                                   // ﾄﾗｯｸﾌｧｲﾙ読込み
      } else {
//      D88_FD_file_read(Track_cnt, Block_cnt);              // FDｲﾒｰｼﾞﾌｧｲﾙ読込み
        D88_FD_file_read();                                  // FDｲﾒｰｼﾞﾌｧｲﾙ読込み
      }
//    D88_FD_OUT_write(Track_cnt, Block_cnt);                // 4つのｾｸﾀのﾌﾞﾛｯｸ ( 1024 byte )書込み
      D88_FD_OUT_write();                                    // 4つのｾｸﾀのﾌﾞﾛｯｸ ( 1024 byte )書込み
    }
//  Processing_progress_rtn(Track_cnt);                      // 処理の進行状況
    Processing_progress_rtn();                               // 処理の進行状況
  }
  digitalWrite(LED_PIN, LOW);
}


// d88ﾍｯﾀﾞﾌｧｲﾙ生成1 ---------------------------------------------
// 153008 = 0x2b0(ﾍｯﾀﾞ) + 35(ﾄﾗｯｸ数) x 1(面) x 16(ｾｸﾀ/ﾄﾗｯｸ) x (0x10(ｾｸﾀﾍｯﾀﾞ) + 0x100(ｾｸﾀﾃﾞｰﾀ))
// 174768 = 0x2b0(ﾍｯﾀﾞ) + 40(ﾄﾗｯｸ数) x 1(面) x 16(ｾｸﾀ/ﾄﾗｯｸ) x (0x10(ｾｸﾀﾍｯﾀﾞ) + 0x100(ｾｸﾀﾃﾞｰﾀ))
// 348848 = 0x2b0(ﾍｯﾀﾞ) + 40(ﾄﾗｯｸ数) x 2(面) x 16(ｾｸﾀ/ﾄﾗｯｸ) x (0x10(ｾｸﾀﾍｯﾀﾞ) + 0x100(ｾｸﾀﾃﾞｰﾀ))
// FD_IN_path  = "/FD_IN/"   + File_Name;  
// Path_String = "/EMU/D88/" + File_Name;  
void D88_headerfile_create1() {
//Serial.println(F("D88_headerfile_create1();"));

  unsigned long F_address[] = {0x0, 0x100};

  Zero_Path_String_create();                                 // 空のﾌｧｲﾙを作る(Path_String)

  for ( int i = 0 ; i < 2 ; i++ ) {
    File Input_File = SD.open(FD_IN_path, FILE_READ);
    if (Input_File == false) {
      Error_MSG_File_read_open(FD_IN_path);                  // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙが読込みﾓｰﾄﾞで開けない)
    }
    Input_File.seek(F_address[i]);
    Input_File.read(RW_Buffer[0], 0x100);
    if (Input_File == false) {
      delay(5000);
      Input_File.seek(File_address);
      Input_File.read(RW_Buffer[0], 256);
      if (Input_File == false) {
        Serial.println(Path_String);
        Error_MSG_System();                                  // ｴﾗｰﾒｯｾｰｼﾞ(ｼｽﾃﾑ異常)
      }
    }
    Input_File.close();

    File Output_File = SD.open(Path_String, FILE_WRITE);
    if (Output_File == false) {
      Serial.println(F("D88_headerfile_create1();"));
      Error_MSG_File_write_open(Path_String);                // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙが書込みﾓｰﾄﾞで開けない)
    }
    Output_File.write(RW_Buffer[0], 0x100);                  // ﾍｯﾀﾞの書込み( 一部 256 byte  )
    if (Output_File == false) {
      Error_MSG_File_write(Path_String);                     // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙ書込みができない)
    }
    Output_File.close();
  }
}


// d88ﾍｯﾀﾞﾌｧｲﾙ生成2 ---------------------------------------------
// 153008 = 0x2b0(ﾍｯﾀﾞ) + 35(ﾄﾗｯｸ数) x 1(面) x 16(ｾｸﾀ/ﾄﾗｯｸ) x (0x10(ｾｸﾀﾍｯﾀﾞ) + 0x100(ｾｸﾀﾃﾞｰﾀ))
// 174768 = 0x2b0(ﾍｯﾀﾞ) + 40(ﾄﾗｯｸ数) x 1(面) x 16(ｾｸﾀ/ﾄﾗｯｸ) x (0x10(ｾｸﾀﾍｯﾀﾞ) + 0x100(ｾｸﾀﾃﾞｰﾀ))
// 348848 = 0x2b0(ﾍｯﾀﾞ) + 40(ﾄﾗｯｸ数) x 2(面) x 16(ｾｸﾀ/ﾄﾗｯｸ) x (0x10(ｾｸﾀﾍｯﾀﾞ) + 0x100(ｾｸﾀﾃﾞｰﾀ))
// FD_IN_path  = "/FD_IN/"   + File_Name;  
// Path_String = "/EMU/D88/" + File_Name;  
void D88_headerfile_create2() {
//Serial.println(F("D88_headerfile_create2();"));

  byte HDR_Buffer[0xB0];

  File Input_File = SD.open(Path_String, FILE_READ);
  if (Input_File == false) {
    Error_MSG_File_read_open(Path_String);                   // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙが読込みﾓｰﾄﾞで開けない)
  }
  Input_File.seek(512);
  Input_File.read(HDR_Buffer, 0xB0);
  if (Input_File == false) {
    delay(5000);
    Input_File.seek(File_address);
    Input_File.read(HDR_Buffer, 256);
    if (Input_File == false) {
      Serial.println(Path_String);
      Error_MSG_System();                                    // ｴﾗｰﾒｯｾｰｼﾞ(ｼｽﾃﾑ異常)
    }
  }
  Input_File.close();
  File Output_File = SD.open(Path_String, FILE_WRITE);
  if (Output_File == false) {
    Serial.println(F("D88_headerfile_create2();"));
    Error_MSG_File_write_open(Path_String);                  // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙが書込みﾓｰﾄﾞで開けない)
  }
  Output_File.write(HDR_Buffer, 0xB0);                       //  ﾍｯﾀﾞの書込み( 一部 176 byte  )
  if (Output_File == false) {
    Error_MSG_File_write(Path_String);                       // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙ書込みができない)
  }
  Output_File.close();
}


// FDｲﾒｰｼﾞ(d88)ﾍｯﾀﾞの書込み1 ---------------------------------------------
// 153008 = 0x2b0(ﾍｯﾀﾞ) + 35(ﾄﾗｯｸ数) x 1(面) x 16(ｾｸﾀ/ﾄﾗｯｸ) x (0x10(ｾｸﾀﾍｯﾀﾞ) + 0x100(ｾｸﾀﾃﾞｰﾀ))
// 174768 = 0x2b0(ﾍｯﾀﾞ) + 40(ﾄﾗｯｸ数) x 1(面) x 16(ｾｸﾀ/ﾄﾗｯｸ) x (0x10(ｾｸﾀﾍｯﾀﾞ) + 0x100(ｾｸﾀﾃﾞｰﾀ))
// 348848 = 0x2b0(ﾍｯﾀﾞ) + 40(ﾄﾗｯｸ数) x 2(面) x 16(ｾｸﾀ/ﾄﾗｯｸ) x (0x10(ｾｸﾀﾍｯﾀﾞ) + 0x100(ｾｸﾀﾃﾞｰﾀ))
// Path_String = "/EMU/D88/" + File_Name;  
// OUTPUT_path = "/FD_OUT/"  + File_Name;  
void D88_header_write_rtn1() {
//Serial.println(F("D88_header_write_rtn1();"));

  unsigned long F_address[] = {0x0, 0x100};

  Zero_OUTPUT_path_create();                                 // 空のﾌｧｲﾙを作る(OUTPUT_path)

  for ( int i = 0 ; i < 2 ; i++ ) {
    File Input_File = SD.open(Path_String, FILE_READ);
    if (Input_File == false) {
      Error_MSG_File_read_open(Path_String);                 // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙが読込みﾓｰﾄﾞで開けない)
    }
    Input_File.seek(F_address[i]);
    Input_File.read(RW_Buffer[0], 0x100);
    if (Input_File == false) {
      delay(5000);
      Input_File.seek(File_address);
      Input_File.read(RW_Buffer[0], 256);
      if (Input_File == false) {
        Serial.println(Path_String);
        Error_MSG_System();                                  // ｴﾗｰﾒｯｾｰｼﾞ(ｼｽﾃﾑ異常)
      }
    }
    Input_File.close();

    File Output_File = SD.open(OUTPUT_path, FILE_WRITE);
    if (Output_File == false) {
      Serial.println(F("D88_header_write_rtn1();"));
      Error_MSG_File_write_open(OUTPUT_path);                // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙが書込みﾓｰﾄﾞで開けない)
    }
    Output_File.write(RW_Buffer[0], 0x100);                  //  ﾍｯﾀﾞの書込み( 一部 256 byte  )
    if (Output_File == false) {
      Error_MSG_File_write(OUTPUT_path);                     // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙ書込みができない)
    }
    Output_File.close();
  }
}


// FDｲﾒｰｼﾞ(d88)ﾍｯﾀﾞの書込み2 ---------------------------------------------
// 153008 = 0x2b0(ﾍｯﾀﾞ) + 35(ﾄﾗｯｸ数) x 1(面) x 16(ｾｸﾀ/ﾄﾗｯｸ) x (0x10(ｾｸﾀﾍｯﾀﾞ) + 0x100(ｾｸﾀﾃﾞｰﾀ))
// 174768 = 0x2b0(ﾍｯﾀﾞ) + 40(ﾄﾗｯｸ数) x 1(面) x 16(ｾｸﾀ/ﾄﾗｯｸ) x (0x10(ｾｸﾀﾍｯﾀﾞ) + 0x100(ｾｸﾀﾃﾞｰﾀ))
// 348848 = 0x2b0(ﾍｯﾀﾞ) + 40(ﾄﾗｯｸ数) x 2(面) x 16(ｾｸﾀ/ﾄﾗｯｸ) x (0x10(ｾｸﾀﾍｯﾀﾞ) + 0x100(ｾｸﾀﾃﾞｰﾀ))
// Path_String = "/EMU/D88/" + File_Name;  
// OUTPUT_path = "/FD_OUT/"  + File_Name;  
void D88_header_write_rtn2() {
//Serial.println(F("D88_header_write_rtn2();"));

  byte HDR_Buffer[0xB0];

  File Input_File = SD.open(Path_String, FILE_READ);
  if (Input_File == false) {
    Error_MSG_File_read_open(Path_String);                   // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙが読込みﾓｰﾄﾞで開けない)
  }
  Input_File.seek(512);
  Input_File.read(HDR_Buffer, 0xB0);
  if (Input_File == false) {
    delay(5000);
    Input_File.seek(File_address);
    Input_File.read(HDR_Buffer, 256);
    if (Input_File == false) {
      Serial.println(Path_String);
      Error_MSG_System();                                    // ｴﾗｰﾒｯｾｰｼﾞ(ｼｽﾃﾑ異常)
    }
  }
  Input_File.close();
  File Output_File = SD.open(OUTPUT_path, FILE_WRITE);
    if (Output_File == false) {
      Serial.println(F("D88_header_write_rtn2();"));
      Error_MSG_File_write_open(OUTPUT_path);                // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙが書込みﾓｰﾄﾞで開けない)
    }
  Output_File.write(HDR_Buffer, 0xB0);                       //  ﾍｯﾀﾞの書込み( 一部 176 byte  )
  if (Output_File == false) {
    Error_MSG_File_write(OUTPUT_path);                       // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙ書込みができない)
  }
  Output_File.close();
}


// FDｲﾒｰｼﾞﾌｧｲﾙ読込み ---------------------------------------------
// 153008 = 0x2b0(ﾍｯﾀﾞ) + 35(ﾄﾗｯｸ数) x 1(面) x 16(ｾｸﾀ/ﾄﾗｯｸ) x (0x10(ｾｸﾀﾍｯﾀﾞ) + 0x100(ｾｸﾀﾃﾞｰﾀ))
// 174768 = 0x2b0(ﾍｯﾀﾞ) + 40(ﾄﾗｯｸ数) x 1(面) x 16(ｾｸﾀ/ﾄﾗｯｸ) x (0x10(ｾｸﾀﾍｯﾀﾞ) + 0x100(ｾｸﾀﾃﾞｰﾀ))
// 348848 = 0x2b0(ﾍｯﾀﾞ) + 40(ﾄﾗｯｸ数) x 2(面) x 16(ｾｸﾀ/ﾄﾗｯｸ) x (0x10(ｾｸﾀﾍｯﾀﾞ) + 0x100(ｾｸﾀﾃﾞｰﾀ))
//void D88_FD_file_read(byte Track_cnt, byte Block_cnt) {
void D88_FD_file_read() {
  unsigned long Track_num  = Track_cnt;
  unsigned long Sector_num;
  File Input_File = SD.open(FD_IN_path, FILE_READ);
  if (Input_File == false) {
    Error_MSG_File_read_open(FD_IN_path);                    // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙが読込みﾓｰﾄﾞで開けない)
  }
  for ( int cnt = 0 ; cnt <= 3 ; cnt++ ) {
    Sector_num = Block_cnt * 4 + cnt + 1;
    File_address = ( Track_num * 0x10 + Sector_num - 1 ) * 0x110 + 0x2b0 + 0x10;
    Input_File.seek(File_address);
    Input_File.read(RW_Buffer[cnt], 256);
    if (Input_File == false) {
      delay(5000);
      Input_File.seek(File_address);
      Input_File.read(RW_Buffer[cnt], 256);
      if (Input_File == false) {
        Serial.println(FD_IN_path);
        Error_MSG_System();                                  // ｴﾗｰﾒｯｾｰｼﾞ(ｼｽﾃﾑ異常)
      }
    }
  }
  Input_File.close();
}


// 4つのｾｸﾀのﾌﾞﾛｯｸ ( 1024 byte )書込み ---------------------------------------------
// 153008 = 0x2b0(ﾍｯﾀﾞ) + 35(ﾄﾗｯｸ数) x 1(面) x 16(ｾｸﾀ/ﾄﾗｯｸ) x (0x10(ｾｸﾀﾍｯﾀﾞ) + 0x100(ｾｸﾀﾃﾞｰﾀ))
// 174768 = 0x2b0(ﾍｯﾀﾞ) + 40(ﾄﾗｯｸ数) x 1(面) x 16(ｾｸﾀ/ﾄﾗｯｸ) x (0x10(ｾｸﾀﾍｯﾀﾞ) + 0x100(ｾｸﾀﾃﾞｰﾀ))
// 348848 = 0x2b0(ﾍｯﾀﾞ) + 40(ﾄﾗｯｸ数) x 2(面) x 16(ｾｸﾀ/ﾄﾗｯｸ) x (0x10(ｾｸﾀﾍｯﾀﾞ) + 0x100(ｾｸﾀﾃﾞｰﾀ))
//void D88_FD_OUT_write(byte Track_cnt, int Block_cnt) {
void D88_FD_OUT_write() {
//Serial.println(F("D88_FD_OUT_write();"));
  unsigned long Track_num  = Track_cnt;
  unsigned long Sector_num;
  char Sector_header[16];                                    // ｾｸﾀﾍｯﾀﾞ ( 16 byte )
  byte Number_0x;
  
  File Output_File = SD.open(OUTPUT_path, FILE_WRITE);
  if (Output_File == false) {
    Serial.println(F("D88_FD_OUT_write();"));
    Error_MSG_File_write_open(OUTPUT_path);                  // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙが書込みﾓｰﾄﾞで開けない)
  }
  for ( int cnt = 0 ; cnt <= 3 ; cnt++ ) {
    Sector_num = Block_cnt * 4 + cnt + 1;
    Number_0x = Track_num / 2;                               // ﾄﾗｯｸ
    Sector_header[0]  = Number_0x;
    Number_0x = Track_num % 2;                               // 面
    Sector_header[1]  = Number_0x;
    Number_0x = Sector_num;                                  // ｾｸﾀ/ﾄﾗｯｸ
    Sector_header[2]  = Number_0x;
    Sector_header[3]  = 0x01;                                // ｾｸﾀｻｲｽﾞ(256 byte)
    Sector_header[4]  = 0x10;                                // ﾄﾗｯｸ中のｾｸﾀ数(下位):0x0010(16byte)
    Sector_header[5]  = 0x00;                                // ﾄﾗｯｸ中のｾｸﾀ数(上位):0x0010(16byte)
    Sector_header[6]  = 0x00;                                // 記録密度
    Sector_header[7]  = 0x00;                                // 削除ﾌﾗｸﾞ
    Sector_header[8]  = 0x00;                                // ｽﾃｰﾀｽ
    Sector_header[9]  = 0x00;                                // 予備1
    Sector_header[10] = 0x00;                                // 予備2
    Sector_header[11] = 0x00;                                // 予備3
    Sector_header[12] = 0x00;                                // 予備4
    Sector_header[13] = 0x00;                                // 予備5
    Sector_header[14] = 0x00;                                // このｾｸﾀのﾃﾞｰﾀｻｲｽﾞ(下位):0x0100(256byte)
    Sector_header[15] = 0x01;                                // このｾｸﾀのﾃﾞｰﾀｻｲｽﾞ(上位):0x0100(256byte)
    Output_File.write(Sector_header, 16);                    // ｾｸﾀﾍｯﾀﾞの書込み
    if (Output_File == false) {
      Error_MSG_File_write(OUTPUT_path);                     // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙ書込みができない)
    }
    Output_File.write(RW_Buffer[cnt], 256);                  // ｲﾒｰｼﾞﾌｧｲﾙ書込み
    if (Output_File == false) {
      Error_MSG_File_write(OUTPUT_path);                     // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙ書込みができない)
    }
  }
  Output_File.close();
}


// FDｲﾒｰｼﾞ(ﾌﾟﾚｰﾝ)を出力 ---------------------------------------------
// 143360 = 35(ﾄﾗｯｸ数) x 1(面) x 16(ｾｸﾀ/ﾄﾗｯｸ) x 256(ｾｸﾀﾃﾞｰﾀ)
// 163840 = 40(ﾄﾗｯｸ数) x 1(面) x 16(ｾｸﾀ/ﾄﾗｯｸ) x 256(ｾｸﾀﾃﾞｰﾀ)
// 327680 = 40(ﾄﾗｯｸ数) x 2(面) x 16(ｾｸﾀ/ﾄﾗｯｸ) x 256(ｾｸﾀﾃﾞｰﾀ)
//void Plane_img_write_rtn(char * File_Name) {
void Plane_img_write_rtn(byte _format) {
//Serial.println(F("Plane_img_write_rtn();"));

  boolean Track_file_flg = false;                            // ﾄﾗｯｸﾌｧｲﾙがあるか
  byte Last_Track;
  if (_format == 5) {
    Last_Track = 34;
  } else if (_format == 6) {
    Last_Track = 39;
  } else if (_format == 7) {
    Last_Track = 79;
  } else {
    Serial.print("FD_format = ");Serial.println(FD_format);
    Error_MSG_System();                                      // ｴﾗｰﾒｯｾｰｼﾞ(ｼｽﾃﾑ異常)
  }
//Insert_Edit_Str("/FD_IN/");
  strcpy_P(Edit_Str, pgm_read_word(&(Str_Fixed_path[8])));
  Connect_Edit_Str(File_Name);                               // Edit_Strに文字列を連結する
  Insert_FD_IN_path(Edit_Str);

//Insert_Edit_Str("/FD_OUT/");
  strcpy_P(Edit_Str, pgm_read_word(&(Str_Fixed_path[10])));
  Connect_Edit_Str(File_Name);                               // Edit_Strに文字列を連結する
  Insert_OUTPUT_path(Edit_Str);

  digitalWrite(LED_PIN, HIGH);

  // ﾌｧｲﾙがある場合は、そのﾌｧｲﾙを削除
  if (SD.exists(OUTPUT_path) == true) {
    SD.remove(OUTPUT_path);
  }
  Zero_OUTPUT_path_create();                                 // 空のﾌｧｲﾙを作る(OUTPUT_path)

  for ( Track_cnt = 0 ; Track_cnt <= Last_Track ; Track_cnt++ ) {
//  Track_path_Generate(File_Name, Track_cnt);               // ﾊﾟｽ+差分ﾄﾗｯｸﾌｧｲﾙ名生成
    Track_path_Generate();                                   // ﾊﾟｽ+差分ﾄﾗｯｸﾌｧｲﾙ名生成
    Track_file_flg = SD.exists(Track_path);                  // ﾄﾗｯｸﾌｧｲﾙがあるか
    for ( Block_cnt = 0 ; Block_cnt <= 3 ; Block_cnt++ ) {
      if (Track_file_flg == true) {
//      Track_file_read(Block_cnt);                          // ﾄﾗｯｸﾌｧｲﾙ読込み
        Track_file_read();                                   // ﾄﾗｯｸﾌｧｲﾙ読込み
      } else {
//      FD_file_read(Track_cnt, Block_cnt);                  // FDｲﾒｰｼﾞﾌｧｲﾙ読込み
        FD_file_read();                                      // FDｲﾒｰｼﾞﾌｧｲﾙ読込み
      }
      FD_OUT_write();                                        // 4つのｾｸﾀのﾌﾞﾛｯｸ ( 1024 byte )書込み
    }
//  Processing_progress_rtn(Track_cnt);                      // 処理の進行状況
    Processing_progress_rtn();                               // 処理の進行状況
  }
  digitalWrite(LED_PIN, LOW);
}


// FDｲﾒｰｼﾞﾌｧｲﾙ読込み ---------------------------------------------
// 143360 = 35(ﾄﾗｯｸ数) x 1(面) x 16(ｾｸﾀ/ﾄﾗｯｸ) x 256(ｾｸﾀﾃﾞｰﾀ)
// 163840 = 40(ﾄﾗｯｸ数) x 1(面) x 16(ｾｸﾀ/ﾄﾗｯｸ) x 256(ｾｸﾀﾃﾞｰﾀ)
// 327680 = 40(ﾄﾗｯｸ数) x 2(面) x 16(ｾｸﾀ/ﾄﾗｯｸ) x 256(ｾｸﾀﾃﾞｰﾀ)
//void FD_file_read(unsigned long Track_cnt, int Block_cnt) {
void FD_file_read() {
  unsigned long Track_num  = Track_cnt;
  unsigned long Sector_num;
  File Input_File = SD.open(FD_IN_path, FILE_READ);
  if (Input_File == false) {
    Error_MSG_File_read_open(FD_IN_path);                    // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙが読込みﾓｰﾄﾞで開けない)
  }
  for ( int cnt = 0 ; cnt <= 3 ; cnt++ ) {
    Sector_num = Block_cnt * 4 + cnt + 1;
    File_address = ( Track_num * 0x10 + Sector_num - 1 ) * 0x100;
    Input_File.seek(File_address);
    Input_File.read(RW_Buffer[cnt], 256);
    if (Input_File == false) {
      delay(5000);
      Input_File.seek(File_address);
      Input_File.read(RW_Buffer[cnt], 256);
      if (Input_File == false) {
        Serial.println(FD_IN_path);
        Error_MSG_System();                                  // ｴﾗｰﾒｯｾｰｼﾞ(ｼｽﾃﾑ異常)
      }
    }
  }
  Input_File.close();
}


// 4つのｾｸﾀのﾌﾞﾛｯｸ ( 1024 byte )書込み ---------------------------------------------
// 143360 = 35(ﾄﾗｯｸ数) x 1(面) x 16(ｾｸﾀ/ﾄﾗｯｸ) x 256(ｾｸﾀﾃﾞｰﾀ)
// 163840 = 40(ﾄﾗｯｸ数) x 1(面) x 16(ｾｸﾀ/ﾄﾗｯｸ) x 256(ｾｸﾀﾃﾞｰﾀ)
// 327680 = 40(ﾄﾗｯｸ数) x 2(面) x 16(ｾｸﾀ/ﾄﾗｯｸ) x 256(ｾｸﾀﾃﾞｰﾀ)
void FD_OUT_write() {
//Serial.println(F("FD_OUT_write();"));

  File Output_File = SD.open(OUTPUT_path, FILE_WRITE);
  if (Output_File == false) {
    Serial.println(F("FD_OUT_write();"));
    Error_MSG_File_write_open(OUTPUT_path);                  // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙが書込みﾓｰﾄﾞで開けない)
  }
  for ( int cnt = 0 ; cnt <= 3 ; cnt++ ) {
    Output_File.write(RW_Buffer[cnt], 256);                  // ｲﾒｰｼﾞﾌｧｲﾙ書込み
    if (Output_File == false) {
      Error_MSG_File_write(OUTPUT_path);                     // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙ書込みができない)
    }
  }
  Output_File.close();
}


// ﾄﾗｯｸﾌｧｲﾙ読込み ---------------------------------------------
//void Track_file_read(int Block_cnt) {
void Track_file_read() {
  unsigned long Sector_num;
  File Input_File = SD.open(Track_path, FILE_READ);
  if (Input_File == false) {
    Error_MSG_File_read_open(Track_path);                    // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙが読込みﾓｰﾄﾞで開けない)
  }
  File_Size = Input_File.size();
  for ( int cnt = 0 ; cnt <= 3 ; cnt++ ) {
    Sector_num = Block_cnt * 4 + cnt + 1;
    if (File_Size == 256) {
      File_address = 0;
    } else {
      File_address = ( Sector_num - 1 ) * 0x100;
    }
    Input_File.seek(File_address);
    Input_File.read(RW_Buffer[cnt], 256);
    if (Input_File == false) {
      delay(5000);
      Input_File.seek(File_address);
      Input_File.read(RW_Buffer[cnt], 256);
      if (Input_File == false) {
        Serial.println(Track_path);
        Error_MSG_System();                                  // ｴﾗｰﾒｯｾｰｼﾞ(ｼｽﾃﾑ異常)
      }
    }
  }
  Input_File.close();
}


// /FD_IN/WK1D0000.IMG /FD_IN/WK2D0000.IMGを作成 ---------------------------------------------
void WORK0000_IMG_create(byte _format) {
//Serial.println(F("WORK0000_IMG_create();"));

  byte Last_Track;
  if (_format == 5) {
    Last_Track = 34;
//  Insert_Path_String("/FD_IN/WK1D0000.IMG");
    strcpy_P(Path_String, pgm_read_word(&(Str_Fixed_path[19])));
  } else if (_format == 7) {
    Last_Track = 79;
//  Insert_Path_String("/FD_IN/WK2D0000.IMG");
    strcpy_P(Path_String, pgm_read_word(&(Str_Fixed_path[9])));
  } else {
    Serial.print("FD_format = ");Serial.println(FD_format);
    Error_MSG_System();                                      // ｴﾗｰﾒｯｾｰｼﾞ(ｼｽﾃﾑ異常)
  }
  // ﾌｧｲﾙがある場合は、
  if (SD.exists(Path_String) == true) {
    return;
//  SD.remove(Path_String);
  }
  digitalWrite(LED_PIN, HIGH);

  for ( int i = 0 ; i < 256 ; i++ ) {
    RW_Buffer[0][i] = 0xFF;
    RW_Buffer[1][i] = 0x00;
    RW_Buffer[2][i] = pgm_read_byte_near(N60_FAT + i);       // 1byte読み込み
    RW_Buffer[3][i] = pgm_read_byte_near(N_FAT + i);         // 1byte読み込み
  }
  // 空のﾌｧｲﾙを作る(Path_String)
  Zero_Path_String_create();

  File Output_File = SD.open(Path_String, FILE_WRITE);
  if (Output_File == false) {
    Serial.println(F("WORK0000_IMG_create();"));
    Error_MSG_File_write_open(Path_String);                  // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙが書込みﾓｰﾄﾞで開けない)
  }
  for ( Track_cnt = 0 ; Track_cnt <= Last_Track ; Track_cnt++ ) {
    for ( Sector_cnt = 1 ; Sector_cnt <= 16 ; Sector_cnt++ ) {
      if (_format == 5) {
        if (Track_cnt == 18) {
          if ((Sector_cnt >= 1) && (Sector_cnt <= 12)) {
            Output_File.write(RW_Buffer[0], 256);            // ｲﾒｰｼﾞﾌｧｲﾙ書込み
          } else if (Sector_cnt == 13) {
            Output_File.write(RW_Buffer[1], 256);            // ｲﾒｰｼﾞﾌｧｲﾙ書込み
          } else if (Sector_cnt >= 14) {
            Output_File.write(RW_Buffer[2], 256);            // ｲﾒｰｼﾞﾌｧｲﾙ書込み
          }
        } else {
          Output_File.write(RW_Buffer[0], 256);              // ｲﾒｰｼﾞﾌｧｲﾙ書込み
        }
      } else if (_format == 7) {
        if (Track_cnt == 37) {
          if ((Sector_cnt >= 1) && (Sector_cnt <= 12)) {
            Output_File.write(RW_Buffer[0], 256);            // ｲﾒｰｼﾞﾌｧｲﾙ書込み
          } else if (Sector_cnt == 13) {
            Output_File.write(RW_Buffer[1], 256);            // ｲﾒｰｼﾞﾌｧｲﾙ書込み
          } else if (Sector_cnt >= 14) {
            Output_File.write(RW_Buffer[3], 256);            // ｲﾒｰｼﾞﾌｧｲﾙ書込み
          }
        } else {
          Output_File.write(RW_Buffer[0], 256);              // ｲﾒｰｼﾞﾌｧｲﾙ書込み
        }
      } else {
        Output_File.write(RW_Buffer[0], 256);                // ｲﾒｰｼﾞﾌｧｲﾙ書込み
      }
      if (Output_File == false) {
        Error_MSG_File_write(Path_String);                   // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙ書込みができない)
      }
    }
  }
  Output_File.close();

  digitalWrite(LED_PIN, LOW);
}


// ﾊﾟｽ+差分ﾄﾗｯｸﾌｧｲﾙ名生成 ---------------------------------------------
// /EMU/FD/FDｲﾒｰｼﾞﾌｧｲﾙ名/TRACK00.BIN
// /EMU/FD/FDｲﾒｰｼﾞﾌｧｲﾙ名/TRACK79.BIN
//void Track_path_Generate(char * File_Name, int Track_cnt) {
void Track_path_Generate() {
//Serial.println(F("Track_path_Generate();"));

//Insert_Edit_Str("/EMU/FD/");
  strcpy_P(Edit_Str, pgm_read_word(&(Str_Fixed_path[12])));
  Connect_Edit_Str(File_Name);                               // Edit_Strに文字列を連結する
//Connect_Edit_Str("/TRACK");                                // Edit_Strに文字列を連結する
  strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_path[17])));
  Connect_Edit_Str(Short_Str);                               // Edit_Strに文字列を連結する
  if (Track_cnt < 10) {
    Connect_Edit_Str("0\0");                                 // Edit_Strに文字列を連結する
  }
  DEC_Str_conversion(Track_cnt);                             // 数値を文字列に変換する
  Connect_Edit_Str(DEC_Str);                                 // Edit_Strに文字列を連結する
//Connect_Edit_Str(".BIN");                                  // Edit_Strに文字列を連結する
  strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_path[18])));
  Connect_Edit_Str(Short_Str);                               // Edit_Strに文字列を連結する
  Insert_Track_path(Edit_Str);
//Serial.print(F("Track_path : "));Serial.println(Track_path); // debug
}


// ﾊﾟｽ+差分ｾｸﾀﾌｧｲﾙ名生成 ---------------------------------------------
// /EMU/VM/SECTOR01.BIN
// /EMU/VM/SECTOR16.BIN
//void Sector_path_Generate(int Sector_cnt) {
void Sector_path_Generate() {
//Serial.println(F("Sector_path_Generate();"));

//Insert_Edit_Str("/EMU/VM/SECTOR");
  strcpy_P(Edit_Str, pgm_read_word(&(Str_Fixed_path[13])));
  if (Sector_cnt < 10) {
    Connect_Edit_Str("0\0");                                 // Edit_Strに文字列を連結する
  }
  DEC_Str_conversion(Sector_cnt);                            // 数値を文字列に変換する
  Connect_Edit_Str(DEC_Str);                                 // Edit_Strに文字列を連結する
//Connect_Edit_Str(".BIN");                                  // Edit_Strに文字列を連結する
  strcpy_P(Short_Str, pgm_read_word(&(Str_Fixed_path[18])));
  Connect_Edit_Str(Short_Str);                               // Edit_Strに文字列を連結する
  Insert_Sector_path(Edit_Str);
//Serial.print(F("Sector_path : "));Serial.println(Sector_path);// debug
}


// 空のﾌｧｲﾙを作る(Path_String) ---------------------------------------------
void Zero_Path_String_create() {
//Serial.println("Zero_Path_String_create();");
  File Output_File = SD.open(Path_String, FILE_WRITE);
  Output_File.close();
}


// 空のﾌｧｲﾙを作る(FD_IN_path) ---------------------------------------------
void Zero_FD_IN_path_create() {
//Serial.println("Zero_FD_IN_path_create();");
  File Output_File = SD.open(FD_IN_path, FILE_WRITE);
  Output_File.close();
}


// 空のﾌｧｲﾙを作る(OUTPUT_path) ---------------------------------------------
void Zero_OUTPUT_path_create() {
//Serial.println("Zero_OUTPUT_path_create();");
  File Output_File = SD.open(OUTPUT_path, FILE_WRITE);
  Output_File.close();
}


// 空のﾌｧｲﾙを作る(Track_path) ---------------------------------------------
void Zero_Track_path_create() {
//Serial.println("Zero_Track_path_create();");
  File Output_File = SD.open(Track_path, FILE_WRITE);
  Output_File.close();
}


// 空のﾌｧｲﾙを作る(Sector_path) ---------------------------------------------
void Zero_Sector_path_create() {
//Serial.println("Zero_Sector_path_create();");
  File Output_File = SD.open(Sector_path, FILE_WRITE);
  Output_File.close();
}


// EMUがあるかﾁｪｯｸ ---------------------------------------------
void EMU_check_rtn() {
//Serial.println(F("EMU_check_rtn();"));

//Insert_Path_String("/EMU");
  strcpy_P(Path_String, pgm_read_word(&(Str_Fixed_path[2])));
  EMU_practicable_flg = SD.exists(Path_String);              // ﾃﾞｨﾚｸﾄﾘ(/EMU)があるか?
}


// ｼｽﾃﾑﾃﾞｰﾀﾁｪｯｸ&削除 ---------------------------------------------
void System_check_rtn() {
//Serial.println(F("System_check_rtn();"));

  File_TBL_create2();                                 // ｼｽﾃﾑで保持しているﾌｧｲﾙﾘｽﾄを作成(/EMU/CONFIG/FD)

  for ( int i = 0 ; i < File_count ; i++ ) {
//  Insert_Edit_Str("/FD_IN/");
    strcpy_P(Edit_Str, pgm_read_word(&(Str_Fixed_path[8])));
    Connect_Edit_Str(File_TBL[i]);                           // Edit_Strに文字列を連結する
    Insert_FD_IN_path(Edit_Str);
    if (SD.exists(FD_IN_path) == false) {
      Insert_File_Name(File_TBL[i]);                         // ﾌｧｲﾙ名
//    Unnecessary_delete_rtn(File_Name);                     // 不要ﾌｧｲﾙ&ﾃﾞｨﾚｸﾄﾘ削除
      Unnecessary_delete_rtn();                              // 不要ﾌｧｲﾙ&ﾃﾞｨﾚｸﾄﾘ削除
    }
  }
  for ( int i = 0 ; i < 4 ; i++ ) {
    if (Drv_FD_Name[i][0] != '*') {
//    Insert_Edit_Str("/FD_IN/");
      strcpy_P(Edit_Str, pgm_read_word(&(Str_Fixed_path[8])));
      Connect_Edit_Str(Drv_FD_Name[i]);                      // Edit_Strに文字列を連結する
      Insert_FD_IN_path(Edit_Str);
      if (SD.exists(FD_IN_path) == false) {
//      Drv_fd_link_crt(i, DUMMY_Name);                      // ﾄﾞﾗｲﾌﾞにFDｲﾒｰｼﾞ紐づけﾌｧｲﾙ作成
        Insert_Drv_FD_Name(DUMMY_Name, i);                   // Drv_FD_Name[]に文字列を挿入する
      }
    }
  }
}


// 不要ﾌｧｲﾙ&ﾃﾞｨﾚｸﾄﾘ削除 ---------------------------------------------
//void Unnecessary_delete_rtn(char * File_Name) {
void Unnecessary_delete_rtn() {
//Serial.println("Unnecessary_delete_rtn();");

  digitalWrite(LED_PIN, HIGH);
  
//Insert_Edit_Str("/EMU/CONFIG/FD/");
  strcpy_P(Edit_Str, pgm_read_word(&(Str_Fixed_path[11])));
  Connect_Edit_Str(File_Name);                               // Edit_Strに文字列を連結する
  Insert_Path_String(Edit_Str);
  if (SD.exists(Path_String) == true) {
    SD.remove(Path_String);
  }

//Insert_Edit_Str("/EMU/FD/");
  strcpy_P(Edit_Str, pgm_read_word(&(Str_Fixed_path[12])));
  Connect_Edit_Str(File_Name);                               // Edit_Strに文字列を連結する
  Insert_Path_String(Edit_Str);
  File Target_Holder = SD.open(Path_String);
  while(true) {
    File Input_File = Target_Holder.openNextFile();
    if (Input_File == false) {                               // これ以上ﾌｧｲﾙがない場合
      break;
    }
    if (Input_File.isDirectory() == false) {                 // ﾃﾞｨﾚｸﾄﾘではない場合
      Insert_Edit_Str(Path_String);
      Connect_Edit_Str('/');                                 // Edit_Strに文字列を連結する
      Connect_Edit_Str(Input_File.name());                   // Edit_Strに文字列を連結する
      Insert_Track_path(Edit_Str);
      if (SD.exists(Track_path) == true) {
        SD.remove(Track_path);
      }
    }
  }
  Target_Holder.close();

//Insert_Edit_Str("/EMU/FD/");
  strcpy_P(Edit_Str, pgm_read_word(&(Str_Fixed_path[12])));
  Connect_Edit_Str(File_Name);                               // Edit_Strに文字列を連結する
  Insert_Path_String(Edit_Str);
  if (SD.exists(Path_String) == true) {                      // ﾃﾞｨﾚｸﾄﾘがある場合は、
    SD.rmdir(Path_String);                                   // ﾃﾞｨﾚｸﾄﾘの削除(中にﾌｧｲﾙがないこと)
  }
  digitalWrite(LED_PIN, LOW);
}


// readme.txt作成 ---------------------------------------------
void readme_txt_create() {
//Serial.println(F("readme_txt_create();"));
  char readme_txt[256];
  
  digitalWrite(LED_PIN, HIGH);
  
//Insert_Edit_Str("/readme.txt");
  strcpy_P(Edit_Str, pgm_read_word(&(Str_Fixed_path[21])));
  Insert_Path_String(Edit_Str);
//Serial.println(Path_String);

  // ﾌｧｲﾙがある場合は、ｷｬﾝｾﾙ
  if (SD.exists(Path_String) == true) {
    return;
  }
  // 空のﾌｧｲﾙを作る(Path_String)
  Zero_Path_String_create();
  
  // 空のﾌｧｲﾙに追加書き
  File Output_File = SD.open(Path_String, FILE_WRITE);
  if (Output_File == false) {
    Serial.println(F("readme_txt_create();"));
    Error_MSG_File_write_open(Path_String);                  // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙが書込みﾓｰﾄﾞで開けない)
  }
  for ( int i = 0 ; i <= 76 ; i++ ){
    strcpy_P(readme_txt, pgm_read_word(&(Str_readme_txt[i])));
    Output_File.print(readme_txt);                           // SDｶｰﾄﾞにﾃﾞｰﾀ書込み
    if (Output_File == false) {
      Error_MSG_File_write(Path_String);                     // ｴﾗｰﾒｯｾｰｼﾞ(ﾌｧｲﾙ書込みができない)
    }
  }
  Output_File.close();

  digitalWrite(LED_PIN, LOW);
}


// 処理の進行状況 ------------------------------------------------
//void Processing_progress_rtn(int Track_cnt) {
void Processing_progress_rtn() {
  int Track_num = Track_cnt;                                 // ﾄﾗｯｸ番号(0-79)
  int Num1, Num2, Num3;
//Serial.println(F("(ｶﾝﾘｮｳ ｼﾀ ﾄﾗｯｸ ﾉ ｼﾞｮｳｷｮｳ)"));
//Serial.println(F("***20***40***60***80"));
  Num1 = Track_num % 4;
  Num2 = Track_num / 4;
  Num3 = Num2 * 16 + 5;
  if (Num1 == 0) {
    Serial.print('*');
    KNJ_print("■", Num3, 462, 2, BLACK);
  }
}


// FDｱｸｾｽ(LEDと作動音) ------------------------------------------------
// アクセスランプ
// 　スタンバイ状態の時には２０％の明るさで点灯します
// 　ドライブのアクセスをしている時には１００％の明るさで点灯します
//
// 　ただしドライブ４まで拡張している場合
// 　ドライブ４はスタンバイ状態でも１００％近い明るさで点灯します
// 　ドライブ１～３のアクセスランプが消えているときがドライブ４のアクセス中となります。
void FD_access_rtn(boolean FD_State) {

  if (FD_State == true) {
//  digitalWrite(LED_PIN, HIGH);
    PORTB |= B10000000;                                      // PB7(D13)(LED) : HIGH
//  PORTD |= B10000000;                                      // PD7(D38)(buzzer) : HIGH
    MsTimer2::start();                                       // PD7(D38)(buzzer) : ON
    switch (Drive_No) {
    case 0:
      DSP.fillRect(D1_LED_SQ, RED);                          // FDD1のLED(面)
      break;
    case 1:
      DSP.fillRect(D2_LED_SQ, RED);                          // FDD2のLED(面)
      break;
    case 2:
      DSP.fillRect(D3_LED_SQ, RED);                          // FDD3のLED(面)
    }
    if (Drv_FD_Name[3][0] != '*') {
      DSP.fillRect(D4_LED_SQ, RED);                          // FDD4のLED(面)
    }
  } else {
//  digitalWrite(LED_PIN, LOW);
    PORTB &= B01111111;                                      // PB7(D13)(LED) : LOW
    PORTD &= B01111111;                                      // PD7(D38)(buzzer) : LOW
    MsTimer2::stop();                                        // PD7(D38)(buzzer) : OFF
    switch (Drive_No) {
    case 0:
      DSP.fillRect(D1_LED_SQ, DARK_RED);                     // FDD1のLED(面)
      break;
    case 1:
      DSP.fillRect(D2_LED_SQ, DARK_RED);                     // FDD2のLED(面)
      break;
    case 2:
      DSP.fillRect(D3_LED_SQ, DARK_RED);                     // FDD3のLED(面)
    }
    if (Drv_FD_Name[3][0] != '*') {
      DSP.fillRect(D4_LED_SQ, DARK_RED);                     // FDD4のLED(面)
    }
  }
}


// FDD駆動音 ------------------------------------------------
void Driving_sound() {

  PORTD &= B01111111;                                        // PD7(D38)(buzzer) : LOW

  long rand_Num = random(5);                                 // 0から5の乱数を生成
  if (rand_Num == 0) {
    PORTD |= B10000000;                                      // PD7(D38)(buzzer) : HIGH
  } else {
    PORTD &= B01111111;                                      // PD7(D38)(buzzer) : LOW
  }
}
//

// resetがかかるか、電源offを待つ ------------------------------------------------
void Waiting_for_reset() {

  while (true) {
    delay(32767);
  }
}


/* RW_Buffer_print ---------------------------------------------
void RW_Buffer_print() {
  
  Serial.print(F("Track = "));
  Serial.print(Track_cnt, DEC);
  Serial.print(F(", Sector = "));
  Serial.print(Sector_cnt, DEC);
  Serial.print(F(", TBL = "));
  for ( int i = 0 ; i < 16 ; i++ ) {
    Serial.print(" 0x");
    Serial.print(RW_Buffer[0][i], HEX);
  }
  Serial.println();
}
*/

//
