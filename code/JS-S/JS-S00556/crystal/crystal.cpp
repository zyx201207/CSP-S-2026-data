#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, ans = 1;
long long m, a[N], s[N];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
        s[i] = a[i + 1] - a[i];
    for (int i = 1; i < n - 1; ) {
        long long t = m;
        int sum = 1;
        for (int j = i; ; ++j) {
            t -= s[j] * (j - i + 1);
            if (t < 0 || j == n) {
                ans = max(sum, ans);
                i = j;
                break;
            }
            ++sum;
        }
    }
    cout << ans << endl;
    return 0;
}
