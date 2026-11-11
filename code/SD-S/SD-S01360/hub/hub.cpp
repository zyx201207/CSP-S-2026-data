#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int,int>
#define pb push_back
const int N=20;
const int P=1e9+7,Inf=1e18;

int n,k;
int dis[N];
bool vis[N];
vector<int> e[N];

void dfs(int u,int fa)
{
//		cout<<u<<endl;
	for(auto v:e[u])
	{
		if(v==fa)continue;
		dis[v]=min(dis[v],dis[u]+1);
		dfs(v,u);
	}
}

void dfs2(int u,int fa)
{
	vis[u]=1;
	for(auto v:e[u])
	{
		if(v==fa||dis[v]!=0)continue;
		dfs2(v,u);
	}
}

bool check()
{
	for(int i=1;i<=n;i++){
		if(dis[i]==0){
			dfs2(i,0);
			break;
		}
	}
	for(int i=1;i<=n;i++)
		if(dis[i]==0&&!vis[i]){
			dfs2(i,0);
			break;
		}
	for(int i=1;i<=n;i++)
		if(dis[i]==0&&!vis[i])return 0;
	return 1;
}

void solve()
{
	int ans=Inf;
	cin>>n>>k;
	for(int i=1;i<=n;i++)e[i].clear();
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		e[u].pb(v);
		e[v].pb(u);
	}
	for(int s=0;s<(1ll<<n);s++)
	{
		int cnt=0;
		for(int i=1;i<=n;i++){
			dis[i]=Inf;
			vis[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			if((1<<(i-1))&s)
			{
				dis[i]=0;
				dfs(i,0);
				cnt++;
			}
		}
		if(!check()||cnt!=k)continue;
		int res=0;
		for(int i=1;i<=n;i++)res=max(res,dis[i]);
		ans=min(ans,res);
	}
	cout<<ans<<'\n';
}

signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)solve();
	return 0;
}


