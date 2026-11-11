#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 7;
int n, m, ans;
int a[MAXN];
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (n == m) {
        for (int i = 1; i <= n; i++) {
            ans &= a[i];
        }
    }
    if (m == 1) {
        ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, a[i]);
        }
    }
    if (m == 2) {
        ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                ans = max(ans, a[i] & a[j]);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}