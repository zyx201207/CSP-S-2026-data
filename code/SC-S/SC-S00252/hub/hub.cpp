#include<bits/stdc++.h>
using namespace std;
const int maxn=15;
vector<int> e[maxn];
int n,k;
int fa[maxn];
bool cs[maxn];
vector<int> us;
int findfa(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=findfa(fa[x]);
}
bool ck()
{
	//if(cs[2]==1&&cs[7]==1&&cs[9]==1) cout<<"tt"<<'\n';
	for(int i=1;i<=n;i++)
	{
		if(cs[i]) fa[i]=i;
		else fa[i]=0;
	}
	vector<int> g;
	g.clear();
	for(int i=1;i<=n;i++) 
	{
		if(!cs[i]) continue;
		for(auto v:e[i])
		{
			if(!cs[v]) continue;
			int x=findfa(v);
			fa[x]=findfa(i);
		}
	}
	for(int i=1;i<=n;i++) 	
	{
		int tt=findfa(i);
        if(tt!=0) g.push_back(tt);
	}
	sort(g.begin(),g.end());
	int tt=unique(g.begin(),g.end())-g.begin();
	//if(cs[2]&cs[7]&cs[9]) cout<<"tt"<<tt<<'\n';
	if(tt>2) return 0;
	return 1;
}
int dfs(int u,int f,int dep)
{
	if(cs[u]) return dep;
	int ans=1000;
	for(auto v:e[u]) if(v!=f) ans=min(ans,dfs(v,u,dep+1));
	return ans;
}
int calc()
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(!cs[i])
		{
			ans=max(ans,dfs(i,0,0));
		}
	}
	return ans;
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		e[u].push_back(v),e[v].push_back(u);
	}
	int ans=10000;
	for(int s=0;s<(1<<n);s++)
	{
		int cnt=0,tmp=s;
		while(tmp) {tmp-=(tmp&(-tmp));cnt++;}
		for(int i=1;i<=n;i++)
		{
			if((1<<(i-1))&s) cs[i]=1;
			else cs[i]=0;
		}
		if(cnt!=k) continue;
		if(!ck()) continue;
		tmp=s;
	    //if(n==5) for(int i=1;i<=n;i++) cout<<cs[i];
		//cout<<'\n';
		ans=min(ans,calc());
	}
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++) e[i].clear();
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--) solve();
	return 0;
}