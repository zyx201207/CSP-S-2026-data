#include<bits/stdc++.h>
#define int long long

const int maxn = 2e6+5;
int x[maxn], r[maxn], l[maxn], cntr[maxn], cntl[maxn];
int rr[maxn], ll[maxn];

void init(int n) {
    for (int i = 0; i <= n+1; ++i) {
        x[i] = r[i] = l[i] = cntr[i] = cntl[i] = rr[i] = ll[i] = 0;
    }
}

void solve() {
    int n, d; std::cin >> n >> d;
    init(n);
    for (int i = 1; i <= n; ++i) {
        std::cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        r[i] = r[i-1];
        while (r[i] < n && x[r[i]+1] - x[i] <= d) r[i]++;
        if (r[i] != i) cntr[r[i]]++;
    }
    l[n+1] = n+1;
    for (int i = n; i >= 1; --i) {
        l[i] = l[i+1];
        while (l[i] >= 1 && x[i] - x[l[i]-1] <= d) l[i]--;
        if (l[i] != i) cntl[l[i]]++;
    }
    for (int i = n; i >= 1; --i) {
        if (r[i] == i) continue;
        rr[i] = cntl[i];
        if (l[r[i]] == i) {
            rr[i] += rr[r[i]];
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (l[i] == i) continue;
        ll[i] = cntr[i];
        if (r[l[i]] == i) {
            ll[i] += ll[l[i]];
        } 
    }
    int ans = 0;
    for (int i = 2; i <= n; ++i) {
        if (l[i-1] == i-1 || r[i] == i) continue;
        int left = 0, right = 0;
        left += cntr[i]; right += cntl[i-1];
        if (r[i-1] == i) left--;
        if (l[i] == i-1) right--;
        if (r[l[i-1]] == i) {
            left += ll[l[i-1]];
        }
        if (l[r[i]] == i-1) {
            right += rr[r[i]];
        }
        ans += left * right;
    }
    std::cout << ans <<"\n";
}

signed main() {
    freopen("migrate.in", "r", stdin); freopen("migrate.out", "w", stdout);
    std::cin.tie(0), std::cout.tie(0), std::ios::sync_with_stdio(0);
    int c, t; std::cin >> c >> t;
    while (t --> 0) solve();
}