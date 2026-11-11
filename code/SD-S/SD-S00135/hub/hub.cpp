#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,INF=0x3f3f3f3f;
int n,k;
vector<int> g[N];
bool flag[N];
int ans;
int dfs2(int x,int fa)
{
	if(flag[x]) return 0;
	int res=INF;
	for(int v:g[x])
	{
		if(v==fa) continue;
		res=min(res,dfs2(v,x));
	}	
	return res+1;
}
void dfs1(int x,int cnt)
{
	if(x==n+1)
	{
		if(cnt!=k) return ;
		int res=0;
		for(int i=1;i<=n;i++) res=max(res,dfs2(i,0));
		ans=min(ans,res);
		return ;
	}
	if(cnt+1<=k) flag[x]=true,dfs1(x+1,cnt+1);
	flag[x]=false,dfs1(x+1,cnt); 
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
	ans=INF;
	dfs1(1,0);
	cout<<ans<<endl;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--) solve();
	return 0;
 }

