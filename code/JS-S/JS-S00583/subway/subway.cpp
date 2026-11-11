#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, ull> pii;

constexpr int N = 500 + 5, M = 5e5 + 5, Mn = 2e4 + 5, bINF = 0x3f, Q = 1e5 + 5;


int c, n, m, d, q; ull w[M];
std::vector<int> a[N], k[N];
std::vector<pii> p[M];
std::vector<pii> G[Mn];
struct Que { int i, u, v; ull ans; } _q[Q];
//std::vector<Node> G[N][M];
/*
ull dis[N][M];
inline void dij(int s) {
    std::priority_queue<std::pair<ull, pii>, std::vector<std::pair<ull, pii> >, std::greater<std::pair<ull, pii> > > q;
    std::memset(dis, bINF, sizeof dis);
    q.emplace(0, std::make_pair(s, 0)); dis[s][0] = 0;
    while(!q.empty()) {
        std::pair<ull, pii> now = q.top(); q.pop();
        for(const auto& x : G[now.second.first][now.second.second]) {
            if(dis[])
        }
    }
}
*/

ull dis[N + M]; bool vis[N + M];
inline void dij(int s) {
    std::priority_queue<std::pair<ull, int>, std::vector<std::pair<ull, int> >, std::greater<std::pair<ull, int> > > q;
    std::memset(dis, bINF, sizeof dis);
    q.emplace(0, s), vis[s] = true, dis[s] = 0;
    while(!q.empty()) {
        std::pair<ull, int> now = q.top(); q.pop();
        ull nw = now.first; int nu = now.second;
        for(const auto& v : G[nu]) {
            if(nw + v.second < dis[v.first]) dis[v.first] = nw + v.second;
            if(!vis[v.first]) vis[v.first] = true, q.emplace(dis[v.first], v.first);
        }
    }
}

int main() {
    std::freopen("subway.in", "r", stdin);
    std::freopen("subway.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; ++i) std::cin >> w[i];
    if(n <= 2) {
        for(int i = 1; i <= n; ++i) {
            int K; std::cin >> K;
            for(int j = 1; j <= K; ++j) {
                int _a, _k; std::cin >> _a >> _k;
                a[i].push_back(_a); k[i].push_back(_k);
                p[_a].emplace_back(i, a[i].size() - 1);
                // G[n + _a].emplace_back(i, _k), G[i].emplace_back(n + _a, _k);
            }
        }

        if(n == 1) {
            while(q--) {
                int u, v; std::cin >> u >> v;
                std::cout << w[u] + w[v] + a[1][u] + a[1][v] << '\n';
            }
        } else if(n == 2) {
            while(q--) {
                int u, v; std::cin >> u >> v;
                //
            }
        }
        return 0;
    }
    for(int i = 1; i <= n; ++i) {
        int K; std::cin >> K;
        for(int j = 1; j <= K; ++j) {
            int _a, _k; std::cin >> _a >> _k;
            a[i].push_back(_a); k[i].push_back(_k);
            G[n + _a].emplace_back(i, _k), G[i].emplace_back(n + _a, _k);
            p[_a].emplace_back(i, a[i].size() - 1);
        }
    }
    std::map<pii, ull> dist;
    for(int I = 1; I <= n; ++I) {
        for(int i = 0; i < p[I].size(); ++i)
        for(int j = 0; j < i; ++j) {
            int x;
            if(!dist.count(std::make_pair(p[I][i].first, p[I][j].first))) x = 2e9;
            else x = dist[std::make_pair(p[I][i].first, p[I][j].first)];
            x = std::min(x, k[p[I][i].first][p[I][i].second] + k[p[I][j].first][p[I][j].second]);
            dist[std::make_pair(p[I][i].first, p[I][j].first)] = dist[std::make_pair(p[I][j].first, p[I][i].first)] = x;
        }
    }
    for(const auto& x : dist) {
        int u = x.first.first, v = x.first.second, w = x.second;
        G[u].emplace_back(v, w);
    }
    for(int _ =  1; _ <= q; ++_) {
        int u, v; std::cin >> u >> v;
        _q[_] = (Que){_, std::min(u, v), std::max(u, v), 0};
    }
    std::sort(_q + 1, _q + q + 1, [&](Que a, Que b) {
        return std::make_pair(a.u, a.v) < std::make_pair(b.u, b.v);
    });
    for(int i = 1; i <= q; ++i) {
        if(i > 1 && _q[i].u == _q[i - 1].u) {
            ;
        } else {
            std::memset(vis, 0, sizeof vis);
            dij(n + _q[i].u);
        }
        _q[i].ans = w[_q[i].u] + w[_q[i].v] + dis[n + _q[i].v];
    }
    std::sort(_q + 1, _q + q + 1, [&](Que a, Que b) {
        return a.i < b.i;
    });
    for(int i = 1; i <= q; ++i) {
        std::cout << _q[i].ans << '\n';
    }

    return 0;
}
