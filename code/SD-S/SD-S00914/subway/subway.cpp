#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e6+10,N=1e5+10,Max=1e15+10;
int c,n,m,d,q;
int w[M],head[M],cnt,ans;
int dis[M],f[1501][1501];
bool vis[M];
struct Node{
	int to;
	int w;
	int nxt;
}a[M*20];
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}return x*f;
}
inline void add(int u,int v,int w)
{
	a[++cnt]=(Node){v,w,head[u]};
	head[u]=cnt;
	return;
}
struct node{
	int to;
	int w;
	bool operator<(const node &b)const
	{
		return w>b.w;
	}
};priority_queue<node>qu;
queue<int>qu2;
inline void solve(int s)
{
	
	for(int i=1;i<=m+n;i++)dis[i]=Max,vis[i]=0;
	int u,v,w;dis[s]=0;
	qu.push((node){s,0});
	while(qu.size())
	{
		while(vis[qu.top().to]&&qu.size())qu.pop();
		if(qu.size()==0)break;
		u=qu.top().to;qu.pop();
		vis[u]=1;
		for(int i=head[u];i;i=a[i].nxt)
		{
			v=a[i].to;w=a[i].w;
			if(w+dis[u]<dis[v])
			{
				dis[v]=w+dis[u];
				qu.push((node){v,dis[v]});
			}
		}//cout<<qu.size()<<'\n';
	}
	return;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1,k,x,y;i<=n;i++)
	{
		k=read();
		for(int j=1;j<=k;j++)
		{
			x=read();y=read();
			add(i+m,x,y);
			add(x,i+m,y);
		}
	}
//	if(c<=6)
	{
		for(int i=1;i<=m;i++)
		{
			solve(i);
			for(int j=1;j<=m;j++)
			{
				f[i][j]=dis[j];
			}
		}
		for(int i=1,x,y;i<=q;i++)
		{
			x=read();y=read();
			cout<<w[x]+w[y]+f[x][y]<<'\n';
		}
	}
	return 0;
}
