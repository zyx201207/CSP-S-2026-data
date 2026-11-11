#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long a[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int l = 1, r = 1;
    long long t = 0;
    int ans = 1;
    while (l <= r && r <= n) {
        r++;
        t += (a[r] - a[r - 1]) * (r - l);
        while (t > m && l < r) {
            t -= (a[r] - a[l]);
            l++;
        }
        ans = max(ans, (r - l + 1));
    }

    cout << ans << "\n";
    return 0;
}
