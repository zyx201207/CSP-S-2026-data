#include <bits/stdc++.h>
using namespace std;
namespace Main
{
	int c, t;
	int n, k;
	int u[1000], v[1000];
	int f[1000];
	int xz[1001];
	int m[1001];
	int find(int x)
	{
		if (f[x] == x)
			return x;
		return f[x] = find(f[x]);
	}
	// void dfs(int x)
	// {
	// 	if (x == k + 1)
	// 	{
	// 		for (int i = 1; i <= k; ++i)
	// 			for (int j = 1; j <= k; ++j)
	// 				if (m[i][j])
	// 					f[find(i)] = find(j);
	// 		set<int> st;
	// 		for (int i = 1; i <= n; ++i)
	// 			st.insert(find(i));
	// 	}
	// }
	int main()
	{
		freopen("hub.in", "r", stdin);
		freopen("hub.out", "w", stdout);
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cin >> c >> t;
		for (int tt = 1; tt <= t; ++tt)
		{
			cin >> n >> k;
			for (int i = 1; i < n; ++i)
			{
				cin >> u[i] >> v[i];
				// m[u[i]][v[i]] = m[v[i]][u[i]] = true;
			}
			for (int i = 1; i <= n; ++i)
				cout << 1 << '\n';
		}
		return 0;
	}
}
int main()
{
	return Main::main();
}
