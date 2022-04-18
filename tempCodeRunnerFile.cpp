#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <iomanip>
#include <fstream>
#include <sstream>
// FOR NUMBERS
using namespace std;

void generate_nums(int arr[])
{

  for (int i = 0; i < 16; i++)
  {
    arr[i] = 0 + rand() % 100;
  }
}

void board(int array[])
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

int main()
{

  srand(time(NULL));
  int array[16];
  generate_nums(array);
  board(array);

  return 0;
}