#include <bits/stdc++.h>

namespace Solution {
    constexpr int N = 5e5+3;
    long long n, m, a[N], s[N];

    int find(int p) {
        int L = 1, R = p, mid = 0, ans = 0;
        while (L <= R) {
            mid = (L + R) >> 1;
            if (a[p] * (p - mid + 1) - (s[p] - s[mid-1]) <= m) ans = mid, R = mid - 1;
            else L = mid + 1;
        }
        return ans;
    }

    void Solve() {
        scanf("%lld%lld",&n,&m);
        for (int i = 1; i <= n; i++) scanf("%lld",&a[i]);
        
        std::sort(a+1,a+n+1);
        for (int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];

        int ans = 1;
        for (int i = 2; i <= n; i++)
            ans = std::max(ans,i-find(i)+1);
        printf("%d\n",ans);
    }
}

int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    Solution::Solve();
}