#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll w[500005];
ll aa[5005][5005];
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll u,n,m,d,q;
    cin>>u>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++){
        cin>>w[i];
    }
    for(ll i=1;i<=n;i++){
        ll ki;
        cin>>ki;
        for(ll j=1;j<=ki;j++){
            ll aaa,ttt;
            cin>>aaa>>ttt;
            aa[i][aaa]=ttt;
        }
    }
    for(ll i=1;i<=q;i++){
        ll g,h;
        cin>>g>>h;
        for(ll k=1;k<=m;k++){
            for(ll r=1;r<=m;r++){
                for(ll j=1;j<=m;j++){
                    aa[r][k]=min(aa[r][k],aa[r][j]+aa[j][k]);
                }
            }
        }
        cout<<aa[g][h]<<endl;
    }
    return 0;
}
