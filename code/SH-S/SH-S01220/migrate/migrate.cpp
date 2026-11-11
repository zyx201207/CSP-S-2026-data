#include <iostream>
using i64 = long long;
const int maxn = 2e6 + 5;

int a[maxn], access[maxn];
// int f[maxn][2];

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int c, t;
    std::cin >> c >> t;

    while(t--)
    {
        int n, d;
        std::cin >> n >> d;
        for(int i = 1; i <= n; ++i)
            std::cin >> a[i];

        int right = 2;
        for(int i = 1; i <= n; ++i)
        {
            while(a[right] - a[i] <= d && right <= n) right++;

            access[i] = right - 1;
        }
    }
}
// 尝试定义状态 f_i_j_k = 从i->j的可行方案数，有k次没有贪心选择可访达最远点。则显然有k >= 2时不存在最优情况。
