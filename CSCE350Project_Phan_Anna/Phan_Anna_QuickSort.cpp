// Written by Anna Phan
#include <iostream>
#include<fstream>
#include <chrono>

using namespace std;
using namespace chrono;

//partition the array and returns pivot index
int partition(int arr[], int start, int end){
  // Choose the middle element as the pivot
  int pivotValue = arr[start];
  int count = 0;
  for (int i = start + 1; i <= end; i++) {
    if (arr[i] <= pivotValue)
      count++;
  }

  // Giving pivot element its correct position
  int pivotIndex = start + count;
  swap(arr[pivotIndex], arr[start]);

  // Sorting left and right parts of the pivot element
  int i = start, j = end;
  while (i < pivotIndex && j > pivotIndex) {
    while (arr[i] <= pivotValue) {
        i++;
    }
    while (arr[j] > pivotValue) {
        j--;
    }
    if (i < pivotIndex && j > pivotIndex) {
        swap(arr[i++], arr[j--]);
    }
  }

  return pivotIndex;
}

//QuickSort algorithm from textbook
void quickSort(int arr[], int start, int end){
  if(start < end){
    int pivotIndex = partition(arr, start, end); // for getting partition
    quickSort(arr, start, pivotIndex - 1); // sorting left side array
    quickSort(arr, pivotIndex + 1, end); // sorting right side array
  }
  return;
}

//Reading in input file and printing sorted list to output file along with an execution time file
int main(int argc, char* argv[]){
  if (argc < 3){
    cerr << "missing an argument" << endl;
    return 1; 
  }

  // Reading input file
  ifstream inputFile(argv[1]);
  if (!inputFile) {
    cerr << "Error opening input file." << endl;
    return 1;
  }

  int size = 1000;
  int numbers[size];
  int count = 0;
  int num;

  while(inputFile >> num){
    if(count >= size){
      cerr << "Input file exceeds maximum size supported." << endl;
      return 1;
    }
    numbers[count++] = num;
  }
  
  inputFile.close();

  //Timing the sorting process
  auto start = high_resolution_clock::now();

  quickSort(numbers, 0, count-1);

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  // print to output file in order
  ofstream outputFile(argv[2]);
  for(int i = 0; i<count; i++){
    outputFile << numbers[i] << " "; 
  }
  outputFile.close();

  // records the execution time to file 
  ofstream timeFile("executionTime.txt");
  timeFile << duration.count() <<  endl;
  timeFile.close();


  return 0;
}
