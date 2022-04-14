/*
Name: Jyoti Gurung
Date: 4/12/22
Assignment: Making an Max Heap (Pyramid with the largest # on the top), up to 100 #s with values up to 1000.
*/

#include <iostream>

using namespace std;

// Set up functions up here; fleshed out under main Driver
void buildHeap(int * input, int n);
void heapify(int * input, int n, int i);
void display(int * input, int size, int depth, int control);

int main(){
  
  int storage[100]; // 100 numbers storage
  int count = 0; // Amount of actual numbers in storage
  char action;

  while (true) {
    
    cout << "a: Add, b: Print" << endl;
    cin >> action;

    switch (action) {

      //Add
      case 'a':

        int input;
        cin >> input;
        
        if (input > 1000 || input == 0) {
          cout << "Enter a value between 1-1000!" << endl;
          break;
        }
        if (count > 100) {
          cout << "Max 100 #s in this heap!" << endl;            break;
        }

        count++;
        storage[count-1] = input;
          
        break;

      //Print
      case 'b':
        buildHeap(storage, count);
        display(storage, count, 1, 1);
        
        
        break;
    }
  
  }  
  
}

//Skeleton for Max Heap
void buildHeap(int * input, int size)
{
    // Index of LAST parent branch, like the one that has baby branches
    int starter = (size / 2) - 1;
 
    // Heapify all the PARENT branches, in reverse order; aka from bottom and in right to left motion
    for (int i = starter; i >= 0; i--) {
        heapify(input, size, i);
    }
}


void heapify(int * input, int size, int i)
{
    int root = i; //Slot of largest #
    int left = 2 * i + 1; 
    int right = 2 * i + 2;
 
    // If left child is larger than root, root is changed to value of left
    if (left < size && input[left] > input[root])
        root = left;
 
    // If right child is larger than root, root is changed to value of right
    if (right < size && input[right] > input[root])
        root = right;
 
    // If largest is not root swap them, and call this function again to heapify branches
    if (root != i) {
        swap(input[i], input[root]);
        heapify(input, size, root);
    }
}

// Print out the arrays that is already sorted
void display(int * input, int size, int depth, int control) {
  
  for (int i = 0; i < size; i++) {
    
    cout << input[i] << " ";
    
    // If the current slot is equal to depth we bring       it down a line
    if (i+1 == depth) {
      // First, Double Control aka each branch has 2          spots for babies
      control = control * 2;
      // Second, add it to depth, which is collecting         the # of slots from previous depths
      depth = depth+control;
      cout << endl;
    }
  }

  cout << endl;
  
}

/*
Sources that Helped me:
1. Aneeq just for looking how he did it: https://github.com/javagoatayowa/New/tree/master/Heap
2. Geekforgeeks for going through the heapify function:
https://www.geeksforgeeks.org/building-heap-from-array/
*/