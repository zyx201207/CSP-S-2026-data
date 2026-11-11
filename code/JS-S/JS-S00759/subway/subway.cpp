#include <bits/stdc++.h>
#define ll long long
using namespace std;

inline ll read(){
    ll x=0;char c=getchar();
    while (!isdigit(c))c=getchar();
    while (isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return x;
}

ll w[500005];
vector<array<ll,2>> vv[500505];
ll ga[505][505];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie(0);cout.tie(0);
    ios::sync_with_stdio(false);
    ll c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    for (ll i=1;i<=m;i++)cin >> w[i];
    for (ll i=1;i<=n;i++){
        ll k;
        cin >> k;
        for (ll j=1;j<=k;j++){
            ll x,t;
            cin >> x >> t;
            vv[x].push_back({i,t});
        }
    }
    memset(ga,0x3f,sizeof(ga));
    for (ll i=1;i<=n;i++)ga[i][i]=0;
    for (ll i=1;i<=m;i++){
        for (auto j:vv[i]){
            for (auto k:vv[i]){
                ga[j[0]][k[0]]=min(ga[j[0]][k[0]],j[1]+k[1]);
            }
        }
    }
    for (ll k=1;k<=n;k++){
        for (ll i=1;i<=n;i++){
            if (ga[i][k]>=1e18)continue;
            for (ll j=1;j<=n;j++){
                ga[i][j]=min(ga[i][j],ga[i][k]+ga[k][j]);
            }
        }
    }
    while (q--){
        ll x,y;
        cin >> x >> y;
        ll ans=1e18;
        for (auto i:vv[x]){
            for (auto j:vv[y]){
                ans=min(ans,i[1]+j[1]+ga[i[0]][j[0]]);
            }
        }
        cout<< ans+w[x]+w[y]<<"\n";
    }
    return 0;
}
