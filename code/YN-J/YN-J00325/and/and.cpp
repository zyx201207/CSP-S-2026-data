#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> now;
long long maxn = LLONG_MIN;

void dfs(vector<int> &ns, int c)
{
	if (now.size() == (size_t)m)
	{
		long long ans = now[0];
		for (size_t i = 1 ; i < now.size() ; ++i)
		{
			ans &= now[i];
		}
		if (ans > maxn)
		{
			maxn = ans;
		}

		auto it = now.end();
		now.erase(--it);
		return;
	}
	else if (c >= n)
	{
		return;
	}

	int cc = c + 1;
	dfs(ns, cc);
	now.push_back(ns[c]);
	dfs(ns, cc);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	cin >> n >> m;

	vector<int> ns(n);

	for (auto &i : ns)
	{
		cin >> i;
	}

	dfs(ns, 0);

	cout << maxn << '\n';

	return 0;
}
