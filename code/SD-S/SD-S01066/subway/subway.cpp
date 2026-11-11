# include<bits/stdc++.h>
# define int long long
using namespace std;
const int MX = 5e5;
const int NX = 500;
const int inf = 0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
int a,k;
long long t,w[MX + 10];
long long dis[NX + 10][NX + 10];
vector<pair<int,long long> > g[MX + 10];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i = 1;i <= n;i++)
	{
		dis[i][i] = 0;
		cin >> k;
		for(int j = 1;j <= k;j++)
		{
			cin >> a >> t;
			g[a].push_back({i + m,t});
		}
	}
	for(int i = 1;i <= m;i++)
	{
		for(auto x : g[i])
		{
			for(auto y : g[i])
			{
				if(x.second + y.second < dis[x.first - m][y.first - m])
				{
					dis[x.first - m][y.first - m] = dis[y.first - m][x.first - m] = x.second + y.second;
				}
			}
		}
	}
	for(int l = 1;l <= n;l++)
	{
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				dis[i][j] = min(dis[i][j],dis[i][l] + dis[l][j]);
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin >> x >> y;
		int ans = inf;
		for(auto i : g[x])
		{
			for(auto j : g[y])
			{
				if(dis[i.first - m][j.first - m] != inf)
				{
					ans = min(ans,i.second + j.second + dis[i.first - m][j.first - m] + w[x] + w[y]);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
