#include<bits/stdc++.h>
using namespace std;
string cx1,cx2;
string zw1,zw2;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>cx1>>zw1>>cx2>>zw2;
    string p1=zw1.substr(0,2);
    string p2=zw2.substr(0,2);
    char z1=zw1[2];
    char z2=zw2[2];
    if(cx1==cx2){
        cout<<1;
        if(p1!=p2){
            cout<<"000";
        }else{
            cout<<1;
            if((z1>='D' and z2>='D') or (z1<='C' and z2<='C')){
                cout<<1;
                if(abs(z1-z2)==1 or (z1=='D' and z2=='F') or (z1=='F' and z2=='D')){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<"00";
            }
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
