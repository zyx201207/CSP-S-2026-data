#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=520, M=5e5+10;
ll w[M], k[M], a[N][M], t[N][M];
bool vis[M];
ll func(ll no, ll en, ll nt){
    if(vis[no]) return 0x3f3f3f3f;
    if(no==en) return nt+w[en];
    vis[no]=1;
    ll min_t=0x3f3f3f3f;
    for(ll i=1; i<=k[no]; i++)
        min_t=min(func(a[no][i], en, nt+t[no][no]+t[no][i]), min_t);
    vis[no]=0;
    return min_t;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("subway.in", "r", stdin);
    /*test*///freopen("subway1.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ll c, n, m, d, q;
    cin>>c>>n>>m>>d>>q;
    for(ll i=1; i<=m; i++) cin>>w[i];
    for(ll i=1; i<=n; i++){
        cin>>k[i];
        for(ll j=1; j<=k[i]; j++)
            cin>>a[i][j]>>t[i][j];
    }
    while(q--){
        memset(vis, 0, sizeof vis);
        ll x, y;
        cin>>x>>y;
        cout<<func(x, y, w[x])<<'\n';
    }
    return 0;
}
