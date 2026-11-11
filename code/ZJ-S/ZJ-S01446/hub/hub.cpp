#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
int c,t,n,k,x,y,mn,ans,dep[1000005];
vector<int> v[1000005];
bool b[1000005],vis[1000005];
void work(int u)
{
	vis[u]=true;
	for(int i=0;i<v[u].size();++i)
	{
		int d=v[u][i];
		if(vis[d]) continue;
		if(!b[d]) continue;
		work(d);
	}
}
void query(int u,int sum)
{
	vis[u]=true;
	if(b[u])
	{
		mn=min(mn,sum);
		return;
	}
	for(int i=0;i<v[u].size();++i)
	{
		int d=v[u][i];
		if(vis[d]) continue;
		query(d,sum+1);
	}
}
void check()
{
	for(int i=1;i<=n;++i)
		vis[i]=false;
	int cnt=0;
	for(int i=1;i<=n;++i)
		if((b[i])&&(!vis[i]))
		{
			cnt++;
			work(i);
		}
	if(cnt<=2)
	{
		int mx=0;
		for(int i=1;i<=n;++i)
		{
			mn=inf;
			for(int j=1;j<=n;++j)
				vis[j]=false;
			query(i,0);
			mx=max(mx,mn);
		}	
		ans=min(ans,mx);
	}
}
void dfs(int d,int sum)
{
	if(d==n+1){
		if(sum==k)
		{
			check();
		}
		return;
	}
	b[d]=false;
	dfs(d+1,sum);
	b[d]=true;
	dfs(d+1,sum+1);
	b[d]=false;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;++i)
		{
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		ans=inf;
		dfs(1,0);
		cout<<ans<<"\n";
	}
	return 0;
}
