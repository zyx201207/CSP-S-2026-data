#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define fi first
#define se second
using namespace std;
const int N=2e5+10;
const int inf=0x3f3f3f3f3f3f3f3f;
int c,T;
int n,k;
vector<int> G[N];
bool g[20][20];
bool fl[N];
int dis[N],dep[N];
void dfs(int u,int fa)
{
	dep[u]=dep[fa]+1;
	if(fl[u]) dis[u]=0;
	else dis[u]=min(dis[u],dep[u]-1);
	for(auto v:G[u])
	{
		if(v==fa) continue;
		dfs(v,u); 
	}
}
void solve1()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) G[i].clear();
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) g[i][j]=0;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		G[u].push_back(v),G[v].push_back(u),g[u][v]=g[v][u]=1;
	}
	int ans=inf;
	for(int st=0;st<(1<<n);st++)
	{
		if(__builtin_popcount(st)!=k) continue;
		for(int j=1;j<=n;j++)
		{
			dis[j]=inf;
			if(st&(1<<(j-1))) fl[j]=1;
			else fl[j]=0;
		}
		int num=0;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(fl[i]&&fl[j]) num+=g[i][j];
		num/=2;
		if(num<k-2) continue;
		for(int i=1;i<=n;i++) if(fl[i]) dfs(i,0);
		int res=0;
		for(int i=1;i<=n;i++) res=max(res,dis[i]);
		ans=min(ans,res);
	}
	cout<<ans<<endl;
}
void solve2()
{
	cout<<0<<endl; 
}
void solve3()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) G[i].clear();
	for(int i=1;i<=n;i++)
	{
		int u,v;
		cin>>u>>v;
		G[u].push_back(v),G[v].push_back(u);
	}
	if(n==k)
	{
		cout<<0<<endl;
		return ;
	}
	if(k>=n/2)
	{
		cout<<1<<endl;
		return ;
	}
	int t=n/2+3;
	int ans=(t-k)/4+1;
	cout<<ans<<endl; 
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>c>>T;
	while(T--)
	{
		if(c<=3) solve1();
		else if(c==7) solve2();
		else if(c==13||c==14) solve3();
		else solve1();
	}
	return 0;
}
