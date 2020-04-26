
#include <iomanip>
#include <iostream>
#include <sstream>      // std::istringstream
#include <string>       // std::string

using namespace std;

bool Check_Valid_Integer(int user_input, string line);


int main() {
  int num1, num2;
  char opr;
  string l;
  
  // first integer
  do {  
    cout << "\nEnter an integer: ";
    getline(cin, l);
    istringstream(l) >> num1;
    cout << endl;
  } while(!Check_Valid_Integer(num1, l));
  
  // second integer
  do {  
    cout << "\nEnter a second integer: ";
    getline(cin, l);
    istringstream(l) >> num2;
    cout << endl;
  } while(!Check_Valid_Integer(num2, l));

  cout << "Enter operator: + (addition), - (subtraction),"
       << " * (multiplication), / (division): ";
  
  cin >> opr;
  cout << endl;
  
  cout << num1 << " " << opr << " " << num2 << " = ";
  try
  {
    switch (opr) {
    case '+':     // Check for overflow sum > maxInt
      try {
        if ((num1+num2) > INT_MAX) {
          throw (num1+num2);
        }
        cout << num1 + num2 << endl;
      } catch (int e) {
        cout << "The answer was over the max integer." << endl;
      }
      break;
    case '-':     // Check for underflow result < minInt
      try {
        if ((num1-num2) < INT_MIN) {
          throw (num1-num2);
        }
        cout << num1 - num2 << endl;
      } catch (int e) {
        cout << "The answer was less than the min integer." << endl;
      }
      break;
    case '*':       // Check for overflow product > maxInt
      try {
        if ((num1*num2) > INT_MAX) {
          throw (num1*num2);
        }
        cout << num1 * num2 << endl;
      } catch (int e) {
        cout << "The answer was over the max integer." << endl;
      }
      break;
    case '/':       // Check for overflow quotient > maxInt
      try {
        if (num2 == 0 || (num1/num2) > INT_MAX) {
          throw num2;
        } else {
          cout << num1 / num2 << endl;
        }
      }
      catch(int e)
      {
        cout << "ERROR \nCannot divide by zero or quotient exceeded max integer." << endl;
      }
      break;
    default:
      throw opr;
    }
  }
  catch(char e)
  {
    cout << "Illegal operation" << endl;
  }
  
  return 0;
}

bool Check_Valid_Integer(int user_input, string line) {
  try
  {
    if (user_input > INT_MAX || user_input < INT_MIN || (!(istringstream(line) >> user_input))) {
      throw user_input;
    }
    return true;
  }
  catch(int e)
  {
    cout << "That is not a valid integer, try again." << endl;
    return false;
  }
}