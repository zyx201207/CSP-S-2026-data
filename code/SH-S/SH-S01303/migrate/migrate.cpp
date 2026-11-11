#include <bits/stdc++.h>
using namespace std;
const int N = 2000010;
using i64 = long long;
struct Info {
    int mn, way;
    Info(void) : mn(1e9), way(0) {}
    Info(const int &a, const int &b) : mn(a), way(b) {}
    inline void operator+=(const Info &rhs) {
        if (mn > rhs.mn) {
            mn = rhs.mn, way = rhs.way;
        } else if (mn == rhs.mn) {
            way = min(3, way + rhs.way);
        }
    }
    inline Info succ(void) {
        return Info(mn + 1, way);
    }
} st[13][5010];
i64 x[N], d, ans;
int c, T, n, L[N];
inline void update(int L, int x, const Info &v) {
    st[0][x] = v;
    for (int i = 1; x - (1 << i) + 1 >= L; i++) {
        st[i][x] = st[i - 1][x];
        st[i][x] += st[i - 1][x - (1 << (i - 1))];
    }
}
inline Info query(int l, int r) {
    Info res;
    if (l > r) return res;
    const int len = r - l + 1;
    for (int i = __lg(len); i >= 0; i--) {
        if (len >> i & 1) {
            res += st[i][r], r -= 1 << i;
        }
    }
    return res;
}
inline void solve(void) {
    cin >> n >> d, ans = 0, x[0] = -3e18;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1, j = 1; i <= n; i++) {
        while (x[i] - x[j] > d) j++;
        L[i] = j;
    }
    for (int i = 1; i <= n; i++) {
        std::vector<Info> dp(n + 1);
        for (int j = i; j <= n; j++) {
            for (int k = 0; j + (1 << k) - 1 <= n; k++) {
                st[k][j] = Info();
            }
        }
        dp[i] = {0, 1}, update(i, i, dp[i].succ());
        for (int j = i + 1; j <= n; j++) {
            dp[j] = query(max(L[j], i), j - 1);
            if (dp[j].way == 2) ans++;
            update(i, j, dp[j].succ());
        }
    }
    cout << ans << '\n';
}
inline void optimizeIO(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
}
int main(void) {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
    cin >> c >> T; while(T--) solve();
	return 0;
}
