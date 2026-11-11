#include<bits/stdc++.h>
#define int long long

const int maxn = 1e6+5;
int a[maxn];
int sum[maxn];

signed main() {
    freopen("crystal.in", "r", stdin); freopen("crystal.out", "w", stdout);
    std::cin.tie(0), std::cout.tie(0), std::ios::sync_with_stdio(0);
    int n, m; std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a+1, a+n+1);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i-1] + a[i];
        int l = 0, r = i;
        while (l < r-1) {
            int mid = (l+r)/2;
            if (a[i]*(i-mid+1) - (sum[i] - sum[mid-1]) <= m) r = mid;
            else l = mid;
        }
        ans = std::max(ans, i-l);
    }
    std::cout << ans <<"\n";
}