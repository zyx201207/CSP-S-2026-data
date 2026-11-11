#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500005],u,v,f[505][505];
vector<pair<int,int> > ve[500005];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>c>>n>>m>>d>>q;memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k,x,t;cin>>k;
		while(k--)
		{
			cin>>x>>t;
			ve[x].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++)
	{
		int l=ve[i].size();pair<int,int> X,Y;
		for(int j=0;j<l;j++)for(int k=0;k<l;k++)
		{
			if(j==k)continue;X=ve[i][j];Y=ve[i][k];
			f[X.first][Y.first]=min(f[X.first][Y.first],X.second+Y.second);
		}
//		for(auto [x,tx]:ve[i])
//		{
//			for(auto [y,ty]:ve[i])
//			{
//				if(x==y)continue;
//				f[x][y]=min(d[x][y],tx+ty);
//			}
//		}
	}
//	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cout<<i<<" "<<j<<" "<<f[i][j]<<"\n";
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j){f[i][j]=0;continue;}
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cout<<i<<" "<<j<<" "<<f[i][j]<<"\n";
	while(q--)
	{
		cin>>u>>v;int ans=1e18;
		int lu=ve[u].size(),lv=ve[v].size();
		for(int i=0;i<lu;i++)
		{
			for(int j=0;j<lv;j++)
			{
				ans=min(ans,ve[u][i].second+ve[v][j].second+f[ve[u][i].first][ve[v][j].first]);
			}
		}
		cout<<ans+w[u]+w[v]<<"\n";
	}
	return 0;
}
//AC???
