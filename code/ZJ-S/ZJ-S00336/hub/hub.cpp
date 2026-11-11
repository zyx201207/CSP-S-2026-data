#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read()
{
	ll f=1,x=0;char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return f*x;
}
int c,T;
int n,k,i;
struct Edge{
	int to,next;
}edge[2000005];
int head[1000005],cnt;
int fa[1000005];
void add(int x,int y)
{
	edge[++cnt]={y,head[x]};
	head[x]=cnt;
}
int count1(int x)
{
	int sum=0;
	while(x!=0)
	{
		sum+=x&1;
		x>>=1;
	}
	return sum;
}
bool vis[2000005];
bool pd(int x,int y)
{
	return (x>>(y-1))&1;
}
int s;
void dfs2(int u)
{
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(pd(s,v)&&!vis[v])
		{
			vis[v]=1;
			dfs2(v);
		}
	}
}
bool check()
{//检查s是不是最多两个联通块 
	memset(vis,0,sizeof(vis));
	int sum=0;
	for(i=1;i<=n;i++)
	{
		if(!pd(s,i))continue;
		if(!vis[i])dfs2(i),sum++;
	}
	return sum<=2;
}
void dfs(int u,int f)
{
	fa[u]=f;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v==f)continue;
		dfs(v,u);
	}
}
int ans,dis[2000005];
struct node{
	int u,dis;
}tmp;
queue<node>q;
int r()
{
	int sum=0;
	while(q.size())q.pop();
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	for(i=1;i<=n;i++)
		if(pd(s,i))
			q.push({i,0}),dis[i]=0;
	while(q.size())
	{
		tmp=q.front();q.pop();
		int u=tmp.u,dis_=tmp.dis;
		if(dis_>dis[u])continue;
		for(int i=head[u];i;i=edge[i].next)
		{
			int v=edge[i].to;
			if(dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				q.push({v,dis[v]});
			}
		}
	}
	for(i=1;i<=n;i++)
		sum=max(sum,dis[i]);
	return sum;
}
void solve()
{
	memset(head,0,sizeof(head));
	memset(fa,0,sizeof(fa));
	cnt=0;ans=2e9;
	n=read();k=read();
	for(i=1;i<n;i++)
	{
		int x=read(),y=read();
		add(x,y);
		add(y,x); 
	}
	dfs(1,0);
	if(n>20)return (void)puts("CCF I LOVE YOU");
	for(s=0;s<(1<<n);s++)
	{
		if(count1(s)!=k)
			continue;
		if(!check())
			continue;
		int R=r();
		ans=min(R,ans);
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();T=read();
	while(T--)
		solve();
	return 0;
}
/*
CCF求求了qwq
我要S1= pls
张锦峰老师，我还记得你
免责申明：该人名为cxslzx上一届毕业生
0 2
5 2
1 2
2 3
3 4
4 5
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
//freopen
//freopen
我要上人类迷惑行为大赏
酸酸甜甜! 
*/
