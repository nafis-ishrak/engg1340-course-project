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

// FOR NUMBERS
using namespace std;

void PrintBoard(int array[]) // printing the board
{
  for (int i = 0; i < 16; i++)
  {
    if (i == 7)
    {
      cout << "";
    }
    if (array[i] / 10 != 0)
      cout << array[i] << "|";
    else
      cout << array[i] << " |";

    if (i == 3 || i == 7 || i == 11 || i == 15)
    {

      cout << "\n\n";
    }
  }
}

bool compare_arrays(int arr1[], int arr2[]) // comparing the current board with sorted board
{
  bool flag;
  for (int i = 0; i < 16; i++)
  {
    if (arr1[i] != arr2[i])
    {
      flag = false; // returns false if there is a mismatch
    }
    else
      flag = true;
  }

  return flag;
}

bool NumberPresent(int arr[], int num)
{
  bool flag = false;
  for (int i = 0; i < 16; i++)
  {
    if (arr[i] == num)
    {
      flag = true;
      break;
    }
  }
  return flag;
}

void swap(int from, int to, int arr[]) // swapping the numbers in the board
{
  int temp1, temp2;

  for (int i = 0; i < 16; i++) // finding the index of the two numbers
  {
    if (arr[i] == from)
      temp1 = i;
    if (arr[i] == to)
      temp2 = i;
  }
  arr[temp1] = to;
  arr[temp2] = from;
}
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

int main()
{

  cout << "\n*** WELLCOME TO THE NUMBER ARRANGING GAME ***\n*** HERE YOU NEED TO ARRANGE THE BOARD IN SUCH A WAY THAT ALL NUMBERS ARE IN ASCENDING ORDER STARTING FROM THE FIRST ROW (LEFT TO RIGHT). ***\n     GOOD LUCK!!!     \n\n";

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
  sort(sorted_arr, sorted_arr + 16);                 // sorting the array in ascending order

  PrintBoard(array); // print out board
  cout << "\n";

  while (compare_arrays(array, sorted_arr) == false) // checks if the game is over or not
  {
    int from, to;
    cout << "Which number do you want to replace  ";
    cin >> from; // NEED TO GIVE A CHECK IF THERE IS A NUMBER
    if (NumberPresent(array, from) == false)
    {
      while (NumberPresent(array, from) == false)
      {
        cout<<"\n";
        cout << "Please enter a valid number from the board!!! \n\n";
        cout << "Which number do you want to replace  ";
        cin >> from;

      }
    }
    cout << "Which number do you want to replace with  ";
    cin >> to;
    if (NumberPresent(array, to) == false)
    {
      while (NumberPresent(array, to) == false)
      {
        cout<<"\n";
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
  system("open https://tinyurl.com/3bcz98xn");

  return 0;
}