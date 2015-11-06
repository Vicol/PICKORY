
#ifndef Debug
#include <RFID.h>

#include <DFPlayer_Mini_Mp3.h>
#include <SoftwareSerial.h>



SoftwareSerial mySerial(3, 2);  // RX, TX


#include <SPI.h>

RFID rfid(10,5);   //D10--reader-SS、D5--reader-RST



#endif


#include<stdio.h>
#include<stdlib.h>
#include<string.h>



#define POOL_SIZE 5
#define NAME_SIZE 11
#define MAX_GOODS 6
#define MAX_SCENE 4
#define MAX_MP3 256
#define MAX_SENTENCE_LENGTH 11
#define GOODS_PER_SCENE 6
#define MAX_EXP 10

struct Pool{
    short label[POOL_SIZE][2];
    char size;
    char name[NAME_SIZE];
};

int flag;
char yoo[MAX_SENTENCE_LENGTH];

char tme[MAX_MP3];

char calc[MAX_SCENE];//check if one scene is visited twice

short unhappy[15],unhappy_s;

short seq[MAX_EXP],seq_s,seq_t;

struct Scene{
    char name[NAME_SIZE];
    struct Pool start,end,goods[MAX_GOODS];
}scene[MAX_SCENE];

void init_scene()
{
 // Serial.print("setup check right1!");
    strcpy(scene[0].name, "735A3021B");
    scene[0].start.size = 3;
    tme[201]=42;
    scene[0].start.label[0][0] = 501;
    tme[207]=37;
    scene[0].start.label[0][1] = 507;
    tme[202]=56;
    scene[0].start.label[1][0] = 502;
    tme[208]=52;
    scene[0].start.label[1][1] = 508;
    tme[203]=59;
    scene[0].start.label[2][0] = 503;
    tme[209]=57;
    scene[0].start.label[2][1] = 509;
  //  Serial.print("setup check right2!");
    mp3_play(301);
  delay(5000);
    scene[0].end.size = 3;
    tme[204]=30;
    scene[0].end.label[0][0] = 504;
    tme[210]=32;
    scene[0].end.label[0][1] = 510;
    tme[205]=36;
    scene[0].end.label[1][0] = 505;
    tme[211]=38;
    scene[0].end.label[1][1] = 511;
    tme[206]=43;
    scene[0].end.label[2][0] = 506;
    tme[212]=49;
    scene[0].end.label[2][1] = 512;
      mp3_play(302);
  delay(5000);
    
    strcpy(scene[0].goods[0 ].name, "B3A6B30A6" );
    scene[0].goods[0].size = 4;
    tme[1]=60;
    scene[0].goods[0].label[0][0] = 1;
    tme[25]=83;
    scene[0].goods[0].label[0][1] = 25;
    tme[2]=68;
    scene[0].goods[0].label[1][0] = 2;
    tme[26]=72;
    scene[0].goods[0].label[1][1] = 26;
    tme[3]=33;
    scene[0].goods[0].label[2][0] = 3;
    tme[27]=60;
    scene[0].goods[0].label[2][1] = 27;
    tme[4]=52;
    scene[0].goods[0].label[3][0] = 4;
    tme[28]=61;
    scene[0].goods[0].label[3][1] = 28;
    
    strcpy(scene[0].goods[1 ].name, "D318ADACCA" );
    scene[0].goods[1].size = 4;
    tme[5]=40;
    scene[0].goods[1].label[0][0] = 5;
    tme[29]=55;
    scene[0].goods[1].label[0][1] = 29;
    tme[6]=67;
    scene[0].goods[1].label[1][0] = 6;
    tme[30]=95;
    scene[0].goods[1].label[1][1] = 30;
    tme[7]=33;
    scene[0].goods[1].label[2][0] = 7;
    tme[31]=63;
    scene[0].goods[1].label[2][1] = 31;
    tme[8]=37;
    scene[0].goods[1].label[3][0] = 8;
    tme[32]=74;
    scene[0].goods[1].label[3][1] = 32;
    
    strcpy(scene[0].goods[2 ].name, "D3CA6ACD5" );
    scene[0].goods[2].size = 4;
    tme[9]=28;
    scene[0].goods[2].label[0][0] = 9;
    tme[33]=44;
    scene[0].goods[2].label[0][1] = 33;
    tme[10]=27;
    scene[0].goods[2].label[1][0] = 10;
    tme[34]=51;
    scene[0].goods[2].label[1][1] = 34;
    tme[11]=35;
    scene[0].goods[2].label[2][0] = 11;
    tme[35]=45;
    scene[0].goods[2].label[2][1] = 35;
    tme[12]=16;
    scene[0].goods[2].label[3][0] = 12;
    tme[36]=59;
    scene[0].goods[2].label[3][1] = 36;
      mp3_play(303);
  delay(5000);
    strcpy(scene[0].goods[3 ].name, "838CB30BC" );
    scene[0].goods[3].size = 4;
    tme[13]=26;
    scene[0].goods[3].label[0][0] = 13;
    tme[37]=46;
    scene[0].goods[3].label[0][1] = 37;
    tme[14]=32;
    scene[0].goods[3].label[1][0] = 14;
    tme[38]=53;
    scene[0].goods[3].label[1][1] = 38;
    tme[15]=31;
    scene[0].goods[3].label[2][0] = 15;
    tme[39]=59;
    scene[0].goods[3].label[2][1] = 39;
    tme[16]=27;
    scene[0].goods[3].label[3][0] = 16;
    tme[40]=44;
    scene[0].goods[3].label[3][1] = 40;
    
    strcpy(scene[0].goods[4 ].name, "83F9A5805F" );
    scene[0].goods[4].size = 4;
    tme[17]=25;
    scene[0].goods[4].label[0][0] = 17;
    tme[41]=66;
    scene[0].goods[4].label[0][1] = 41;
    tme[18]=26;
    scene[0].goods[4].label[1][0] = 18;
    tme[42]=45;
    scene[0].goods[4].label[1][1] = 42;
    tme[19]=33;
    scene[0].goods[4].label[2][0] = 19;
    tme[43]=48;
    scene[0].goods[4].label[2][1] = 43;
    tme[20]=37;
    scene[0].goods[4].label[3][0] = 20;
    tme[44]=57;
    scene[0].goods[4].label[3][1] = 44;
    
    strcpy(scene[0].goods[5 ].name, "23D22E2DD" );
    scene[0].goods[5].size = 4;
    tme[21]=40;
    scene[0].goods[5].label[0][0] = 21;
    tme[45]=46;
    scene[0].goods[5].label[0][1] = 45;
    unhappy[unhappy_s++] = 45;tme[22]=45;
    scene[0].goods[5].label[1][0] = 22;
    tme[46]=46;
    scene[0].goods[5].label[1][1] = 46;
    unhappy[unhappy_s++] = 46;tme[23]=47;
    scene[0].goods[5].label[2][0] = 23;
    tme[47]=66;
    scene[0].goods[5].label[2][1] = 47;
    unhappy[unhappy_s++] = 47;tme[24]=51;
    scene[0].goods[5].label[3][0] = 24;
    tme[48]=72;
    scene[0].goods[5].label[3][1] = 48;
    unhappy[unhappy_s++] = 48;
  mp3_play(304);
  delay(5000);
    strcpy(scene[1].name, "33D8ADACEA");
    scene[1].start.size = 3;
    tme[213]=43;
    scene[1].start.label[0][0] = 513;
    tme[219]=33;
    scene[1].start.label[0][1] = 519;
    tme[214]=53;
    scene[1].start.label[1][0] = 514;
    tme[220]=57;
    scene[1].start.label[1][1] = 520;
    tme[215]=31;
    scene[1].start.label[2][0] = 515;
    tme[221]=23;
    scene[1].start.label[2][1] = 521;
    
    scene[1].end.size = 3;
    tme[216]=59;
    scene[1].end.label[0][0] = 516;
    tme[222]=62;
    scene[1].end.label[0][1] = 522;
    tme[217]=37;
    scene[1].end.label[1][0] = 517;
    tme[223]=54;
    scene[1].end.label[1][1] = 523;
    tme[218]=32;
    scene[1].end.label[2][0] = 518;
    tme[224]=33;
    scene[1].end.label[2][1] = 524;
    
    
    strcpy(scene[1].goods[0 ].name, "43345F22A" );
    scene[1].goods[0].size = 3;
    tme[51]=48;
    scene[1].goods[0].label[0][0] = 101;
    tme[69]=68;
    scene[1].goods[0].label[0][1] = 119;
    tme[52]=53;
    scene[1].goods[0].label[1][0] = 102;
    tme[70]=91;
    scene[1].goods[0].label[1][1] = 120;
    tme[53]=36;
    scene[1].goods[0].label[2][0] = 103;
    tme[71]=77;
    scene[1].goods[0].label[2][1] = 121;
    
    strcpy(scene[1].goods[1 ].name, "99F3F055CF" );
    scene[1].goods[1].size = 3;
    tme[54]=48;
    scene[1].goods[1].label[0][0] = 104;
    tme[72]=74;
    scene[1].goods[1].label[0][1] = 122;
    tme[55]=46;
    scene[1].goods[1].label[1][0] = 105;
    tme[73]=57;
    scene[1].goods[1].label[1][1] = 123;
    tme[56]=46;
    scene[1].goods[1].label[2][0] = 106;
    tme[74]=51;
    scene[1].goods[1].label[2][1] = 124;
    
    strcpy(scene[1].goods[2 ].name, "9345392ED" );
    scene[1].goods[2].size = 3;
    tme[57]=53;
    scene[1].goods[2].label[0][0] = 107;
    tme[75]=71;
    scene[1].goods[2].label[0][1] = 125;
    tme[58]=42;
    scene[1].goods[2].label[1][0] = 108;
    tme[76]=57;
    scene[1].goods[2].label[1][1] = 126;
    tme[59]=57;
    scene[1].goods[2].label[2][0] = 109;
    tme[77]=91;
    scene[1].goods[2].label[2][1] = 127;
    
    strcpy(scene[1].goods[3 ].name, "9320D1062" );
    scene[1].goods[3].size = 3;
    tme[60]=61;
    scene[1].goods[3].label[0][0] = 110;
    tme[78]=74;
    scene[1].goods[3].label[0][1] = 128;
    tme[61]=68;
    scene[1].goods[3].label[1][0] = 111;
    tme[79]=85;
    scene[1].goods[3].label[1][1] = 129;
    tme[62]=64;
    scene[1].goods[3].label[2][0] = 112;
    tme[80]=65;
    scene[1].goods[3].label[2][1] = 130;
    
    strcpy(scene[1].goods[4 ].name, "34130270" );
    scene[1].goods[4].size = 3;
    tme[63]=61;
    scene[1].goods[4].label[0][0] = 113;
    tme[81]=71;
    scene[1].goods[4].label[0][1] = 131;
    tme[64]=34;
    scene[1].goods[4].label[1][0] = 114;
    tme[82]=60;
    scene[1].goods[4].label[1][1] = 132;
    tme[65]=51;
    scene[1].goods[4].label[2][0] = 115;
    tme[83]=77;
    scene[1].goods[4].label[2][1] = 133;
    
    strcpy(scene[1].goods[5 ].name, "9385D2C4" );
    scene[1].goods[5].size = 3;
    tme[66]=51;
    scene[1].goods[5].label[0][0] = 116;
    tme[84]=68;
    scene[1].goods[5].label[0][1] = 134;
    unhappy[unhappy_s++] = 134;tme[67]=79;
    scene[1].goods[5].label[1][0] = 117;
    tme[85]=94;
    scene[1].goods[5].label[1][1] = 135;
    unhappy[unhappy_s++] = 135;tme[68]=61;
    scene[1].goods[5].label[2][0] = 118;
    tme[86]=60;
    scene[1].goods[5].label[2][1] = 136;
    unhappy[unhappy_s++] = 136;
    
    
    
    
  /*  
    strcpy(scene[2].name, "C3BBA6AC72");
    scene[2].start.size = 3;
    tme[225]=58;
    scene[2].start.label[0][0] = 525;
    tme[231]=63;
    scene[2].start.label[0][1] = 531;
    tme[226]=50;
    scene[2].start.label[1][0] = 526;
    tme[232]=40;
    scene[2].start.label[1][1] = 532;
    tme[227]=43;
    scene[2].start.label[2][0] = 527;
    tme[233]=55;
    scene[2].start.label[2][1] = 533;
    
    scene[2].end.size = 3;
    tme[228]=51;
    scene[2].end.label[0][0] = 528;
    tme[234]=50;
    scene[2].end.label[0][1] = 534;
    tme[229]=52;
    scene[2].end.label[1][0] = 529;
    tme[235]=55;
    scene[2].end.label[1][1] = 535;
    tme[230]=44;
    scene[2].end.label[2][0] = 530;
    tme[236]=42;
    scene[2].end.label[2][1] = 536;
    
    
    strcpy(scene[2].goods[0 ].name, "A356AFACF6" );
    scene[2].goods[0].size = 4;
    tme[101]=66;
    scene[2].goods[0].label[0][0] = 201;
    tme[123]=87;
    scene[2].goods[0].label[0][1] = 223;
    tme[102]=85;
    scene[2].goods[0].label[1][0] = 202;
    tme[124]=98;
    scene[2].goods[0].label[1][1] = 224;
    tme[103]=66;
    scene[2].goods[0].label[2][0] = 203;
    tme[125]=71;
    scene[2].goods[0].label[2][1] = 225;
    tme[104]=78;
    scene[2].goods[0].label[3][0] = 204;
    tme[126]=75;
    scene[2].goods[0].label[3][1] = 226;
    
    strcpy(scene[2].goods[1 ].name, "83BDA6AC34" );
    scene[2].goods[1].size = 4;
    tme[105]=61;
    scene[2].goods[1].label[0][0] = 205;
    tme[127]=66;
    scene[2].goods[1].label[0][1] = 227;
    tme[106]=73;
    scene[2].goods[1].label[1][0] = 206;
    tme[128]=103;
    scene[2].goods[1].label[1][1] = 228;
    tme[107]=36;
    scene[2].goods[1].label[2][0] = 207;
    tme[129]=66;
    scene[2].goods[1].label[2][1] = 229;
    tme[108]=45;
    scene[2].goods[1].label[3][0] = 208;
    tme[130]=73;
    scene[2].goods[1].label[3][1] = 230;
    
    strcpy(scene[2].goods[2 ].name, "2346AFAC66" );
    scene[2].goods[2].size = 4;
    tme[109]=52;
    scene[2].goods[2].label[0][0] = 209;
    tme[131]=46;
    scene[2].goods[2].label[0][1] = 231;
    tme[110]=55;
    scene[2].goods[2].label[1][0] = 210;
    tme[132]=57;
    scene[2].goods[2].label[1][1] = 232;
    tme[111]=57;
    scene[2].goods[2].label[2][0] = 211;
    tme[133]=62;
    scene[2].goods[2].label[2][1] = 233;
    tme[112]=57;
    scene[2].goods[2].label[3][0] = 212;
    tme[134]=62;
    scene[2].goods[2].label[3][1] = 234;
    
    strcpy(scene[2].goods[3 ].name, "53813A2FA" );
    scene[2].goods[3].size = 4;
    tme[113]=43;
    scene[2].goods[3].label[0][0] = 213;
    tme[135]=66;
    scene[2].goods[3].label[0][1] = 235;
    tme[114]=64;
    scene[2].goods[3].label[1][0] = 214;
    tme[136]=69;
    scene[2].goods[3].label[1][1] = 236;
    tme[115]=43;
    scene[2].goods[3].label[2][0] = 215;
    tme[137]=60;
    scene[2].goods[3].label[2][1] = 237;
    tme[116]=50;
    scene[2].goods[3].label[3][0] = 216;
    tme[138]=71;
    scene[2].goods[3].label[3][1] = 238;
    
    strcpy(scene[2].goods[4 ].name, "53553A23E" );
    scene[2].goods[4].size = 3;
    tme[117]=48;
    scene[2].goods[4].label[0][0] = 217;
    tme[139]=64;
    scene[2].goods[4].label[0][1] = 239;
    tme[118]=45;
    scene[2].goods[4].label[1][0] = 218;
    tme[140]=60;
    scene[2].goods[4].label[1][1] = 240;
    tme[119]=55;
    scene[2].goods[4].label[2][0] = 219;
    tme[141]=51;
    scene[2].goods[4].label[2][1] = 241;
    
    strcpy(scene[2].goods[5 ].name, "1391ADAC83" );
    scene[2].goods[5].size = 3;
    tme[120]=57;
    scene[2].goods[5].label[0][0] = 220;
    tme[142]=60;
    scene[2].goods[5].label[0][1] = 242;
    unhappy[unhappy_s++] = 242;tme[121]=50;
    scene[2].goods[5].label[1][0] = 221;
    tme[143]=62;
    scene[2].goods[5].label[1][1] = 243;
    unhappy[unhappy_s++] = 243;tme[122]=52;
    scene[2].goods[5].label[2][0] = 222;
    tme[144]=69;
    scene[2].goods[5].label[2][1] = 244;
    unhappy[unhappy_s++] = 244;
    
    strcpy(scene[3].name, "168FEE66");
    scene[3].start.size = 3;
    tme[237]=48;
    scene[3].start.label[0][0] = 537;
    tme[243]=63;
    scene[3].start.label[0][1] = 543;
    tme[238]=35;
    scene[3].start.label[1][0] = 538;
    tme[244]=43;
    scene[3].start.label[1][1] = 544;
    tme[239]=41;
    scene[3].start.label[2][0] = 539;
    tme[245]=55;
    scene[3].start.label[2][1] = 545;
    
    scene[3].end.size = 3;
    tme[240]=52;
    scene[3].end.label[0][0] = 540;
    tme[246]=50;
    scene[3].end.label[0][1] = 546;
    tme[241]=54;
    scene[3].end.label[1][0] = 541;
    tme[247]=52;
    scene[3].end.label[1][1] = 547;
    tme[242]=37;
    scene[3].end.label[2][0] = 542;
    tme[248]=29;
    scene[3].end.label[2][1] = 548;
    
    
    strcpy(scene[3].goods[0 ].name, "53C8AEAC99" );
    scene[3].goods[0].size = 4;
    tme[151]=44;
    scene[3].goods[0].label[0][0] = 301;
    tme[175]=57;
    scene[3].goods[0].label[0][1] = 325;
    tme[152]=77;
    scene[3].goods[0].label[1][0] = 302;
    tme[176]=50;
    scene[3].goods[0].label[1][1] = 326;
    tme[153]=48;
    scene[3].goods[0].label[2][0] = 303;
    tme[177]=54;
    scene[3].goods[0].label[2][1] = 327;
    tme[154]=58;
    scene[3].goods[0].label[3][0] = 304;
    tme[178]=48;
    scene[3].goods[0].label[3][1] = 328;
    
    strcpy(scene[3].goods[1 ].name, "83FBA3AC77" );
    scene[3].goods[1].size = 4;
    tme[155]=48;
    scene[3].goods[1].label[0][0] = 305;
    tme[179]=52;
    scene[3].goods[1].label[0][1] = 329;
    tme[156]=51;
    scene[3].goods[1].label[1][0] = 306;
    tme[180]=48;
    scene[3].goods[1].label[1][1] = 330;
    tme[157]=41;
    scene[3].goods[1].label[2][0] = 307;
    tme[181]=41;
    scene[3].goods[1].label[2][1] = 331;
    tme[158]=62;
    scene[3].goods[1].label[3][0] = 308;
    tme[182]=59;
    scene[3].goods[1].label[3][1] = 332;
    
    strcpy(scene[3].goods[2 ].name, "63E6A2AC8B" );
    scene[3].goods[2].size = 4;
    tme[159]=79;
    scene[3].goods[2].label[0][0] = 309;
    tme[183]=59;
    scene[3].goods[2].label[0][1] = 333;
    tme[160]=54;
    scene[3].goods[2].label[1][0] = 310;
    tme[184]=59;
    scene[3].goods[2].label[1][1] = 334;
    tme[161]=77;
    scene[3].goods[2].label[2][0] = 311;
    tme[185]=61;
    scene[3].goods[2].label[2][1] = 335;
    tme[162]=41;
    scene[3].goods[2].label[3][0] = 312;
    tme[186]=63;
    scene[3].goods[2].label[3][1] = 336;
    
    strcpy(scene[3].goods[3 ].name, "63B2B0061" ); 
    scene[3].goods[3].size = 4;
    tme[163]=53;
    scene[3].goods[3].label[0][0] = 313;
    tme[187]=50;
    scene[3].goods[3].label[0][1] = 337;
    tme[164]=51;
    scene[3].goods[3].label[1][0] = 314;
    tme[188]=48;
    scene[3].goods[3].label[1][1] = 338;
    tme[165]=39;
    scene[3].goods[3].label[2][0] = 315;
    tme[189]=59;
    scene[3].goods[3].label[2][1] = 339;
    tme[166]=46;
    scene[3].goods[3].label[3][0] = 316;
    tme[190]=54;
    scene[3].goods[3].label[3][1] = 340;
    
    strcpy(scene[3].goods[4 ].name, "335FACAC6C" ); 
    scene[3].goods[4].size = 4;
    tme[167]=53;
    scene[3].goods[4].label[0][0] = 317;
    tme[191]=50;
    scene[3].goods[4].label[0][1] = 341;
    tme[168]=46;
    scene[3].goods[4].label[1][0] = 318;
    tme[192]=70;
    scene[3].goods[4].label[1][1] = 342;
    tme[169]=51;
    scene[3].goods[4].label[2][0] = 319;
    tme[193]=48;
    scene[3].goods[4].label[2][1] = 343;
    tme[170]=69;
    scene[3].goods[4].label[3][0] = 320;
    tme[194]=63;
    scene[3].goods[4].label[3][1] = 344;
    
    strcpy(scene[3].goods[5 ].name, "4368A4AC23" ); 
    scene[3].goods[5].size = 4;
    tme[171]=60;
    scene[3].goods[5].label[0][0] = 321;
    tme[195]=61;
    scene[3].goods[5].label[0][1] = 345;
    unhappy[unhappy_s++] = 345;tme[172]=41;
    scene[3].goods[5].label[1][0] = 322;
    tme[196]=72;
    scene[3].goods[5].label[1][1] = 346;
    unhappy[unhappy_s++] = 346;tme[173]=48;
    scene[3].goods[5].label[2][0] = 323;
    tme[197]=68;
    scene[3].goods[5].label[2][1] = 347;
    unhappy[unhappy_s++] = 347;tme[174]=34;
    scene[3].goods[5].label[3][0] = 324;
    tme[198]=43;
    scene[3].goods[5].label[3][1] = 348;
    unhappy[unhappy_s++] = 348;
    
   // Serial.print("setup check right3!");
    */
    tme[250] = 8;
    tme[251] = 8;
    tme[252] = 8;
    tme[253] = 17;
    tme[254] = 11;
    tme[255] = 8;
}

/*
 *
 *
 *
 */




/*
 *
 *
 *
 */


void play(int name){
  delay(100);
    mp3_play(name);
    //delay(10000);
    //return;
//Serial.print("Find the file:");
//Serial.println(name);
//Serial.print("Delay for");
    if(name >= 600){
      
        delay((int)tme[name - 601 + 250] * 100);
    //    Serial.println(tme[name - 601 + 250] * 1000);
    }
    else{
        if(name >=400){
            delay(int(tme[200 + name % 100]) * 100);
        //    Serial.println(tme[200 + name % 100] * 100);
        }
        else
        {
            
        // /   Serial.println(name % 100 + name / 100 * 50 );
         //   Serial.println(tme[2]);
            delay((int)tme[name % 100 + (int)(name / 100) * 50 ] * 100);
          //  Serial.println((int)tme[name % 50 + name / 100 * 50 ] * 100);
        }
    }
}

void storyboard(){
    int i,happy,tmp;
    delay(2000);
    for(;seq_s < seq_t; seq_s++){
        
        play(seq[seq_s % MAX_EXP]);
        /*if(seq_s + 1 < seq_t){
            happy = 1;
            for(i = 0;i < unhappy_s;i++)
                if(unhappy[i] == seq[(seq_s + 1) % MAX_EXP])
                {
                    happy = 0;
                    break;
                }
            
            if(happy)
            {
                tmp = rand()%6;
                if(tmp < 4)
                    tmp /= 2;
                else
                    tmp -= 2;
            }
            else
                tmp = rand()% 2 + 4;
            play(601 + tmp);
        }*/
    }
    
}


int check(char* A, unsigned char* B){
    int i = 0;
    int j = 0;
    for(i = 0;i < 5; ++i){
        if(B[i] / 16  != 0)
        {
            if(B[i]/16>9)
            yoo[j++] = B[i] / 16 - 10 + 'A';
            else
                            yoo[j++] = B[i] / 16  + '0';
        }
        if(B[i]%16>9)
            yoo[j++] = B[i] % 16 - 10 + 'A';
        else
            yoo[j++] = B[i] % 16  + '0';
    }
    for(i = 0;i < j; ++i)
        if(A[i] != yoo[i])return 0;
    return 1;
}



void loop(){
  
    int i, j;
    if(rfid.isCard())
    {
        if (rfid.readCardSerial()) {
          
            char tmpstr[MAX_SENTENCE_LENGTH];
Serial.println("Find the card!");
             Serial.print("The card's number is  : ");
            Serial.print(rfid.serNum[0],HEX);
            Serial.print(rfid.serNum[1],HEX);
            Serial.print(rfid.serNum[2],HEX);
            Serial.print(rfid.serNum[3],HEX);
           Serial.print(rfid.serNum[4],HEX);
            Serial.println(" ");      
            
            for(i = 0;i < MAX_SCENE; ++i)
            {
                
Serial.print("Checking scence:   ");
Serial.print(scene[i].name);
Serial.println(" ");
                
                if(check(scene[i].name,rfid.serNum))
                  {
Serial.println("Find one card of scene!");
                    calc[i] ++;
                    if(calc[i] % 2 == 0){
                        int tmp = rand()%3;
                        play(scene[i].end.label[tmp][0]);
                        seq[(seq_t++)%MAX_EXP] = scene[i].end.label[tmp][1];
                        storyboard();
                    }
                    else{
                        int tmp = rand()%3;
                        play(scene[i].start.label[tmp][0]);
                        seq[(seq_t++)%MAX_EXP] = scene[i].start.label[tmp][1];
                    }
                    return;
                }
            
                Serial.println("Ooops , no scene found ");
                for(j = 0;j < GOODS_PER_SCENE; ++j){
                      Serial.print("Checking goods:   ");
                      Serial.print(scene[i].goods[j].name);
Serial.println(" ");
                  
                    if(check(scene[i].goods[j].name,rfid.serNum))
                    {
                        Serial.println("Find one card of goods!");
                        int tmp = rand()%scene[i].goods[j].size;
                        play(scene[i].goods[j].label[tmp][0]);
                        seq[(seq_t++)%MAX_EXP] = scene[i].goods[j].label[tmp][1];
                        return;
                    }
                }
               Serial.println("Ooops , no goods found ");
            }
            

        }
        rfid.selectTag(rfid.serNum);
    }

    rfid.halt();
    
}



void setup()
{
    
    int i;
    
    Serial.begin(9600);
    //while(!Serial);
    delay(2000);
    mySerial.begin(9600);
    
    
    
//    Serial.print("setup check right!");
    mp3_set_serial (mySerial);  //set Serial for DFPlayer-mini mp3 module
 //     Serial.print("setup check right11!");
 delay(2000);
    mp3_set_volume (20);
   delay(2000);
 //     Serial.print("setup check right12!");
    // read Rfid
    //Serial.println("\\:v 100");*/
    SPI.begin();
 //     Serial.print("setup check right13!");
    rfid.init(); 
 
 
 //Serial.print("setup check right!second");
 unhappy_s = 0;
    
     strcpy(scene[0].name, "735A3021B");
    scene[0].start.size = 3;
    tme[201]=42;
    scene[0].start.label[0][0] = 501;
    tme[207]=37;
    scene[0].start.label[0][1] = 507;
    tme[202]=56;
    scene[0].start.label[1][0] = 502;
    tme[208]=52;
    scene[0].start.label[1][1] = 508;
    tme[203]=59;
    scene[0].start.label[2][0] = 503;
    tme[209]=57;
    scene[0].start.label[2][1] = 509;
    
    Serial.print("setup check right2!");
   
    scene[0].end.size = 3;
    tme[204]=30;
    scene[0].end.label[0][0] = 504;
    tme[210]=32;
    scene[0].end.label[0][1] = 510;
    tme[205]=36;
    scene[0].end.label[1][0] = 505;
    tme[211]=38;
    scene[0].end.label[1][1] = 511;
    tme[206]=43;
    scene[0].end.label[2][0] = 506;
    tme[212]=49;
    scene[0].end.label[2][1] = 512;

    
    strcpy(scene[0].goods[0 ].name, "B3A6B30A6" );
    scene[0].goods[0].size = 4;
    tme[1]=60;
    scene[0].goods[0].label[0][0] = 1;
    tme[25]=83;
    scene[0].goods[0].label[0][1] = 25;
    tme[2]=68;
    scene[0].goods[0].label[1][0] = 2;
    tme[26]=72;
    scene[0].goods[0].label[1][1] = 26;
    tme[3]=33;
    scene[0].goods[0].label[2][0] = 3;
    tme[27]=60;
    scene[0].goods[0].label[2][1] = 27;
    tme[4]=52;
    scene[0].goods[0].label[3][0] = 4;
    tme[28]=61;
    scene[0].goods[0].label[3][1] = 28;
    
    strcpy(scene[0].goods[1 ].name, "D318ADACCA" );
    scene[0].goods[1].size = 4;
    tme[5]=40;
    scene[0].goods[1].label[0][0] = 5;
    tme[29]=55;
    scene[0].goods[1].label[0][1] = 29;
    tme[6]=67;
    scene[0].goods[1].label[1][0] = 6;
    tme[30]=95;
    scene[0].goods[1].label[1][1] = 30;
    tme[7]=33;
    scene[0].goods[1].label[2][0] = 7;
    tme[31]=63;
    scene[0].goods[1].label[2][1] = 31;
    tme[8]=37;
    scene[0].goods[1].label[3][0] = 8;
    tme[32]=74;
    scene[0].goods[1].label[3][1] = 32;
    
    strcpy(scene[0].goods[2 ].name, "D3CA6ACD5" );
    scene[0].goods[2].size = 4;
    tme[9]=28;
    scene[0].goods[2].label[0][0] = 9;
    tme[33]=44;
    scene[0].goods[2].label[0][1] = 33;
    tme[10]=27;
    scene[0].goods[2].label[1][0] = 10;
    tme[34]=51;
    scene[0].goods[2].label[1][1] = 34;
    tme[11]=35;
    scene[0].goods[2].label[2][0] = 11;
    tme[35]=45;
    scene[0].goods[2].label[2][1] = 35;
    tme[12]=16;
    scene[0].goods[2].label[3][0] = 12;
    tme[36]=59;
    scene[0].goods[2].label[3][1] = 36;
     
  
  
   Serial.print("setup check right3!");
    strcpy(scene[0].goods[3 ].name, "838CB30BC" );
    scene[0].goods[3].size = 4;
    tme[13]=26;
    scene[0].goods[3].label[0][0] = 13;
    tme[37]=46;
    scene[0].goods[3].label[0][1] = 37;
    tme[14]=32;
    scene[0].goods[3].label[1][0] = 14;
    tme[38]=53;
    scene[0].goods[3].label[1][1] = 38;
    tme[15]=31;
    scene[0].goods[3].label[2][0] = 15;
    tme[39]=59;
    scene[0].goods[3].label[2][1] = 39;
    tme[16]=27;
    scene[0].goods[3].label[3][0] = 16;
    tme[40]=44;
    scene[0].goods[3].label[3][1] = 40;
    
    strcpy(scene[0].goods[4 ].name, "83F9A5805F" );
    scene[0].goods[4].size = 4;
    tme[17]=25;
    scene[0].goods[4].label[0][0] = 17;
    tme[41]=66;
    scene[0].goods[4].label[0][1] = 41;
    tme[18]=26;
    scene[0].goods[4].label[1][0] = 18;
    tme[42]=45;
    scene[0].goods[4].label[1][1] = 42;
    tme[19]=33;
    scene[0].goods[4].label[2][0] = 19;
    tme[43]=48;
    scene[0].goods[4].label[2][1] = 43;
    tme[20]=37;
    scene[0].goods[4].label[3][0] = 20;
    tme[44]=57;
    scene[0].goods[4].label[3][1] = 44;
    
    strcpy(scene[0].goods[5 ].name, "23D22E2DD" );
    scene[0].goods[5].size = 4;
    tme[21]=40;
    scene[0].goods[5].label[0][0] = 21;
    tme[45]=46;
    scene[0].goods[5].label[0][1] = 45;
    unhappy[unhappy_s++] = 45;tme[22]=45;
    scene[0].goods[5].label[1][0] = 22;
    tme[46]=46;
    scene[0].goods[5].label[1][1] = 46;
    unhappy[unhappy_s++] = 46;tme[23]=47;
    scene[0].goods[5].label[2][0] = 23;
    tme[47]=66;
    scene[0].goods[5].label[2][1] = 47;
    unhappy[unhappy_s++] = 47;tme[24]=51;
    scene[0].goods[5].label[3][0] = 24;
    tme[48]=72;
    scene[0].goods[5].label[3][1] = 48;
    unhappy[unhappy_s++] = 48;

  
  
   Serial.print("setup check right4!");
    strcpy(scene[1].name, "33D8ADACEA");
    scene[1].start.size = 3;
    tme[213]=43;
    scene[1].start.label[0][0] = 513;
    tme[219]=33;
    scene[1].start.label[0][1] = 519;
    tme[214]=53;
    scene[1].start.label[1][0] = 514;
    tme[220]=57;
    scene[1].start.label[1][1] = 520;
    tme[215]=31;
    scene[1].start.label[2][0] = 515;
    tme[221]=23;
    scene[1].start.label[2][1] = 521;
    
    scene[1].end.size = 3;
    tme[216]=59;
    scene[1].end.label[0][0] = 516;
    tme[222]=62;
    scene[1].end.label[0][1] = 522;
    tme[217]=37;
    scene[1].end.label[1][0] = 517;
    tme[223]=54;
    scene[1].end.label[1][1] = 523;
    tme[218]=32;
    scene[1].end.label[2][0] = 518;
    tme[224]=33;
    scene[1].end.label[2][1] = 524;
    
    
    strcpy(scene[1].goods[0 ].name, "43345F22A" );
    scene[1].goods[0].size = 3;
    tme[51]=48;
    scene[1].goods[0].label[0][0] = 101;
    tme[69]=68;
    scene[1].goods[0].label[0][1] = 119;
    tme[52]=53;
    scene[1].goods[0].label[1][0] = 102;
    tme[70]=91;
    scene[1].goods[0].label[1][1] = 120;
    tme[53]=36;
    scene[1].goods[0].label[2][0] = 103;
    tme[71]=77;
    scene[1].goods[0].label[2][1] = 121;
    
    strcpy(scene[1].goods[1 ].name, "99F3F055CF" );
    scene[1].goods[1].size = 3;
    tme[54]=48;
    scene[1].goods[1].label[0][0] = 104;
    tme[72]=74;
    scene[1].goods[1].label[0][1] = 122;
    tme[55]=46;
    scene[1].goods[1].label[1][0] = 105;
    tme[73]=57;
    scene[1].goods[1].label[1][1] = 123;
    tme[56]=46;
    scene[1].goods[1].label[2][0] = 106;
    tme[74]=51;
    scene[1].goods[1].label[2][1] = 124;
    
    strcpy(scene[1].goods[2 ].name, "9345392ED" );
    scene[1].goods[2].size = 3;
    tme[57]=53;
    scene[1].goods[2].label[0][0] = 107;
    tme[75]=71;
    scene[1].goods[2].label[0][1] = 125;
    tme[58]=42;
    scene[1].goods[2].label[1][0] = 108;
    tme[76]=57;
    scene[1].goods[2].label[1][1] = 126;
    tme[59]=57;
    scene[1].goods[2].label[2][0] = 109;
    tme[77]=91;
    scene[1].goods[2].label[2][1] = 127;
    
    strcpy(scene[1].goods[3 ].name, "9320D1062" );
    scene[1].goods[3].size = 3;
    tme[60]=61;
    scene[1].goods[3].label[0][0] = 110;
    tme[78]=74;
    scene[1].goods[3].label[0][1] = 128;
    tme[61]=68;
    scene[1].goods[3].label[1][0] = 111;
    tme[79]=85;
    scene[1].goods[3].label[1][1] = 129;
    tme[62]=64;
    scene[1].goods[3].label[2][0] = 112;
    tme[80]=65;
    scene[1].goods[3].label[2][1] = 130;
    
    strcpy(scene[1].goods[4 ].name, "34130270" );
    scene[1].goods[4].size = 3;
    tme[63]=61;
    scene[1].goods[4].label[0][0] = 113;
    tme[81]=71;
    scene[1].goods[4].label[0][1] = 131;
    tme[64]=34;
    scene[1].goods[4].label[1][0] = 114;
    tme[82]=60;
    scene[1].goods[4].label[1][1] = 132;
    tme[65]=51;
    scene[1].goods[4].label[2][0] = 115;
    tme[83]=77;
    scene[1].goods[4].label[2][1] = 133;
    
    strcpy(scene[1].goods[5 ].name, "9385D2C4" );
    scene[1].goods[5].size = 3;
    tme[66]=51;
    scene[1].goods[5].label[0][0] = 116;
    tme[84]=68;
    scene[1].goods[5].label[0][1] = 134;
    unhappy[unhappy_s++] = 134;tme[67]=79;
    scene[1].goods[5].label[1][0] = 117;
    tme[85]=94;
    scene[1].goods[5].label[1][1] = 135;
    unhappy[unhappy_s++] = 135;tme[68]=61;
    scene[1].goods[5].label[2][0] = 118;
    tme[86]=60;
    scene[1].goods[5].label[2][1] = 136;
    unhappy[unhappy_s++] = 136;
    
    
    strcpy(scene[2].name, "C3BBA6AC72");
    scene[2].start.size = 3;
    tme[225]=58;
    scene[2].start.label[0][0] = 525;
    tme[231]=63;
    scene[2].start.label[0][1] = 531;
    tme[226]=50;
    scene[2].start.label[1][0] = 526;
    tme[232]=40;
    scene[2].start.label[1][1] = 532;
    tme[227]=43;
    scene[2].start.label[2][0] = 527;
    tme[233]=55;
    scene[2].start.label[2][1] = 533;
    
    scene[2].end.size = 3;
    tme[228]=51;
    scene[2].end.label[0][0] = 528;
    tme[234]=50;
    scene[2].end.label[0][1] = 534;
    tme[229]=52;
    scene[2].end.label[1][0] = 529;
    tme[235]=55;
    scene[2].end.label[1][1] = 535;
    tme[230]=44;
    scene[2].end.label[2][0] = 530;
    tme[236]=42;
    scene[2].end.label[2][1] = 536;
    
    
    strcpy(scene[2].goods[0 ].name, "A356AFACF6" );
    scene[2].goods[0].size = 4;
    tme[101]=66;
    scene[2].goods[0].label[0][0] = 201;
    tme[123]=87;
    scene[2].goods[0].label[0][1] = 223;
    tme[102]=85;
    scene[2].goods[0].label[1][0] = 202;
    tme[124]=98;
    scene[2].goods[0].label[1][1] = 224;
    tme[103]=66;
    scene[2].goods[0].label[2][0] = 203;
    tme[125]=71;
    scene[2].goods[0].label[2][1] = 225;
    tme[104]=78;
    scene[2].goods[0].label[3][0] = 204;
    tme[126]=75;
    scene[2].goods[0].label[3][1] = 226;
    
    strcpy(scene[2].goods[1 ].name, "83BDA6AC34" );
    scene[2].goods[1].size = 4;
    tme[105]=61;
    scene[2].goods[1].label[0][0] = 205;
    tme[127]=66;
    scene[2].goods[1].label[0][1] = 227;
    tme[106]=73;
    scene[2].goods[1].label[1][0] = 206;
    tme[128]=103;
    scene[2].goods[1].label[1][1] = 228;
    tme[107]=36;
    scene[2].goods[1].label[2][0] = 207;
    tme[129]=66;
    scene[2].goods[1].label[2][1] = 229;
    tme[108]=45;
    scene[2].goods[1].label[3][0] = 208;
    tme[130]=73;
    scene[2].goods[1].label[3][1] = 230;
    
    strcpy(scene[2].goods[2 ].name, "2346AFAC66" );
    scene[2].goods[2].size = 4;
    tme[109]=52;
    scene[2].goods[2].label[0][0] = 209;
    tme[131]=46;
    scene[2].goods[2].label[0][1] = 231;
    tme[110]=55;
    scene[2].goods[2].label[1][0] = 210;
    tme[132]=57;
    scene[2].goods[2].label[1][1] = 232;
    tme[111]=57;
    scene[2].goods[2].label[2][0] = 211;
    tme[133]=62;
    scene[2].goods[2].label[2][1] = 233;
    tme[112]=57;
    scene[2].goods[2].label[3][0] = 212;
    tme[134]=62;
    scene[2].goods[2].label[3][1] = 234;
    
    strcpy(scene[2].goods[3 ].name, "53813A2FA" );
    scene[2].goods[3].size = 4;
    tme[113]=43;
    scene[2].goods[3].label[0][0] = 213;
    tme[135]=66;
    scene[2].goods[3].label[0][1] = 235;
    tme[114]=64;
    scene[2].goods[3].label[1][0] = 214;
    tme[136]=69;
    scene[2].goods[3].label[1][1] = 236;
    tme[115]=43;
    scene[2].goods[3].label[2][0] = 215;
    tme[137]=60;
    scene[2].goods[3].label[2][1] = 237;
    tme[116]=50;
    scene[2].goods[3].label[3][0] = 216;
    tme[138]=71;
    scene[2].goods[3].label[3][1] = 238;
    
    strcpy(scene[2].goods[4 ].name, "53553A23E" );
    scene[2].goods[4].size = 3;
    tme[117]=48;
    scene[2].goods[4].label[0][0] = 217;
    tme[139]=64;
    scene[2].goods[4].label[0][1] = 239;
    tme[118]=45;
    scene[2].goods[4].label[1][0] = 218;
    tme[140]=60;
    scene[2].goods[4].label[1][1] = 240;
    tme[119]=55;
    scene[2].goods[4].label[2][0] = 219;
    tme[141]=51;
    scene[2].goods[4].label[2][1] = 241;
    
    strcpy(scene[2].goods[5 ].name, "1391ADAC83" );
    scene[2].goods[5].size = 3;
    tme[120]=57;
    scene[2].goods[5].label[0][0] = 220;
    tme[142]=60;
    scene[2].goods[5].label[0][1] = 242;
    unhappy[unhappy_s++] = 242;tme[121]=50;
    scene[2].goods[5].label[1][0] = 221;
    tme[143]=62;
    scene[2].goods[5].label[1][1] = 243;
    unhappy[unhappy_s++] = 243;tme[122]=52;
    scene[2].goods[5].label[2][0] = 222;
    tme[144]=69;
    scene[2].goods[5].label[2][1] = 244;
    unhappy[unhappy_s++] = 244;
    
    strcpy(scene[3].name, "168FEE66");
    scene[3].start.size = 3;
    tme[237]=48;
    scene[3].start.label[0][0] = 537;
    tme[243]=63;
    scene[3].start.label[0][1] = 543;
    tme[238]=35;
    scene[3].start.label[1][0] = 538;
    tme[244]=43;
    scene[3].start.label[1][1] = 544;
    tme[239]=41;
    scene[3].start.label[2][0] = 539;
    tme[245]=55;
    scene[3].start.label[2][1] = 545;
    
    scene[3].end.size = 3;
    tme[240]=52;
    scene[3].end.label[0][0] = 540;
    tme[246]=50;
    scene[3].end.label[0][1] = 546;
    tme[241]=54;
    scene[3].end.label[1][0] = 541;
    tme[247]=52;
    scene[3].end.label[1][1] = 547;
    tme[242]=37;
    scene[3].end.label[2][0] = 542;
    tme[248]=29;
    scene[3].end.label[2][1] = 548;
    
    
    strcpy(scene[3].goods[0 ].name, "53C8AEAC99" );
    scene[3].goods[0].size = 4;
    tme[151]=44;
    scene[3].goods[0].label[0][0] = 301;
    tme[175]=57;
    scene[3].goods[0].label[0][1] = 325;
    tme[152]=77;
    scene[3].goods[0].label[1][0] = 302;
    tme[176]=50;
    scene[3].goods[0].label[1][1] = 326;
    tme[153]=48;
    scene[3].goods[0].label[2][0] = 303;
    tme[177]=54;
    scene[3].goods[0].label[2][1] = 327;
    tme[154]=58;
    scene[3].goods[0].label[3][0] = 304;
    tme[178]=48;
    scene[3].goods[0].label[3][1] = 328;
    
    strcpy(scene[3].goods[1 ].name, "83FBA3AC77" );
    scene[3].goods[1].size = 4;
    tme[155]=48;
    scene[3].goods[1].label[0][0] = 305;
    tme[179]=52;
    scene[3].goods[1].label[0][1] = 329;
    tme[156]=51;
    scene[3].goods[1].label[1][0] = 306;
    tme[180]=48;
    scene[3].goods[1].label[1][1] = 330;
    tme[157]=41;
    scene[3].goods[1].label[2][0] = 307;
    tme[181]=41;
    scene[3].goods[1].label[2][1] = 331;
    tme[158]=62;
    scene[3].goods[1].label[3][0] = 308;
    tme[182]=59;
    scene[3].goods[1].label[3][1] = 332;
    
    strcpy(scene[3].goods[2 ].name, "63E6A2AC8B" );
    scene[3].goods[2].size = 4;
    tme[159]=79;
    scene[3].goods[2].label[0][0] = 309;
    tme[183]=59;
    scene[3].goods[2].label[0][1] = 333;
    tme[160]=54;
    scene[3].goods[2].label[1][0] = 310;
    tme[184]=59;
    scene[3].goods[2].label[1][1] = 334;
    tme[161]=77;
    scene[3].goods[2].label[2][0] = 311;
    tme[185]=61;
    scene[3].goods[2].label[2][1] = 335;
    tme[162]=41;
    scene[3].goods[2].label[3][0] = 312;
    tme[186]=63;
    scene[3].goods[2].label[3][1] = 336;
    
    strcpy(scene[3].goods[3 ].name, "63B2B0061" ); 
    scene[3].goods[3].size = 4;
    tme[163]=53;
    scene[3].goods[3].label[0][0] = 313;
    tme[187]=50;
    scene[3].goods[3].label[0][1] = 337;
    tme[164]=51;
    scene[3].goods[3].label[1][0] = 314;
    tme[188]=48;
    scene[3].goods[3].label[1][1] = 338;
    tme[165]=39;
    scene[3].goods[3].label[2][0] = 315;
    tme[189]=59;
    scene[3].goods[3].label[2][1] = 339;
    tme[166]=46;
    scene[3].goods[3].label[3][0] = 316;
    tme[190]=54;
    scene[3].goods[3].label[3][1] = 340;
    
    strcpy(scene[3].goods[4 ].name, "335FACAC6C" ); 
    scene[3].goods[4].size = 4;
    tme[167]=53;
    scene[3].goods[4].label[0][0] = 317;
    tme[191]=50;
    scene[3].goods[4].label[0][1] = 341;
    tme[168]=46;
    scene[3].goods[4].label[1][0] = 318;
    tme[192]=70;
    scene[3].goods[4].label[1][1] = 342;
    tme[169]=51;
    scene[3].goods[4].label[2][0] = 319;
    tme[193]=48;
    scene[3].goods[4].label[2][1] = 343;
    tme[170]=69;
    scene[3].goods[4].label[3][0] = 320;
    tme[194]=63;
    scene[3].goods[4].label[3][1] = 344;
    
    strcpy(scene[3].goods[5 ].name, "4368A4AC23" ); 
    scene[3].goods[5].size = 4;
    tme[171]=60;
    scene[3].goods[5].label[0][0] = 321;
    tme[195]=61;
    scene[3].goods[5].label[0][1] = 345;
    unhappy[unhappy_s++] = 345;tme[172]=41;
    scene[3].goods[5].label[1][0] = 322;
    tme[196]=72;
    scene[3].goods[5].label[1][1] = 346;
    unhappy[unhappy_s++] = 346;tme[173]=48;
    scene[3].goods[5].label[2][0] = 323;
    tme[197]=68;
    scene[3].goods[5].label[2][1] = 347;
    unhappy[unhappy_s++] = 347;tme[174]=34;
    scene[3].goods[5].label[3][0] = 324;
    tme[198]=43;
    scene[3].goods[5].label[3][1] = 348;
    unhappy[unhappy_s++] = 348;
   /**/
    
    
    for(i = 0;i < MAX_SCENE; ++i)
        calc[i] = 0;
    
    //ready for storyboard
    seq_s = 0,seq_t = 0;
    /* read and play mp3 */   
}

