#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long long n, m;
	cin >> n >> m;
	vector <long long> a(n);
	for (auto i = 0; i < n; ++i)
		cin >> a[i];
	auto check = [&] ()
		{
			const auto mns = a[1] - a.front();
			for (auto i = 2; i < n; ++i)
				if (a[i] - a[i - 1] != mns)
					return false;
			return true;
		};
	if (check())
	{
		sort(a.begin(), a.end());
		auto i = n - 2, cnt = 1LL;
		while (i >= 0)
			if (m >= a[n - 1] - a[i])
			{
				++cnt;
				m -= a[n - 1] - a[i--];
			}
			else
				break;
		cout << cnt << '\n';
		return 0;
	}
	else
	{
		auto ans = LLONG_MIN;
		for (auto i = 0; i < n; ++i)
		{
			const auto elem = a[i];
			auto tmp = m;
			sort(a.begin(), a.end(), [&] (const auto ielem, const auto jelem)
					{
						return abs(ielem - elem) < abs(jelem - elem);
					}
			);
			auto cnt = 0LL;
			for (const auto ielem: a)
				if (tmp >= abs(elem - ielem))
				{
					++cnt;
					tmp -= abs(elem - ielem);
				}
				else
					break;
			ans = max(ans, cnt);
		}
		cout << ans << '\n';
		return 0;
	}
	return 0;
}
