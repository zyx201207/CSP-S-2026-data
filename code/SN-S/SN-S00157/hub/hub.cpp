#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

const int N=15;

int c,T,n,k;
int vis[N],f[N][N];
vector<int> g[N];

void clear()
{
	for(int i=1;i<=n;i++)
	{
		vis[i]=0;
		g[i].clear();
		for(int j=1;j<=n;j++)
			f[i][j]=0;
	}
}

void dfs(int x,int u,int fa)
{
	if((x>>(u-1)&1)==0)
		return ;
	vis[u]=1;
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i];
		if(v==fa)
			continue;
		dfs(x,v,u);
	}
}

bool check(int x)
{
	int s=0;
	for(int i=0;i<n;i++)
		if(x>>i&1)
			s++;
	if(s!=k)
		return 0;
	for(int i=1;i<=n;i++)
		vis[i]=0;
	s=0;
	for(int i=1;i<=n;i++)
		if((x>>(i-1)&1)&&(!vis[i]))
		{
			dfs(x,i,0);
			s++;
		}
	if(s>2)
		return 0;
	return 1;
}

void work1()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			f[i][j]=1e9;
		for(int j=0;j<g[i].size();j++)
			f[i][g[i][j]]=f[g[i][j]][i]=1;
		f[i][i]=0;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	int ans=1e9;
	for(int i=0;i<(1<<n);i++)
	{
		if(check(i))
		{
			int res=0;
			for(int u=1;u<=n;u++)
			{
				int sum=1e9;
				for(int v=1;v<=n;v++)
				{
					if((i>>(v-1)&1)==0)
						continue;
					sum=min(sum,f[u][v]);
				}
				res=max(res,sum);
			}
			ans=min(ans,res);
		}
	}
	cout<<ans<<endl;
}

void solve()
{
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(c<=3)
	{
		work1();
	}
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		solve();
		clear();
	}
	return 0;
}
