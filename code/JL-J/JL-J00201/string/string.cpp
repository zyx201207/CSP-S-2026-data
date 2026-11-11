#include <bits/stdc++.h>
using namespace std;
int n, a[200001];
char c[200001];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> c[i];
    long long l = a[1], r = 0, ans = 0;
    char lc = c[1], rc;
    int lp = 2, rp = n;
    while (lp <= rp){
        if (l == 0){
            l = a[lp];
            lc = c[lp];
            lp++;
        }
        if (r == 0) {
            r = a[rp];
            rc = c[rp];
            rp--;
        }
        int t = min(l, r);
            l -= t;
            r -= t;
            if (lc != rc)
                ans += t;
    }
    cout << ans;
    return 0;
}
