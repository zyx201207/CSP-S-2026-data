#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n;
long long a[N], m;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    sort(a + 1, a + n + 1);
    long long need = 0;
    int res = 0;
    for (int r = 1, l = 1; r <= n; r ++ ) {
        need += (a[r] - a[r - 1]) * (long long)(r - l);
        while (l < r && need > m) need -= a[r] - a[l ++ ];
        res = max(res, r - l + 1);
    }
    cout << res << '\n';
    return 0;
}

