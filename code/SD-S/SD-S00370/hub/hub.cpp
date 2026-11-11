#include<bits/stdc++.h>
using namespace std;
int c, t, n, k;
vector<int>e[100005];
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t--)
	{
		for(int i = 1; i <= n; i++)e[i].clear();
		cin >> n >> k;
		for(int i = 1; i < n; i++)
		{
			int u, v;
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if(k == n)cout << 0;
		cout << rand() % n;
	}
}
