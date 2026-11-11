#include <bits/stdc++.h>
using namespace std;
#define int ll
#define ll long long
#define usd unsigned
#define AC return
#define AK return 0
#define el putchar('\n')
#define YS cout << "YES"
#define NO cout << "NO"
#define Ys cout << "Yes"
#define No cout << "No"
#define ys cout << "yes"
#define no cout << "no"
#define void inline void
#define il inline
#define lowbit(x) ((x) & (-(x)))
#define debug(x) cerr << #x << ' ' << x << '\n'
#define Mod(x) (((x) % mod + mod) % mod)
#define pii pair <int, int>
il char gc() { char c; while((c = getchar()) <= ' ') ; return c; }
il int rd() {
    int x, f = 1; char c;
    while(!isdigit(c = getchar())) if(c == '-') f = -f;
    x = c ^ 48;
    while(isdigit(c = getchar())) x = (x << 3) + (x << 1) + (c ^ 48);
    return x * f;
}
void ACehomoxue();
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int t = 1;
    // t = rd()
    while(t--) ACehomoxue();
    AK;
}
const int mod = 998244353, maxn = 505, maxm = 5 * 1e5 + 18;

int c, n, m, d, q, f[maxn][maxn], w[maxm];
vector <pii> vec[maxm];

void ACehomoxue() {
    c = rd(), n = rd(), m = rd(), d = rd(), q = rd();
    for(int i = 1; i <= m; i++) w[i] = rd();
    for(int i = 1; i <= n; i++) {
        int s = rd();
        for(int p, t; s--; ) {
            p = rd(), t = rd();
            vec[p].push_back({i, t});
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) f[i][j] = 1e18;
        f[i][i] = 0;
    }
    for(int i = 1; i <= m; i++) {
        for(pii to1 : vec[i]) {
            for(pii to2 : vec[i]) {
                int p1 = to1.first, w1 = to1.second, p2 = to2.first, w2 = to2.second;
                f[p1][p2] = min(f[p1][p2], w1 + w2);
            }
        }
    }
    for(int k = 1; k <= n; k++) {
        for(int x = 1; x <= n; x++) {
            for(int y = 1; y <= n; y++) {
                f[x][y] = min(f[x][y], f[x][k] + f[k][y]);
            }
        }
    }
    for(int u, v, ans; q--; ) {
        u = rd(), v = rd(), ans = 1e18;
        for(pii to1 : vec[u]) {
            for(pii to2 : vec[v]) {
                int p1 = to1.first, w1 = to1.second, p2 = to2.first, w2 = to2.second;
                ans = min(ans, w1 + w2 + f[p1][p2]);
            }
        }
        cout << ans + w[u] + w[v];
        el;
    }
}

