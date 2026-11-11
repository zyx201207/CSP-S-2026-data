#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	deque <pair <int, char> > q;
	for (int i = 1; i <= n; i++)
	{
		pair <int, char> tmp;
		cin >> tmp.first >> tmp.second;
		q.push_back(tmp);
	}
	int ans = 0;
	while (q.size() > 1)
	{
		pair <int, char> frontff = q.front();
		pair <int, char> backff = q.back();
		if (frontff.second == backff.second)
		{
			if (frontff.first == backff.first)
			{
				q.pop_back();
				q.pop_front();
			}
			else if (frontff.first > backff.first)
			{
				q.pop_back();
				q.pop_front();
				q.push_front({frontff.first - backff.first, frontff.second});
			}
			else if (frontff.first < backff.first)
			{
				q.pop_back();
				q.pop_front();
				q.push_back({backff.first - frontff.first, backff.second});
			}
		}
		else
		{
			if (frontff.first == backff.first)
			{
				ans += frontff.first;
				q.pop_back();
				q.pop_front();
			}
			else if (frontff.first > backff.first)
			{
				ans += backff.first;
				q.pop_back();
				q.pop_front();
				q.push_front({frontff.first - backff.first, frontff.second});
			}
			else if (frontff.first < backff.first)
			{
				ans += frontff.first;
				q.pop_back();
				q.pop_front();
				q.push_back({backff.first - frontff.first, backff.second});
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
