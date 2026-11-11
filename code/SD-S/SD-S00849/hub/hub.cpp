#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
const int N = 1000005;
int c,T,n,k,cnt,mx,ans;
vector<int>vec[N];
bool key[N];
int dfs(int u,int fa,int dis)
{
	int ret = 999999;
	if (key[u]) ret = dis = 0;
	for (int i: vec[u])
	{
		if (i == fa) continue;
		if (!key[i])
		{
			ret = min(ret,dfs(i,u,dis+1));
		}
		else
		{
			if (!key[u]) cnt++;
			ret = min(ret,dfs(i,u,0)+1);
		}
	}
	mx = max(min(ret,dis),mx);
	return ret;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> c >> T;
	while (T--)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
		{
			vec[i].clear();
		}
		for (int i = 1; i < n; i++)
		{
			int u,v;
			cin >> u >> v;
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		ans = 999999;
		for (int i = 0; i < 1<<n; i++)
		{
			if (__builtin_popcount(i) != k) continue;
			for (int j = 0; j < n; j++)
				if (i>>j&1) key[j+1] = 1;
				else key[j+1] = 0;
			cnt = 0,mx = 0;
			if (key[1]) cnt++;
			dfs(1,0,99999);
			if (cnt > 2) continue;
			ans = min(ans,mx);
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
0 1
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9
*/
