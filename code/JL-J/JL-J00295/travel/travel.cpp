#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int ok=1;
    string a,b,c,d,str;
    cin>>a>>b>>c>>d;
    if(a==c) ok=1;
    else ok=0;
    if(ok==0) str+="0";
    else str+="1";
    if(ok==1){
        if(b[0]==d[0]&&b[1]==d[1]) ok=1;
        else ok=0;
    }
    if(ok==0) str+="0";
    else str+="1";
    if(ok==1){
    if(b[2]=='F'||b[2]=='D'){
        if(b[2]=='F'&&d[2]!='D') ok=0;
        if(b[2]=='D'&&d[2]!='F') ok=0;
    }
    if(d[2]=='F'||d[2]=='D'){
        if(d[2]=='F'&&b[2]!='D') ok=0;
        if(d[2]=='D'&&b[2]!='F') ok=0;

    }
    }
    if(ok==0) str+="0";
    else str+="1";
    if(ok==1)
    {
        if(b[2]+1==d[2]||b[2]-1==d[2]) ok=1;
        if(d[2]+1==b[2]||d[2]-1==b[2]) ok=1;
        else ok=0;
    }
    if(ok==0) str+="0";
    else str+="1";
    cout<<str;
    }
