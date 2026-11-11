#include<bits/stdc++.h>
using namespace std;
int gd1,gd2;
char cx[105];
string zw;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=1;i<=2;i++){
        cin>>cx[i];
    }
    for(int i=1;i<=3;i++){
        cin>>zw[i];
    }
    for(int i=3;i<=4;i++){
        cin>>cx[i];
    }
    for(int i=4;i<=6;i++){
        cin>>zw[i];
    }
    gd1=zw[3];
    gd2=zw[6];
    if(cx[1]==cx[3]&&cx[2]==cx[4]) cout<<'1';
    else{
        cout<<"0000";
        return 0;
    }
    if(zw[1]==zw[4]&&zw[2]==zw[5]) cout<<'1';
    else{
        cout<<"000";
        return 0;
    }
    if(gd1<=67&&gd2<=67) cout<<'1';
    else{
        cout<<"00";
        return 0;
    }
    if(gd1-gd2==1||gd1-gd2==-1) cout<<'1';
    else cout<<'0';
    return 0;
}
