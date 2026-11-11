#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string num1,sit1,num2,sit2;
    cin>>num1>>sit1>>num2>>sit2;

    if(num1==num2) cout<<1;
    else {cout<<"0000";return 0;}

    int a=0,b=0;
    if(sit1[0]!='0') a+=sit1[0]-'0';
    a=a*10+sit1[1];
    if(sit2[0]!='0') b+=sit2[0]-'0';
    b=b*10+sit2[1];
    if(a==b) cout<<1;
    else {cout<<"000";return 0;}

    if(sit1[2]=='A'||sit1[2]=='B'||sit1[2]=='C'){
        if(sit2[2]=='A'||sit2[2]=='B'||sit2[2]=='C') cout<<1;
        else {cout<<"00";return 0;}
    }
    else{
        if(sit2[2]=='D'||sit2[2]=='F') cout<<1;
        else {cout<<"00";return 0;}
    }

    if(sit1[2]=='A'&&sit2[2]=='B') cout<<1;
    else if(sit1[2]=='B'&&(sit2[2]=='A'||sit2[2]=='C')) cout<<1;
    else if(sit1[2]=='C'&&sit2[2]=='B') cout<<1;
    else if(sit1[2]=='D'&&sit2[2]=='F') cout<<1;
    else if(sit1[2]=='F'&&sit2[2]=='D') cout<<1;
    else {cout<<0;return 0;}
    return 0;
}
