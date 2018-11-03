#include <iostream>

using namespace std;


int array[1000002];
int n=1000001;
int getSum(int index) 
{ 
    int sum = 0; // Iniialize result 
  
    // index in BITree[] is 1 more than the index in arr[] 
    index = index + 1; 
  
    // Traverse ancestors of BITree[index] 
    while (index>0) 
    { 
        // Add current element of BITree to sum 
        sum += array[index]; 
  
        // Move index to parent node in getSum View 
        index -= index & (-index); 
    } 
    return sum; 
} 

  
  
  

void updateBIT(int index, int val) 
{ 
    // index in BITree[] is 1 more than the index in arr[] 
    index = index + 1; 
  
    // Traverse all ancestors and add 'val' 
    while (index <= n) { 
    // Add 'val' to current node of BI Tree 
        array[index] += val; 
      
        // Update index to that of parent in update View 
        index += index & (-index); 
    } 
} 


int function(int value){
    int k;
    if(value == 0){
        k = getSum(n-1)-0;
    }else{
        k = getSum(n-1)-getSum(value-1);
    }

    updateBIT(value, 1);
    return  k;
}



int main()
{
    int z;
    cin>>z;
    
    
    for (int i=1; i<=n; i++){
        array[i] = 0;
    }
    
    
    for(int i=0;i<z;i++){
        int k;
        cin>>k;
        cout<<z-function(k)<<endl;
    }
    

    return 0;
}