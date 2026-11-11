#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sycn_with_stdio(false);
	cin.tie(nullptr);

	int c, t;
	cin >> c >> t;

	while (t--)
	{
		int n, k;
		cin >> n >> k;

		vector<vector<int>> m(n);
		for (int i = 0 ; i < n ; ++i)
		{
			int u, v;
			cin >> u >> v;

			m[u].push_back(v);
			m[v].push_back(u);
		}


	}

	return 0;
}
