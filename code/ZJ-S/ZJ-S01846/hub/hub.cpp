#include<bits/stdc++.h>
using namespace std;
int c, t;
//vector<int> e[1000002];
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	for(; t--; )
	{
		int n, k;
		cin >> n >> k;
		for(int i = 1; i < n; i++)
		{
			int u, v;
			cin >> u >> v;
//			e[u].push_back(v);
//			e[v].push_back(u);
		}
		cout << k - 1 << '\n';
	}
	return 0;
}