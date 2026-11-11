#include <bits/stdc++.h>
using namespace std;

namespace IO { char ch;
    void rd(int &x) {
        for (ch = getchar(), x = 0; !isdigit(ch); ch = getchar()) ;
        for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
    }
} using IO::rd;

const int N = 1e6 + 5;
const int inf = 0x3f3f3f3f;

int n, K;
vector<int> G[N];

int a[N], tot;

namespace IO1 {
    int X, Y;
    int mx, id, fr[N];
    void dfs(int u, int dis, int fa) {
        if (dis > mx) mx = dis, id = u;
        for (int v : G[u]) if (v != fa) fr[v] = u, dfs(v, dis + 1, u);
    }
    void get() {
        mx = -1; dfs(1, 0, 0), X = id;
        mx = -1; dfs(X, 0, 0); Y = id;
        a[tot = 1] = Y;
        while (Y != X) Y = fr[Y], a[++tot] = Y;
        a[tot + 1] = 0;
    }
}

int dis[N], cnt[N];
void dfs(int u, int fa) {
    dis[u] = 0;
    for (int v : G[u]) if (v != fa)
        dfs(v, u), dis[u] = max(dis[u], dis[v] + 1);
}
int sum(int u, int fa, int len) {
    int res = 0;
    for (int v : G[u]) if (v != fa)
        res += sum(v, u, len);
    if (res) res++;
    else if (dis[u] > len) res++;
    return res;
}

int mn[N];
bool jud(int len) {
    if (len * 2 + 1 >= tot) return 1;
    int u = a[len + 1], v = a[tot - len], s = 0;
    for (int i = 1; i <= tot; i++) cnt[i] = 0;
    for (int i = len + 2; i < tot - len; i++) {
        for (int v : G[a[i]]) if (v != a[i - 1] && v != a[i + 1])
            cnt[i] += sum(v, a[i], len);
        if (cnt[i]) cnt[i]++;
        else cnt[i] = dis[a[i]] >= len;
        s += cnt[i];
    }
    if ((tot - len) - len <= K - s) return 1;

    for (int i = len + 2; i <= tot - len; i++) mn[i] = inf;
    for (int i = len + 2; i <= tot - len; i++) {
        if (cnt[i] || i == tot - len)
            mn[i] = i;
    }
    for (int i = len + 2; i < tot - len; i++) {
        if (!cnt[i]) {
            int l = i - (len - dis[a[i]]);
            int r = i + (len - dis[a[i]]);
            if (l > len + 1 && r < tot - len) {
                mn[l] = min(mn[l], r);
            }
        }
    }
    int r = tot - len;
    for (int l = tot - len - 1; l >= len + 1; l--) {
        if ((l - len) + (tot - len - r + 1) <= K - s) return 1;
        r = min(r, mn[l]);
    }
    return 0;
}

void solve(int id) {
    rd(n), rd(K);
    for (int i = 1; i <= n; i++)
        G[i].clear();
    for (int i = 1, u, v; i < n; i++) {
        rd(u), rd(v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    IO1::get();
    for (int i = 1; i <= tot; i++) {
        dis[a[i]] = 0;
        for (int v : G[a[i]]) if (v != a[i - 1] && v != a[i + 1])
            dfs(v, a[i]), dis[a[i]] = max(dis[a[i]], dis[v] + 1);
    }

    int l = 0, r = n, ans = -1;
    while (l <= r) {
        int m = l + r >> 1;
        if (jud(m)) r = m - 1, ans = m;
        else l = m + 1;
    }
    printf("%d\n", ans);
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int cid, T; rd(cid), rd(T);
    for (int id = 1; id <= T; id++) solve(id);
    return 0;
}