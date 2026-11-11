#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e6 + 5;
int c;
int n; ll d, a[N];
int nxt[N];
void solve() {
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1, j = 1; i <= n; i++) {
        while (j <= n && a[j] - a[i] <= d)
            j++;
        j--;
        nxt[i] = j;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] < a[i + 1] - d)
            continue;
        int cnt = 0; bool ok = 0, fg = 0;
        int j = nxt[i];
        while (j < n) {
            if (a[j] < a[j + 1] - d)
                break;
            if (nxt[j - 2] == nxt[j])
                break;
            if (nxt[j - 1] == nxt[j]) {
                if (ok || fg)
                    break;
                ans += nxt[j] - max(j, nxt[j - 2]);
                fg = 1;
            }
            else if (fg)
                ans += nxt[j] - max(j, nxt[j - 1]);
            else
                ans += (!ok) * (nxt[j - 1] - max(j, nxt[j - 2]));
            ok = nxt[j - 1] >= nxt[j] - 1, j = nxt[j];
        }
    }
    cout << ans << '\n';
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> c >> t;
    while (t--)
        solve();
    return 0;
}