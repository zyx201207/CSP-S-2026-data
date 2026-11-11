#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string xz,rz;
    int xc,rc;
    cin>>rc>>rz>>xc>>xz;
    if(xc==rc){
        if(xz[0]==rz[0]&&xz[1]==rz[1]){
            if((xz[2]=='A'||xz[2]=='B'||xz[2]=='C')&&(rz[2]=='A'||rz[2]=='B'||rz[2]=='C')||(xz[2]=='D'||xz[2]=='F')&&(rz[2]=='D'||rz[2]=='F')){
                if((xz[2]=='A'&&rz[2]=='C')||(rz[2]=='A'&&xz[2]=='C')){
                    cout<<"1110";
                }else{
                    cout<<"1111";
                }
            }else{
                cout<<"1100";
            }
        }else{
            cout<<"1000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
