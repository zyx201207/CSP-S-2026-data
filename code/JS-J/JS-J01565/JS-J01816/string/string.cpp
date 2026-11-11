#include <bits/stdc++.h>
using namespace std;

int n, a[200010];
char c[200010];

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> c[i];
    int l = 1, r = n;
    long long ans = 0;
    for (; l < r; ) {
        int x = min(a[l], a[r]);
        a[l] -= x; a[r] -= x;
        if (c[l] != c[r])
            ans += x;
        if (!a[l])
            l++;
        if (!a[r])
            r--;
    }
    cout << ans << "\n";
    return 0;
}
