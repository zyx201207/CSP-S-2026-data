#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, a[N];
bool b[N];
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) b[i] = true;
    int ans = 0;
    for (int r = 29; r >= 0; r--) {
        int cnt = 0;
        for (int i = 0; i < n; i++) if (b[i] && (a[i] >> r & 1)) cnt++;
        if (cnt >= m) {
            ans |= 1 << r;
            for (int i = 0; i < n; i++) b[i] = (b[i] && (a[i] >> r & 1));
        }
    }
    cout << ans << '\n';
    return 0;
}
