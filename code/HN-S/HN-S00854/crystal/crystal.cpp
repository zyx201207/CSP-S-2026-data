#include<bits/stdc++.h>
using namespace std;
int In;
typedef long long vt;
vt vm;
const int IN=5e5+5;
vt vaI[IN];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>In>>vm;
    for(int I=1;I<=In;++I){
        cin>>vaI[I];
    }
    sort(vaI+1,vaI+In+1);
    int Il=In;
    vt vsum=0;
    int ans=0;
    for(int Ir=In;Ir;--Ir){
        for(;Il>1&&vsum+vaI[Ir]-vaI[Il-1]<=vm;){
            vsum+=vaI[Ir]-vaI[Il-1];
            --Il;
        }
        ans=max(ans,Ir-Il+1);
        if(Ir>1){
            vsum-=(vaI[Ir]-vaI[Ir-1])*(Ir-Il);
        }
    }
    cout<<ans;
    return 0;
}