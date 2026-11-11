#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>

using namespace std;
const int INF=0x3f3f3f3f;
int n,k,c,t,jd[25],dep[25],f[25][5];
bool vis[20],vis2[25];
vector<int>e[25];
void dfs(int u)
{
	vis[u]=0;
	for(auto p:e[u])
		if(vis[p])
		{
			dfs(p);
		} 
}
void dfs2(int u,int fa)
{
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	for(int i=1;i<=5;i++)f[u][i]=f[f[u][i-1]][i-1];
	for(auto p:e[u])
	{
		if(p==fa)continue;
		dfs2(p,u);
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int i=5;i>=0;i--)
		if(dep[f[x][i]]>=dep[y])
			x=f[x][i];
	if(x==y)return x;
	for(int i=5;i>=0;i--)
		if(f[x][i]!=f[y][i])
			x=f[x][i],y=f[y][i];
	return f[x][0];
}
int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	cout.tie(nullptr);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(c<=3)
	{
		while(t--)
		{
			int ans=0;memset(f,0,sizeof f);
			memset(dep,0,sizeof dep);
			for(int i=1;i<=n;i++)
			{
				e[i].clear();
			}
			cin>>n>>k;
			for(int i=1;i<n;i++)
			{
				int u,v;
				cin>>u>>v;
				e[u].pb(v);
				e[v].pb(u);
			}
			for(int i=0;i<(1<<n);i++)
			{
				for(int j=0;j<=n;j++)vis[j]=vis2[j]=0;
				int opt=i,cnt=0,kk=0;
				while(opt)
				{
					if(opt&1)cnt++,vis[kk+1]=vis2[kk+1]=1,jd[cnt]=kk+1;
					kk++;
					opt>>=1;
				}
				if(cnt!=k)continue;
				int cnt2=0;bool f=0;
				for(int j=1;j<=n;j++)
				{
					if(vis[j])
					{
						if(cnt2==2)
						{
							f=1;
							break;
						}
						dfs(j);
						cnt2++;
					}
				}
				if(f)continue;dfs2(1,0);
				int mi=INF;
				for(int l=1;l<=n;l++)
				{
					mi=INF;
					for(int r=1;r<=n;r++)
					{
						if(l==r)continue;
						if(vis2[l])
						{
							mi=0;
							break;
						}
					//	cout<<1<<'\n';
						if(lca(l,r)==l||lca(l,r)==r)
						{
							int x=abs(dep[l]-dep[r]);
							mi=min(mi,x);
						}
						else
						{
							int x=dep[l]+dep[r]-2*dep[lca(l,r)];
							mi=min(mi,x);
						}
					}
					ans=max(ans,mi);
				}
			}
			cout<<ans<<'\n';
		}
	}
	else
	{
		while(t--)
		{
			cin>>n>>k;
			cout<<(n+1-2ll*k)/8ll+1<<'\n';
		}
	}
	
	return 0;
}
