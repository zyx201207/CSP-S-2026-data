#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200005];
int dp[200005];
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    int maxn = 0;
    int flag = 1;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        int t = a[i];
        maxn = max(maxn, a[i]);
        int s = 0;
        while(t > 0)t/=2, s++;
        if(s != __builtin_popcount(a[i])) {
            flag = 0;
        }
    }
    if(m == 1) {
        cout << maxn;
        return 0;
    }
    if(m == n) {
        int nm = a[1];
        for(int i = 2; i <= n; i++) {
            nm = nm & a[i];
        }
        cout << nm;
        return 0;
    }
    if(flag) {
        sort(a+1, a+1+n, greater<int>());
        cout <<a[m];
        return 0;
    }

    int ans = 0;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == 1) {
                dp[i] = a[j];
            }else {
                dp[i] = dp[i] & a[j];
            }
        }
    }
    for(int i = 1; i <= m; i++) ans= max(ans, dp[i]);
    cout << ans;
    return 0;
}
