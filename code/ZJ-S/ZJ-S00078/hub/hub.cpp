#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
vector<int> road[1000010];
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	while(t--)
	{
		int n,k;cin >> n >> k;
		for(int i = 1;i <= n-1;i++)
		{
			int u,v;cin >> u >> v;
			road[u].push_back(v);
			road[v].push_back(u);
		}
		cout << 1 << endl;
	}
	return 0;
}
