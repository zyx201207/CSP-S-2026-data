#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector <int> a(n + 10);
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (auto i = 0; i < n; ++i)
        cin >> a[i];
    if (m == 1 || n <= 2 * 1e5 && m <= n)
    {
        cout << *max_element(a.begin(), a.end()) << '\n';
        return 0;
    }
    if (m == 2)
    {
        auto ans = INT_MIN;
        for (auto i = 0; i < n - 1; ++i)
            for (auto j = i + 1; j < n; ++j)
                ans = max(ans, a[i] & a[j]);
        cout << ans << '\n';
        return 0;
    }
    if (m == n - 1)
    {
        auto ans = INT_MIN;
        for (auto i = 0; i < n; ++i)
        {
            auto cnt = i? a.front(): a[1];
            for (auto j = 0; j < n; ++j)
                if (j != i)
                    cnt &= a[i];
            ans = max(ans, cnt);
        }
        cout << ans << '\n';
        return 0;
    }
    if (m == n)
    {
        auto ans = a.front();
        for (auto i = 1; i < n; ++i)
            ans &= a[i];
        cout << ans << '\n';
        return 0;
    }
    sort(a.begin(), a.end(), greater <>());
    auto ans = a.front();
    for (auto i = 1; i < m; ++i)
        ans &= a[i];
    cout << ans << '\n';
	return 0;
}
