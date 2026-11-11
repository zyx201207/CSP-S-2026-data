#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int, int> pii;
const int N = 5e2 + 5;
const int M = 5e5 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f3f3f3f3f;
int read() {
    int g = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        g = g * 10 + (ch ^ 48);
        ch = getchar();
    }
    return g * f;
}
vector<pii> e[M];
int n, m, d, q;
int w[M], k[N], a[M], t[M];
int dist[M];
int dis[550][550];
void dijk(int s) {
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(make_pair(0, s));
    while (!pq.empty()) {
        int now = pq.top().se, val = pq.top().fi;
        pq.pop();
        if (val > dist[now]) continue;
        for (auto i : e[now]) {
            int nxt = i.fi, cost = i.se;
            if (dist[nxt] > val + cost) {
                dist[nxt] = val + cost;
                pq.push(make_pair(val + cost, nxt));
            }
        }
    }
}
void dijk2(int s) {
    for (int i = 1; i <= m; i++) dis[s][i] = INF;
    dis[s][s] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(make_pair(0, s));
    while (!pq.empty()) {
        int now = pq.top().se, val = pq.top().fi;
        pq.pop();
        if (val > dis[s][now]) continue;
        for (auto i : e[now]) {
            int nxt = i.fi, cost = i.se;
            if (dis[s][nxt] > val + cost) {
                dis[s][nxt] = val + cost;
                pq.push(make_pair(val + cost, nxt));
            }
        }
    }
}
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c = read();
    n = read(), m = read(), d = read(), q = read();
    for (int i = 1; i <= m; i++) w[i] = read();
    for (int i = 1; i <= n; i++) {
        k[i] = read();
        for (int j = 1; j <= k[i]; j++) {
            a[j] = read(), t[j] = read();
        }
        for (int j = 1; j <= k[i]; j++) {
            for (int l = j + 1; l <= k[i]; l++) {
                e[a[j]].pb(make_pair(a[l], t[j] + t[l]));
                e[a[l]].pb(make_pair(a[j], t[j] + t[l]));
            }
        }
    }
    if (9 <= c && c <= 11) {
        for (int i = 1; i <= m; i++) {
            dijk2(i);
        }
        while (q--) {
            int x = read(), y = read();
            printf("%lld\n", dis[x][y] + w[x] + w[y]);
        }
    }
    else {
        while (q--) {
            int x = read(), y = read();
            dijk(x);
            printf("%lld\n", w[x] + w[y] + dist[y]);
        }
    }
    return 0;
}
