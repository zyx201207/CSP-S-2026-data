#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=510,M=510,INF=0x3f3f3f3f3f3f3f3f;
ll w[M],k[N],f[M][M];
struct node
{
	ll to,t;
};
vector <node> G[N];
ll c,n,m,d,q;

void solve()
{
	ll x,y;
	cin >> x >> y;
	cout << w[x]+f[x][y]+w[y] << "\n";
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	
	for (int i=1;i<=m;i++) cin >> w[i];
	ll to,t;
	for (int i=1;i<=n;i++)
	{
		cin >> k[i];
		for (int j=1;j<=k[i];j++)
		{
			cin >> to >> t;
			G[i].push_back({to,t});
		}
	}
	
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=m;j++)
		{
			f[i][j]=INF;
			if (i==j) f[i][j]=0;
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<k[i];j++)
		{
			for (int c=j+1;c<k[i];c++)
			{
				int u=G[i][j].to,v=G[i][c].to;
				f[u][v]=f[v][u]=min(f[u][v],G[i][j].t+G[i][c].t);
			}
		}
	}
	for (int k=1;k<=m;k++)
	{
		for (int i=1;i<=m;i++)
		{
			for (int j=1;j<=m;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		}
	}
	
	while (q--) solve();
	return 0;
}

