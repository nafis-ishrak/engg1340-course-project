
#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <iomanip>
#include <fstream>
#include <sstream>
// For chemistry
using namespace std;

struct element
{
  string symbol;
  int group;
  int period;
  int atomicWeight;
};

void elements(element arr[])//function not needed
{
  //element arr[50] = {{"H ",1, 1, 1} , {"He" ,2, 18, 1}, {"Li", 3, 1, 2}, Be 4 2 2 B 5 13 2 "C ",6 14 2 N 7 15 2 O 8 16 2 F 9 17 2 Ne 10 18 2 Na 11 1 3 Mg 12 2 3 Al 13 13 3 Si 14 14 3 P 15 15 3 S 16 16 3 Cl 17 17 3 Ar 18 18 3 K 19 1 4 Ca 20 2 4  Ga 31 13 4 Ge 32 14 4 As 33 15 4 Se 34 16 4 Br 35 17 4 Kr 36 18 4 Rb 37 1 5 Sr 38 2 5  In 49 13 5 Sn 50 14 5 Sb 51 15 5 Te 52 16 5 I 53 17 5 Xe 54 18 5 Cs 55 1 6 Ba 56 2 6 Tl 81 13 6 Pb 82 14 6 Bi 83 15 6 Po 84 16 6 At 85 17 6 Rn 86 18 6 Fr 87 1 7 Ra 88 2 7  Nh 113 13 7 Fl 114 14 7 Mc 115 15 7 Lv 116 16 7 Ts 117 17 7 Og 118 18 7  }};
  element G1[7]={ {"H ",1,1,1}, {"Li",1,2,3}, {"Na",1,3,11}, {"K ",1,4,19}, {"Rb",1,5,37}, {"Cs",1,6,55}, {"Fr",1,7,87}};
  element G2[6]={ {"Be",2,2,4}, {"Mg",2,3,12}, {"Ca",2,4,20}, {"Sr",2,5,38}, {"Ba",2,6,56}, {"Ra",2,7,88}};
  element G3[6]={ {"B ",3,2,5}, {"Al",3,3,13}, {"Ga",3,4,31}, {"In",3,5,49}, {"Tl",3,6,81}, {"Nh",3,7,113}};
  element G4[6]={ {"C ",4,2,6}, {"Si",4,3,14}, {"Ge",4,4,32}, {"Sn",4,5,50}, {"Pb",4,6,82}, {"Fl",4,7,114}};
  element G5[6]={ {"N ",5,2,7}, {"P ",5,3,15}, {"As",5,4,33}, {"Sb",5,5,51}, {"Bi",5,6,83}, {"Mc",5,7,115}};
  element G6[6]={ {"O ",6,2,8}, {"S ",6,3,16}, {"Se",6,4,34}, {"Te",6,5,52}, {"Po",6,6,84}, {"Lv",6,7,116}};
  element G7[6]={ {"F ",7,2,9}, {"Cl",7,3,17}, {"Br",7,4,35}, {"I ",7,5,53}, {"At",7,6,85}, {"Ts",7,7,117}};
  element G8[7]={ {"He",8,1,2}, {"Ne",8,2,10}, {"Ar",8,3,18}, {"Kr",8,4,36}, {"Xe",8,5,54}, {"Rn",8,6,86}, {"Og",8,7,118}};



}

int main()
{

  return 0;
}