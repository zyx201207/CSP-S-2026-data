#include<bits/stdc++.h>
using namespace std;
const int N=15;
int c,T,n,k;
int z[N],ans;
int dep[N],dis[N][N];
bool adj[N][N];
void chk()
{
	int cnt=0;
	for(int i=1;i<=k;i++)
		for(int j=1;j<i;j++)
			if(adj[z[j]][z[i]])cnt++;
	if(k-cnt>2)return;
	int mx=0,D;
	for(int i=1;i<=n;i++)
	{
		D=n;
		for(int j=1;j<=k;j++)
			D=min(D,dis[i][z[j]]);
		mx=max(mx,D);
	}
	ans=min(ans,mx);
}
void dfsZ(int d)
{
	if(d>k)
	{
		chk();
		return;
	}
	for(int i=z[d-1]+1;i<=n;i++)
	{
		z[d]=i;
		dfsZ(d+1);
	}
}
void dfsD(int x,int f,int rt)
{
	dep[x]=dep[f]+1;
	dis[rt][x]=dep[x]-1;
	for(int i=1;i<=n;i++)
		if(adj[x][i]&&i!=f)dfsD(i,x,rt);
}
void solve()
{
	memset(adj,0,sizeof(adj));
	cin>>n>>k;
	ans=n;
	for(int i=1;i<=n;i++)
		dis[i][i]=0;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u][v]=adj[v][u]=1;
	}
	for(int i=1;i<=n;i++)
		dfsD(i,0,i);
	dfsZ(1);
	cout<<ans<<'\n';
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--)solve();
	return 0;
}
