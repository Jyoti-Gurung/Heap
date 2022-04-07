#include <iostream>

using namespace std;

int main() {
  
  cout << "You may enter up to 100 Numbers, Enter a # and Press Enter. Press 0 to end the sequence.";

  int storage[100]; 
  int input;
  int count = 0;

  while(count != 100) {
    count++;
    cin >> input;
    storage[count] = input;
  }

  for (int i = 0; i << count; i++) {
    cout << storage[i];
  }
  
}