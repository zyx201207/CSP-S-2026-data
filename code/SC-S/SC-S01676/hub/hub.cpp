#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,k;
int fa[15],dis[15][15];
vector<int> g[15];
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
void merge(int x,int y)
{
	x = find(x),y = find(y);
	if (x != y)
		fa[x] = y;
}
void solve()
{
	cin >> n >> k;
	if (n > 10)
		cout << "给了呗兄弟\n",exit(0);
	for (int i = 1; i <= n; i++)
	{
		memset(dis[i],0x3f,sizeof(int) * (n + 5));
		g[i].clear(),dis[i][i] = 0;
	}
	for (int i = 1,u,v; i < n; i++)
	{
		cin >> u >> v;
		dis[u][v] = dis[v][u] = 1;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (dis[i][k] != inf && dis[k][j] != inf)
					dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
	int ans = inf;
	for (int s = 0; s < 1 << n; s++)
	{
		if (__builtin_popcountll(s) != k)
			continue;
		iota(fa + 1,fa + n + 1,1);
		for (int i = 1; i <= n; i++)
			if ((s >> (i - 1)) & 1)
				for (auto v : g[i])
					if ((s >> (v - 1)) & 1)
						merge(i,v);	
		set<int> st;
		for (int i = 1; i <= n; i++)
			if ((s >> (i - 1)) & 1)
				st.insert(find(i));
		if (st.size() > 2)
			continue;
		int max1 = 0;
		for (int i = 1; i <= n; i++)
		{
			int tmp = inf;
			for (int j = 1; j <= n; j++)
				if ((s >> (j - 1)) & 1)
					tmp = min(tmp,dis[i][j]);
			max1 = max(max1,tmp);
		}
//		if (max1 == 1)
//			cout << find(2) << ' ' << find(8) << ' ' << find(9) << '\n';
//			cout << bitset<10>(s) << '\n';
		ans = min(ans,max1);
	}
	cout << ans << '\n';
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int _,t;
	cin >> _ >> t;
	while (t--)
		solve();
	return 0;
}