#include <bits/stdc++.h>
using namespace std;

int n, ans = 1;
long long m;
vector<long long> a;

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    a.resize(n);
    for (long long &e: a) cin >> e;

    sort(a.begin(), a.end());

    long long sum = 0;
    for (int l = 0, r = 0; r < n; r ++) {
        sum += a[r];
        for (;;) {
            int len = r - l + 1;
            if (a[r]*len > sum + m) {
                if(l == r) break;
                else {
                    sum -= a[l];
                    l ++;
                }
            } else {
                ans = max(ans, len);
                // cout << ans << ' ' << len << ' ' << l << ' ' << r << '\n';
                break;
            }
        }
        // if (a[r] > 25) {
        //     cerr << 1;
        // }
    }

    cout << ans << '\n';

    return 0;
}