#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#define endl '\n'
using namespace std;
const int N=1e6+5;
bool flag[N];
int c,t,n,k,u,v,ln,cnt,ans,de[N],f[N][25],fa[N];
vector<int> e[N];
void dfs(int u,int fa)
{
	for(int i=0;i<e[u].size();i++)
	{
		int v=e[u][i];
		if(f[u][0]==v)
			continue;
		de[v]=de[u]+1;
		f[v][0]=u;
		dfs(v,u);
	}
}
int lca(int u,int v)
{
	if(de[u]>de[v])
		swap(u,v);
	int y=de[v]-de[u];
	for(int i=0;i<=ln;i++)
		if(y&(1<<i))
			v=f[v][i];
	if(u==v)
		return u;
	for(int i=ln;i>=0;i--)
		if(f[u][i]!=f[v][i])
		{
			u=f[u][i];
			v=f[v][i];
		}
	return f[u][0];
}
int find(int x)
{
	if(fa[x]==x)
		return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void merge(int u,int v)
{
	u=find(u),v=find(v);
	if(u!=v)
		fa[v]=u; 
}
int dist(int x,int y)
{
	return de[x]+de[y]-2*de[lca(x,y)];
}
int calc(bool flag[])
{
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int u=1;u<=n;u++)
	{
		if(!flag[u])
			continue;
		for(int i=0;i<e[u].size();i++)
		{
			int v=e[u][i];
			if(flag[v])
				merge(u,v);
		}
	}
	cnt=0;
	for(int i=1;i<=n;i++)
		if(flag[i]&&fa[i]==i)
			cnt++;
	if(cnt>2)
		return 1e9;
	int maxx=-1;
	for(int i=1;i<=n;i++)
	{
		if(flag[i])
			maxx=max(maxx,0);
		else
		{
			int minn=1e9;
			for(int j=1;j<=n;j++)
			{
				if(flag[j])
					minn=min(minn,dist(i,j));
			}
			maxx=max(maxx,minn);
		}
	}
	return maxx;
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		e[i].clear();
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	de[1]=1;
	dfs(1,-1);
	ln=log2(n);
	for(int j=1;j<=ln;j++)
		for(int i=1;i<=n;i++)
			f[i][j]=f[f[i][j-1]][j-1];
	ans=1e9;
	for(int i=0;i<(1<<n);i++)
	{
		if(__builtin_popcount(i)!=k)
			continue;
		memset(flag,false,sizeof(flag));
		for(int j=0;j<n;j++)
			if(i&(1<<j))
				flag[j+1]=true;
		ans=min(ans,calc(flag));
	}
	cout<<ans<<"\n";
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--)
		solve();
	return 0;
}