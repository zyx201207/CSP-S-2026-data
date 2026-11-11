#include <bits/stdc++.h>
using namespace std;

long long ans;
int n, l, r, a[200010];
char c[200010];

int main () {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n, l = 1, r = n, ans = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> c[i];
    while (l < r) {
        int res = min(a[l], a[r]);
        a[l] -= res, a[r] -= res;
        if (c[l] != c[r])
            ans += res;
        if (!a[l])
            l++;
        if (!a[r])
            r--;
    }
    cout << ans << '\n';
    return 0;
}
