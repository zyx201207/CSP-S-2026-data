#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int,int>
#define fi first
#define se second

const int maxn = 5e5 + 10;
int kscd,n,m,xya,q;
int val[maxn];
int dis[501][501];
vector<pii> vec[maxn];

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	memset(dis,0x3f,sizeof(dis));
	cin >> kscd >> n >> m >> xya >> q;
	for(int i = 1;i <= m;i++) cin >> val[i];
	for(int i = 1;i <= n;i++)
	{
		int tt;cin >> tt;
		while(tt--)
		{
			int x,vl;cin >> x >> vl;
			vec[x].push_back({i,vl});
		}
	}
	
	for(int i = 1;i <= m;i++) 
		for(unsigned u = 0;u < vec[i].size();u++) 
			for(unsigned v = u + 1;v < vec[i].size();v++)
			{
				int uu = vec[i][u].fi,vv = vec[i][v].fi;
				int w = vec[i][u].se + vec[i][v].se;
				if(dis[uu][vv] > w) dis[uu][vv] = dis[vv][uu] = w;
			}
	for(int i = 1;i <= n;i++) dis[i][i] = 0;
			
	for(int k = 1;k <= n;k++)
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
				
	for(int i = 1;i <= q;i++)
	{
		int u,v;cin >> u >> v;
		int ans = val[u] + val[v];
		int dd = 1e18;
		for(auto x : vec[u]) for(auto y : vec[v]) dd = min(dd,dis[x.fi][y.fi] + x.se + y.se);
		cout << ans + dd << '\n';
	}
	return 0;
	
 }
