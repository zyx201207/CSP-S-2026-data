#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200010;
int a[N];
char c[N];
int n;
signed main() {
    freopen("string.in", "a+", stdin);
    freopen("string.out", "w+", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
    }
    int l = 1;
    int r = n;
    int use_l = 0;
    int use_r = 0;
    int ans = 0;
    while (l < r) {
        if (c[l] == c[r]) {
            
        } else {
            ans += min(a[l] - use_l, a[r] - use_r);
        }
        if (a[l] - use_l == a[r] - use_r) {
            l++;
            r--;
            use_l = 0;
            use_r = 0;
        } else if(a[l] - use_l < a[r] - use_r) {
            use_r += a[l] - use_l;
            l++;
            use_l = 0;
        } else if(a[l] - use_l > a[r] - use_r) {
            use_l += a[r] - use_r;
            r--;
            use_r = 0;
        }
    }
    cout << ans << "\n";
    return 0;
}