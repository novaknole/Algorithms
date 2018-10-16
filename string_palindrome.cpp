#include <iostream>


using namespace std;


bool is_palindrome(string str,int left_index, int right_index){
    if(left_index>right_index)  return true;
    if(str[left_index] != str[right_index]) return false;
    else if(left_index == right_index) return true;
    else  return is_palindrome(str,left_index+1, right_index-1);
}

int main(){
    string palindrome;
    cin>>palindrome;
    cout<<is_palindrome(palindrome,0,palindrome.size()-1)<<endl;
}