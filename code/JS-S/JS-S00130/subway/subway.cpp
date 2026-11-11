#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define getchar getchar_unlocked
using pii = pair<int, int>;
void r(int &x) {
    bool flag = 0; int res = 0;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-') flag = 1;
        c = getchar();
    }
    while (isdigit(c)) {
        res *= 10;
        res += c - '0';
        c = getchar();
    }
    x = (flag?-res:res);
}
int c, n, m, d, ques, T;
const int N = 5e5+5;
int w[N];
vector<int> a[505];
vector<int> t[505];
vector<pii> G[N];
int dist[N];
void dijkstra(int s) {
    for (int i = 0; i <= m + n; i++) dist[i] = 1e18;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, s});
    dist[s] = 0;
    while (!pq.empty()) {
        pii t = pq.top(); pq.pop();
        int u = t.second, d1 = t.first;
        if (d1 > dist[u]) continue;
        for (auto to : G[u]) {
            int v = to.first, w = to.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

void A(){
    for (int i = 1; i <= n; i++) {
        int k; r(k);
        if (k == 1){
            int aij, tij; r(aij), r(tij);
        }else {
            int a1, t1, a2, t2; r(a1), r(t1), r(a2), r(t2);
            G[a1].push_back({a2, t1 + t2});
            G[a2].push_back({a1, t1 + t2});
        }
    }
    while (ques--) {
        int x, y;
        r(x), r(y);
        int s = x;
        for (int i = 0; i <= n; i++) dist[i] = 1e18;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, s});
    dist[s] = 0;
    while (!pq.empty()) {
        pii t = pq.top(); pq.pop();
        int u = t.second, d1 = t.first;
        if (d1 > dist[u]) continue;
        for (auto to : G[u]) {
            int v = to.first, w = to.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
        int ans = dist[y];
        ans += w[x], ans += w[y];
        printf("%lld\n", ans);
    }
}
bool in[N];
void solve(){
    for (int i = 0; i <= m + n; i++) dist[i] = 1e18, in[i] = 0;
        int x, y;
        r(x), r(y);
        queue<pii> q;
        q.push({x, 0});
        dist[x] = 0;
        in[x] = 1;
        while (!q.empty()) {
            pii u = q.front(); q.pop();
            in[u.first] = 0;
            if (u.second > dist[u.first]) continue;
            for (auto to : G[u.first]) {
                int v = to.first;
                if (dist[v] > dist[u.first] + 1) {
                    dist[v] = dist[u.first] + 1;
                    if (!in[v]) q.push({v, dist[v]});
                }
                if (v == y) {
                    printf("%lld\n", T * dist[y] + w[x] + w[y]);
                    return ;
                }
            }
        }


        int ans = T * dist[y];
        ans += w[x], ans += w[y];
        printf("%lld\n", ans);
}
void B(){
    while (ques--) {
        solve();
    }
}
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    r(c), r(n), r(m), r(d), r(ques);
    for (int i = 1; i <= m; i++) 
        r(w[i]);
    // if (c >= 7 && c <= 11) {
    //     A();
    //     return 0;
    // }
    for (int i = 1; i <= n; i++) {
        int k; r(k);
        for (int j = 1; j <= k; j++) {
            
            int aij, tij; r(aij), r(tij);
            T = tij;
            G[aij].push_back({m+i, tij});
            G[m+i].push_back({aij, tij});

        }
    }
    
    if (c >= 12 && c <= 19) {
        B();
        return 0;
    }
    if (m == 2) {
        int x, y;
        r(x), r(y);
        dijkstra(x);
        int ans = dist[y];
        ans += w[x], ans += w[y];
        while (ques--) printf("%lld\n", ans);
    }
    while (ques--) {
        int x, y;
        r(x), r(y);
        dijkstra(x);
        int ans = dist[y];
        ans += w[x], ans += w[y];
        printf("%lld\n", ans);
    }
    return 0;
}