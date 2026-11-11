#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    reopen("travel.out","w",stdout);
    string c1;
    string s1;
    string c2;
    string s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        if(s1!=s2){
            cout<<100;}}
    else{
        for(int i=0;i<=3;i++)
            cout<<0;
    }


    return 0;}




