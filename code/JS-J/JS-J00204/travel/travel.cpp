#include<bits/stdc++.h>
using namespace std;
int xrc,xxc;
char xrw[10],xxw[10];

int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>xrc>>xrw[1]>>xrw[2]>>xrw[3]>>xxc>>xxw[1]>>xxw[2]>>xxw[3];
if(xrc==xxc){
    cout<<1;
    if(xrw[1]==xxw[1]&&xrw[2]==xxw[2]){
        cout<<1;
        if((xrw[3]<='F'&&xrw[3]>='D'&&xxw[3]<='F'&&xxw[3]>='D')||(xrw[3]<='C'&&xrw[3]>='A'&&xxw[3]<='C'&&xxw[3]>='A')){
            cout<<1;
            if(int(xrw[3]-xxw[3])==1||int(xrw[3]-xxw[3])==-1){
                cout<<1;
            }
            else{
                cout<<"0";
            }
        }
        else{
            cout<<"00";
        }
    }
    else{
        cout<<"000";
    }
}
else{
    cout<<"0000";
}



return 0;
}
