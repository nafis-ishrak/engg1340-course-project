#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <ctime>
#include "periodictable.h"
#include "numbers.h"

using namespace std;

std::string SG1[6], SG2[6], SG3[6], SG4[6], SG5[6], SG6[6], SG7[6], SG8[6];

std::string G1[6]= {"H", "Li", "Na", "K", "Rb", "Cs"};
std::string G2[6]= {"Be", "Mg", "Ca", "Sr", "Ba", "Ra"};
std::string G3[6]= {"B", "Al", "Ga", "In", "Tl", "Nh"};
std::string G4[6]= {"C", "Si", "Ge", "Sn", "Pb", "Fl"};
std::string G5[6] = {"N", "P", "As", "Sb","Bi", "Mc"};
std::string G6[6] = {"O", "S ", "Se", "Te", "Po", "Lv"};
std::string G7[6] = {"F", "Cl", "Br", "I", "At", "Ts"};
std::string G8[6] = {"He","Ne", "Ar", "Kr", "Xe", "Rn"};

int numbers[6]={0,1,2,3,4,5};

struct element
{
  std::string symbol;
  int group;
  int period;
  int AtomicNumber;
};

element Group1[6] = {{"H ", 1, 1, 1}, {"Li", 1, 2, 3}, {"Na", 1, 3, 11}, {"K ", 1, 4, 19}, {"Rb", 1, 5, 37}, {"Cs", 1, 6, 55}};
element Group2[6] = {{"Be", 2, 2, 4}, {"Mg", 2, 3, 12}, {"Ca", 2, 4, 20}, {"Sr", 2, 5, 38}, {"Ba", 2, 6, 56}, {"Ra", 2, 7, 88}};
element Group3[6] = {{"B ", 3, 2, 5}, {"Al", 3, 3, 13}, {"Ga", 3, 4, 31}, {"In", 3, 5, 49}, {"Tl", 3, 6, 81}, {"Nh", 3, 7, 113}};
element Group4[6] = {{"C ", 4, 2, 6}, {"Si", 4, 3, 14}, {"Ge", 4, 4, 32}, {"Sn", 4, 5, 50}, {"Pb", 4, 6, 82}, {"Fl", 4, 7, 114}};
element Group5[6] = {{"N ", 5, 2, 7}, {"P ", 5, 3, 15}, {"As", 5, 4, 33}, {"Sb", 5, 5, 51}, {"Bi", 5, 6, 83}, {"Mc", 5, 7, 115}};
element Group6[6] = {{"O ", 6, 2, 8}, {"S ", 6, 3, 16}, {"Se", 6, 4, 34}, {"Te", 6, 5, 52}, {"Po", 6, 6, 84}, {"Lv", 6, 7, 116}};
element Group7[6] = {{"F ", 7, 2, 9}, {"Cl", 7, 3, 17}, {"Br", 7, 4, 35}, {"I ", 7, 5, 53}, {"At", 7, 6, 85}, {"Ts", 7, 7, 117}};
element Group8[6] = {{"He", 8, 1, 2}, {"Ne", 8, 2, 10}, {"Ar", 8, 3, 18}, {"Kr", 8, 4, 36}, {"Xe", 8, 5, 54}, {"Rn", 8, 6, 86}};


int main()
{
    int input;
    cout << "*** WELCOME TO THE 15 PUZZLE GAME! ***\n*** WHAT DO YOU WANT TO PLAY? ***\nPress 1 for Numbers\nPress 2 for Periodic Table\n\n";
    cin>>input;

    if (input==1){

        cout << "\n*** WELLCOME TO THE NUMBER ARRANGING GAME ***\n*** HERE YOU NEED TO ARRANGE THE BOARD IN SUCH A WAY THAT ALL NUMBERS ARE IN ASCENDING ORDER STARTING FROM THE FIRST ROW (LEFT TO RIGHT). ***\n\n                         GOOD LUCK!!!               \n\n";

        srand(time(NULL)); // so that there are different random numbers in every attempt of the game

        int array[16];
        int hundred_numbers[100]; // storing all the numbers in an array

        for (int i = 0; i < 100; i++) // adding values
        {
            hundred_numbers[i] = i;
        }

        shuffle(hundred_numbers, 100); // shuffling the all the numbers

        for (int i = 0; i < 16; i++)
        {
            array[i] = hundred_numbers[i]; // storing the first 16 random numbers to the array
        }

        int sorted_arr[16];

        copy(begin(array), end(array), begin(sorted_arr)); // copying the array
        sort(sorted_arr, sorted_arr + 16);// sorting the array in ascending order

        PrintBoard(array); // print out board
        cout << "\n";

        while (compare_arrays(array, sorted_arr) == false) // checks if the game is over or not
        {
            int from, to;
            cout << "Which number do you want to replace  ";
            cin >> from; // NEED TO GIVE A CHECK IF THERE IS A NUMBER
            if (NumberPresent(array, from) == false)
            {
                while (NumberPresent(array, from) == false)//continues to ask input until a valid number is entered
                {
                    cout << "\n";
                    cout << "Please enter a valid number from the board!!! \n\n";
                    cout << "Which number do you want to replace  ";
                    cin >> from;
                }
            }
            cout << "Which number do you want to replace with  ";
            cin >> to;
            if (NumberPresent(array, to) == false)
            {
                while (NumberPresent(array, to) == false)//continues to ask input until a valid number is entered
                {
                    cout << "\n";
                    cout << "Please enter a valid number from the board!!! \n\n";
                    cout << "Which number do you want to replace with ";
                    cin >> to;
                }
            }

            cout << "\n";
            swap(from, to, array); // swapping the values
            PrintBoard(array);
        }
        cout << "\n";
        cout << "you have won the game!\n";
        cout<<"Click the link for your gift - \nhttps://www.youtube.com/watch?v=dQw4w9WgXcQ"<<endl;
    }



    if (input==2){
        cout << "*** WELLCOME TO THE PERIODIC TABLE ARRANGING GAME ***\n*** HERE YOU NEED TO ARRANGE THE GROUPS OF THE PERIODIC TABLE IN SUCH A WAY THAT ALL ELEMENTS ARE IN ASCENDING ORDER. ***\n***THE ELEMENTS ARE CASE-SENSITIVE, PLEASE INPUT THE APPROPRIATE SYMBOL***\n     GOOD LUCK!!!     \n\nLet's start with G1! Arrange G1!\n\n";

        playing_groups(SG1,G1);
        cout<<"\nThe group looks perfect!\n\nLet's learn about the Group 1!\n"<<endl;
        for (int i=0; i<6; i++){
            cout<<Group1[i].symbol<<" = Group "<<Group1[i].group<<", Period "<<Group1[i].period<<", Atomic Number "<<Group1[i].AtomicNumber<<endl;
        }
        cout<<"\nArrange the G2 now!\n"<<endl;
        playing_groups(SG2, G2);
        cout<<"\nThe group looks perfect!\n\nLet's learn about the Group 2!\n"<<endl;
        for (int i=0; i<6; i++){
            cout<<Group2[i].symbol<<" = Group "<<Group2[i].group<<", Period "<<Group2[i].period<<", Atomic Number "<<Group2[i].AtomicNumber<<endl;
        }
        cout<<"\nArrange the G3 now!\n"<<endl;
        playing_groups(SG3, G3);
        cout<<"\nThe group looks perfect!\n\nLet's learn about the Group 3!\n"<<endl;
        for (int i=0; i<6; i++){
            cout<<Group3[i].symbol<<" = Group "<<Group3[i].group<<", Period "<<Group3[i].period<<", Atomic Number "<<Group3[i].AtomicNumber<<endl;
        }
        cout<<"\nArrange the G4 now!\n"<<endl;
        playing_groups(SG4,G4);
        cout<<"\nThe group looks perfect!\n\nLet's learn about the Group 4!\n"<<endl;
        for (int i=0; i<6; i++){
            cout<<Group4[i].symbol<<" = Group "<<Group4[i].group<<", Period "<<Group4[i].period<<", Atomic Number "<<Group4[i].AtomicNumber<<endl;
        }
        cout<<"\nArrange the G5 now!\n"<<endl;
        playing_groups(SG5, G5);
        cout<<"\nThe group looks perfect!\n\nLet's learn about the Group 5!\n"<<endl;
        for (int i=0; i<6; i++){
            cout<<Group5[i].symbol<<" = Group "<<Group5[i].group<<", Period "<<Group5[i].period<<", Atomic Number "<<Group5[i].AtomicNumber<<endl;
        }
        cout<<"\nArrange the G6 now!\n"<<endl;
        playing_groups(SG6, G6);
        cout<<"\nThe group looks perfect!\n\nLet's learn about the Group 6!\n"<<endl;
        for (int i=0; i<6; i++){
            cout<<Group6[i].symbol<<" = Group "<<Group6[i].group<<", Period "<<Group6[i].period<<", Atomic Number "<<Group6[i].AtomicNumber<<endl;
        }
        cout<<"\nArrange the G7 now!\n"<<endl;
        playing_groups(SG7,G7);
        cout<<"\nThe group looks perfect!\n\nLet's learn about the Group 7!\n"<<endl;
        for (int i=0; i<6; i++){
            cout<<Group7[i].symbol<<" = Group "<<Group7[i].group<<", Period "<<Group7[i].period<<", Atomic Number "<<Group7[i].AtomicNumber<<endl;
        }
        cout<<"\nArrange the G8 now!\n"<<endl;
        playing_groups(SG8, G8);
        cout<<"\nThe group looks perfect!\n\nLet's learn about the Group 8!\n"<<endl;
        for (int i=0; i<6; i++){
            cout<<Group8[i].symbol<<" = Group "<<Group8[i].group<<", Period "<<Group8[i].period<<", Atomic Number "<<Group8[i].AtomicNumber<<endl;
        }
        
        cout << "\n";
        cout << "you have won the game!\n";
        cout<<"Click the link for your gift - \nhttps://www.youtube.com/watch?v=dQw4w9WgXcQ"<<endl;
    }

  return 0;
}
