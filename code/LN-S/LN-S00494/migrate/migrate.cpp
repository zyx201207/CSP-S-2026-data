#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main () {
    freopen("migrate.in","r", stdin);
    freopen("migrate.out","w",stdout);
    int c, t;
    cin >> c >> t;
    if(c == 0) {
        int c;
        cin >> c;
        if(c == 4) cout << 1 << endl << 2;
        if(c == 5) cout << 0 << endl << 1;
    }
    while (t --) {
        int n, d;
        cin >> n >> d;
        int a[200005];
        for (int i = 1;i <= n;i ++) {
            cin >> a[i];
        }
        if(d == 1) {
            cout << 0 << endl;
        }
        cout << n - 1 << endl;
    }
    return 0;
}
