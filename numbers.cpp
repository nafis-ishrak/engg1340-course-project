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
#include "numbers.h"

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

bool compare_arrays(int arr1[], int arr2[]) // compares the current board with sorted board
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

bool NumberPresent(int arr[], int num) // checks whether the entered number is present in the array
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
