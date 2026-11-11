#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char c1,c2;
    string s1,s2;
    int a;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
    }
    else{
        cout<<"0";
    }

    if(a/10%2==0){
        cout<<"1";
    }
    else{
        cout<<'0';
    }

    if(a/10%2==1){
        cout<<'1';
    }
    else{
        cout<<'0';
    }
    if(a%10==0){
        cout<<'0';
    }
    else{
        cout<<'1';
    }

}
