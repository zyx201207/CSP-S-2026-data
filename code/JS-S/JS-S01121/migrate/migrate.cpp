#include <bits/stdc++.h>
using namespace std;

vector<int64_t> x;

int main(void)
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    int64_t c, t;
    cin >> c >> t;
    while (t--)
    {
        int64_t n, d, ans = 0;
        cin >> n >> d;
        x.clear();
        x.resize(n + 1);
        for (int i = 1; i <= n; ++i)
            cin >> x[i];
        for (int i = 1; i <= n; ++i)
        {
            auto nxt = upper_bound(x.begin() + 1, x.end(), x[i] + d);
            if (nxt == x.end())
                break;
            int64_t id = nxt - x.begin();
            int64_t mid = id - 1 - i;
            cout << id << ' ' << mid << '\n';
            if (mid == 1)
                ans += n - id + 1;
            else if (mid > 1)
                ++ans;
        }
        cout << ans << '\n';
    }
    return 0;
}