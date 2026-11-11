#include<bits/stdc++.h>
using namespace std;
int rxs,xxs,rzs,xzs;
string rx,rz,xx,xz;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>rx>>rz>>xx>>xz;
    rxs=int(rx[0]-'0')*10+int(rx[1]-'0');
    xxs=int(xx[0]-'0')*10+int(xx[1]-'0');
    rzs=int(rz[0]-'0')*10+int(rz[1]-'0');
    xzs=int(xz[0]-'0')*10+int(xz[1]-'0');
    if(rxs==xxs){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(rzs==xzs){
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }
    if(rz[2]=='A'){
        if(xz[2]=='B')cout<<"11";
        else if(xz[2]=='C')cout<<"10";
        else if(xz[2]=='D')cout<<"00";
        else if(xz[2]=='F')cout<<"00";
    }

    else if(rz[2]=='B'){
        if(xz[2]=='A')cout<<"11";
        else if(xz[2]=='C')cout<<"11";
        else if(xz[2]=='D')cout<<"00";
        else if(xz[2]=='F')cout<<"00";
    }

    else if(rz[2]=='C'){
        if(xz[2]=='A')cout<<"10";
        else if(xz[2]=='B')cout<<"11";
        else if(xz[2]=='D')cout<<"00";
        else if(xz[2]=='F')cout<<"00";
    }

    else if(rz[2]=='D'){
        if(xz[2]=='A')cout<<"00";
        else if(xz[2]=='B')cout<<"00";
        else if(xz[2]=='C')cout<<"00";
        else if(xz[2]=='F')cout<<"11";
    }

    else{
        if(xz[2]=='A')cout<<"00";
        else if(xz[2]=='B')cout<<"00";
        else if(xz[2]=='C')cout<<"00";
        else if(xz[2]=='D')cout<<"11";
    }
    return 0;
}
/*
12 12A 12 01B
05 01A 05 12B
02 04C 02 04D
*/
