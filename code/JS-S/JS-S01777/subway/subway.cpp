#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
constexpr ll N=500, M=2e4+5, D=M+N+5, inf=(1ll<<60);
vector<pi> g[D];
priority_queue<pi, vector<pi>, greater<pi>>q;
ll c,n,m,d,qr;
ll w[M], dis[D], vis[D];
ll to[M][N];
ll dij(ll s) {
    memset(dis, -1, sizeof dis);
    memset(vis, 0, sizeof vis);
    while(!q.empty()) q.pop();
    dis[s]=0;
    q.push({0,s});
    while(!q.empty()) {
        ll u=q.top().se;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        ll v,w;
        for(auto [v,w]:g[u]) {
            if(vis[v]) continue;
            if(dis[v]==-1||dis[u]+w<dis[v]) {
                dis[v]=dis[u]+w;
                q.push({dis[v],v});
            }
        }

    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out","w",stdout);
    cin.tie(0),cout.tie(0)->sync_with_stdio(0);
    cin >>c >> n >> m >> d >> qr;
    for(int i=1; i<=m; i++) cin >> w[i];
    for(int i=1; i<=n; i++) {
        ll k,a,t;
        cin >> k;
        for(int j=1; j<=k; j++) {
            cin >> a >> t;
            g[a].push_back({m+i, t});
            g[m+i].push_back({a, t});
        }
    }
    for(int i=1; i<=n; i++) {
        dij(m+i);
        for(int j=1; j<=m; j++) {
            to[j][i]=dis[j];
        }
    }
    while(qr--) {
        ll x, y, ans;
        cin >> x >> y;
        ans=inf;
        for(int i=1; i<=n; i++) ans=min(ans, (ll)to[x][i]+to[y][i]);
        cout << ans+w[x]+w[y] << '\n';
    }
    return 0;
}
