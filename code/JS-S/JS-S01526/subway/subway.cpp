#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define il inline
#define rg register
#define gc getchar_unlocked
#define pc putchar_unlocked
using namespace std;
const int N = 500005;
const int INF = 0x7ffffffffff;

il int read() {
    short f = 1;
    int x = 0;
    char c = gc();
    while (c < '0' || c > '9') {
        if (c == '-') f *= (-1);
        c = gc();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = gc();
    }
    return x * f;
}

void wit(int x) {
    if (x == 0) return ;
    wit(x / 10);
    pc(x % 10 + '0');
    return ;
}

void write(int x, bool edl) {
    if (x <= 0) {
        if (x == 0) pc('0');
        else {
            pc('-');
            wit(x * (-1));
        }
    }
    else wit(x);
    if (edl) pc('\n');
    else pc(' ');
    return ;
}

struct node {
    int v, pos;
};

int c, n, m, d, q, w[N], T, dis[N], a[N], t[1000][1000];
vector <node> g[N];

void add(int from, int to, int pos) {
    g[from].push_back((node){to, pos});
}

void dfs(int u, int fa, int pos) {
    for (auto x : g[u]) {
        if (x.v == fa) continue;
        if (u != fa && x.pos != pos) {
            if (dis[x.v] > dis[u] + 1) {
                dis[x.v] = dis[u] + 1;
                dfs(x.v, u, x.pos);
            }
        }
        else {
            dis[x.v] = min(dis[u], dis[x.v]);
            dfs(x.v, u, x.pos);
        }
    }
}

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    c = read(); n = read(); m = read(); d = read(); q = read();
    for (int i = 1; i <= m; i++) w[i] = read();
    for (int i = 1; i <= n; i++) {
        int k;
        k = read();
        for (int j = 1; j <= k; j++) {
            a[j] = read();
            T = read();
        }
        for (int j = 1; j < k; j++) add(a[j], a[j % k + 1], i);
    }
    
    for (int i = 1; i <= q; i++) {
        for (int j = 1; j <= m; j++) {
            dis[j] = INF;
        }
        int u, v;
        u = read(); v = read();
        dis[u] = 0;
        dfs(u, u, 0);
        write(dis[v] * T * 2 + T + T + w[u] + w[v], 1);
    }
    return 0;
}





