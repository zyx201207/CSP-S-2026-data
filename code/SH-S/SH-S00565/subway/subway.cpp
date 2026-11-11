#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x;
}
void print(int x){if(x>9) print(x/10);putchar(x%10+'0');}
struct node
{
	int v,w;
	bool operator<(node x) const{return x.w<w;}
};
int c,n,m,d,q,minn,num,ans,w[500010],a[500010],t[500010],dis[500010],vis[500010],b[3][500010],fl[3][500010];
vector<node> edges[500010];
priority_queue<node> pq;
void dijkstra(int s)
{
	for(int i=1;i<=m;i++) vis[i]=0,dis[i]=4e18;
	pq.push({s,0}),dis[s]=0;
	while(!pq.empty())
	{
		node t=pq.top();pq.pop();int u=t.v,ww=t.w;
		if(vis[u]) continue;vis[u]=1;
		for(node x:edges[u])
			if(dis[x.v]>x.w+ww)
				dis[x.v]=x.w+ww,pq.push({x.v,x.w+ww});
	}
}
signed main()//52pts
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	if(n==1)
	{
		for(int i=1,k,x;i<=n;i++)
		{
			k=read();
			for(int j=1;j<=k;j++) x=read(),t[x]=read();
		}
		for(int i=1,x,y;i<=q;i++) x=read(),y=read(),cout<<w[x]+w[y]+t[x]+t[y]<<'\n';
		return 0;
	}
	if(n==2)
	{
		minn=4e18;
		for(int i=1,k,x;i<=n;i++)
		{
			k=read();
			for(int j=1;j<=k;j++) x=read(),b[i][x]=read(),fl[i][x]=1;
		}
		for(int i=1;i<=m;i++)
			if(fl[1][i]&&fl[2][i]&&minn>b[1][i]+b[2][i])
				minn=b[1][i]+b[2][i],num=i;
		for(int i=1,x,y;i<=q;i++)
		{
			x=read(),y=read(),ans=4e18;
			if(fl[1][x]&&fl[1][y]) ans=min(ans,b[1][x]+b[1][y]);
			if(fl[2][x]&&fl[2][y]) ans=min(ans,b[2][x]+b[2][y]);
			if(fl[1][x]&&fl[2][y]) ans=min(ans,minn+b[1][x]+b[2][y]);
			if(fl[2][x]&&fl[1][y]) ans=min(ans,minn+b[2][x]+b[1][y]);
			cout<<ans+w[x]+w[y]<<'\n';
		}
		return 0;
	}
	for(int i=1,k;i<=n;i++)
	{
		k=read();
		for(int j=1;j<=k;j++) a[j]=read(),t[j]=read();
		for(int j=1;j<k;j++)
			for(int p=j+1;p<=k;p++)
				edges[a[j]].push_back({a[p],t[j]+t[p]}),edges[a[p]].push_back({a[j],t[p]+t[j]});
	}
	for(int i=1,x,y;i<=q;i++) x=read(),y=read(),dijkstra(x),print(dis[y]+w[x]+w[y]),putchar('\n');
}
