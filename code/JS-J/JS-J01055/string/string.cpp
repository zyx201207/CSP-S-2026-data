#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, a[N];
char c[N];
long long ans;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> c[i];
    }
    for (int i = 1, j = n; i < j; ) {
        int diff = min(a[i], a[j]);
        if (c[i] != c[j]) ans += diff;
        a[i] -= diff, a[j] -= diff;
        if (!a[i]) ++i;
        if (!a[j]) --j;
    }
    cout << ans;
    return 0;
}
