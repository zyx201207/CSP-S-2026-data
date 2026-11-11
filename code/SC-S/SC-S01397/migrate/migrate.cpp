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
	if(x==0)putchar('0');
	if(x<0)x=-x,putchar('-');
	int p=0;
	while(x)buf[++p]=x%10,x/=10;
	for(int i=p;i>=1;i--)putchar(buf[i]+'0');
	if(f)putchar(ac);
}
int c,n,d;
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
void dij(int s)
{
	for(int i=0;i<=n;i++)dis[i]=inf,vis[i]=0,p[i]=0;
	while(!pq.empty())pq.pop();
	pq.push({0,s}),dis[s]=0,p[s]=1;
	while(!pq.empty())
	{
		int u=pq.top().id;pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].to,w=e[i].w;
			if(dis[v]>dis[u]+w)dis[v]=dis[u]+w,pq.push({dis[v],v}),p[v]=p[u];
			else if(dis[v]==dis[u]+w)p[v]+=p[u];
		}
	}
}
int x[maxn];
void solve()
{
	n=read(),d=read(),cnt=0;
	for(int i=1;i<=n;i++)x[i]=read(),head[i]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(i!=j&&abs(x[i]-x[j])<=d)add(i,j,1),add(j,i,1);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		dij(i);
//		for(int j=1;j<=n;j++)write(p[j],' ',1),write(dis[j],'\n',1);
		for(int j=i;j<=n;j++)
		{
			if(p[j]==2)ans++;
		}
//		putchar('\n');
	}
	write(ans,'\n',1);
//	putchar('\n');
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	int t=read();
	while(t--)solve();
	return 0;
}