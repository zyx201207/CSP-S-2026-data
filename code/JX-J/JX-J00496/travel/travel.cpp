#include<bits/stdc++.h>
using namespace std;
string rx,rz,xx,xz;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>rx>>rz;
    cin>>xx>>xz;
    if(rx[0]==xx[0]&&rx[1]==xx[1]){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    if(rz[0]==xz[0]&&rz[1]==xz[1]){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    if((rz[2]-'0'<='C'-'0'&&xz[2]-'0'<='C'-'0')||(rz[2]-'0'>='D'-'0'&&xz[2]-'0'>='D'-'0')){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }
    if(abs((rz[2]-'0')-(xz[2]-'0'))==1){
        cout<<1;
    }else cout<<0;
    return 0;
}
