#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=505;
const ll M=1e6+5;
const ll Q=1e5+5;
ll c,n,m,d,q;
ll w[M];
ll a[N][M],t[N][M];
ll x[Q],y[Q];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++)
        cin>>w[i];
    for(ll i=1;i<=n;i++){
        ll k;
        cin>>k;
        for(ll j=1;j<=k;j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(ll i=1;i<=q;i++)
        cin>>x[i]>>y[i];

    for(ll r=1;r<=q;r++){
        ll sta=x[r];
        ll en=y[r];
        ll sum=0;
        sum+=w[sta]+w[en];
        cout<<sum<<'\n';
    }
    return 0;
}
