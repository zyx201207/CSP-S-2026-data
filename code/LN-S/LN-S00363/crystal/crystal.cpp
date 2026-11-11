#include <algorithm>
#include <iostream>
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, ans = 0;
    long long m;
    std::cin >> n >> m;
    long long a[n];
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    std::sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        int l = i, r = n;
        while (l < r)
        {
            int mid = l + r >> 1;
            long long sum = 0;
            for (int j = i; j < mid; j++)
                sum += a[mid] - a[j];
            sum > m ? r = mid : l = mid + 1;
        }
        ans = std::max(ans, l - i);
    }
    std::cout << ans << '\n';
    return 0;
}
