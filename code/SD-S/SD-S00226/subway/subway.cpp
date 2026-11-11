#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<queue>
#define ll long long
using namespace std;
const int N=5e5+50,M=505;
const ll inf=1e18;
int w[N],k[M];
vector<int>a[M];
vector<ll>t[M];
int c,n,m,d,q;
ll f[2005][2005];
ll dfs(int l,int r)
{
	if(l>r) return inf;
	if(f[l][r]!=inf) return f[l][r];
	for(int k=l+1;k<r;k++)
		f[l][r]=min(f[l][r],dfs(l,k)+dfs(k,r));
	return f[l][r];
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		int x,y;
		for(int j=1;j<=k[i];j++)
		{
			cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
			f[i][j]=inf;
		f[i][i]=0;
	}
	for(int x=1;x<=m;x++)
		for(int i=0;i<k[x];i++)
			for(int j=0;j<k[x];j++)
			{
				int l=a[x][i],r=a[x][j];
				f[l][r]=min(f[l][r],t[x][i]+t[x][j]);
			}
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		if(u>v) swap(u,v);
		cout<<w[u]+w[v]+dfs(u,v)<<'\n';
	}
	return 0;
}
