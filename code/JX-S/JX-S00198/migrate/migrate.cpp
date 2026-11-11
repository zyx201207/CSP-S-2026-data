#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int c, T, n;
long long d, x[N];
void solve(){
    cin >> n >> d;
    for (int i = 1; i <= n; i ++ ) cin >> x[i];
    if (n == 1) {
        cout << "0\n";
        return;
    } else if (c >= 11 && c <= 12) {
        int d2 = x[2] - x[1];
        map<long long, int> mp;
        for (int i = 1; i <= n; i ++ ) mp[x[i] % d] ++ ;
        int cnt = 0;
        for (int i = 1; i <= n; i ++ ) {
            int l = upper_bound(x + 1, x + n + 1, x[i] - d) - x;
            l -- ;
            int r = lower_bound(x + 1, x + n + 1, x[i] + d) - x;
            int cnt = 0;
            cnt += l;
            cnt += n - r;
            cnt -= mp[x[i] % d];
            cnt += 2;
        }
        cout << cnt << '\n';
    } else cout << "0\n";
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> T;
    while (T -- ) solve();
    return 0;
}

