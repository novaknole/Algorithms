#include <iostream>

using namespace std;



int main()
{
    int n;
    int m;
    cin>>n;
    cin>>m;
    int array[n];
    int helper[n];
    for(int i=0;i<n;i++){
        helper[i] = -1;
    }
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    
    for(int j=0;j<n;j++){
        int leftSolution; int rightSolution;
        if(j-m < 0) {
            helper[j] = 0;
        }else{
            leftSolution = array[j]+helper[j-m];
            if(j-1 < 0) rightSolution = 0;
            else rightSolution = helper[j-1];
            helper[j] = max(leftSolution,rightSolution);
        }
    }
    
    cout<<helper[n-1]<<endl;
    
    
}