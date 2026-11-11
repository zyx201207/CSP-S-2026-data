#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define ll long long
using namespace std;
ll read() {
    ll w = 0, f = 1;
    char c = getchar();
    while(c < '0' || c > '9') {
        if(c == '-') {
            f = -f;
        }
        c = getchar();
    }
    while('0' <= c && c <= '9') {
        w = w * 10 + c - '0';
        c = getchar();
    }
    return w * f;
}
void write(ll x) {
    if(x < 0) {
        putchar('-');
        x = -x;
    }
    if(x > 9) {
        write(x / 10);
    }
    putchar(x % 10 + '0');
}
const int M = 2e4 + 505, N = 505;
int cnt, c, n, m, d, q, tot, u, v, k[N], head[M], w[M];
vector<ll> dis[N];
//ll dis[N][M];
vector<int> a[N], t[N];
struct edge {
    int to, weight, nxt;
}e[M << 1];
inline void add(int x, int y, int z) {
    e[++cnt].to = y;
    e[cnt].weight = z;
    e[cnt].nxt = head[x];
    head[x] = cnt;
}
inline void dijkstra(int s, int mark) {
    fill(dis[mark].begin(), dis[mark].end(), (ll)1e18);
    dis[mark][s] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> q;
    q.push(make_pair(0, s));
    while(!q.empty()) {
        auto now = q.top();
        q.pop();
        if(dis[mark][now.second] != now.first) {
            continue;
        }
        for(int i = head[now.second]; i; i = e[i].nxt) {
            if(dis[mark][now.second] + e[i].weight < dis[mark][e[i].to]) {
                dis[mark][e[i].to] = dis[mark][now.second] + e[i].weight;
                q.push(make_pair(dis[mark][e[i].to], e[i].to));
            }
        }
    }
}
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    c = read(), n = read(), m = read(), d = read(), q = read();
    rep(i, 1, m) {
        w[i] = read();
    }
    tot = m + n;
    rep(i, 1, n) {
        k[i] = read();
        a[i].resize(k[i] + 2);
        t[i].resize(k[i] + 2);
        rep(j, 1, k[i]) {
            a[i][j] = read(), t[i][j] = read();
            add(m + i, a[i][j], t[i][j]);
            add(a[i][j], m + i, t[i][j]);
        }
    }
    rep(i, 1, n) {
        dis[i].resize(tot + N);
        dijkstra(m + i, i);
    }
    while(q--) {
        cin >> u >> v;
        ll ans = (ll)1e18;
        rep(i, 1, n) {
            ans = min(ans, dis[i][u] + dis[i][v]);
        }
        write(ans + w[u] + w[v]);
        putchar('\n');
    }
    return 0;
}