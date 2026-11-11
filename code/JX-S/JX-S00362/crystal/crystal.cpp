#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>

template <typename T>
using vec = std::vector<T>;
template <typename T>
using vec2 = vec<vec<T>>;
using LL = long long;
using ULL = unsigned long long;

const int MAXN = 5e5 + 5;
const int MOD = 998244353;

LL a[MAXN], pre[MAXN];
int main()
{

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    std::sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int l = 1, r = i;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (1LL * (i - mid + 1) * a[i] - (pre[i] - pre[mid - 1]) <= m)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        ans = std::max(ans, i - (r + 1) + 1);
    }
    std::cout << ans;
    return 0;
}
