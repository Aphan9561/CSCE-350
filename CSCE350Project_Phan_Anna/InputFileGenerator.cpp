// Written by Anna Phan
#include <iostream>
#include<fstream>

using namespace std;

// generates random number
int generateRandomNumber(int min, int max) {
  return min + rand() % (max - min + 1);
}

// making the input file and calling the random number generator
void randGenerator(const string& fileName, int size){
  ofstream outputFile(fileName);

  for(int i = 0; i < size; i++){
    int randomValue = generateRandomNumber(-100, 100);
    outputFile << randomValue << " ";
  }

  outputFile.close();
}

//Running the code
int main(){
  //25 input files for each size
  for (int inputSize : {10, 100, 1000}) {
    for(int i = 1; i <= 25; i++){
      string inputFileName = "input_" + to_string(inputSize) + "_" + to_string(i) + ".txt";
      randGenerator(inputFileName, inputSize);
    }
  }
}
