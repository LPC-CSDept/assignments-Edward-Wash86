#ifndef ASSIGNMENT144_H
#define ASSIGNMENT144_H

using namespace std;

// class Numbers{
//   private:
//     int *score; //pointer to an address with no data stored.
//   public:
//     Numbers();
//     Numbers(int *B){
//       score = new int [10];
//       for(int i = 0; i < sizeof(score); i++){
//         score[i] = 674 * B[i];
//         }
//     };
//   void getScore(){
//     for(int i = 0; i < sizeof(score); i++){
//       cout << score[i] << endl;
//     }
//   }
// };

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Numbers{
  private:
    int size;
    int *numbers; //pointer
  public:
    Numbers(){
      size = 0;
      numbers = nullptr;
    }; // default constructor
    Numbers(int s){
      size = s;
      numbers = new int [size];
      for(int i = 0; i < size; i++){
        numbers[i] = rand() % 100;
        }
    };
    Numbers(const Numbers &p){
      this -> size = p.size;
      this -> numbers = new int[size];
      for(int i = 0; i < size; i++){
        this -> numbers[i] = p.numbers[i];
      }
    }; //referance
    ~Numbers(){
      cout << endl;
      cout << "Activated Deconstructor" << endl;
      delete [] numbers;
    }; 
    //Destructor
    int getMax() const{
      int max = numbers[0];
      for(int i = 0; i < size; i++){
        if(numbers[i] > max){
          max = numbers[i];
        }
      }
      return max;
    };
    int getSize(){
      return size;
    }
    friend void printNumbers(Numbers print);
};

void printNumbers(Numbers print){
  cout << "Array Size: " ;
  cout << print.getSize() << endl;
  cout << "Numbers Stored: ";
  for(int i = 0; i < print.getSize(); i++){
    cout << print.numbers[i] << " ";
  }
}

#endif