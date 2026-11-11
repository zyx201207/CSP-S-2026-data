#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int c_1=0,c_2=0,s1n=0,s2n=0;
    c_1=(c1[0]-'0')*10+c1[1]-'0';
    c_2=(c2[0]-'0')*10+c2[1]-'0';
    s1n=(s1[0]-'0')*10+s1[1]-'0';
    s2n=(s2[0]-'0')*10+s2[1]-'0';
    bool t;
    if(c_1==c_2){
        cout<<1;
        t=1;
    }
    else{
        cout<<0;
        t=0;
    }


    if(s1n==s2n&&t==1){
        cout<<1;
    }
    else{
        cout<<0;
        t=0;
    }


    if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&t==1){
        cout<<1;
    }
    else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')&&t==1){
        cout<<1;
    }
    else{
        cout<<0;
        t=0;
    }


    if(t==1&&(s1[2]+1==s2[2]||s1[2]-1==s2[2])){
        cout<<1;
    }
    else {
        cout<<0;
    }
    return 0;
}
