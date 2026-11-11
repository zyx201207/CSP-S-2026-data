#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+8;
int c,n,m,d,q,ans,ed;
int w[N],k[N],vis[N],t[N][N],p[N][N];
vector<vector<int>> e(N);

void DFS(int fa,int i)
{
	vis[i]=1;
	ans+=t[fa][i];
	if(i==ed)
	{
		return;
	}
	int u=i;
	for(auto v:e[u])
	{
		if(!vis[v])
		{
			DFS(u,v);
		}
	}
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int u=i,v,w;
			cin>>v>>w;
			e[u].push_back(v);
			e[v].push_back(u);
			t[u][v]=w;
			t[v][u]=w;
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		ed=y;
		ans=w[x]+w[y];
		DFS(x,x);
		cout<<ans<<"\n";
	}
	return 0;
}
