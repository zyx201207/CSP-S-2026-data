#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=105;
int c,t,n,k,cnt,ans,h[N],vis[N],a[N],d[N],f[N][N];
struct E
{
	int ne,to;	
}e[2*N];
void add(int u,int v)
{
	cnt++;
	e[cnt].ne=h[u];
	e[cnt].to=v;
	f[u][v]=1;
	h[u]=cnt;
}
void dfs(int u)
{
	vis[u]=2;
	for(int i=h[u];i;i=e[i].ne)
	{
		int v=e[i].to;
		if(vis[v]==1) dfs(v);
	}
}
void F(int x,int y)
{
	if(x>n)
	{
		int tot=0,now=0;
		if(y!=k) return;
		for(int i=1;i<=k;i++) vis[a[i]]=1;
		for(int i=1;i<=k;i++) if(vis[a[i]]==1) dfs(a[i]),tot++;
		if(tot>2) return;
		for(int i=1;i<=n;i++)
		{
			d[i]=1e9;
			for(int j=1;j<=k;j++) d[i]=min(d[i],f[i][a[j]]);
			now=max(now,d[i]);
		}
		for(int i=1;i<=k;i++) vis[a[i]]=1;
		ans=min(ans,now);
		return;
	}
	F(x+1,y);
	if(y<k)
	{
		vis[x]=1;
		a[y+1]=x;
		F(x+1,y+1);
		vis[x]=0;
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		memset(h,0,sizeof(h));
		cnt=0,ans=1e9;
		cin>>n>>k;
		memset(f,0x3f,sizeof(f));
		for(int i=1;i<=n;i++) f[i][i]=0; 
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			add(u,v);
			add(v,u);
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
		F(0,0);
		cout<<ans<<endl;
	}
	return 0;	
} 
