#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 5;
int n;
ll m, a[N];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    ll cnt = 0, sum = 0;
    int ans = 0;
    for (int i = 1, j = 1; i <= n; i++) {
        sum += a[i], cnt++;
        while (a[i] * cnt - sum > m) {
            sum -= a[j], cnt--;
            j++;
        }
        ans = max(i - j + 1, ans);
    }
    cout << ans << '\n';
    return 0;
}