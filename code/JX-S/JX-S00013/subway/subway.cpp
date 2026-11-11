#include <bits/stdc++.h>
using namespace std;
#define fi first 
#define se second
#define ll long long
#define Pair pair<ll,ll>
int const MAXN = 5e5 + 5;
ll c, n, m, d, q, w[MAXN], k[MAXN], dis[MAXN], cnt, l[MAXN], r[MAXN];
bool vis[MAXN];
vector<ll> qu[1005], quu[1005], ans[1005];
struct Node{
    ll v, w;
};
vector<Node> e[MAXN + 500];
void dijskral(int x) {
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    priority_queue<Pair, vector<Pair>, greater<Pair>> p;
    p.push({0, x});
    dis[x] = 0;
    while(!p.empty()) {
        int u = p.top().se;
        p.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(Node d : e[u]) {
            ll v = d.v, w = d.w;
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                p.push({dis[v], v});
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0),cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out", "w" ,stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    cnt = 600;
    for(int i = 1; i <= n; i++) {
        cin >> k[i];
        cnt++;
        for(int j = 1; j <= k[i]; j++) {
            int v, w;
            cin >> v >> w;
            e[v].push_back({cnt, w});
            e[cnt].push_back({v, w});
        }
    }
    for(int i = 1; i <= q; i++) {
        cin >> l[i] >> r[i];
        qu[l[i]].push_back(r[i]);
        //cout << dijskral(l, r) + w[l] + w[r]<< '\n';   
    }
    for(int i = 1; i <= m; i++) {
        if(qu[i].size() == 0) continue;
        dijskral(i);
        for(int d : qu[i]) ans[i].push_back(dis[d]);
    }
    for(int i = 1; i <= q; i++) {
        int p = 0;
        for(int j = 0; j < qu[l[i]].size(); j++) {
            if(qu[l[i]][j] == r[i]) {
                p = j;
                break;
            }
        }
        cout << ans[l[i]][p] + w[l[i]] + w[r[i]] << '\n';
    }
    return 0;
}
