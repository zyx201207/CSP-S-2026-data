#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mid ((l+r)>>1)
#define ls (rt*2)
#define rs (rt*2+1)
const int N=15;
const int INF=0x3f3f3f3f;
const int Mod=1e9+7;
int n,k,ans;
vector<int> G[N];
void init()
{
	for(int i=1;i<=n;i++)
	{
		G[i].clear();
	}
	ans=n-1;
	return;
}
bool chs[N];
bool vis[N];
void dfs0(int u,int fa)
{
	vis[u]=true;
	for(auto x:G[u])
	{
		if(!vis[x]&&chs[x])
		{
			dfs0(x,u);
		}
	}
	return;
}
bool check()
{
	int cntt=0;
	for(int i=1;i<=n;i++)vis[i]=false;
	for(int i=1;i<=n;i++)
	{
		if(chs[i]&&(!vis[i]))
		{
			dfs0(i,0);
			cntt++;
			if(cntt>2)return false;
		}
	}
	return true;
}
int dfs(int u,int fa,int dep)
{
	if(chs[u])return dep;
	int res=INF;
	for(auto v:G[u])
	{
		if(v==fa)continue;
		res=min(res,dfs(v,u,dep+1));
	}
	return res;
}
void work(int now,int cs)
{
	if(now==n+1)
	{
		if(cs!=k)return;
		if(check())
		{
			int res=0;
			for(int i=1;i<=n;i++)
			{
				res=max(res,dfs(i,0,0));
			}
			ans=min(ans,res);
		}
		return;
	}
	work(now+1,cs);
	chs[now]=true;
	work(now+1,cs+1);
	chs[now]=false; 
	return;
}
void solve()
{
	cin>>n>>k;
	init();
	for(int i=1;i<n;i++)
	{
		int u,v;cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	work(1,0);
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T;cin>>T>>T;
	while(T--)solve();
	return 0;
}
