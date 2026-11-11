// Nina Iseri i love you

#include <bits/stdc++.h>
using namespace std;


#define range(v, l, r) next(begin(v), l), next(begin(v), r+1)
#define range_full(v) begin(v), end(v)

int64_t n, m;
array<int64_t, size_t(2e5+5)> a;
int64_t ans;

void dfs(int64_t idx, int64_t step, int64_t acc) {
    // cout << idx << " " << step << " " << acc << "\n";
    if (step >= m) {
        ans = max(ans, acc);
        return;
    }
    if (idx > n) {
        return;
    }
    dfs(idx+1, step+1, acc&a[idx]);
    dfs(idx+1, step, acc);
}

int32_t main() {
    ignore = freopen("and.in", "r", stdin);
    ignore = freopen("and.out", "w", stdout);
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    bool flagA{1}, flagB{1};
    for (int64_t i=1; i<=n; i++) {
        cin >> a[i];
        flagA &= (((a[i]+1)&(-a[i]-1)) == a[i]+1);
        flagB &= (a[i]+1==i);
    }

    if (flagA) {
        // cout << "entered A\n";
        sort(range(a, 1, n));
        cout << a[n-m+1];
    }
    else if (flagB) {
        // cout << "entered B\n";
        sort(range(a, 1, n));
        // try use the highest bit
        // int64_t bits = __builtin_popcountll(n-1);
        if (n == 2) {
            if (m == 1) {
                cout << 1;
                return 0;
            }
            else {
                cout << 0;
                return 0;
            }
        }
        else if (n == 1) {
            cout << 0;
            return 0;
        }
        int64_t ans = n-1;
        // cout << __lg(3-1)/__lg(2)+1 << "\n";
        int64_t k = __lg(m-1)/__lg(2)+1;
        // cout << k << "\n";
        for (int64_t i=1; i<=k; i++) {
            ans ^= 1<<(i-1);
        }
        cout << ans;
        // int64_t s{};
        // for (int64_t i=bits; i>=2; i++) {
        //     if (m <= ((1<<(i-1))+s)) {
        //         cout << (1<<i);
        //         return 0;
        //     }
        //     s += (1<<(i-2));
        // }
        // cout << 0;

        // if ((int64_t(1) << m) <= n) {
        //     cout << a[n/(1<<(m-1))-1];
        // }
        // else {
        //     cout << 0;
        // }
    }
    else if (n <= 2000) {
        // bao li
        dfs(1, 0, (int64_t(1)<<31)-1);
        cout << ans;
    }

    return 0;
}