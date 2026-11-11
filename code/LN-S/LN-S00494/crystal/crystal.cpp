#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, a[500005], m, d[500005], sum, ans;
signed main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out","w", stdout);
    cin >> n >> m;
    ans = n;
    bool flag = false;
    for (int i = 1;i <= n;i ++) {
        cin >>a[i];
        d[i] = a[i] - a[i - 1];
        sum += abs(d[i]);
        bool ok = true;
        if(a[i] != a[i - 1])ok = false;
        if(a[i] = i) {
            flag = true;
        }
        else flag = false;
    }
    if(ok) {
        cout << min(n, m) << endl;
        return 0;
    }
    if(flag) {
        if(m / 2 + 1 <= n) {
            cout << m / 2 + 1;
            return 0;
        }
        else {
            cout << n;
            return 0;
        }
    }
    for (int i = n;i >= 1;i --) {
        if(sum <= m)break;
        else {
            sum -= abs(d[i]);
            ans --;
        }
    }
    cout <<ans;
    return 0;
}

