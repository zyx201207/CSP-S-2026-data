#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r", travel.cpp);
    freopen("travel.out","w",travel.cpp);
    char c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    if(s1/1000==s2/1000){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    if(s1/100%10==s2/100%10){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    if(s1%100+'1'==s2%100){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    return 0;
}
