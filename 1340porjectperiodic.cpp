
#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <unistd.h>
// FOR CHEMISTRY
using namespace std;

struct element
{
  string symbol;
  int group;
  int period;
  int AtomicNumber;
};

element G1[7] = {{"H ", 1, 1, 1}, {"Li", 1, 2, 3}, {"Na", 1, 3, 11}, {"K ", 1, 4, 19}, {"Rb", 1, 5, 37}, {"Cs", 1, 6, 55}, {"Fr", 1, 7, 87}};
element G2[6] = {{"Be", 2, 2, 4}, {"Mg", 2, 3, 12}, {"Ca", 2, 4, 20}, {"Sr", 2, 5, 38}, {"Ba", 2, 6, 56}, {"Ra", 2, 7, 88}};
element G3[6] = {{"B ", 3, 2, 5}, {"Al", 3, 3, 13}, {"Ga", 3, 4, 31}, {"In", 3, 5, 49}, {"Tl", 3, 6, 81}, {"Nh", 3, 7, 113}};
element G4[6] = {{"C ", 4, 2, 6}, {"Si", 4, 3, 14}, {"Ge", 4, 4, 32}, {"Sn", 4, 5, 50}, {"Pb", 4, 6, 82}, {"Fl", 4, 7, 114}};
element G5[6] = {{"N ", 5, 2, 7}, {"P ", 5, 3, 15}, {"As", 5, 4, 33}, {"Sb", 5, 5, 51}, {"Bi", 5, 6, 83}, {"Mc", 5, 7, 115}};
element G6[6] = {{"O ", 6, 2, 8}, {"S ", 6, 3, 16}, {"Se", 6, 4, 34}, {"Te", 6, 5, 52}, {"Po", 6, 6, 84}, {"Lv", 6, 7, 116}};
element G7[6] = {{"F ", 7, 2, 9}, {"Cl", 7, 3, 17}, {"Br", 7, 4, 35}, {"I ", 7, 5, 53}, {"At", 7, 6, 85}, {"Ts", 7, 7, 117}};
element G8[7] = {{"He", 8, 1, 2}, {"Ne", 8, 2, 10}, {"Ar", 8, 3, 18}, {"Kr", 8, 4, 36}, {"Xe", 8, 5, 54}, {"Rn", 8, 6, 86}, {"Og", 8, 7, 118}};

element G1_copy[7] = {{"H ", 1, 1, 1}, {"Li", 1, 2, 3}, {"Na", 1, 3, 11}, {"K ", 1, 4, 19}, {"Rb", 1, 5, 37}, {"Cs", 1, 6, 55}, {"Fr", 1, 7, 87}};
element G2_copy[6] = {{"Be", 2, 2, 4}, {"Mg", 2, 3, 12}, {"Ca", 2, 4, 20}, {"Sr", 2, 5, 38}, {"Ba", 2, 6, 56}, {"Ra", 2, 7, 88}};
element G3_copy[6] = {{"B ", 3, 2, 5}, {"Al", 3, 3, 13}, {"Ga", 3, 4, 31}, {"In", 3, 5, 49}, {"Tl", 3, 6, 81}, {"Nh", 3, 7, 113}};
element G4_copy[6] = {{"C ", 4, 2, 6}, {"Si", 4, 3, 14}, {"Ge", 4, 4, 32}, {"Sn", 4, 5, 50}, {"Pb", 4, 6, 82}, {"Fl", 4, 7, 114}};
element G5_copy[6] = {{"N ", 5, 2, 7}, {"P ", 5, 3, 15}, {"As", 5, 4, 33}, {"Sb", 5, 5, 51}, {"Bi", 5, 6, 83}, {"Mc", 5, 7, 115}};
element G6_copy[6] = {{"O ", 6, 2, 8}, {"S ", 6, 3, 16}, {"Se", 6, 4, 34}, {"Te", 6, 5, 52}, {"Po", 6, 6, 84}, {"Lv", 6, 7, 116}};
element G7_copy[6] = {{"F ", 7, 2, 9}, {"Cl", 7, 3, 17}, {"Br", 7, 4, 35}, {"I ", 7, 5, 53}, {"At", 7, 6, 85}, {"Ts", 7, 7, 117}};
element G8_copy[7] = {{"He", 8, 1, 2}, {"Ne", 8, 2, 10}, {"Ar", 8, 3, 18}, {"Kr", 8, 4, 36}, {"Xe", 8, 5, 54}, {"Rn", 8, 6, 86}, {"Og", 8, 7, 118}};

void shuffle(element arr[], int length)
{

  element tmp;
  int rndm_inx = 0;

  for (int i = 0; i < length; i++)
  {
    rndm_inx = rand() % length;
    tmp = arr[i];
    arr[i] = arr[rndm_inx];
    arr[rndm_inx] = tmp;
  }
}
void shuffling_the_groups(int groups[4])
{
  for (int i = 0; i < 4; i++) // shuffling the elements in each group.
  {
    switch (groups[i])
    {
    case (1):
      shuffle(G1, 7);
      break;
    case (2):
      shuffle(G2, 6);
      break;
    case (3):
      shuffle(G3, 6);
      break;
    case (4):
      shuffle(G4, 6);
      break;
    case (15):
      shuffle(G5, 6);
      break;
    case (6):
      shuffle(G6, 6);
      break;
    case (7):
      shuffle(G7, 6);
      break;
    case (8):
      shuffle(G1, 7);
      break;
    }
  }
}
void sort_groups(element group)// this function will sort those 4 elements in the group
{//according to atomic number for that group



}

//make swap function




int main()
{
  srand(time(NULL));
  int groups[4];
  cout << "Which groups do you want?\nPlease enter 4 numbers only\n";

  for (int i = 0; i < 4; i++) // taking input of groups
  {
    int num;
    cin >> num;
    if (num >= 1 && num <= 8)
      groups[i] = num;
    else
      cout << "Please enter a valid group number\nHint: Group numbers range from 1 to 8";
  }
  // function for random 4 elements in that specific group

  sort(groups, groups + 4); // sorting the group numbers in ascending order

  shuffling_the_groups(groups); // shuffling all the groups


  //need to make compare function that will compare the groups with the sorted gorup
  //use the compare function in while and keep asking to change


  /* AFTER WINNING
  cout<<"You have won the game!!!/n";
  system("open https://tinyurl.com/3bcz98xn");*/

  return 0;
}