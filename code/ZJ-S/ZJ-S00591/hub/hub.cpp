#include <bits/stdc++.h>
using namespace std;
int t, c;
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--)
	{
		int n, k, ans = -1;
		cin >> n >> k;
		vector<int> e[500005];
		for (int i = 1; i < n; i++)
		{
			int u, v;
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
			if (min(u, v) == 1)
				ans = max(ans, abs(u - v));
		}
		cout << ans << endl;
	}
	return 0;
}

