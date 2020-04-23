
//Calculator Using Reverse Polish Notation
// Integer Integer Operator
//https://en.wikipedia.org/wiki/Reverse_Polish_notation
//http://www.cplusplus.com/forum/beginner/157181/


#include <iomanip>
#include <iostream>
#include <sstream>      // std::istringstream
#include <string>       // std::string

using namespace std;

int main() {
    int num1, num2;
    char opr;
    string line;

       //Check num1 is a valid integer
    while((cout << "Please enter a positive integer: ") && getline(cin, line) && (!(istringstream(line) >> num1)))
    {
        cout << "That is not an integer, try again." << endl;
    }
       //Check num2 is a valid integer
    while((cout << "Please enter a second positive integer: ") && getline(cin, line) && (!(istringstream(line) >> num2)))
    {
        cout << "That is not an integer, try again." << endl;
    }
 
   //Check opr is a valid operator
  cout << "Enter operator: + (addition), - (subtraction),"
       << " * (multiplication), / (division): ";
  cin >> opr;
  cout << endl;

  cout << num1 << " " << opr << " " << num2 << " = ";
    
    // INT_MAX = 2147483647
    // INT_MIN = -2147483648

  switch (opr) {
    case '+':
      cout << num1 + num2 << endl; // Check for overflow num1  > (INT_MAX - num2)
      break;
    case '-':
      cout << num1 - num2 << endl; // Check for underflow num1 < (INT_MIN + num2)
      break;
    case '*':
      cout << num1 * num2 << endl; // Check for overflow num1 > (INT_MAX / num2)
      break;
    case '/':
      if (num2 != 0)
        cout << num1 / num2 << endl;
      else
        cout << "ERROR \nCannot divide by zero" << endl;
      break;
    default:
      cout << "Illegal operation" << endl;
  }

  return 0;
}
