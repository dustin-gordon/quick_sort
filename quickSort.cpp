/**
 * @author Dustin Gordon 
 */

#include <iostream>
using namespace std;
  
// A helper function to facilitate swapping two int elements.
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
} 
  
/* This function partitions sub-array A[p..r]. It takes last element in the sub-array, i.e., A[r], as pivot,
 * places the pivot element at its correct position in sorted array,
 * places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot,
 * and returns the index of the pivot element (i.e. it's correct position in sorted array)
 */
int partition (int Array[], int part, int rear)
{
    int pivot = Array[rear];
    int i = (part-1);

    for(int j = part; j <= rear-1; j++)
    {
        if(Array[j] <= pivot)
        {
            i++;
            swap(&Array[i], &Array[j]);
        }
    }
    swap(&Array[i + 1], &Array[rear]);
    return (i + 1);
} 
  
/* Using quickSort to sort sub-array A[p..r]
 * p is for left index and r is right index of the
 * sub-array of A[] to be sorted.
 */
void quickSort(int Array[], int part, int rear)
{
    if (part < rear)
    {
        int index = partition(Array, part, rear);

        quickSort(Array, part, index - 1);
        quickSort(Array, index + 1, rear);
    }
} 
  

int main() 
{ 
    cout << "Please enter the length (number of elements) of the input array: ";
	int n;
	cin >> n;
	
	if(n <= 0) {
		cout << "Illegal input array length!" << endl;
		return 0;
	}
	
	int* A = new int [n];
	
	cout << "Please enter each element in the array" << endl; 
	cout << "(each element must be an integer within the range of int type)." << endl;
	for(int i = 0; i < n; i++)
	{
		cout << "A[" << i << "] = ";
		cin >> A[i];
	}
  
    cout << "Given array A[] is: "; 
	for(int i = 0; i < n-1; i++)
    {
        cout << A[i] << ",";
    }
	cout << A[n-1] << endl;

    quickSort(A, 0, n-1); 
  
    cout << "After quickSort, sorted array A[] is: "; 
	for(int i = 0; i < n-1; i++)
    {
        cout << A[i] << ",";
    }
	cout << A[n-1] << endl;
	
	delete [] A;
    return 0; 
} 