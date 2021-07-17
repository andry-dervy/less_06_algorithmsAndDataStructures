//============================================================================
// Name        : less_06_algorithmsAndDataStructures.cpp
// Author      : andry antonenko
// IDE         : Eclipse IDE
// Description : lesson 6 of the algorithms and structures data
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

/*
1. Реализовать пузырьковую сортировку двумерного массива
например, массив 1,9,2 5,7,6 4,3,8
должен на выходе стать 1,2,3 4,5,6 7,8,9
*/

void swap(int * pA, int * pB)
{
  *pA ^= *pB ^= *pA ^= *pB;
}

int* nextElemet(int **ppArr,int mSize, int nSize, int m, int n)
{
  if(n == nSize - 1)
  {
    return (int*)(ppArr[m+1]);
  }
  return (int*)(ppArr[m] + n + 1);
}

void bubbleSort(int **ppArr,int mSize, int nSize)
{
  int size = mSize * nSize;
  for(int i = 0; i < size; i++)
  {
    for(int j = 0; j < size-1; j++)
    {
      if(ppArr[j/nSize][j%nSize] > *(nextElemet(ppArr,mSize,nSize,j/nSize,j%nSize)))
        swap(&ppArr[j/nSize][j%nSize], nextElemet(ppArr,mSize,nSize,j/nSize,j%nSize) );
    }
  }

}

int** getArrayRand(int mSize, int nSize)
{
  int **ppArr = nullptr;
  try {
    ppArr = (int**) new int*[mSize];
    for(int m = 0; m < mSize; m++)
    {
      ppArr[m] = new int[nSize];
      for(int n = 0; n < nSize; n++)
      {
        ppArr[m][n] = rand()%100;
      }
    }
  }
  catch (const std::exception&)
  {
    cout << "No memory allocated." << endl;
  }
  return ppArr;
}

void freeArray(int** ppArr, int mSize)
{
  if(ppArr != NULL)
  {
    for(int m = 0; m < mSize; m++)
    {
      delete ppArr[m];
    }
    delete ppArr;
    ppArr = nullptr;
  }
}

void printArray(const int** ppArr, const int mSize,const int nSize)
{
  for(int m = 0; m < mSize; m++)
  {
    for(int n = 0; n < nSize; n++)
    {
      cout << ppArr[m][n] << " ";
    }
    cout << endl;
  }
}

/*
2. Описать подробную блок-схему алгоритма Трабба-Прадо-Кнута
1 - запросить у пользователя 11 чисел и
записать их в последовательность П
2 - инвертировать последовательность П
3 - для каждого элемента последовательности П
произвести вычисление по формуле sqrt(fabs(Х)) + 5 * pow(Х, 3) и
если результат вычислений превышает 400 - проинформировать пользователя.

3. Реализовать алгоритм Трабба-Прадо-Кнута в коде на языке С
*/

void enterNumbers(int *pArr, int aSize)
{
  for(int i = 0; i < aSize; i++)
  {
    cin >> pArr[i];
  }
}

void invertNumbers(int *pArr, int aSize)
{
  if(aSize > 1)
  {
    int temp = pArr[aSize - 1];
    pArr[aSize - 1] = pArr[0];
    invertNumbers(&pArr[1],aSize-2);
    pArr[0] = temp;
  }
}

void printVector(const int *pArr, int aSize)
{
  for(int i = 0; i < aSize; i++)
  {
    cout << pArr[i] << " ";
  }
  cout << endl;
}

const int LIMIT = 400;

void alarm(const int *pArr, int aSize)
{
  double d;
  for(int i = 0; i < aSize; i++)
  {
    d = sqrt(fabs(pArr[i])) + 5 * pow(pArr[i], 3);
    if(d > LIMIT)
    {
      cout << "Index " << i <<
          " of the element " << pArr[i] <<
          " which isn't true to limits." <<
          " | " << d << " > " << LIMIT << endl;
    }
  }
}

/*

Результатом выполнения задания должны стать два файла:
с кодом на языке С, содержащим функцию main и две функции,
соответствующие сортировке и алгоритму Трабба-Прадо-Кнута, и
с изображением в любом популярном формате (jpg, png, gif)
*/

int main() {

// Task 1
//*
  cout << "Task 1\n" << endl;

	const int mSize = 5;
	const int nSize = 15;

	int** ppArr = getArrayRand(mSize,nSize);
  cout << "Array before sorting:" << endl;
	printArray((const int**)ppArr, mSize, nSize);
	bubbleSort(ppArr,mSize, nSize);
  cout << "Array after sorting:" << endl;
  printArray((const int**)ppArr, mSize, nSize);
	freeArray(ppArr, mSize);
//*/

// Task 2 and 3
//*
  cout << "Task 2 and 3\n" << endl;

  const int nNumbers = 11;
  cout << "Enter " << nNumbers << " of numbers:" << endl;
  int nArr[nNumbers];// = {1,2,3,4,5,6,7,8,9,10,11};
  enterNumbers(nArr, nNumbers);
  cout << "Print numbers:" << endl;
  printVector(nArr,nNumbers);
  invertNumbers(nArr,nNumbers);
  cout << "Print numbers after invertion:" << endl;
  printVector(nArr,nNumbers);
  alarm(nArr,nNumbers);
//*/

	return 0;
}
