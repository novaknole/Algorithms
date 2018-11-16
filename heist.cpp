#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr, arr + n);

    int count=0;
    for(int j=1;j<n;j++){
        int current = arr[j];
        int previous = arr[j-1];
        count+=current-previous-1;
    }
    cout<<count<<endl;
}