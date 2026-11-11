#include <bits/stdc++.h>
#define N 200005
using namespace std;
int n, m, a[N];
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    if (n == m) {
        int ans;
        cin >> ans;
        for (int i = 1; i < n; i++) {
            cin >> a[i];
            ans &= a[i];
        }
        cout << ans << '\n';
        return 0;
    }
    return 0;
}
