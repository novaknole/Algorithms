
#include <iostream>
#include <string>
using namespace std;




  

void getZArray(string str, int Z[]) { 
    int n = str.length(); 
    int L, R, k; 
    L = R = 0; 
    for (int i = 1; i < n; ++i) { 
        if (i > R) 
        { 
            L = R = i; 
            while (R<n && str[R-L] == str[R]) 
                R++; 
            Z[i] = R-L; 
            R--; 
        } 
        else
        { 
          
            k = i-L; 
  
          
            if (Z[k] < R-i+1) 
                Z[i] = Z[k]; 
  
            
            else{ 
            
                L = i; 
                while (R<n && str[R-L] == str[R]) 
                    R++; 
                Z[i] = R-L; 
                R--; 
            } 
        } 
    } 
} 
  



int main(){
    int n;
    cin>>n;

    string k;
    cin>>k;
    k=k+k;

    int Z[n*2];
    getZArray(k,Z);
    bool isItUgly = true;
    for(int i=1;i<n;i++){
        int z_value = Z[i];
        if(z_value+i <= n*2-1){
            if(k[z_value+i] < k[z_value]) {
                isItUgly = false;
                break;
            }
        }
    }

    if(isItUgly) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    
}