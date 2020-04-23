
//Calculator Using Reverse Polish Notation
// Integer Integer Operator
//https://en.wikipedia.org/wiki/Reverse_Polish_notation



#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  int num1, num2;
  char opr;

  cout << "Enter two integers: ";
  cin >> num1 >> num2;
  cout << endl;
    
   //Check num1 is a valid integer
   //Check num2 is a valid integer
   // boolean function that checks for valid integer boolean Check_Valid_Integer(int user_input);
   //while(Check_Valid_Integer) {  }
    

  cout << "Enter operator: + (addition), - (subtraction),"
       << " * (multiplication), / (division): ";
  cin >> opr;
    
   //Check opr is a valid operator
    // boolean function that checks for valid operator boolean Check_Valid_Operator(char user_input);
    //while(Check_Valid_Operator) {  }
    
  cout << endl;

  cout << num1 << " " << opr << " " << num2 << " = ";

  switch (opr) {
    case '+':
      cout << num1 + num2 << endl; // Check for overflow sum > maxInt
      break;
    case '-':
      cout << num1 - num2 << endl; // Check for underflow result < minInt
      break;
    case '*':
      cout << num1 * num2 << endl; // Check for overflow product > maxInt
      break;
    case '/':
      if (num2 != 0)
        cout << num1 / num2 << endl; // Check for overflow quotient > maxInt
      else
        cout << "ERROR \nCannot divide by zero" << endl;
      break;
    default:
      cout << "Illegal operation" << endl;
  }

  return 0;
}
