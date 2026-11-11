#include<bits/c++io.h>
#include<iostream>
using namespace std;
int main()
{
    int nx;
    cin>>nx;
    int a,b;

    for(int i=1;i<=nx;i++){
        cin>>a>>b;

        if(a!=b){
            cout<<a+b;

        }
        else{
            cout<<0;
        }
    }
    return 0;
}




