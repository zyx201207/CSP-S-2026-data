#include<bits/stdc++.h>
using namespace std;
int xc,rc,xz,rz,xs,rs;
char x[10],r[10];
string s;
int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s;
    if(s[0]=='0'){
        xc=s[1]-'0';
    }
    else{
        xc=s[0]-'0';
        xc=xc*10+s[1]-'0';
    }
    cin>>s;
    if(s[0]=='0'){
        xz=s[1]-'0';
    }
    else{
        xz=s[0]-'0';
        xz=xz*10+s[1]-'0';
    }
    xs=s[2]-'A';


    cin>>s;
    if(s[0]=='0'){
        rc=s[1]-'0';
    }
    else{
        rc=s[0]-'0';
        rc=rc*10+s[1]-'0';
    }
    cin>>s;
    if(s[0]=='0'){
        rz=s[1]-'0';
    }
    else{
        rz=s[0]-'0';
        rz=rz*10+s[1]-'0';
    }
    rs=s[2]-'A';


    int f=1;
    if(xc==rc)
        cout<<"1";
    else{
        cout<<"0";
        f=0;
    }
    if(xz==rz && f==1)
        cout<<"1";
    else{
        cout<<"0";
        f=0;
    }
    if(((xs<=2 && rs<=2) || (xs>2 && rs>2)) && f==1)
        cout<<"1";
    else{
        cout<<"0";
        f=0;
    }
    if(f==1 && (xs-rs)*(xs-rs)==1)
        cout<<"1";
    else
        cout<<"0";
    return 0;
}

