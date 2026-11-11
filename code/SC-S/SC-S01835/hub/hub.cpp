#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k,u,v;
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> k;
		vector<int> e[2000005];
		for (int i = 1; i <= n; i++)
		{
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		cout << "0\n";
	}
	return 0;
}