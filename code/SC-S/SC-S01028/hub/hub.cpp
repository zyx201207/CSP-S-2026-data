#include<bits/stdc++.h>
#define endl "\n"
//#define int long long
using namespace std;
const int N=2e6+9,inf=1e9;
int n,k,U[N],V[N];
bool vis[N];
int dis[600][600];
vector<int> op[600][600];
vector<int> vv[N];
int rt;
void dfs1(int u,int _fa)
{
	for(int v:vv[u])
	{
		if(v==_fa) continue;
		dis[rt][v]=dis[rt][u]+1;
		dfs1(v,u);
	}
}
bool all[N];
void solve()
{
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		vv[u].emplace_back(v);
		vv[v].emplace_back(u);
		U[i]=u;
		V[i]=v;
	}
	for(int i=1;i<=n;i++)
	{
		rt=i;
		dis[i][i]=0;
		dfs1(rt,0);
		for(int j=1;j<=n;j++)
			op[i][dis[i][j]].emplace_back(j);
	}
	int ans=inf;
	for(int i=0;i<(1<<n);i++)
	{
		int res=0;
		for(int j=1;j<=n;j++)
		{
			if(i&(1<<(j-1)))
				vis[j]=1,res++;
			else
				vis[j]=0;
		}
		if(res!=k) continue;
		for(int j=1;j<=n-1;j++)
		{
			if(vis[U[j]] && vis[V[j]])
				res--;
		}
		if(res>2) continue;
//		cout<<114514<<endl;
		for(int j=1;j<=n;j++)
			all[j]=0;
		for(int j=0;j<=n;j++)/*枚举一下长度*/
		{
			for(int kk=1;kk<=n;kk++)
			{
				if((1<<(kk-1))&i)
				for(int v:op[kk][j])
					all[v]=1;
			}
			bool io=1;
			for(int kk=1;kk<=n;kk++)
				io&=all[kk];
			if(io){
				ans=min(ans,j);
				break;
			}
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
	{
		vv[i].clear();
		for(int j=0;j<=n;j++)
			op[i][j].clear();
		
	}
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,T=1;
	cin>>c>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}