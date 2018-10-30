/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include<bits/stdc++.h> 
using namespace std;


long long gcd(long long a, long long b) { 
    if (b == 0) 
       return a; 
    return __gcd(b, a%b); 
} 
  
 
long long getBoundaryCount(long long x1,long long y1,long long x2,long long y2) { 
    
    if (x1==x2) 
        return llabs(y1-y2); 
    if (y1==y2) 
        return llabs(x1-x2); 
  
    return __gcd(abs(x1-x2),abs(y1-y2));
} 
  




long long polygonArea(long long X[], long long Y[], long long n) { 
    long long area = 0.0; 
    long long j = n - 1; 
    for (long long i = 0; i < n; i++) { 
        area += (X[j] + X[i]) * (Y[j] - Y[i]); 
        j = i; 
    } 
    return llabs(area);
}


int main(){
    long long n;
    cin>>n;
    long long X[n];
    long long Y[n];
    for(int i=0;i<n;i++){
        cin>>X[i];cin>>Y[i];
    }

    long long area = polygonArea(X,Y,n);
    
    long long boundary=0.0;
    for(int i=0;i<n-1;i++){
        long long x_1= X[i];
        long long y_1 = Y[i];
        long long x_2 = X[i+1];
        long long y_2 = Y[i+1];
        boundary+=getBoundaryCount(x_1,y_1,x_2,y_2);
    }

     boundary+=getBoundaryCount(X[0],Y[0],X[n-1],Y[n-1]);
    
     cout<<(area-boundary+2)/2<<endl;

    
}
