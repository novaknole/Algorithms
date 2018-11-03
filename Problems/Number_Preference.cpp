#include <iostream>
#include <cmath>
#include <algorithm> 
#include <map>
using namespace std;



int main(){
    int n;
    cin>>n;
    std::map<long long,int> likeMap;
    std::map<long long,int> unLikeMap;
    int likedOnes=0;
    for(int i=0;i<n;i++){
        int likeOrHate;
        cin>>likeOrHate;
        int howManyNum;
        cin>>howManyNum;
        if(likeOrHate == 1) likedOnes++;

        for(int j=0;j<howManyNum;j++){
            long long integer;
            cin>>integer;
            if(likeOrHate==1) {
                if(likeMap[integer] != -1) likeMap[integer]++;
            }else{
                likeMap[integer] = -1;
                unLikeMap[integer]=0;
            }
           
        }
       
    }
    long long howManyIntegers=0;

    if(likedOnes == 0){
        cout<<1000000000000000000- unLikeMap.size()<<endl;
    }else{
        for (std::map<long long,int>::iterator it=likeMap.begin(); it!=likeMap.end(); ++it){
            
            int second = it->second;
            if(second == likedOnes){
                howManyIntegers++;
            }
        }
        cout<<howManyIntegers<<endl;
    }


    
            

}