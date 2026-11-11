#include<bits/stdc++.h>
using namespace std;
int In;
const int IN=2e6+5;
typedef long long xt;
xt xD;
xt xI[IN];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int Tc,Ts;
    cin>>Tc;
    if(Tc==11||Tc==12){
        xt xdf;
        xt Icr;
        for(cin>>Ts;Ts;--Ts){
            cin>>In>>xD;
            for(int I=1;I<=In;++I){
                cin>>xI[I];
            }
            if(In==1){
                cout<<"0\n";
                continue;
            }
            xdf=xI[2]-xI[1];
            if(xD<xdf){
                cout<<"0\n";
                continue;
            }
            Icr=xD/xdf;
            if(Icr==1){
                cout<<"0\n";
                continue;
            }
            if(In<(Icr<<1)){
                cout<<"0\n";
                continue;
            }
            else{
                cout<<In-(Icr<<1)+1<<'\n';
            }
        }
        return 0;
    }
    return 0;
}