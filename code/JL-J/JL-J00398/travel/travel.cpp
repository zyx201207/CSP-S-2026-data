#include<bits/stdc++.h>
using namespace std;
int a,b;
string a1,b1;
int main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    cin>>a>>a1;
    cin>>b>>b1;
    if(a==01 || b==01 || a==16 || b==16){
        cout<<0000;
        return 0;
    }
    if(a==b){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(a1[1]==b1[1]){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if((a1[2]<='C' && b1[2]<='C') || (a1[2]>'C' && b1[2]>'C')){
        cout<<1;
        if((a1[2]=='A' && b1[2]=='B') ||(a1[2]=='B' && b1[2]=='C') || (a1[2]=='B' && b1[2]=='A') ||(a1[2]=='C' && b1[2]=='B') || (a1[2]=='D' && b1[2]=='F') || (a1[2]=='F' && b1[2]=='D')){
        cout<<1;
        return 0;
    }
    else{
        cout<<0;
        return 0;
    }
    }
    else{
        cout<<0;
        cout<<0;
    }

}
