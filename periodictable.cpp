#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;
 

string SG1[6], SG2[6], SG3[6], SG4[6], SG5[6], SG6[6], SG7[6], SG8[6];

string G1[6]= {"H", "Li", "Na", "K", "Rb", "Cs"};
string G2[6]= {"Be", "Mg", "Ca", "Sr", "Ba", "Ra"};
string G3[6]= {"B", "Al", "Ga", "In", "Tl", "Nh"};
string G4[6]= {"C", "Si", "Ge", "Sn", "Pb", "Fl"};
string G5[6] = {"N", "P", "As", "Sb","Bi", "Mc"};
string G6[6] = {"O", "S ", "Se", "Te", "Po", "Lv"};
string G7[6] = {"F", "Cl", "Br", "I", "At", "Ts"};
string G8[6] = {"He","Ne", "Ar", "Kr", "Xe", "Rn"};

int numbers[6]={0,1,2,3,4,5};

void shuffle(int arr[], int length)
{

  int tmp = 0;
  int rndm_inx = 0;

  for (int i = 0; i < length; i++)
  {
    rndm_inx = rand() % length;
    tmp = arr[i];
    arr[i] = arr[rndm_inx];
    arr[rndm_inx] = tmp;
  }
}
void shuffled_group(string x[], string y[]){
    int n[6]={0,1,2,3,4,5};
    shuffle(n,6);
    for (int i=0; i<6; i++){
        x[i]= y[n[i]];
    }

}
void doSwap (string string1, string string2) {
    string temp;
    temp = string1;
    string1 = string2;
    string2 = temp;
}

void swap(string from, string to, string arr[]) // swapping the numbers in the board
{
  int temp1, temp2;

  for (int i = 0; i < 6; i++) // finding the index of the two numbers
  {
    if (arr[i] == from)
      temp1 = i;
    if (arr[i] == to)
      temp2 = i;
  }
  arr[temp1] = to;
  arr[temp2] = from;
}

bool comparing_arrays(string arr1[], string arr2[]) // comparing the current board with sorted board
{
  bool flag;
  for (int i = 0; i < 6; i++)
  {
    if (arr1[i] != arr2[i])
    {
      flag=false;
    }
    else
      flag= true;
    }
 
  return flag;
}
 

void periodic_board(string array[]) // printing the board
{
  for (int i = 0; i < 6; i++)
  {
    cout << array[i] << " | ";
  }
}

void playing_groups(string x[], string y[])
{
    srand(time(NULL)); // so that there are different random numbers in every attempt of the game

  
    shuffled_group(x, y ); // shuffling the all the numbers

// sorting the array in ascending order
    
    periodic_board(x); // print out board
    cout << "\n";

    while (comparing_arrays(x, y) == false) // checks if the game is over or not
    {
        string from, to;
        cout << "\nWhich element do you want to replace  ";
        cin >> from;
        cout << "\nWhich element do you want to replace with  ";
        cin >> to;
        cout<<"\n";
    

        swap(from, to, x);
        periodic_board(x);
        cout<<endl;
    }
}


int main(){

    cout << "*** WELLCOME TO THE PERIODIC TABLE ARRANGING GAME ***\n*** HERE YOU NEED TO ARRANGE THE GROUPS OF THE PERIODIC TABLE IN SUCH A WAY THAT ALL ELEMENTS ARE IN ASCENDING ORDER. ***\n     GOOD LUCK!!!     \n\nLet's start with G1! Arrange G1!\n\n";

    playing_groups(SG1,G1);
    cout<<"\nThe group looks perfect!\n\nArrange the G2 now!\n"<<endl;
    playing_groups(SG2, G2);
    cout<<"\nThe group looks perfect!\n\nArrange the G3 now!\n"<<endl;
    playing_groups(SG3, G3);
    cout<<"\nThe group looks perfect!\n\nArrange the G4 now!\n"<<endl;
    playing_groups(SG4,G4);
    cout<<"\nThe group looks perfect!\n\nArrange the G5 now!\n"<<endl;
    playing_groups(SG5, G5);
    cout<<"\nThe group looks perfect!\n\nArrange the G6 now!\n"<<endl;
    playing_groups(SG6, G6);
    cout<<"\nThe group looks perfect!\n\nArrange the G7 now!\n"<<endl;
    playing_groups(SG7,G7);
    cout<<"\nThe group looks perfect!\n\nArrange the G8 now!\n"<<endl;
    playing_groups(SG8, G8);

    
    cout << "\n";
    cout << "you have won the game!\n";
    system("open https://tinyurl.com/3bcz98xn");

    return 0;
}