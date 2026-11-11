#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
char s[200005];
signed main () {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i] >> s[i];
    }
    int l = 1, r = n;
    char ll = s[l], rr = s[r];
    while (l <= r) {
        int x = min(a[l], a[r]);
        if (ll != rr) sum += x;
        if (x == a[l]) {
            l ++;
            ll = s[l];
            a[r] -= x;
        }
        else {
            r --;
            rr = s[r];
            a[l] -= x;
        }
    }
    cout << sum;
    return 0;
}
