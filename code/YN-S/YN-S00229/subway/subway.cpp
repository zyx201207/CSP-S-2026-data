#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;

	vector<int> w(m);
	for (auto &i : w)
	{
		cin >> i;
	}

	vector<vector<int>> k(n);
	for (auto &i : k)
	{
		int temp;
		cin >> temp;

		i.push_back(temp);
	}

	vector<pair<int, int>> pl(p);
	for (auto &i : pl)
	{
		int u, v;
		cin >> u >> v;

		i = { u, v };
	}



	return 0;
}