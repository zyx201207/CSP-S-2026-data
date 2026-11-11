#include<bits/stdc++.h>
#define ll long long
#define pp pair<int,int>
const int N=2e5+1010;
using namespace std;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0')
	{
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
int c,t,n,k,u,v,vis[N],fa[N],dep[N],mx,mi,ans,sum;
int falg;
vector<int> e[N];
int dfs2(int u,int faa)
{
	int op=0,flg=0,cntt=0;
	dep[u]=dep[faa]+1;
	fa[u]=faa;
	for(int v:e[u])
	{
		if(v==faa) continue;
		if(vis[v]) flg=1,cntt++;
		op+=dfs2(v,u);
	}
	if(flg&&vis[u]) return op-cntt+1;
	else if(flg&&!vis[u]) return op;
	else if(!flg&&vis[u]) return op+1;
	else return op;
}
void dfs(int u,int cnt)
{
	if(cnt==k)
	{
		falg=dfs2(1,0);
		if(falg>2) return;
		mx=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]) continue;
			mi=0x3f3f3f3f;
			for(int j=1;j<=n;j++)
			{
				if(!vis[j]) continue;
				sum=0;
				int x,y;
				x=i,y=j;
				if(dep[x]<dep[y]) swap(x,y);
				while(dep[x]>dep[y]) sum++,x=fa[x];
				while(x!=y) sum+=2,x=fa[x],y=fa[y];
				mi=min(mi,sum);
//				if(vis[2]&&vis[4]&&vis[9])cout<<i<<" "<<j<<" "<<sum<<"\n";
			}
			mx=max(mx,mi);
		}
		ans=min(ans,mx);
		return;
	}
	if(u>n) return;
	vis[u]=1;
	dfs(u+1,cnt+1);
	vis[u]=0;
	dfs(u+1,cnt);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		ans=2e9;
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<n;i++) cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
		dfs(1,0);
		cout<<ans<<"\n";
	}
	return 0;
}