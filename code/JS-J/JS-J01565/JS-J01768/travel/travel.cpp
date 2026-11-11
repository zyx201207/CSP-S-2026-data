#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string rx,ry,xx,xy;

int main(){
    freopen("travel.in",'r',stdin);
    freopen("travel.out",'w',stdout);
    cin>>rx>>ry>>xx>>xy;
    if(rx==xx){
        cout<<'1';
    }
    else{
        cout<<'0'<<'0'<<'0'<<'0';
        return 0;
    }

    if(ry[1]==xy[1]){
        cout<<'1';
    }
    else{
        cout<<'0'<<'0'<<'0';
        return 0;
    }

    if((ry[2]=='D'||ry[2]=='F')&&(xy[2]=='A'||xy[2]=='B'||xy[2]=='C')){
        cout<<'0';
        cout<<'0';
        return 0;
    }
    else if((ry[2]=='A'||ry[2]=='B'||ry[2]=='C')&&(xy[2]=='D'||xy[2]=='F')){
        cout<<'0';
        cout<<'0';
        return 0;
    }
    else{
        cout<<'1';
    }

    if((ry[2]=='A'&&xy[2]=='B')||(ry[2]=='B'&&xy[2]=='A')){
        cout<<'1';
    }
    else if((ry[2]=='C'&&xy[2]=='B')||(ry[2]=='B'&&xy[2]=='C')){
        cout<<'1';
    }
    else if((ry[2]=='D'&&xy[2]=='F')||(ry[2]=='F'&&xy[2]=='D')){
        cout<<'1';
    }
    else{
        cout<<'0';
    }
    return 0;
}
