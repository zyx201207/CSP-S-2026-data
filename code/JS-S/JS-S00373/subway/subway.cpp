#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using ld=long double;
/*
graph(E=entrance, P=platform, L=line)
like
1E - 1P T L1 - 2P - 2E
        L L2 - 3P - 3E
iE=i, iP=i+m, Li=i+2m
*/
/**
 * m 个地铁站   5e5 
 * n 条地铁线路 500 
 * q 个出行计划 1e5
 * O((2m+n)q)   <- _/(Dijkstra)
 * O((2m+n)^3+q)
 */
int c,n,m,d,q;
const int N=500+5, M=5e5+5, Q=1e5+5;
struct Edge {
    int v;
    ll w;
};
vector<Edge> g[N+2*M];
ll dis[N+2*M];
auto f = [](int u){
    if(u<=m) return to_string(u)+'E';
    else if(u<=2*m) return to_string(u-m)+'P';
    else return 'L'+to_string(u-2*m);
};
ll work(int a, int b) {
    static constexpr ll INF = 0x3f3f3f3f3f3f3f3fLL;
    memset(dis, INF, sizeof(ll)*(n+2*m+2));
    using pii = pair<ll,int>;//{dis, node}
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dis[a]=0;
    pq.push({0, a});
    while(!pq.empty()) {
        pii t = pq.top();
        pq.pop();
        ll d=t.first;
        int u=t.second;
        if(d>dis[u]) continue;
        dis[u]=d;
        for(Edge i : g[u]) {
            if(dis[i.v] > d+i.w) {
                dis[i.v] = d+i.w;
                // cout<<f(a)<<'-'<<f(i.v)<<':'<<dis[i.v]<<' ';
                pq.push(make_pair(d+i.w, i.v));
            }
        }
    }
    // cout<<'\n';
    return dis[b];
}
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) {
        int w;
        cin>>w;
        g[i].push_back({i+m, w});
        g[i+m].push_back({i, w});
    }
    for(int i=1;i<=n;i++) {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++) {
            int a, t;
            cin>>a>>t;
            g[a+m].push_back({i+2*m, t});
            g[i+2*m].push_back({a+m, t});
        }
    }
    // for(int i=1;i<=n+2*m;i++) {
        
    //     cout<<f(i)<<"-> ";
    //     for(auto j : g[i]) {
    //         cout<<f(j.v)<<'('<<j.w<<')'<<' ';
    //     }
    //     cout<<'\n';
    // }
    while(q--) {
        int x, y;
        cin>>x>>y;
        cout<<work(x, y)<<'\n';
    }
    return 0;
}