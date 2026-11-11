#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, a[200005], s, ans = 0;
char c[200005];

signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1 ; i <= n ; i++) {
        cin >> a[i] >> c[i];
        s += a[i];
    }
    int st = 1, ed = n;
    while(st <= ed) {
        if(c[st] != c[ed]){
            ans += min(a[st], a[ed]);
        }
        if(a[st] == a[ed]){
            a[st] = a[ed] = 0;
            st++, ed--;
        } else if(a[st] > a[ed]) {
            a[st] -= a[ed];
            a[ed] = 0;
            ed--;
        } else {
            a[ed] -= a[st];
            a[st] = 0;
            st++;
        }
    }
    cout << ans << endl;
    return 0;
}
