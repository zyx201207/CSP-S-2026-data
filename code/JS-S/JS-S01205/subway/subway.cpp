// Arknighs Endfield
// rossi i love you

#include <bits/stdc++.h>
using namespace std;

#define range(v, l, r) next(begin(v), l), next(begin(v), r+1)
#define range_full(v) begin(v), end(v)

int64_t c, n, m, d, q;
struct edge { int64_t to, w, next; };
int64_t cnt, mncnt;
array<int64_t, size_t(15e5+5)> h;
array<edge, size_t(15e5+5)> e;

inline int64_t ne(int64_t n) { return 2*n; }
inline int64_t nw(int64_t n) { return 2*n+1; }
// int64_t mn(int64_t)


string ns(int64_t id) {
    string res{};
    if (id > 2*m+1) {
        res += "metro line " + to_string(id-2*m-1);
    }
    else if (id&1) {
        res += "wait " + to_string(id>>1);
    }
    else {
        res += "entrance " + to_string(id>>1);
    }
    return res;
}


inline void add(int64_t u, int64_t v, int64_t w) {
    e[++cnt] = {v, w, h[u]};
    h[u] = cnt;
    e[++cnt] = {u, w, h[v]};
    h[v] = cnt;

    // cout << "add line " << ns(u) << " <-> " << ns(v) << "\n";
}


array<array<int64_t, size_t(5e3+5)>, size_t(5e3+5)> dis;

array<bool, size_t(15e5+5)> vis;
// array<int64_t, size_t(15e5+5)> dis;
priority_queue<pair<int64_t, int64_t>, vector<pair<int64_t, int64_t>>, greater<pair<int64_t, int64_t>>> qq;
void dijkstra(int64_t s) {
    fill(range_full(vis), false);
    fill(range_full(dis[s]), 0x3f3f3f3f);
    dis[s][s<<1]=0;
    qq.emplace(0, s<<1);
    while (!qq.empty()) {
        int64_t d, id;
        tie(d, id) = qq.top();
        qq.pop();
        if (vis[id]) continue;
        vis[id] = true;
        for (int64_t i=h[id]; i!=-1; i=e[i].next) {
            int64_t to = e[i].to, w = e[i].w;
            if (d+w < dis[s][to]) {
                dis[s][to] = d+w;
                qq.emplace(d+w, to);
            }
        }
    }
}

int32_t main() {
    ignore = freopen("subway.in", "r", stdin);
    ignore = freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    fill(range_full(h), -1);

    cin >> c >> n >> m >> d >> q;
    for (int64_t i=1; i<=m; i++) {
        int64_t wi;
        cin >> wi;
        add(ne(i), nw(i), wi);
    }
    mncnt = 2*m+1;
    for (int64_t i=1; i<=n; i++) {
        int64_t ki;
        cin >> ki;
        ++mncnt;
        for (int64_t j=1; j<=ki; j++) {
            int64_t ai, ti;
            cin >> ai >> ti;
            add(mncnt, nw(ai), ti);
        }
    }

    // for (int64_t i=2; i<=mncnt; i++) {
    //     for (int64_t j=h[i]; j!=-1; j=e[j].next) {
    //         cout << j << ": " << ns(i) << " <-> " << ns(e[j].to) << "\n";
    //     }
    // }


    // cout << "\n";

    for (int64_t i=1; i<=m; i++) {
        dijkstra(i);
    }

    for (int64_t i=1; i<=q; i++) {
        int64_t x, y;
        cin >> x >> y;
        cout << dis[x][ne(y)] << "\n";
    }
 

    return 0;
}   