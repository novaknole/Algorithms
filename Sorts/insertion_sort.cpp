
#include <iostream>

using namespace std;


/* Insertion Sort
 Time Complexity:
    O(n^2)

*/
void InsertionSort(int arr[],int size){
    for(int i=1;i<size;i++){
        int current = arr[i];
        int j=i-1;
        while(true){
            int prev = arr[j];
            if(current<prev){
                arr[j] = current;
                arr[j+1] = prev;
            }
            j=j-1;
            if(j==-1) break;
        }
    }
}
int main(){
    int unsorted_array[] = {300,20,3};
    int size = sizeof(unsorted_array)/sizeof(unsorted_array[0]);
    InsertionSort(unsorted_array, size);
    for(int i=0;i<size;i++){
        cout<<unsorted_array[i]<<endl;
    }
}