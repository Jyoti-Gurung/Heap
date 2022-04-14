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

//Skeleton for Max Heap
void buildHeap(int * input, int size)
{
    // Index of last non-leaf node
    int starter = (size / 2) - 1;
 
    // Perform reverse level order traversal
    // from last non-leaf node and heapify
    // each node
    for (int i = starter; i >= 0; i--) {
        heapify(input, size, i);
    }
}


void heapify(int * input, int size, int i)
{
    int root = i; //Slot of largest #
    int left = 2 * i + 1; 
    int right = 2 * i + 2;
 
    // If left child is larger than root
    if (left < size && input[left] > input[root])
        root = left;
 
    // If right child is larger than root
    if (right < size && input[right] > input[root])
        root = right;
 
    // If largest is not root
    if (root != i) {
        swap(input[i], input[root]);
        //Recursively heapify affected branch/s
        heapify(input, size, root);
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

/*
Sources that Helped me:
1. Aneeq just for looking how he did it: https://github.com/javagoatayowa/New/tree/master/Heap
2. Geekforgeeks for going through the heapify function:
https://www.geeksforgeeks.org/building-heap-from-array/
*/