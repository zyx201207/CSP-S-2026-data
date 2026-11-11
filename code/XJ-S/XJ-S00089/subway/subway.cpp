#include <bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q,u,v,w[M],k[N];
long long f[N][N];
vector<pair<int,int>> g[M];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int a,t;
			cin>>a>>t;
			g[a].push_back({i,t});
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++) for(int j=0;j<(int)g[i].size()-1;j++) for(int k=j+1;k<(int)g[i].size();k++)
		f[g[i][j].first][g[i][k].first]=f[g[i][k].first][g[i][j].first]=min(min(f[g[i][k].first][g[i][j].first],f[g[i][j].first][g[i][k].first]),1LL*(g[i][j].second+g[i][k].second));
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--)
	{
		cin>>u>>v;
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(int i=0;i<(int)g[u].size();i++)
		{
			for(int j=0;j<(int)g[v].size();j++)
			{
				ans=min(ans,f[g[u][i].first][g[v][j].first]+w[u]+w[v]+g[u][i].second+g[v][j].second);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
