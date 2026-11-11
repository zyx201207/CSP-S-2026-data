#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int cr,cx;
    string zr,zx;
    cin>>cr>>zr>>cx>>zx;
    if(cr==cx){
        cout<<1;
        if(zr[0]==zx[0]&&zr[1]==zx[1]){
            cout<<1;
            if(((zr[2]=='A'||zr[2]=='B'||zr[2]=='C')&&(zx[2]=='A'||zx[2]=='B'||zx[2]=='C'))||((zr[2]=='D'||zr[2]=='F')&&(zr[2]=='D'||zr[2]=='F'))){
                cout<<1;
                if(int(char(zr[2])-char(zx[2]))==1||int(char(zr[2])-char(zx[2]))==-1||((zr[2]=='D'||zr[2]=='F')&&(zx[2]=='D'||zx[2]=='F'))){
                    cout<<1;
                }else{
                    cout<<"0";
                }
            }else{
                cout<<"00";
            }
        }else{
              cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
