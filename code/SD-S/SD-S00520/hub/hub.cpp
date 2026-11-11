#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=15;
int c,T,n,k,u,v,vis[N],ans,cnt,vs[N],dis[N][N],minn,maxn;
vector<int> e[N];
void dfs(int u)
{
	vs[u]=1;
	for(int v:e[u])
		if(!vs[v]&&vis[v])
			dfs(v);
	return;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--)
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
		ans=1e18;
		for(int m=0;m<(1<<n);m++)
		{
			if(__builtin_popcount(m)!=k)
				continue;
			for(int i=1;i<=n;i++)
				if((1<<(i-1))&m)
					vis[i]=1;
				else
					vis[i]=0;
			memset(vs,0,sizeof vs);
			cnt=0;
			for(int i=1;i<=n;i++)
				if(vis[i]&&!vs[i])
				{
					cnt++;
					dfs(i);
				}
			if(cnt>2)
				continue;
			memset(dis,0x3f,sizeof dis);
			for(int i=1;i<=n;i++)
				dis[i][i]=0;
			for(int tt=1;tt<=n+2;tt++)
				for(int u=1;u<=n;u++)
					for(int v=1;v<=n;v++)
						for(int to:e[v])
							dis[u][to]=min(dis[u][to],dis[u][v]+1);
			maxn=0;
			for(int u=1;u<=n;u++)
				if(!vs[u])
				{
					minn=1e18;
					for(int v=1;v<=n;v++)
						if(vs[v])
							minn=min(minn,dis[u][v]);
					maxn=max(maxn,minn);
				}
			ans=min(ans,maxn);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
