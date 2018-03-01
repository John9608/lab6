//Juan Trigueros
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <utility>
using namespace std;

void insertionSort(int arr[], int size);
void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);

int main() {
    srand(time(NULL));
    int size, range;

    cout << "Enter a number to decide the size of an array of numbers: ";
    cin >> size;
    cout << endl;

    cout << "Enter a number to create a range of random numbers from 1 to that number: ";
    cin >> range;

    int arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % range + 1;
    }
    int algorithm;
    cout << "Algorithms\n";
    cout << "1. Insertion\n2. Bubble\n3. Selection\n\n";
    cout << "Choose a sorting algorithm by entering its number: ";
    cin >> algorithm;
    if (algorithm == 1) {
        insertionSort(arr, size);
    }
    if (algorithm == 2) {
        bubbleSort(arr, size);
    }
    
    bool ordered = true;
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
          cout << "Error: Not ordered\n";
          ordered = false;
          break;
        }
    }
    if (ordered == true) {
    cout << "Order is good" << endl;
    }

    return 0;
}

void insertionSort(int arr[], int size) {
    int m, main, j;
    for (m = 1; m < size; m++)
    {
        main = arr[m];
        j = m - 1;

        while (j >= 0 && arr[j] > main)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = main;
    }
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-1-i; j++) {
            if (arr[j+1] < arr[j]) {
                swap(arr[j+1], arr[j]);
            }
        }
    }
}
