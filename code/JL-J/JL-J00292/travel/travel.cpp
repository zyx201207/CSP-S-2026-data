#include<bits/stdc++.h>
using namespace std;
int ca,cb;
string za,zb;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>ca>>za>>cb>>zb;
    if(ca==cb) cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    if(za[0]==zb[0]&&za[1]==zb[1]){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    if((za[2]=='A'||za[2]=='B'||za[2]=='C')&&(zb[2]=='A'||zb[2]=='B'||zb[2]=='C')) cout<<1;
    else if((za[2]=='D'||za[2]=='F')&&(zb[2]=='D'||zb[2]=='F')) cout<<1;
    else{
        cout<<"00";
        return 0;
    }
    if((za[2]=='A'&&zb[2]=='B')||(za[2]=='B'&&zb[2]=='A')||(za[2]=='B'&&zb[2]=='C')||(za[2]=='C'&&zb[2]=='B')||(za[2]=='D'&&zb[2]=='F')||(za[2]=='F'&&zb[2]=='D')){
        cout<<1;
    }else cout<<0;
    return 0;
}
