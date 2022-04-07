#include <iostream>

using namespace std;

int main() {
  
  cout << "You may enter up to 100 Numbers, Enter a # and Press Enter. Press 0 to end the sequence.";

  int storage[100]; 
  int input;
  int count = 0;
  int done;

  while(done != 0) {
    count++;
    cin >> input;
    if (input != 0) {
      storage[count] = input;
    }
    else {
      done = 0;
    }
  }

  for (int i = 0; i << count; i++) {
    cout << storage[i];
  }
  
}