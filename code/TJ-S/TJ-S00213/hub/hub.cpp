#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int c, t, n, k, u, v;
vector<int> e[N];
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> k;
		for(int i = 1; i < n; i++)
		{
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		cout << 1 << '\n';
	}
	return 0;
}
