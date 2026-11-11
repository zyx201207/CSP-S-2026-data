#include <iostream> 
#include <vector>
#include <cmath>
using std::cin;
using std::cout;

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, max = 0;
    cin >> n >> m;

    std::vector<int> a(n + 1);
    std::vector<bool> is(n + 1, 1);

    for (int i = 1; i <= n; ++i)
        cin >> a[i], max = std::max(max, a[i]);

    int now = 0;
    while(max)
        max >>= 1, ++now;

    while(--now >= 0) {
        int sum = 0;
        for (int i = 1; i <= n; ++i)
            if (is[i])
                sum += ((a[i] & (1 << now)) > 0);
        if (sum < m)
            continue;

        for (int i = 1; i <= n; ++i)
            if ((a[i] & (1 << now)) == 0)
                is[i] = 0;
        if (sum == m)
            break;
    }

    int ans = 0, sum = 0;
    for (int i = 1; i <= n; ++i)
        if (is[i] && sum++ < m)
            ans = (ans == 0 ? a[i] : ans & a[i]);

    cout << ans << '\n';
}