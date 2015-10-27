#include <stdio.h>
#include <stdlib.h>
  
double  _mergeSort(int arr[], int temp[], int left, int right);
double merge(int arr[], int temp[], int left, int mid, int right);
  
/* This function uese mergesort to sort the input array and returns the
   number of inversions in the array */
double mergeSort(int arr[], int array_size)
{
    int *temp = (int *)malloc(sizeof(int)*array_size);
    return _mergeSort(arr, temp, 0, array_size - 1);
}
  
/* An auxiliary recursive function that sorts the input array and
  returns the number of inversions in the array. */
double _mergeSort(int arr[], int temp[], int left, int right)
{
  int mid;
  double inv_count = 0.0;
  if (right > left)
  {
    /* Divide the array into two parts and call _mergeSortAndCountInv()
       for each of the parts */
    mid = left + (right - left) / 2;
  
    /* Inversion count will be sum of inversions in left-part, right-part
      and number of inversions in merging */
    inv_count  = _mergeSort(arr, temp, left, mid);
    inv_count += _mergeSort(arr, temp, mid + 1, right);
  
    /*Merge the two parts*/
    inv_count += merge(arr, temp, left, mid + 1, right);
  }
  return inv_count;
}
  
/* This funt merges two sorted arrays and returns inversion count in
   the arrays.*/
double merge(int arr[], int temp[], int left, int mid, int right)
{
  int i, j, k;
  double inv_count = 0.0;
  
  i = left; /* i is index for left subarray*/
  j = mid;  /* i is index for right subarray*/
  k = left; /* i is index for resultant merged subarray*/
  while ((i <= mid - 1) && (j <= right))
  {
    if (arr[i] <= arr[j])
      temp[k++] = arr[i++];
    else
    {
      temp[k++] = arr[j++];
      inv_count = inv_count + (mid - i);
    }
  }
  
  /* Copy the remaining elements of left subarray
   (if there are any) to temp*/
  while (i <= mid - 1)
    temp[k++] = arr[i++];
  
  /* Copy the remaining elements of right subarray
   (if there are any) to temp*/
  while (j <= right)
    temp[k++] = arr[j++];
  
  /*Copy back the merged elements to original array*/
  for (i = left; i <= right; i++)
    arr[i] = temp[i];
  
  return inv_count;
}
  
/* Driver program to test above functions */
int main(int argv, char** args)
{
  int arr[100000];
  FILE *myFile;
  myFile = fopen("IntegerArray.txt", "r");
  for (int i = 0; i < 100000; ++i)
    {
        fscanf(myFile, "%d", &arr[i]);
    }

  printf(" Number of inversions are %20f \n", mergeSort(arr, 100000));
  
  return 0;
}
