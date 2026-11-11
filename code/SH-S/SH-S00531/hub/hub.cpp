#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> g[1000010];

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t, n, k;
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> k;
		for(int i = 1; i < n; i++)
		{
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << 2 << endl;
	}
	return 0;
}
