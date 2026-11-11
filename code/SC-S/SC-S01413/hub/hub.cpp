#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
struct Edge{
	int to,nxt;
}edge[N*2];
int h[N],cnt=1;
void add(int u,int v)
{
	edge[cnt]={v,h[u]};
	h[u]=cnt++;
}
int dis[N];
void dfs2(int u,int fa)
{
	for(int i=h[u];i;i=edge[i].nxt)
	{
		int to=edge[i].to;
		if(to==fa||dis[to]<dis[u]+1) continue;
		dis[to]=dis[u]+1;
		dfs2(to,u);
	}
}
int jihe[N];
int dfs(int now,int yixuan,int k,int n)
{
	if(yixuan==k)
	{
		int ans=0;
		dis[jihe[1]]=dis[jihe[2]]=0;
		dfs2(jihe[1],0);
		dfs2(jihe[2],0);
		for(int i=1;i<=n;i++)
			if(jihe[1]!=i&&jihe[2]!=i) ans=max(ans,dis[i]);
		return ans;
	}
	jihe[++yixuan]=now;
	dfs(now+1,yixuan,k,n);
	yixuan--;
	dfs(now+1,yixuan,k,n);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		memset(dis,0x3f3f3f3f,sizeof dis);
		memset(jihe,0,sizeof jihe);
		cnt=1;
		int n,k,ans=1e9;
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			add(u,v),add(v,u);
		}
		ans=min(ans,dfs(1,0,k,n));
		cout<<ans<<endl;
	}
	return 0;
}