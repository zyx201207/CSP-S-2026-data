#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define maxn 1000005
#define SIZE 1<<14
#define inf 0x7f7f7f7f7f7f7f7f
using namespace std;
int read()
{
	int x=0,f=1,ac=getchar();
	if(ac=='-')f=-1;
	while(!isdigit(ac)){if(ac=='-')f=-1;ac=getchar();}
	while(isdigit(ac)){x=x*10+ac-'0',ac=getchar();}
	return x*f;
}
int buf[SIZE];
void write(int x,char ac,int f)
{
	if(x==0){putchar('0');return;}
	if(x<0)x=-x,putchar('-');
	int p=0;
	while(x)buf[++p]=x%10,x/=10;
	for(int i=p;i>=1;i--)putchar(buf[i]+'0');
	if(f)putchar(ac);
}
int c,n,m,d,q;
int w[505],t[25][505];
int get(int x,int y){return x+y*m;}
struct awa{
	int to,nxt,w;
}e[maxn];
int head[maxn],cnt=0;
void add(int u,int v,int w)
{
	e[++cnt]={v,head[u],w};
	head[u]=cnt;
}
struct qwq{
	int w,id;
	bool operator<(const qwq&o)const{
		return w>o.w;
	}
};
int p[maxn],u[maxn];
priority_queue<qwq>pq;
int dis[maxn],vis[maxn];
int diss[505][505];
void dij(int s)
{
	for(int i=1;i<=m+n;i++)dis[i]=inf,vis[i]=0;
	while(!pq.empty())pq.pop();
	pq.push({0,s}),dis[s]=0;
	while(!pq.empty())
	{
		int u=pq.top().id;pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].to,w=e[i].w;
			if(dis[v]>dis[u]+w)dis[v]=dis[u]+w,pq.push({dis[v],v});
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++)
	{
		int k=read();
		for(int j=1;j<=k;j++)
		{
			u[j]=read(),p[u[j]]++;
			int w=read();
//			add(u[j],get(u[j],p[u[j]]),w);
//			add(get(u[j],p[u[j]]),u[j],w);
			add(i+m,u[j],w),add(u[j],i+m,w);
		}
//		for(int j=2;j<=k;j++)
//		{
//			add(get(u[j-1],p[u[j-1]]),get(u[j],p[u[j]]),0);
//			add(get(u[j],p[u[j]]),get(p[u[j-1]],u[j-1]),0);
//		}
	}
	for(int i=1;i<=n;i++)
	{
		dij(i+m);
		for(int j=1;j<=n;j++)diss[i][j]=dis[j+m];
	}
	for(int i=1;i<=q;i++)
	{
		int u=read(),v=read();
		int ans=inf;
		for(int i=head[u];i;i=e[i].nxt)
		{
			int vu=e[i].to,wu=e[i].w;
			if(vu<=m)continue;
			for(int j=head[v];j;j=e[j].nxt)
			{
				int vv=e[j].to,wv=e[j].w;
				if(vv<=m)continue;
				ans=min(ans,diss[vu-m][vv-m]+wu+wv+w[u]+w[v]);
			}
		}
		write(ans,'\n',1);
	}
	return 0;
}