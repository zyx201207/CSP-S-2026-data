#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
typedef long long ll;
int n, ans;
ll m, a[N];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int t = n + 1;
    ll sum = 0;
    for(int i = n; i; i --) {
        while(t > 1 && -sum - a[t - 1] + 1ll * (i - (t - 1) + 1) * a[i] <= m) {
            t --;
            sum += a[t];
        }
        ans = max(ans, i - t + 1);
        sum -= a[i];
    }
    cout << ans;
    return 0;
}