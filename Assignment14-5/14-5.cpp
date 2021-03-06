#include <iostream>
#include <vector>

using namespace std;

//Overload Operators - giving new meaning/ adding peramiters & change the behaivior of an operator.

//operator are the same as function just called with a character instead of giving it a formal name.
//Operators:
  //+, -, /, =, -=, +=, <<, >>, ",", *(dereferance operator), &(memory addresses), new, delete, ()

//THIS - only accessable through a member function, poointer to the current object instance.


// class nads{
//   private:
//     vector <int> apple;
//     char A = 'A';
//   public:
//     nads(){
//       for(int i = 0; i < 5; i++){
//       apple.push_back(6 + i);
//     };
//     int nads :: operator>(const nads &r){
//       int sum1 = 0, sum2 = 0;
//       for(int i = 0; i < 6; i++){
//         sum1+= this -> score[i];
//         sum2 += r.score[i];
//       }
//       return sum1 > sum2;
//     }

//     int nads :: operator + (const nads &r){
//       int sum1 = 0, sum2 = 0;
//       for(int i =0l i < 6; i++){
//         sum1+= this -> score[i];
//         sum2 += r.score[i];
//       }
//       return sum1 + sum2;
//     }


  
// }





// int main(){
//   nads ben();
  
//   }


// }

#include <iostream>

using namespace std;


class Numbers{
  private:
    int size;
    int *numbers;
  public:
    Numbers();
    Numbers(int s){
      size = s;
      numbers = new int [s];
      for(int i = 0; i < s; i++){
        numbers[i] = i * 9;
        }
    };
    Numbers(const Numbers &q){
      size = q.size;
      numbers = new int [size];
      for(int i = 0; i < size; i++){
        numbers[i] = q.numbers[i];
      }
      
    }
    

    ~Numbers(){
      cout << endl;
      cout << "Activated Deconstructor" << endl;
      delete [] numbers;
    };
    int operator>(const Numbers &n){
      int sum1 = 0, sum2 = 0;
      for(int i = 0; i < sizeof(numbers); i++){
        sum1+= this -> numbers[i];
        sum2 += n.numbers[i];
      }
      cout << "sum1: " << sum1 << " " << "sum2: " << sum2 << endl;
      cout << "If the result is: 1, sum1 is larger." << endl;
      cout << "If the result is: 0, sum1 is not larger." << endl;
      return sum1 > sum2;
    }
    Numbers operator= (Numbers &n){
      
      this -> size = n.size;
      for(int i = 0; i < sizeof(numbers); i++){
        this -> numbers[i] = n.numbers[i];
      }
        
      return n;
    };
    Numbers operator+(const Numbers &n){
      int sum1 = 0, sum2 = 0;
      for(int i =0; i < size; i++){
        sum1+= this -> numbers[i];
        sum2 += n.numbers[i];
      }
      return sum1 + sum2;
    };

    friend void printNumbers(const Numbers &n);
};

void printNumbers(const Numbers &n){
  for(int i = 0; i < n.size; i++){
    cout << n.numbers[i] << " ";
    }

}


int main() {

  Numbers n1(10);
  cout << endl;
  Numbers n2(n1);
  cout << endl;
  cout << "Printed: " << endl;
  printNumbers(n1);
  cout << endl;
  printNumbers(n2);
  cout << endl;
  int larger = n1 > n2;
  cout << larger;


  
} 

