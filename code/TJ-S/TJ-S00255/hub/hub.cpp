#include <iostream>
#include <vector>
using namespace std;
vector<int> g[1000010];
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	while (T--)
	{
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; i++) g[i].clear();
		for (int i = 1; i < n; i++)
		{
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int m = (n - 1) / 2;
		if (k == n) cout << 0 << endl;
		else if (k >= m) cout << 1 << endl;
		else
		{
			int t = m + 1 - k;
			cout << t / 4 + 1 << endl;
		}
 	}
	return 0;
}
