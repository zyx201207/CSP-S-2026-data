#include<iostream>
#include<vector>
using namespace std;
const int N=25;
vector<int>g[N];
int vis[N],d[N];
void dfs(int u,int dd)
{
	if(dd>=d[u])return;
	d[u]=dd;
	for(int v:g[u])dfs(v,dd+1);
}
void ATRI()
{
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;++i)g[i].clear();
	for(int i=1,u,v;i<n;++i)cin>>u>>v,g[u].push_back(v),g[v].push_back(u);
	int ans=n;
	for(int s=0;s<1<<n;++s)if(__builtin_popcount(s)==k)
	{
		for(int i=1;i<=n;++i)vis[i]=s>>i-1&1,d[i]=n+1;
		int ct=0,mx=0;
		for(int i=1;i<=n;++i)for(int j:g[i])if(vis[i]&&vis[j]&&i<j)++ct;
		if(ct<k-2)continue;
		for(int i=1;i<=n;++i)if(vis[i])dfs(i,0);
		for(int i=1;i<=n;++i)mx=max(mx,d[i]);
		ans=min(ans,mx);
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,t;cin>>c>>t;while(t--)ATRI();
	return 0;
}