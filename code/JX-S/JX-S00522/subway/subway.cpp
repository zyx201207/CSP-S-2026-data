#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 507, M = 5e5 + 7;
int c, n, m, d, T;
int e[N][N];
int w[M];
vector<pair<int, int> > et[M];
int k[N];
int dis[N][N];
int read() {
    int res = 0;
    char c = getchar();
    while(!isdigit(c)) {
        c = getchar();
    }
    while(isdigit(c)) {
        res *= 10;
        res += c - '0';
        c = getchar();
    }
    return res;
}
struct node {
    int u;
    int dis;
    friend bool operator < (node a, node b) {
        return a.dis > b.dis;
    }
};
priority_queue<node> q;
bool vis[N];
void dijkstra(int s) {
    q.push({s, 0});
    dis[s][s] = 0;
    for(int i = 1; i <= n; i++) {
        vis[i] = 0;
    }
    while(!q.empty()) {
        int u = q.top().u;
        q.pop();
        if(vis[u]) {
            continue;
        }
        vis[u] = 1;
        for(int v = 1; v <= n; v++) {
            if(!e[u][v]) {
                continue;
            }
            if(dis[s][v] > dis[s][u] + e[u][v]) {
                dis[s][v] = dis[s][u] + e[u][v];
                if(!vis[v]) {
                    q.push({v, dis[s][v]});
                }
            }
        }
    }
}
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    c = read(), n = read(), m = read(), d = read(), T = read();
    for(int i = 1; i <= m; i++) {
        w[i] = read();
    }
    for(int i = 1; i <= n; i++) {
        k[i] = read();
        for(int j = 1; j <= k[i]; j++) {
            int u = read(), v = read();
            et[u].push_back({i, v});
        }
    }
    memset(e, 0x3f, sizeof(e));
    for(int i = 1; i <= m; i++) {
        for(auto j : et[i]) {
            for(auto k : et[i]) {
                if(j.first == k.first) {
                    continue;
                }
                e[j.first][k.first] = min(e[j.first][k.first], j.second + k.second);
            }
        }
    }
    memset(dis, 0x3f, sizeof(dis));
    for(int i = 1; i <= n; i++) {
        dijkstra(i);
    }
    while(T--) {
        int u = read(), v = read();
        int ans = 1e18;
        for(auto i : et[u]) {
            for(auto j : et[v]) {
                int from = i.first, to = j.first;
                ans = min(ans, dis[from][to] + w[u] + w[v] + i.second + j.second);
            }
        }
        printf("%lld\n", ans);
    }
}
/*
bushi
zen me hui shi da mo ni,
wo te me bei da mo le,
QwQ
zhen de you dian bei e xin dao le,
gan xie oldstreet rang wo zuo guo cha bu duo de,

wo qu,
zhe long long zhen de hen fan a
QwQ, wo zhen fu le,
dan shi wo shi jue bu ke neng define int long long de!

*/
