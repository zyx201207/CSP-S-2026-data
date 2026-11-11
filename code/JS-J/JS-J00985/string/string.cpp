// Nina Iseri i love you

#include <bits/stdc++.h>
using namespace std;


#define range(v, l, r) next(begin(v), l), next(begin(x), r+1)
#define range_full(v) begin(v), end(v)

int64_t n;
array<int64_t, size_t(2e5+5)> a;
array<char, size_t(2e5+5)> c;
int64_t l, r;
int64_t ans;

int32_t main() {
    ignore = freopen("string.in", "r", stdin);
    ignore = freopen("string.out", "w", stdout);
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    cin >> n;
    for (int64_t i=1; i<=n; i++) {
        cin >> a[i] >> c[i];
    }

    l = 1;
    r = n;

    while (l < r) {
        if (c[l] != c[r]) {
            if (a[l] > a[r]) {
                ans += a[r];
                a[l] -= a[r];
                --r;
            }
            else if (a[l] == a[r]) {
                ans += a[r];
                --r;
                ++l;
            }
            else {
                ans += a[l];
                a[r] -= a[l];
                ++l;
            }
        }
        else {
            if (a[l] > a[r]) {
                a[l] -= a[r];
                --r;
            }
            else if (a[l] == a[r]) {
                --r;
                ++l;
            }
            else {
                a[r] -= a[l];
                ++l;
            }
        }
    }

    cout << ans;



    return 0;
}