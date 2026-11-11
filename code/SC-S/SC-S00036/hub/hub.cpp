#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

template<class T> inline void ckmin(T& x, T y) { if(x > y) x = y; }
template<class T> inline void ckmax(T& x, T y) { if(x < y) x = y; }
/*~~~~~~~~~~~~~~~~~~~~ Boundary Line ~~~~~~~~~~~~~~~~~~~~*/
static constexpr int N = 1e3 + 5;
int n, k, c, t;
vector<int> v[N];
struct Edge { int x, y; } e[N];
/*~~~~~~~~~~~~~~~~~~~~ Boundary Line ~~~~~~~~~~~~~~~~~~~~*/

int dep[N], fa[N];
void dfs(int x, int fa) {
    dep[x] = dep[fa] + 1, ::fa[x] = fa;
    for(int y : v[x]) if(y != fa) dfs(y, x);
}

int dp[N][N][3], siz[N], nw[N][3], depp[N];
void dfs(int x, int fa, int ex, int ey, vector<int>& vv) {
    dp[x][0][0] = 0, dp[x][1][1] = 0;
    siz[x] = 1, depp[x] = 0, vv.push_back(x);
    for(int y : v[x]) if(y != fa && !(x == ex && y == ey) && !(x == ey && y == ex)) {
        dfs(y, x, ex, ey, vv);
        ckmax(depp[x], depp[y] + 1);
        for(int i = 0; i <= siz[x] + siz[y]; i++) nw[i][0] = nw[i][1] = nw[i][2] = 0x3f3f3f3f;
        for(int i = 0; i <= siz[x]; i++) {
            for(int j = 0; j <= siz[y]; j++) {
                ckmin(nw[i + j][0], max(dp[x][i][0], dp[y][j][0] + 1));
                ckmin(nw[i + j][1], max(dp[x][i][1], min(dp[y][j][0] + 1, dp[y][j][1])));
            }
        }
        siz[x] += siz[y];
        for(int i = 0; i <= siz[x]; i++) dp[x][i][0] = nw[i][0], dp[x][i][1] = nw[i][1], dp[x][i][2] = nw[i][2];
    }
}

int dfs(int x, int fa, int eg, int ex, int ey) {
    int ans = 0;
    for(int y : v[x]) if(y != fa && y != eg && !(x == ex && y == ey) && !(x == ey && y == ex)) {
        ckmax(ans, dfs(y, x, eg, ex, ey) + 1);
    }
    return ans;
}

int Get(int x, int ex, int ey) {
    if(x == 1) return 0;
    else {
        int ans = dfs(fa[x], 0, x, ex, ey) + 1;
        return ans;
    }
}

int solve(int x, int y) {
    memset(dp, 0x3f, sizeof dp);
    vector<int> a, b;
    dfs(1, 0, x, y, a);
    if(dep[x] < dep[y]) swap(x, y);
    dfs(x, y, x, y, b);
    int ans = 0x3f3f3f3f, xx = x, yy = y;
    for(int i = 1; i < k; i++) {
        for(int x : a) for(int y : b) {
            // if(t == 0 && xx == 3 && yy == 5 && y == 7) cerr << "??? " << x << ' ' << y << ' ' << i << ' ' << dp[x][i][1] << ' ' << dp[y][k - i][1] << ' ' << Get(x, xx, yy) << ' ' << Get(y, xx, yy) << '\n';
            ckmin(ans, max({dp[x][i][1], Get(x, xx, yy), dp[y][k - i][1], Get(y, xx, yy)}));
        }
    }
    
    // if(t == 0) cerr << x << ' ' << y << ' ' << ans << '\n';

    return ans;
}

void solve() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) v[i].clear();
    for(int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        e[i] = {x, y};
        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs(1, 0);

    int ans = 0x3f3f3f3f;
    for(int i = 1; i < n; i++) ckmin(ans, solve(e[i].x, e[i].y));
    cout << ans << '\n';
}

/*~~~~~~~~~~~~~~~~~~~~ Boundary Line ~~~~~~~~~~~~~~~~~~~~*/
signed main() {
    cin.tie(0) -> sync_with_stdio(0);

    // #ifdef LOCAL
    // freopen("samples/input.txt", "r", stdin);
    // freopen("samples/hub1.in", "r", stdin);
    // freopen("samples/output.txt", "w", stdout);
    // #endif

    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    cin >> c >> t;
    while(t --> 0) solve();
    return 0;
}