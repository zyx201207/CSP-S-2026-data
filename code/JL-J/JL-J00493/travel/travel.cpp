#include<bits/stdc++.h>
using namespace std;
string rc,rz,xc,xz;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>rc>>rz>>xc>>xz;
    if(rc==xc){

    }else{
        cout<<"0000";
        return 0;
    }
    if(rz[0]==xz[0]&&rz[1]==xz[1]){

    }else{
        cout<<"1000";
        return 0;
    }
    if((rz[2]=='D'&&xz[2]=='F')||(rz[2]=='F'&&xz[2]=='D')){
        cout<<"1111";
        return 0;
    }
    if((rz[2]=='A'&&xz[2]=='C')||(rz[2]=='C'&&xz[2]=='A')){
        cout<<"1110";
        return 0;
    }
    if((rz[2]=='A'&&xz[2]=='B')||(rz[2]=='B'&&xz[2]=='A')){
        cout<<"1111";
        return 0;
    }
    if((rz[2]=='B'&&xz[2]=='C')||(rz[2]=='C'&&xz[2]=='B')){
        cout<<"1111";
        return 0;
    }
    cout<<"1100";
    return 0;
}
