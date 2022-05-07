#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "periodictable.h"

using namespace std;

void shuffle_r(int arr[], int length)
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
 

void shuffled_group(std::string x[], std::string y[]){ //shuffling the elements  of the group
    int n[6]={0,1,2,3,4,5};
    shuffle_r(n,6);
    for (int i=0; i<6; i++){
        x[i]= y[n[i]];
    }

}
void doSwap (std::string string1, std::string string2) {
    std::string temp;
    temp = string1;
    string1 = string2;
    string2 = temp;
}

void swapping_elements(std::string from, std::string to, std::string arr[]) // swapping the elements in the board
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

bool comparing_element_arrays(std::string arr1[], std::string arr2[]) // comparing the current board with sorted board
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
bool Element_Present(std::string arr[], std::string num) // checks whether the entered number is present in the array
{
  bool flag = false;
  for (int i = 0; i < 6; i++)
  {
    if (arr[i] == num)
    {
      flag = true;
      break;
    }
  }
  return flag;
}
 

void periodic_board(std::string array[]) // printing the board
{
  for (int i = 0; i < 6; i++)
  {
    cout << array[i] << endl;
    cout << "\n--\n" << endl;
  }
}

void playing_groups(std::string x[], std::string y[])
{
  srand(time(NULL)); // so that there are different random numbers in every attempt of the game

  
  shuffled_group(x, y ); // shuffling the all the elements of the group

// sorting the array in ascending order
    
  periodic_board(x); // print out board
  cout << "\n";

  while (comparing_element_arrays(x, y) == false) // checks if the game is over or not
  {
    std::string from, to;
    cout << "\nWhich element do you want to replace  ";
    cin >> from;
    if (Element_Present(x, from) == false)
    {
      while (Element_Present(x, from) == false)//continues to ask input until a valid element is entered
      {
        cout << "\n";
        cout << "Please enter a valid element from the board!!! \n\n";
        cout << "Which element do you want to replace  ";
        cin >> from;
      }
    }
    cout << "Which element do you want to replace with  ";
    cin >> to;
    if (Element_Present(x, to) == false)
    {
      while (Element_Present(x, to) == false)//continues to ask input until a valid element is entered
      {
        cout << "\n";
        cout << "Please enter a valid element from the board!!! \n\n";
        cout << "Which element do you want to replace with ";
        cin >> to;
      }
    }
    
    
    
    
    cout<<"\n";
  

    swapping_elements(from, to, x);
    periodic_board(x);
    cout<<endl;
  }
}


