#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 7;
long long x[MAXN];
void solve()
{
    long long n, d;
    cin >> n >> d;
    long long len = d + 1;
    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        if (i + len <= n) {
            cnt++;
        }
    }
    cout << cnt << '\n';
}
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while (t--) {
        solve();
    }
    return 0;
}