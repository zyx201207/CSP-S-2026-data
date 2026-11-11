#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int cas, T;
int n;int d;
int a[N];

inline void solve(){
    cin>> n>> d;
    int dd = 0, ans = 0;
    for(int i = 1;i <= n;i++) {
        cin>> a[i];
    }
    if(n <= 2) {cout<< 0<< '\n'; return;}
    dd = a[2] - a[1];
    if(dd != -1){;
        int k = 0;
        for(;d >= dd;d -= dd) k++;
        int m = 0, res = 0;
        for(;n >= k;n -= k) m++;
        res = n;
        ans = m * (m - 1) / 2 * res + (res == (k - 1));
    }cout<< ans<< '\n';
}

signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>> cas>> T;
    while(T--) solve();
    return 0;
}
