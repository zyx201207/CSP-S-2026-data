#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int c, t;
int n, k;

vector<int> g[N];

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	
	srand(time(0));
	
	cin >> c >> t;
	
	while (t--)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; ++i)
		{
			g[i].clear();
		}
		for (int i = 1; i <= n - 1; ++i)
		{
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << rand() % (n + 1) << endl;
	}
	 
	
	return 0;
}
 
