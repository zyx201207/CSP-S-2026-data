#include<bits/stdc++.h>
using namespace std;
#define M 500005
#define N 505
typedef pair<int,int> pii;
int c,n,m,d,q,w[M];
vector<pii> ts[M];
long long bl[N][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	int k,a,t;
	for(int i=1;i<=n;++i)
	{
		cin>>k;
		for(int j=1;j<=k;++j)
		{
			cin>>a>>t;
			ts[a].push_back(make_pair(i,t));
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j) if(j!=i)
			bl[i][j]=1e18;
	for(int i=1;i<=m;++i)
		for(pii x:ts[i])
			for(pii y:ts[i])
			{
				int u=x.first,v=y.first,t1=x.second,t2=y.second;
				bl[u][v]=bl[v][u]=min(bl[v][u],(long long)(t1)+t2);
			}
	for(int i=1;i<=n;++i)
		for(int u=1;u<=n;++u)
			for(int v=1;v<=n;++v)
				bl[u][v]=min(bl[u][v],bl[u][i]+bl[i][v]);
	int u,v;
//	cout<<q<<'\n';
	for(int i=1;i<=q;++i)
	{
		long long ans=1e18;
		cin>>u>>v;
		for(pii x:ts[u])
			for(pii y:ts[v])
				ans=min(ans,bl[x.first][y.first]+x.second+y.second);
		cout<<w[u]+w[v]+ans<<'\n';
	}
	cout.flush();
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
