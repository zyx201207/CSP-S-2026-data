#include<bits/stdc++.h>
using namespace std;
int rc,xc;
string rz,xz;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>rc>>rz>>xc>>xz;
    if(rc!=xc){
        cout<<"0000";
        return 0;
    }else{
        cout<<1;
    }
    if(rz[0]!=xz[0]||rz[1]!=xz[1]){
        cout<<"000";
        return 0;
    }else cout<<1;
    int rzz=(int)rz[2]-64,xzz=(int)xz[2]-64;
    if((rzz<=3&&xzz<=3)||(rzz>3&&xzz>3)){
        cout<<1;
        if(rzz>3&&xzz>3)cout<<1;
        else{
            if(xzz>rzz)swap(xzz,rzz);
            if(rzz==4&&xzz==3)cout<<0;
            else if(rzz-xzz==1)cout<<1;
            else cout<<0;
        }
    }else{
        cout<<"00";
    }
    return 0;
}
