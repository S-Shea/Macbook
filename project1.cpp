#include <iostream>
#include <time.h>

using namespace std;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Quick sort algorithm and helper functions from https://www.geeksforgeeks.org/cpp-program-for-quicksort/

int partition(int arr[], int start, int end)
{
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
 //recursive quick sort algorithm 
void quickSort(int arr[], int start, int end)
{
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(arr, start, end);
 
    // Sorting the left part
    quickSort(arr, start, p - 1);
 
    // Sorting the right part
    quickSort(arr, p + 1, end);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// binary search from https://www.geeksforgeeks.org/binary-search/
// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
 
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
 
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
 
    // We reach here when element is not
    // present in array
    return -1;
}

int linearSearch(int arr[], int arrSize, int target) {
    //return -1 if target element is not found
    int ret = -1;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == target) {
            //ret is assigned the index of the target element if found
            ret = i;
        }
    }
    return ret;
}

//uses nested loops to search through array and compare each element to see if they add up to the given sum
//if a pair is found, the sum is printed followed by the pair of integers
void sumPairs(int arr[], int size, int sum) {
    cout << sum << endl;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == sum) {
                cout << " = " << arr[i] << " + " << arr[j] << endl;
            }
        }
    }
}

//Driver function
int main() {
    int maxValues; //size of array
    int currentValues; //current size of array as it is added to
    int tempVal; //used to read in number

    //assign number of elements to maxValues then create the dynamic arrays, A and B, with maxValues as the size
    cin >> maxValues;
    currentValues = maxValues;
    int *A = new int[maxValues];
    int *B = new int[maxValues];
    cout << "Length of the array: " << maxValues << endl;
    
    //read values from file and put into array A
    for (int i = 0; i < maxValues; i++) {
        cin >> tempVal;
        A[i] = tempVal;
    }

    //copy array A to array B
    for (int i = 0; i < maxValues; i++) {
        B[i] = A[i];
    }

    //sort array B in ascending order
    quickSort(B, 0, maxValues - 1);

    //output array A
    cout << "Array A: ";
    for (int i = 0; i < maxValues; i++) {
        cout << A[i] << " ";
    } cout << endl;

    //output array B
    cout << "Array B: ";
    for (int i = 0; i < maxValues; i++) {
        cout << B[i] << " ";
    } cout << endl;
    cout << endl;
    
    //loop to check for commands by upercase letter
    //performs actions based on command letter and number of operations given after it
    
    while (!cin.eof()) {
        
        //setup for temp values to be read in from file
        string inputStr;
        int numOperations = 0;

        //read from file to check value
        cin >> inputStr;

//FIND CASE
        if (inputStr == "F") {
            cout << "Find: " << endl; 
            cin >> numOperations;

            //gets list of values to search for and puts them into array
            int *opArray = new int[numOperations];
            for (int i = 0; i < numOperations; i++) {
                int temp;
                cin >> temp;
                opArray[i] = temp;
            }
            
            //Array B (sorted)
            for (int i = 0; i < numOperations; i++) {
                int element = binarySearch(B, 0, maxValues - 1, opArray[i]);
                if (element > -1) {
                    cout << "Element " << opArray[i] << "  found at " << element << " in B" << endl;
                }
                else {
                    cout << "Element " << opArray[i] << "  not found in B" << endl;
                }
            } cout << endl;

            //Array A (unsorted)
            for (int i = 0; i < numOperations; i++) {
                int element = linearSearch(A, maxValues, opArray[i]);
                if (element > -1) {
                    cout << "Element " << opArray[i] << "  found at " << element << " in A" << endl;
                }
                else {
                    cout << "Element " << opArray[i] << "  not found in A" << endl;
                }
            } cout << endl;
            delete [] opArray;
        }

//SUMPAIRS CASE
        else if (inputStr == "A") {
            cout << "SumPairs: " << endl;
            cin >> numOperations;
            int *opArray = new int[numOperations];

            //gets list of values to add and puts them into array
            for (int i = 0; i < numOperations; i++) {
                int temp;
                cin >> temp;
                opArray[i] = temp;
            }
            
            //Array B (sorted)
            cout << "B:" << endl;
            for (int i = 0; i < numOperations; i++) {
                sumPairs(B, maxValues, opArray[i]);
            }cout << endl << endl;

            //Array A (unsorted)
            cout << "A:" << endl;
            for (int i = 0; i < numOperations; i++) {
                sumPairs(A, maxValues, opArray[i]);
            } cout << endl;
            delete [] opArray;
        }

//REMOVE CASE
        else if (inputStr == "R") {
            cout << "Remove: " << endl;
            cin >> numOperations;
            int *opArray = new int[numOperations];

            //gets list of values to remove and puts them into array
            for (int i = 0; i < numOperations; i++) {
                int temp;
                cin >> temp;
                opArray[i] = temp;
            }

             //Array B (sorted)
            int inc = 0;
            int Bsize = maxValues;
            while (inc < numOperations) {
                //search for element to delete to get its index in the array
                int index = binarySearch(B, 0, Bsize, opArray[inc]);
                if (index > -1) {
                    //create temp array and copy B values to it
                    int * tempArrB = new int[Bsize - 1];
                    for (int i = 0; i < Bsize; i++) {
                        tempArrB[i] = B[i];
                    }

                    cout << "Removing " << opArray[inc] << " at " << index << " in B" << endl;
                    Bsize--;
                    for (int i = index; i < Bsize; i++) {
                        tempArrB[i] = tempArrB[i + 1];
                    }
                    
                    //create new B array with smaller size and set it equal to the temp array
                    //delete [] B;
                    B = new int[Bsize];
                    B = tempArrB;
                   
                }
                else {
                    cout << "Element " << opArray[inc] << "  not found in B" << endl;
                }
                inc++;
            } cout << endl;
            
            //Array A (unsorted)
            int Asize = maxValues;
            inc = 0;
            while (inc < numOperations) {
                //search for element to remove and get its index in the array
                int index = linearSearch(A, Asize, opArray[inc]);
                if (index > -1) {
                    //create temp array and copy A values to it
                    int * tempArrA = new int[Asize - 1];
                    for (int i = 0; i < Asize; i++) {
                        tempArrA[i] = A[i];
                    }

                    cout << "Removing " << opArray[inc] << " at " << index << " in A" << endl;
                    Asize--;
                    for (int i = index; i < Asize; i++) {
                        tempArrA[i] = tempArrA[i + 1];
                    }

                    //delete original array and assign the temp array values to the new smaller one
                    //delete [] A;
                    A = new int[Asize];
                    A = tempArrA;
                   currentValues = Asize;
                }
                else {
                    cout << "Element " << opArray[inc] << "  not found in A" << endl;
                }
                inc++;
            } cout << endl;
            

            //A output
            cout << "After removal Array A: ";
            for (int i = 0; i < Asize - 1; i++) {
                cout << A[i] << " ";
            } cout << A[Asize - 1] << endl;

            //B ouput
            cout << "After removal Array B: ";
            for (int i = 0; i < Bsize - 1; i++) {
                cout << B[i] << " ";
            } cout << B[Bsize - 1] << endl;
            cout << endl;
            delete [] opArray;
        }

//INSERT CASE
        else if (inputStr == "I") {
            cout << "Insert: " << endl;
            cin >> numOperations;
            int* opArray = new int[numOperations];

            //gets list of values to insert and puts them into array
            for (int i = 0; i < numOperations; i++) {
                int temp;
                cin >> temp;
                opArray[i] = temp;
            }

            //Array B (sorted) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            int Bsize = currentValues;
            Bsize = Bsize + numOperations;

            //temp array to hold values while increasing size of original array
            int * tempArrB = new int[Bsize];
            for (int i = 0; i < currentValues; i++) {
                tempArrB[i] = B[i];
            }

            //delete original B array and create new one with larger size
            //delete [] B;
            int * B = new int[Bsize];

            //add original values back into B
            for (int i = 0; i < currentValues; i++) {
                B[i] = tempArrB[i];
            }

            //add new values to B array
            int inc = 0;
            for (int i = currentValues; i < Bsize; i++) {
                cout << "Inserting " << opArray[inc] << " in B" << endl;
                B[i] = opArray[inc];
                inc++;
            }

            //sort new array
            quickSort(B, 0, Bsize - 1);
            cout << endl;
            //Array B done ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

            //Array A (unsorted) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            int Asize = currentValues;
            Asize = Asize + numOperations;

            //temp array to hold values while increasing size of origninal array
            int * tempArrA = new int[Asize];
            for (int i = 0; i < currentValues; i++) {
                tempArrA[i] = A[i];
            }

            //delete original A array and create a new one with larger size
            //delete [] A;
            int * A = new int[Asize];

            //add original values back into A
            for (int i = 0; i < currentValues; i++) {
                A[i] = tempArrA[i];
            }

            //add new values to A array
            inc = 0;
            for (int i = currentValues; i < Asize; i++) {
                A[i] = opArray[inc];
                cout << "Inserting " << opArray[inc] << " in A" << endl;
                inc++;
            }
            cout << endl;
            //A array done ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

            //A output
            cout << "After insertions Array A: "; 
            for (int i = 0; i < Asize; i++) {
                cout << A[i] << " ";
            } //cout << A[Asize - 1] << endl; 
            cout << endl;

            //B output
            cout << "After insertions Array B: ";
            for (int i = 0; i < Bsize; i++) {
                cout << B[i] << " ";
            }cout << endl;
            
            delete [] opArray;
        } 
        else {
            cout << inputStr;
        }
    } 


    //delete arrays and end program
    delete [] A;
    //A = NULL;
    delete [] B;
    //B = NULL;
    return 0;
}

#include <iostream>
#include <time.h>
 
using namespace std;
 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Quick sort algorithm and helper functions from https://www.geeksforgeeks.org/cpp-program-for-quicksort/
 
int partition(int arr[], int start, int end)
{
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
 //recursive quick sort algorithm 
void quickSort(int arr[], int start, int end)
{
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(arr, start, end);
 
    // Sorting the left part
    quickSort(arr, start, p - 1);
 
    // Sorting the right part
    quickSort(arr, p + 1, end);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
// binary search from https://www.geeksforgeeks.org/binary-search/
// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
 
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
 
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
 
    // We reach here when element is not
    // present in array
    return -1;
}
 
int linearSearch(int arr[], int arrSize, int target) {
    //return -1 if target element is not found
    int ret = -1;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == target) {
            //ret is assigned the index of the target element if found
            ret = i;
        }
    }
    return ret;
}
 
//uses nested loops to search through array and compare each element to see if they add up to the given sum
//if a pair is found, the sum is printed followed by the pair of integers
void sumPairs(int arr[], int size, int sum) {
    cout << sum << endl;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == sum) {
                cout << " = " << arr[i] << " + " << arr[j] << endl;
            }
        }
    }
}
 
//Driver function
int main() {
    int maxValues; //size of array
    int currentValues; //current size of array as it is added to
    int tempVal; //used to read in number
 
    //assign number of elements to maxValues then create the dynamic arrays, A and B, with maxValues as the size
    cin >> maxValues;
    currentValues = maxValues;
    int *A = new int[maxValues];
    int *B = new int[maxValues];
    cout << "Length of the array: " << maxValues << endl;
    
    //read values from file and put into array A
    for (int i = 0; i < maxValues; i++) {
        cin >> tempVal;
        A[i] = tempVal;
    }
 
    //copy array A to array B
    for (int i = 0; i < maxValues; i++) {
        B[i] = A[i];
    }
 
    //sort array B in ascending order
    quickSort(B, 0, maxValues - 1);
 
    //output array A
    cout << "Array A: ";
    for (int i = 0; i < maxValues; i++) {
        cout << A[i] << " ";
    } cout << endl;
 
    //output array B
    cout << "Array B: ";
    for (int i = 0; i < maxValues; i++) {
        cout << B[i] << " ";
    } cout << endl;
    cout << endl;
    
    //loop to check for commands by upercase letter
    //performs actions based on command letter and number of operations given after it
    
    while (!cin.eof()) {
        
        //setup for temp values to be read in from file
        string inputStr;
        int numOperations = 0;
 
        //read from file to check value
        cin >> inputStr;
 
//FIND CASE
        if (inputStr == "F") {
            cout << "Find: " << endl; 
            cin >> numOperations;
 
            //gets list of values to search for and puts them into array
            int *opArray = new int[numOperations];
            for (int i = 0; i < numOperations; i++) {
                int temp;
                cin >> temp;
                opArray[i] = temp;
            }
            
            //Array B (sorted)
            for (int i = 0; i < numOperations; i++) {
                int element = binarySearch(B, 0, maxValues - 1, opArray[i]);
                if (element > -1) {
                    cout << "Element " << opArray[i] << "  found at " << element << " in B" << endl;
                }
                else {
                    cout << "Element " << opArray[i] << "  not found in B" << endl;
                }
            } cout << endl;
 
            //Array A (unsorted)
            for (int i = 0; i < numOperations; i++) {
                int element = linearSearch(A, maxValues, opArray[i]);
                if (element > -1) {
                    cout << "Element " << opArray[i] << "  found at " << element << " in A" << endl;
                }
                else {
                    cout << "Element " << opArray[i] << "  not found in A" << endl;
                }
            } cout << endl;
            delete [] opArray;
        }
 
//SUMPAIRS CASE
        else if (inputStr == "A") {
            cout << "SumPairs: " << endl;
            cin >> numOperations;
            int *opArray = new int[numOperations];
 
            //gets list of values to add and puts them into array
            for (int i = 0; i < numOperations; i++) {
                int temp;
                cin >> temp;
                opArray[i] = temp;
            }
            
            //Array B (sorted)
            cout << "B:" << endl;
            for (int i = 0; i < numOperations; i++) {
                sumPairs(B, maxValues, opArray[i]);
            }cout << endl << endl;
 
            //Array A (unsorted)
            cout << "A:" << endl;
            for (int i = 0; i < numOperations; i++) {
                sumPairs(A, maxValues, opArray[i]);
            } cout << endl;
            delete [] opArray;
        }
 
//REMOVE CASE
        else if (inputStr == "R") {
            cout << "Remove: " << endl;
            cin >> numOperations;
            int *opArray = new int[numOperations];
 
            //gets list of values to remove and puts them into array
            for (int i = 0; i < numOperations; i++) {
                int temp;
                cin >> temp;
                opArray[i] = temp;
            }
 
             //Array B (sorted)
            int inc = 0;
            int Bsize = maxValues;
            while (inc < numOperations) {
                //search for element to delete to get its index in the array
                int index = binarySearch(B, 0, Bsize, opArray[inc]);
                if (index > -1) {
                    //create temp array and copy B values to it
                    int * tempArrB = new int[Bsize - 1];
                    for (int i = 0; i < Bsize; i++) {
                        tempArrB[i] = B[i];
                    }
 
                    cout << "Removing " << opArray[inc] << " at " << index << " in B" << endl;
                    Bsize--;
                    for (int i = index; i < Bsize; i++) {
                        tempArrB[i] = tempArrB[i + 1];
                    }
                    
                    //create new B array with smaller size and set it equal to the temp array
                    //delete [] B;
                    B = new int[Bsize];
                    B = tempArrB;
                   
                }
                else {
                    cout << "Element " << opArray[inc] << "  not found in B" << endl;
                }
                inc++;
            } cout << endl;
            
            //Array A (unsorted)
            int Asize = maxValues;
            inc = 0;
            while (inc < numOperations) {
                //search for element to remove and get its index in the array
                int index = linearSearch(A, Asize, opArray[inc]);
                if (index > -1) {
                    //create temp array and copy A values to it
                    int * tempArrA = new int[Asize - 1];
                    for (int i = 0; i < Asize; i++) {
                        tempArrA[i] = A[i];
                    }
 
                    cout << "Removing " << opArray[inc] << " at " << index << " in A" << endl;
                    Asize--;
                    for (int i = index; i < Asize; i++) {
                        tempArrA[i] = tempArrA[i + 1];
                    }
 
                    //delete original array and assign the temp array values to the new smaller one
                    //delete [] A;
                    A = new int[Asize];
                    A = tempArrA;
                   currentValues = Asize;
                }
                else {
                    cout << "Element " << opArray[inc] << "  not found in A" << endl;
                }
                inc++;
            } cout << endl;
            
 
            //A output
            cout << "After removal Array A: ";
            for (int i = 0; i < Asize - 1; i++) {
                cout << A[i] << " ";
            } cout << A[Asize - 1] << endl;
 
            //B ouput
            cout << "After removal Array B: ";
            for (int i = 0; i < Bsize - 1; i++) {
                cout << B[i] << " ";
            } cout << B[Bsize - 1] << endl;
            cout << endl;
            delete [] opArray;
        }
 
//INSERT CASE
        else if (inputStr == "I") {
            cout << "Insert: " << endl;
            cin >> numOperations;
            int* opArray = new int[numOperations];
 
            //gets list of values to insert and puts them into array
            for (int i = 0; i < numOperations; i++) {
                int temp;
                cin >> temp;
                opArray[i] = temp;
            }
 
            //Array B (sorted) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            int Bsize = currentValues;
            Bsize = Bsize + numOperations;
 
            //temp array to hold values while increasing size of original array
            int * tempArrB = new int[Bsize];
            for (int i = 0; i < currentValues; i++) {
                tempArrB[i] = B[i];
            }
 
            //delete original B array and create new one with larger size
            //delete [] B;
            int * B = new int[Bsize];
 
            //add original values back into B
            for (int i = 0; i < currentValues; i++) {
                B[i] = tempArrB[i];
            }
 
            //add new values to B array
            int inc = 0;
            for (int i = currentValues; i < Bsize; i++) {
                cout << "Inserting " << opArray[inc] << " in B" << endl;
                B[i] = opArray[inc];
                inc++;
            }
 
            //sort new array
            quickSort(B, 0, Bsize - 1);
            cout << endl;
            //Array B done ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
            //Array A (unsorted) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            int Asize = currentValues;
            Asize = Asize + numOperations;
 
            //temp array to hold values while increasing size of origninal array
            int * tempArrA = new int[Asize];
            for (int i = 0; i < currentValues; i++) {
                tempArrA[i] = A[i];
            }
 
            //delete original A array and create a new one with larger size
            //delete [] A;
            int * A = new int[Asize];
 
            //add original values back into A
            for (int i = 0; i < currentValues; i++) {
                A[i] = tempArrA[i];
            }
 
            //add new values to A array
            inc = 0;
            for (int i = currentValues; i < Asize; i++) {
                A[i] = opArray[inc];
                cout << "Inserting " << opArray[inc] << " in A" << endl;
                inc++;
            }
            cout << endl;
            //A array done ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
            //A output
            cout << "After insertions Array A: "; 
            for (int i = 0; i < Asize; i++) {
                cout << A[i] << " ";
            } //cout << A[Asize - 1] << endl; 
            cout << endl;
 
            //B output
            cout << "After insertions Array B: ";
            for (int i = 0; i < Bsize; i++) {
                cout << B[i] << " ";
            }cout << endl;
            
            delete [] opArray;
        } 
        else {
            cout << inputStr;
        }
    } 
 
 
    //delete arrays and end program
    delete [] A;
    //A = NULL;
    delete [] B;
    //B = NULL;
    return 0;
