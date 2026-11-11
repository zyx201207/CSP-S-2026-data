#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=512;
int dep[N],cnt[N][N],siz[N],n;
vector<int>g[N];
void dfs(int u,int fa)
{
	dep[u]=dep[fa]+1;
	for(int i=dep[u];i<=n;i++)cnt[u][i]=1;
	siz[u]=1;
	for(int v:g[u])
	{
		if(v==fa)continue;
		dfs(v,u);
		siz[u]+=siz[v];
		for(int i=dep[u]+1;i<=n;i++)cnt[u][i]+=cnt[v][i];
	}
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--)
	{
		int K,ans=-1;cin>>n>>K;
		for(int i=1;i<=n;i++)
		{
			g[i].clear();
			for(int j=1;j<=n;j++)cnt[i][j]=0;
		}
		for(int i=1,u,v;i<n;i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);
		for(int j=0;j<=n;j++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int k=(j+1)/2;k<=j;k++)
				{
					int sum=0,res=0;
					for(int v:g[i])sum+=cnt[v][dep[v]+j-k-1];
					for(int v:g[i])res=max(res,sum-cnt[v][dep[v]+j-k-1]+cnt[v][dep[v]+k-1]);
//					cout<<i<<" "<<j<<" "<<k<<" "<<res+1<<"\n";
					if(res+1>=K)
					{
						ans=j;
						break;
					}
				}
				if(ans!=-1)break;
			}
			if(ans!=-1)break;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 1
5 2
1 2
2 3
3 4
4 5

0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

0 1
6 5
1 2
2 5
4 5
5 3
3 6
*/