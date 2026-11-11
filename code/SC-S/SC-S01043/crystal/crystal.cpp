#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;

int sum[N], a[N];

signed main() {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, K; cin >> n >> K;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
        int l = 1, r = i, res = i;
        while(l <= r) {
            int mid = (l + r) / 2;
            int k = i - mid + 1;
            if(k * a[i] - sum[i] + sum[mid - 1] <= K) {
                r = mid - 1;
                res = mid;
            }
            else l = mid + 1;
        }
        ans = max(ans, i - res + 1);
    }
    cout << ans;
    return 0;
}
// g++ std.cpp -o std --std=c++14 -Wall -W &&  ulimit -s &&./std
// 524288
// 131072