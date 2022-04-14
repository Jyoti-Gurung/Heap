/*
Name: Jyoti Gurung
Date: 4/12/22
Assignment: Making an Max Heap (Pyramid with the best on the top), up to 100 #s with values up to 1000.
*/

#include <iostream>

using namespace std;

void buildHeap(int * input, int n);
void heapify(int * input, int n, int i);
void display(int * input, int size, int depth, int control);

int main(){
  
  int storage[100];
  
  int count = 0;
  char action;

  while (true) {
    
    cout << "a: Add, b: Print" << endl;
    cin >> action;

    switch (action) {

      //add
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

      //print
      case 'b':
        buildHeap(storage, count);
        display(storage, count, 1, 1);
        
        
        break;
    }
  
  }  
  
}

// Function to build a Max-Heap from the given array
void buildHeap(int * input, int n)
{
    // Index of last non-leaf node
    int startIdx = (n / 2) - 1;
 
    // Perform reverse level order traversal
    // from last non-leaf node and heapify
    // each node
    for (int i = startIdx; i >= 0; i--) {
        heapify(input, n, i);
    }
}

// To heapify a subtree rooted with node i which is
// an index in arr[]. N is size of heap
void heapify(int * input, int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && input[l] > input[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && input[r] > input[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(input[i], input[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(input, n, largest);
    }
}

void display(int * input, int size, int depth, int control) {
  
  for (int i = 0; i < size; i++) {
    cout << input[i] << " ";
    if (i+1 == depth) {
      control = control * 2;
      depth = depth+control;
      cout << endl;
    }
  }

  cout << endl;
  
}