#include<bits/stdc++.h>
using namespace std;
#define pr pair<int, int>
#define pb push_back
#define mid (l + r) / 2
#define ls num << 1
#define rs num << 1 | 1

inline int read() {
    int x = 0, m = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') m = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * m;
}

inline void write(int x) {
    if (x < 0) {
        putchar('-');
        write(-x);
        return;
    }
    if (x >= 10) write(x / 10);
    putchar(x % 10 + '0');
}

const int N = 1e6 + 5;

vector<int> v[N];
int d1[N], d2[N], f[N], dep[N], Dep[N], mx[N][3];
int X, Y, maxn, root, L, lim;
int Lm;

void dfs(int ro, int fa, int dis) {
    if (dis > maxn) {
        maxn = dis;
        root = ro;
    }
    for (auto u : v[ro]) {
        if (u == fa) continue;
        dfs(u, ro, dis + 1);
    }
}

void Dfs(int ro, int fa, int *d) {
    for (auto u : v[ro]) {
        if (u == fa) continue;
        d[u] = d[ro] + 1;
        Dfs(u, ro, d);
    }
}

void init(int ro, int fa) {
    dep[ro] = 0;
    mx[ro][0] = mx[ro][1] = 0;
    for (auto u : v[ro]) {
        if (u == fa) continue;
        Dep[u] = Dep[ro] + 1;
        init(u, ro);
        dep[ro] = max(dep[ro], dep[u] + 1);
        if (!mx[ro][0] || dep[mx[ro][0]] < dep[u]) {
            mx[ro][2] = mx[ro][1], mx[ro][1] = mx[ro][0], mx[ro][0] = u;
        }
        else if (!mx[ro][1] || dep[mx[ro][1]] < dep[u]) {
            mx[ro][2] = mx[ro][1], mx[ro][1] = u;
        }
        else if (!mx[ro][2] || dep[mx[ro][2]] < dep[u]) {
            mx[ro][2] = u;
        }
    }
}

void dp(int ro, int fa) {
    f[ro] = 1;
    for (auto u : v[ro]) {
        if (u == fa) continue;
        dp(u, ro);
        if (dep[u] + 1 > lim) f[ro] += f[u];
    }
}

int Lim;
int lm[N], w1[N], w2[N], W1[N], W2[N], F[N], rt[N], Min;

void solve(int ro, int fa, int *w, int *W) {
    if (Dep[ro] >= Lm) return;
    if (Lim > lim) W[Dep[ro]] = min(W[Dep[ro]], f[ro]);
    if (Lim >= 0) w[Lim] = min(w[Lim], f[ro]);
    int lst = Lim;
    Lim = min(Lim, lm[Dep[ro]]);
    for (auto u : v[ro]) {
        if (u == fa) continue;
        int p = mx[ro][0];
        if (p == u) p = mx[ro][1];
        int LL = lim - dep[p] - 1;
        if (LL <= 0) continue;
        int k = min(Dep[ro] + dep[ro], Dep[ro] + LL), Lst = lm[k];
        lm[k] = min(lm[k], LL - Dep[ro]);
        solve(u, ro, w, W);
        lm[k] = Lst;
    }
    Lim = lst;
}

void Solve(int ro, int fa) {
    rt[Dep[ro]] = ro;
    Min = min(Min, f[ro] + ((Lim >= 0) ? F[rt[Lim]] : 0));
    if (Lim >= 0 && F[rt[Lim]] >= Min) return;
    int lst = Lim;
    Lim = max(Lim, lm[Dep[ro]]);
    for (auto u : v[ro]) {
        if (u == fa) continue;
        int val = F[fa] + f[ro];
        if (dep[u] + 1 > lim) val -= f[u];
        F[ro] = val;
        int p = mx[ro][0];
        if (p == u) p = mx[ro][1];
        int LL = lim - dep[p] - 1;
        if (LL <= 0) {
            int Lst = Lim;
            Lim = max(Lim, Dep[ro]);
            Solve(u, ro);
            Lim = Lst;
        }
        else {
            int k = min(Dep[ro] + dep[ro], Dep[ro] + LL), Lst = lm[k];
            lm[k] = max(lm[k], Dep[ro] - LL);
            Solve(u, ro);
            lm[k] = Lst;
        }
    }
    Lim = lst;
}

signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int synAKIOI = read(), T = read();
    while (T--) {
        int n = read(), m = read();
        for (int i = 1; i < n; i++) {
            int x = read(), y = read();
            v[x].pb(y);
            v[y].pb(x);
        }
        dep[0] = -1;
        maxn = root = -1;
        dfs(1, 0, 0);
        X = root;
        maxn = -1;
        dfs(X, 0, 0);
        Y = root;
        L = maxn;
        Dfs(X, 0, d1);
        Dfs(Y, 0, d2);
        int r1 = 0, r2 = 0;
        for (int i = 1; i <= n; i++) {
            if (d1[i] + d2[i] == L && abs(d1[i] - d2[i]) <= 1) {
                swap(r1, r2);
                r1 = i;
            }
        }
        Dep[r1] = Dep[r2] = 0;
        if (r2) init(r1, r2), init(r2, r1);
        else init(r1, r2);
        auto chk = [&](int x) -> int {
            lim = x;
            if (!r2) {
                dp(r1, 0);
                if (f[r1] <= m) return 1;
                for (int i = 0; i <= dep[r1]; i++) lm[i] = -1;
                Min = m + 1;
                Lim = -1;
                Solve(r1, 0);
                if (Min <= m) return 1;
                Lm = min(dep[r1], 2 * x) + 1;
                for (int i = 0; i <= Lm; i++) lm[i] = Lm, w1[i] = w2[i] = W1[i] = W2[i] = m + 1;
                Lim = Lm;
                int D = dep[mx[r1][2]] + 1;
                if (D < x) {
                    lm[x - D] = min(lm[x - D], x - D);
                    solve(mx[r1][0], r1, w1, W1);
                    solve(mx[r1][1], r1, w2, W2);
                    int mi1 = m + 1, mi2 = m + 1;
                    for (int i = 0; i <= Lm; i++) {
                        mi1 = min(mi1, W1[i]);
                        mi2 = min(mi2, W2[i]);
                        if (w1[i] + mi2 <= m || w2[i] + mi1 <= m) return 1;
                    }
                }
                return 0;
            }
            else {
                dp(r1, r2), dp(r2, r1);
                if (f[r1] + f[r2] <= m) return 1;
                for (int i = 0; i <= dep[r1]; i++) lm[i] = -1;
                Min = m + 1;
                Lim = -1;
                F[r2] = 0;
                Solve(r1, r2);
                if (Min + f[r2] <= m) return 1;
                F[r1] = 0;
                Min = m + 1;
                Solve(r2, r1);
                if (Min + f[r1] <= m) return 1;
                Lm = min(dep[r1], 2 * x) + 1;
                for (int i = 0; i <= Lm; i++) lm[i] = Lm, w1[i] = w2[i] = W1[i] = W2[i] = m + 1;
                Lim = Lm;
                solve(r1, r2, w1, W1);
                solve(r2, r1, w2, W2);
                int mi1 = m + 1, mi2 = m + 1;
                for (int i = 0; i <= Lm; i++) {
                    if (w1[i] + mi2 <= m || w2[i] + mi1 <= m) return 1;
                    mi1 = min(mi1, W1[i]);
                    mi2 = min(mi2, W2[i]);
                }
                return 0;
            }
        };
        int l = 0, r = (L - 1) / 2, ans = r + 1;
        while (l <= r) {
            if (chk(mid)) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        write(ans);
        putchar('\n');
        for (int i = 1; i <= n; i++) {
            vector<int> ().swap(v[i]);
            d1[i] = d2[i] = 0;
        }
    }
}