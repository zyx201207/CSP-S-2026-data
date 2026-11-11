#include <bits/stdc++.h>
using namespace std;
long long a[500005];

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    long long m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 1;
    sort(a + 1, a + n + 1);
    int la = 1;
    long long now = 0;
    for (int i = 2; i <= n; i++) {
        now += 1LL * (i - la) * (a[i] - a[i - 1]);
        while (now > m) {
            now -= a[i] - a[la];
            la++;
        }
        ans = max(ans, i - la + 1);
    }
    cout << ans;
    return 0;
}
