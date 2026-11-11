#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int x,y,z;
int ans;
int w[500005],k[505],line[500005];
int dis[505][505];
struct str
{
	int id,ds;
};
vector<str>G[505];
vector<str>F[500005];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)cin >> w[i];
	for(int i = 1; i <= n; i++)for(int j = 1; j <= n; j++)dis[i][j]=1e18;
	for(int i = 1; i <= n; i++)
	{
		dis[i][i]=0;
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++)
		{
			cin >> x >> y;
			G[i].push_back({x,y});
			F[x].push_back({i,y});
			line[x]++;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < k[i]; j++)
		{
			for(int l = 0; l < line[G[i][j].id]; l++)
			{
				z=F[G[i][j].id][l].id;
				dis[i][z]=dis[z][i]=min(dis[i][z],G[i][j].ds+F[G[i][j].id][l].ds);
			}
		}
	}
	for(int kk = 1; kk <= n; kk++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][kk]+dis[kk][j]);
			}
		}
	}
	while(q--)
	{
		cin >> x >> y;
		ans=1e18;
		for(int i = 0; i < line[x]; i++)
		{
			for(int j = 0; j < line[y]; j++)
			{
				ans=min(ans,F[x][i].ds+F[y][j].ds+dis[F[x][i].id][F[y][j].id]);
			}
		}
		cout << ans+w[x]+w[y] << endl;
	}
	return 0;
}
