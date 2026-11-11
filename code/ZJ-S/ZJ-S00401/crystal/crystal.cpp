#include <bits/stdc++.h>
using namespace std;

#define llint long long

int n;
llint m;
llint a[500010];
llint s[500010];
int ans;

int main () {
    freopen ("crystal.in", "r", stdin);
    freopen ("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort (a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 1; i <= n; ++i) {
        int flag = 0;
        // for (int j = i; j >= 1; --j) {
        //     if (a[i] * (i - j) - (s[i - 1] - s[j - 1]) > m) {
        //         flag = j;
        //         break;
        //     }
        // }
        int l = 1, r = i - 1;
        while (l < r) {
            int mid  = (l + r) >> 1;
            if (a[i] * (i - mid) - (s[i - 1] - s[mid - 1]) > m) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        flag = l;
        // cout << i << ' ' << flag << endl;
        ans = max (ans, i - flag + 1);
    }
    cout << ans << endl;
    fclose (stdin);
    fclose (stdout);
    return 0;
}