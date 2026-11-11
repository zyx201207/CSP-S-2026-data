#include <bits/stdc++.h>
using namespace std;

int n, m;
long long maxn = LLONG_MIN;
vector<int> c;

void dfs(long long need, long long ans, int now, long long mark)
{
	if (need > m)
		return;
	if (need == m || now >= n || c[now] >= mark)
	{
		while (c[now] == mark)
		{
			++now;
			++ans;
		}
		if (maxn < ans)
			maxn = ans;
		return;
	}

	dfs(need + mark - c[now], ans + 1, now + 1, mark);
	dfs(need, ans, now + 1, mark);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;

	c.resize(n);
	for (auto &i : c)
	{
		cin >> i;
	}

	sort(c.begin(), c.end());

	for (const auto &i : c)
	{
		dfs(0, 0, 0, i);
	}
	cout << maxn << '\n';

	return 0;
}
