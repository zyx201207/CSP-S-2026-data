#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 510, M = 50010;
int C;
int n,m,d,q,w[M],k[N];
int a[N][M],t[N][M];

struct Edge {
    int v,w,color=0;
    Edge() {}
    Edge(int v,int w):v(v),w(w) {}
    Edge(int v,int w,int color):v(v),w(w),color(color) {}
    bool operator<(const Edge &other) const {
        return w > other.w;
    }
};
vector<Edge> edge[M];  // 邻接表
vector<Edge> route[N];  // 地铁线路

int DijkstraA(int s,int t) {
    priority_queue<Edge> heap;
    vector<int> dis(n,0x3f3f3f3f);
    vector<int> vis(n,0);
    dis[s] = 0; heap.push({s,dis[s]});
    while (!heap.empty()) {
        int u = heap.top().v; heap.pop();
        if (vis[u]) {
            continue;
        } else {
            vis[u] = 1;
        }
        for (auto ver : edge[u]) {
            int v = ver.v, w = ver.w;
            if (!vis[v] and dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                heap.push({v,dis[v]});
            }
        }
    }
    return dis[t];
}

int T;
int DijkstraB(int s,int t) {
    priority_queue<Edge> heap;
    vector<int> dis(n,0x3f3f3f3f);
    vector<int> vis(n,0);
    dis[s] = 0; heap.push({s,dis[s]});
    while (!heap.empty()) {
        int u = heap.top().v; heap.pop();
        if (vis[u]) {
            continue;
        } else {
            vis[u] = 1;
        }
        int lastColor = 0;
        for (auto ver : edge[u]) {
            int v = ver.v, w = ver.w, k = ver.color;
            if (!lastColor) {
                lastColor = k;
            } else if (k != lastColor) {
                w += T;
            }
            if (!vis[v] and dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                heap.push({v,dis[v]});
            }
        }
    }
    return dis[t];
}

int DijkstraALL(int s,int t) {
    priority_queue<Edge> heap;
    vector<int> dis(n,0x3f3f3f3f);
    vector<int> vis(n,0);
    dis[s] = 0; heap.push({s,dis[s]});
    while (!heap.empty()) {
        int u = heap.top().v; heap.pop();
        if (vis[u]) {
            continue;
        } else {
            vis[u] = 1;
        }
        int lastColor = 0;
        for (auto ver : edge[u]) {
            int v = ver.v, w = ver.w, k = ver.color;
            if (!lastColor) {
                lastColor = k;
            } else if (k != lastColor) {
                w += t;
            }
            if (!vis[v] and dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                heap.push({v,dis[v]});
            }
        }
    }
    return dis[t];
}

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%lld %lld %lld %lld %lld", &C, &n, &m, &d, &q);
    for (int i=1; i<=m; ++i) {
        scanf("%lld", &w[i]);
    }
    if (C >= 7 and C <= 11) {  // A
        for (int i=1; i<=n; ++i) {
            scanf("%lld", &k[i]);
            if (!k[i]) {
                continue;
            }
            if (k[i] == 1) {
                int aa,tt;
                scanf("%lld %lld", &aa, &tt);
                continue;
            } else {  // k[i] == 2
                int u,w1,v,w2;
                scanf("%lld %lld %lld %lld",&u,&w1,&v,&w2);
                edge[u].push_back({v,w1+w2});
                edge[v].push_back({u,w1+w2});
            }
        }
        for (int i=1; i<=q; ++i) {
            int s,t;
            scanf("%lld %lld", &s, &t);
            printf("%lld\n", DijkstraA(s,t) + w[s] + w[t]);
        }
    } else if (C >= 12 and C <= 19) {  // B
        for (int i=1; i<=n; ++i) {
            scanf("%lld", &k[i]);
            for (int j=1; j<=k[i]; ++j) {
                scanf("%lld %lld",&a[i][j],&t[i][j]);
                T = t[i][j];
                edge[a[i][j-1]].push_back({a[i][j],0,k[i]});
            }
        }
        for (int i=1; i<=q; ++i) {
            int s,t;
            scanf("%lld %lld", &s, &t);
            printf("%lld\n", DijkstraB(s,t) + w[s] + w[t]);
        }
    } else {
        for (int i=1; i<=n; ++i) {
            scanf("%lld", &k[i]);
            for (int j=1; j<=k[i]; ++j) {
                scanf("%lld %lld",&a[i][j],&t[i][j]);
                edge[a[i][j-1]].push_back({a[i][j],0,k[i]});
            }
        }
        for (int i=1; i<=q; ++i) {
            int s,t;
            scanf("%lld %lld", &s, &t);
            printf("%lld\n", DijkstraALL(s,t) + w[s] + w[t]);
        }
    }
    return 0;
}