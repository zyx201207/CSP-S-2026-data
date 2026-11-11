#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 5e5 + 10;
int n, m;
int a[N], mis[N], maxlen = 1, summ[N];

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);

    for(int r = 1; r <= n; r ++) {
        summ[r] = a[r] + summ[r - 1];
        while((a[r] * (maxlen + 1) - (summ[r] - summ[r - (maxlen + 1)])) <= m && (r - (maxlen + 1) + 1) >= 1) {
//            cout << "   " << r - (maxlen + 1) + 1 << " " << r << " " << maxlen + 1 << " " << a[r]  << " " << summ[r] << " " << summ[r - (maxlen + 1) + 1]  << " " << (a[r] * (maxlen + 1) - (summ[r] - summ[r - (maxlen + 1)])) << " " << m << "\n";
            maxlen ++;
        }
//        cout << r - maxlen << " " << r << " " << maxlen<< "\n";
    }
    cout << maxlen;
}
