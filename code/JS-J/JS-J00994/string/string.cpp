#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n;
int a[maxn];
char c[maxn];
int l, r;
long long ans = 0;
signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
    }
    l = 1;
    r = n;
    while (l <= r) {
        int x = min(a[l], a[r]);
        if (c[l] != c[r]) {
            ans += x;
        }
        if (a[l] > a[r]) {
            a[l] -= a[r];
            r--;
        }
        else if (a[l] < a[r]) {
            a[r] -= a[l];
            l++;
        }
        else l++, r--;
    }
    cout << ans;
    return 0;
}
