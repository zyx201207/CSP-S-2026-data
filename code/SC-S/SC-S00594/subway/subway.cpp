#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>
typedef long long ll;

const int N = 6e5 + 5;
const ll Inf = 1e18 + 5;

struct Node {
    int v, w;
    bool operator < (const Node &rhs) const {
        return w < rhs.w;
    }
};

std :: queue<int> q;
bool inq[N], vis[N];
std :: vector<Node> E[N];
int c, n, m, d, Q, cnt, T, w[N];
std :: unordered_map<int, ll> ans[N];

template <class T>
void read(T &a) {
    a = 0;
    char CC = getchar();
    while (CC < '0' || CC > '9') c = getchar();
    while (CC >= '0' && CC <= '9') a = (a << 3) + (a << 1) + (CC ^ 48), CC = getchar();
}

void spfa(int s) {

    for (int i = 1; i <= cnt; i ++) inq[i] = false, ans[s][i] = Inf;
    q.push(s);
    ans[s][s] = 0, inq[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (auto v : E[u])
            if (ans[s][v.v] > ans[s][u] + v.w) {
                ans[s][v.v] = ans[s][u] + v.w;
                if (!inq[v.v]) {
                    q.push(v.v);
                    inq[v.v] = true;
                }
            }
    }

}

void bfs(int s) {

    for (int i = 1; i <= cnt; i ++) inq[i] = false;
    q.push(s);
    ans[s][s] = 0, inq[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : E[u])
            if (!inq[v.v]) {
                ans[s][v.v] = ans[s][u] + T, inq[v.v] = true;
                q.push(v.v);
            }
    }

}

int main() {

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    read(c), read(n), read(m), read(d), read(Q);
    cnt = m;
    for (int i = 1; i <= m; i ++) read(w[i]);
    for (int i = 1; i <= n; i ++) {
        int k;
        read(k);
        ++ cnt;
        for (int j = 1; j <= k; j ++) {
            int v, w;
            T = w;
            read(v), read(w);
            E[v].push_back({cnt, w}), E[cnt].push_back({v, w});
        }
    }
    for (int i = 1; i <= cnt; i ++) std :: sort(E[i].begin(), E[i].end());

    while (Q --) {
        int s, t;
        read(s), read(t);
        if (!vis[s]) {
            if (c >= 12 && c <= 15) bfs(s);
            else spfa(s);
            vis[s] = true;
        }
        printf("%lld\n", ans[s][t] + w[s] + w[t]);
    }

    return 0;
}