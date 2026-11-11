#include<bits/stdc++.h>
#define pb push_back
#define endl '\n'
using namespace std;
const int MAXN=105;
int c,t;
int n,k,ans;
vector<int> G[MAXN];

int dep[MAXN],f[MAXN];

bool vis[MAXN];

int fa[MAXN];
int fd(int x){return fa[x]==x?x:fa[x]=fd(fa[x]);}

void dfs1(int u,int fa)
{
	dep[u]=dep[fa]+1;
	f[u]=fa;
	for(int v:G[u]) if(v!=fa) dfs1(v,u);
}

int lca(int u,int v)
{
	if(dep[u]<dep[v]) swap(u,v);
	while(dep[f[u]]>=dep[v]) u=f[u];
	if(u==v) return u;
	while(f[u]!=f[v]) u=f[u],v=f[v];
	return f[u];
}

int dis(int u,int v)
{
	int l=lca(u,v);
	return dep[u]+dep[v]-2*dep[l];
}

void dfs(int u,int cnt)
{
	if(u>n)
	{
		if(cnt==k)
		{
			for(int i=1;i<=n;i++) fa[i]=i;
			for(int i=1;i<=n;i++) if(vis[i])
			{
//				cout<<i<<endl;
				for(int v:G[i]) 
				{
//					cout<<v<<" ";	
					if(vis[v]) 
					{
						int a=fd(i),b=fd(v);
//						cout<<"bing"<<i<<" "<<v<<endl;
						if(a!=b) fa[a]=b; 
					}
//					cout<<endl;
				}
			}
				
			int g=0;
			for(int i=1;i<=n;i++) if(vis[i]&&fa[i]==i) g++;
			
			
//				cout<<"dfssfdf"<<endl;
//				for(int i=1;i<=n;i++) if(vis[i]) cout<<i<<" ";
//				cout<<endl;
//				cout<<g<<endl;
			if(g<=2)
			{
//				cout<<"dfssfdf"<<endl;
//				for(int i=1;i<=n;i++) if(vis[i]) cout<<i<<" ";
//				cout<<endl;
				
				int r=0;
				for(int i=1;i<=n;i++)
				{
					int dd=n+1,sdfsdf=0;
					for(int j=1;j<=n;j++) if(vis[j]) 
					dd=min(dd,dis(i,j)),sdfsdf++;
					
					if(sdfsdf==1) dd=0;
					r=max(r,dd);
				}
//				cout<<r<<endl;
				ans=min(r,ans);
			}
		}
		return ;
	}
	vis[u]=0; dfs(u+1,cnt);
	vis[u]=1; dfs(u+1,cnt+1);
}

void solve()
{
	cin>>n>>k; ans=n+1;
	for(int i=1;i<=n;i++) vis[i]=0,G[i].clear();
	for(int i=1,u,v;i<n;i++)
	{
		cin>>u>>v;
		G[u].pb(v),G[v].pb(u);
	}
	
	
//	for(int d:G[7]) cout<<"dfsdf"<<d<<endl;
	dfs1(1,0);
//	cout<<"dsfdfs"<<dis(1,3)<<endl;
	dfs(1,0);
	cout<<ans<<endl;
}

int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	for(cin>>c>>t;t--;) solve();
	return 0;
}

/*
只能写暴力了 

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

5 2
1 2
2 3
3 4
4 5


*/
