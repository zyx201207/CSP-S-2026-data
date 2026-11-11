#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 10;
int c, T, n, d, a[N], fa[N], dp[N][2];
int deal(int l, int r) {
    int sum = 0;
    for (int i = l; i <= r; i++) {
        if (fa[i] < r && i + 1 < fa[i]) {
            int L = max(fa[fa[i] - 2] + 1, fa[i] + 1);
            int R = fa[fa[i] - 1];
            if (L <= R) sum += (R - L + 1);
        }
    }
    for (int i = l; i <= r; i++) dp[i][0] = dp[i][1] = 0;
    for (int i = l; i <= r; i++) if (fa[fa[i]] < r) {
        if (fa[fa[i] - 1] < fa[fa[i]]) dp[i][0]++;
        else if (fa[fa[i] - 2] < fa[fa[i]]) dp[i][1]++;
        {
            int A = i, B = fa[A], C = fa[B], D = fa[C];
            {
                int lx = max(C + 1, fa[C - 1] + 1);
                int rx = D;
                if (lx <= rx) {
                    sum += dp[i][1] * (rx - lx + 1);
                }
            }
            {
                int lx = max(C + 1, fa[C - 2] + 1);
                int rx = min(D, fa[C - 1]);
                if (fa[B - 1] < C - 1 && lx <= rx) {
                    sum += dp[i][0] * (rx - lx + 1);
                }
            }
        }
        if (fa[fa[fa[i]]] < r) {
            int A = i, B = fa[A], C = fa[B], D = fa[C], op;
            if (fa[C - 1] < D) op = 0;
            else if (fa[C - 2] < D) {
                if (fa[B - 1] >= C - 1) op = 2;
                else op = 1;
            } else op = 2;
            for (int x = 0; x + op < 2; x++) dp[B][x + op] += dp[A][x];
        }
    }
    return sum;
}
void solve() {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1, v = 1; i <= n; i++) {
        v = max(v, i);
        while (v + 1 <= n && a[v + 1] - a[i] <= d) v++; 
        fa[i] = v;
    }
    int sum = 0;
    for (int i = 1, lst = 0; i <= n; i++) 
        if (fa[i] == i) {
            sum += deal(lst + 1, i);
            lst = i;
        }
    cout << sum << '\n';
}
signed main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin.tie(0)->sync_with_stdio(false);
    cin >> c >> T;
    while (T--) solve();
    return 0;
}