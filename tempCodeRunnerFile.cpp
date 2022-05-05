#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
// FOR NUMBERS
using namespace std;
// C++ program to shuffle
// the given array
// using random_shuffle() method

void shuffle(int arr[])
{
  unsigned seed = 0;
  random_shuffle(arr, arr + 16);
}

void generate_nums(int arr[], int allnum[]) // generateing 16 random but unique numbers
{
  for (int i = 0; i < 16; i++)
  {
    arr[i] = allnum[i];
  }
}

void PrintBoard(int array[]) // printing the board
{
  for (int i = 0; i < 16; i++)
  {
    if (i == 7)
    {
      cout << " ";
    }
    cout << array[i] << " |";
    if (i == 3 || i == 7 || i == 11 || i == 15)
    {

      cout << "\n";
    }
  }
}

bool compare_arrays(int arr1[], int arr2[]) // comparing the current board with sorted board
{
  bool flag = true;

  for (int i = 0; i < 16; i++)
  {
    if (arr1[i] != arr2[i])
    {
      return false;
    }
  }
  if (flag == true)
  {
    return true;
  }
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

int main()
{

  int array[16];
  int all_the_numbers[100];
  for (int i = 0; i < 100; i++)
  {
    all_the_numbers[i] = i;
  }

  shuffle(all_the_numbers); // shuffling the arrays;
  generate_nums(array, all_the_numbers);
  int sorted_arr[16];

  copy(begin(array), end(array), begin(sorted_arr)); // copying the array
  sort(sorted_arr, sorted_arr + 16);

  PrintBoard(array); // print out board
  cout << "\n";
  // board(sorted_arr);

  while (compare_arrays(array, sorted_arr) == false) // fix this
  {
    int from, to;
    cout << "Which number do you want to replace  ";
    cin >> from;
    cout << "Which number do you want to replace with  ";
    cin >> to;

    swap(from, to, array);
    PrintBoard(array);
  }

  return 0;
}