#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;
int n, ans;
int arr[N];
char c[N];

signed main () {
    ios :: sync_with_stdio (0); cin.tie(0); cout.tie(0);
    freopen ("string.in", "r", stdin);
    freopen ("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++ i) cin >> arr[i] >> c[i];
    int l = 1, r = n, llft = arr[1], rlft = arr[n];

    while (l < r) {
        if (c[l] == c[r]) {
            if (llft > rlft) {
                llft -= rlft;
                r --;
                rlft = arr[r];
            }
            else if (rlft > llft) {
                rlft -= llft;
                l ++;
                llft = arr[l];
            }
            else {
                l ++;
                r --;
                llft = arr[l];
                rlft = arr[r];
            }
        }
        else {
            if (llft > rlft) {
                llft -= rlft;
                ans += rlft;
                r --;
                rlft = arr[r];
            }
            else if (rlft > llft) {
                rlft -= llft;
                ans += llft;
                l ++;
                llft = arr[l];
            }
            else {
                l ++;
                r --;
                ans += rlft;
                llft = arr[l];
                rlft = arr[r];
            }
        }
    }
    cout << ans;
 //   cerr << ans;
    return 0;
}

