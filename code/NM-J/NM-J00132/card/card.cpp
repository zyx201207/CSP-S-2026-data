#include<bits/stdc++.h>
using namespace std;
int a;
int main(){
    cin>>a;
    if(a%2==0){
        a=a/2;
    }
    if(a%2==1){
        a=2*a+1;
    }
    cout<<a;
    return 0;
}
