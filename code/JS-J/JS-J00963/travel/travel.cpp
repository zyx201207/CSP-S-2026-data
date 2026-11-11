#include<bits/stdc++.h>
using namespace std;
string rc,rz,xc,xz;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>rc>>rz>>xc>>xz;
    int f=1;
    for(int i=0;i<rc.size();i++){
        if(rc[i]!=xc[i]){
            f=0;
            break;
        }
    }
    if(f==1){
        cout<<1;
        for(int i=0;i<=1;i++){
            if(rz[i]!=xz[i]){
                f=0;
                break;
            }
        }
        if(f==1){
            cout<<"1";
            if(rz[2]>='A'&&rz[2]<='C'&&xz[2]>='A'&&xz[2]<='C'){
                cout<<1;
                if(abs(rz[2]-xz[2])==1){
                    cout<<"1";
                }
                else cout<<"0";
            }
            else if(rz[2]>='D'&&rz[2]<='F'&&xz[2]>='D'&&xz[2]<='F'){
                cout<<"11";
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else cout<<"0000";

    return 0;
}
