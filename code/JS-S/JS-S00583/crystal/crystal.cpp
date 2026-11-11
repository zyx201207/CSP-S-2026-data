// (i-j)a_i-sum(a_j~a_{i-1}) <= m
// i * a _ i - j * a _ i - (S _ {i - 1} - S _ {j - 1}) <= m
// S _ {j - 1} - j * a _ i <= m - i * a _ i + S _ {i - 1}

#include <iostream>
#include <cstdlib>
#include <algorithm>

typedef long long ll;
typedef unsigned long long ull;

constexpr int N = 5e5 + 5;

int n; ll m, a[N], s[N], ans = -1;

inline bool chk(int mid, int i) { return (s[mid - 1] - 1ll * mid * a[i] <= m - 1ll * i * a[i] + s[i - 1]); }

int main() {
    std::freopen("crystal.in", "r", stdin);
    std::freopen("crystal.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    for(int i = 1; i <= n; ++i) std::cin >> a[i];
    std::sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];

    for(int i = 1; i <= n; ++i) {
        if(i < n && a[i] == a[i + 1]) continue;
        int l = 1, r = i;
        while(l < r) {
            int mid = l + r >> 1;
            if(chk(mid, i)) r = mid;
            else l = mid + 1;
        }
        ans = std::max(ans, i - l + 1);
    }
    std::cout << ans << '\n';

    return 0;
}
