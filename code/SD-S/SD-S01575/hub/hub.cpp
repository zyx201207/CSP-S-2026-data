#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<=b;i++)
#define eb emplace_back
const int N=1e6+5;
int c;
int n,k,a[N],ans,d[N];
vector<int>G[N];
bool in[N],vis[N];
void dfs3(int u,int fa)
{
	vis[u]=true;
	for(auto v:G[u])
	{
		if(v==fa)continue;
		if(in[v])dfs3(v,u);
	}
}
bool check()
{
	int cnt=0;
	For(i,1,n)vis[i]=0;
	For(i,1,n)in[i]=0;
	For(i,1,k)in[a[i]]=1;
	For(i,1,k)
	{
		if(!vis[a[i]])
		{
			dfs3(a[i],0);
			cnt++;
		}
	}
	return cnt<=2;
}
void dfs2(int u,int fa)
{
	d[u]=min(d[u],d[fa]+1);
	for(auto v:G[u])
	{
		if(v==fa)continue;
		dfs2(v,u);
	}
}
void get()
{
	int res=0;
	if(check())
	{
		//For(i,1,k)cout<<a[i]<<' ';
		//cout<<endl;
		For(i,1,n)d[i]=INT_MAX;
		For(i,1,k)d[a[i]]=0,dfs2(a[i],0);
		For(i,1,n)res=max(res,d[i]);
		ans=min(ans,res);
	}
}
void dfs(int x,int cnt)
{
	if(cnt==k)
	{
		get();
		return  ;
	}
	if(x==n+1)return ;
	a[++cnt]=x;
	dfs(x+1,cnt);
	a[cnt--]=0;
	dfs(x+1,cnt);
}
void solve()
{
	cin>>n>>k;
	For(i,1,n)G[i].clear();
	For(i,1,n-1)
	{
		int u,v;
		cin>>u>>v;
		G[u].eb(v);
		G[v].eb(u);
	}
	ans=INT_MAX;
	dfs(1,0);
	cout<<ans<<'\n';
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T=1;
	cin>>c>>T;
	while(T--)solve();
	return 0;
}


