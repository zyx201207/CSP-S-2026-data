#include<bits/stdc++.h>
using namespace std;
int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a1,a2,b1,b2;
    char x,y;
    cin>>a1>>a2>>x>>b1>>b2>>y;
    if(a1!=b1){
        cout<<"0000";
        return 0;
    }
    if(a1==b1){
        cout<<"1";
    }else{
        cout<<"0";
    }
    if(a2==b2){
        cout<<"1";
    }else{
        cout<<"000";
        return 0;
    }
    int a3,b3;
    if(x<='C') a3=1;
    else a3=2;
    if(y<='C') b3=1;
    else b3=2;
    if(a3==b3&&a2==b2) cout<<"1";
    else cout<<"0";
    if(a2!=b2){
        cout<<"0";
        return 0;
    }
    if(x=='A'&&y=='B'){
        cout<<"1";
        return 0;
    }
    if(x=='C'&&y=='B'){
        cout<<"1";
        return 0;
    }
    if(x=='B'&&y=='A'){
        cout<<"1";
        return 0;
    }
    if(x=='B'&&y=='C'){
        cout<<"1";
        return 0;
    }
    if(x=='D'&&y=='F'){
        cout<<"1";
        return 0;
    }
    if(x=='F'&&y=='D'){
        cout<<"1";
        return 0;
    }
    cout<<"0";

    return 0;
}

