#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int a[N], n, m, s[N];
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        s[i] = s[i - 1] + a[i];
    }
    int maxx = -1e18;
    for (int i = 1; i <= n; ++i) {
        int l = 1, r = i, id = i;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (a[i] * (i - mid) <= s[i - 1] - s[mid - 1] + m) {
                r = mid - 1;
                id = mid;
            }else {
                l = mid + 1;
            }
        }
        maxx = max(maxx, i - id + 1);
    }
    cout << maxx << '\n';
    return 0;
}