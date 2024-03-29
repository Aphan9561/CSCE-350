//Written by Anna Phan
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
  int n, p = 0; //Number of lockers and passes
  int locker_open = 0; //Number of open lockers 

  //Prompt the user for lockers and passes
  cout << "Enter number of lockers: ";
  cin >> n;
  cout << "Enter number of passes: ";
  cin >> p;

  //locker array
  int* locker = new int[n];
  //toggle the lockers 
  for(int i = 1; i <= n; i++){
    for (int j = 1; j <= p; j++){
      if((j+1)%i == 0){
        if(locker[i] == 0){
          locker[i] = 1;
        } else if (locker[i] == 1){
          locker[i] = 0;
        }
      }
    }
  }

  //results
  cout << "Last pass status of all lockers: " << endl;
  //locker number and their status
  for(int i = 0; i <n; i++){
    if(locker[i] == 0){
      cout << "Locker " << i+1 << " is close." << endl;
    } else if (locker[i] == 1) {
      cout << "Locker " << i+1 << " is open." << endl; 
      locker_open++;
    }
  }
  //how many lockers are open
  if(locker_open == 1){
    cout << locker_open << " locker are open." << endl;
  } else { 
    cout << locker_open << " lockers are open." << endl;
  }
  
}