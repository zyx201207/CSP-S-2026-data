#include<bits/stdc++.h>
using namespace std;

int a[200005];

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_strio(false);
    cin.tie(nullptr);
    int n,m;
    int ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (m == n) {
            ans = ans & a[i];
        }
        if (n == 1) {
            ans = max(ans, a[i]);
        }
    }
    if (m == 2) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                ans = max(ans, a[i] & a[j]);
            }
        }
    }
    cout << ans <<'\n';
    return 0;
}
