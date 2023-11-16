#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

bool is_number_string(const string& s) {
  int len = s.length();
  for (int i = 0; i < len; i++)
    if (s[i] < '0' || s[i] > '9')
      return false;

  return true;
}

int main() {
  string cc_number;

  cout << "Credit card validator" << endl;
  cout << "Enter 'exit' at anytime to quit" << endl;

  while (true) {
    cout << "Please enter a CC number to validate: ";
    cin >> cc_number;

    if (cc_number == "exit")
      break;
    else if (!is_number_string(cc_number)) {
      cout << "Invalid input!";
      continue;
    }

    int len = cc_number.length();
    int double_even_sum = 0;

    /*
    * Step 1 is to double every second digit, starting from the right.
    * If it results in a two digit number, add both digits to obtain
    * a single digit number. Finally, sum all the answers to obtain "double_even_sum"
    */

    for (int i = len - 2; i >= 0; i = i - 2) {
      int double_value = ((cc_number[i] - 48) * 2);
      if (double_value > 9)
        double_value = (double_value / 10) + (double_value % 10);

      double_even_sum += double_value;
    }

    // Step 2 - add every odd digit from the right to the value
    // double_even_sum
    
    for (int i = len - 1; i >= 0; i = i - 2)
      double_even_sum += (cc_number[i] - 48);

    // Check if final is a multiple of 10

    cout << (double_even_sum % 10 == 0 ? "Valid!" : "Invalid") << endl;

    continue;
  }
}
