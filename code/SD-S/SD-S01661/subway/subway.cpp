#include<bits/stdc++.h>
using namespace std;
#define N 510010
#define M 1000010
#define LL long long
int c,n,m,d,q,id,tot,w[N],f[N],deg[N],head[N];
LL dis[N];
struct Node{
	int to,nex,val;
}a[M];
struct Heap{
	int x;
	LL val;
};
vector<int> g[N];
vector<Heap> hl[N];
bool operator<(const Heap &a1,const Heap &a2){
	return a1.val>a2.val;
}
inline void add(int u,int v,int w)
{
	a[++tot].to=v;
	a[tot].val=w;
	a[tot].nex=head[u];
	head[u]=tot;
}
inline void bfs(int st)
{
	queue<int> que;
	que.push(st),dis[st]=0,f[st]=st;
	while(!que.empty())
	{
		int tp=que.front();que.pop();
		const int t=hl[tp].size();
		int flag=0;
		for(int i=0;i<t;++i)
		{
			Heap nx=hl[tp][i];
			if(f[nx.x]!=st) continue;
			if(dis[tp]==dis[nx.x]+nx.val)
			{
				flag=1;
				break;
			}
		}
		if(flag) continue;
		hl[tp].push_back((Heap){st,dis[tp]});
		for(int i=head[tp];~i;i=a[i].nex)
		{
			int y=a[i].to;
			if((f[y]!=st)||(dis[y]>dis[tp]+a[i].val))
			{
				dis[y]=dis[tp]+a[i].val;
				f[y]=st,que.push(y);
			}
		}
	}
}
inline void Dijk(int st)
{
	priority_queue<Heap> que;
	que.push((Heap){st,0}),dis[st]=0,f[st]=st;
	while(!que.empty())
	{
		Heap tp=que.top();que.pop();
		if(tp.val!=dis[tp.x]) continue;
		const int t=hl[tp.x].size();
		int flag=0;
		for(int i=0;i<t;++i)
		{
			Heap nx=hl[tp.x][i];
			if(f[nx.x]!=st) continue;
			if(dis[tp.x]==dis[nx.x]+nx.val)
			{
				flag=1;
				break;
			}
		}
		if(flag) continue;
		hl[tp.x].push_back((Heap){st,dis[tp.x]});
		for(int i=head[tp.x];~i;i=a[i].nex)
		{
			int y=a[i].to;
			if((f[y]!=st)||(dis[y]>dis[tp.x]+a[i].val))
			{
				dis[y]=dis[tp.x]+a[i].val;
				f[y]=st,que.push((Heap){y,dis[y]});
			}
		}
	}
}
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
		f=(c=='-')?-1:f,c=getchar();
	while(isdigit(c))
		x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(head,-1,sizeof(head));
	c=read(),n=read(),m=id=read(),d=read(),q=read();
	for(int i=1;i<=m;++i) w[i]=read();
	for(int i=1;i<=n;++i)
	{
		++id;
		int k=read();
		for(int j=1;j<=k;++j)
		{
			int u=read(),v=read();
			add(id,u,v),add(u,id,v);
			++deg[id],++deg[u];
		}
	}
	for(int i=1;i<=id;++i)
		g[deg[i]].push_back(i);
	for(int i=m;i>=1;--i)
	{
		const int t=g[i].size();
		random_shuffle(g[i].begin(),g[i].end());
		for(int j=0;j<t;++j)
		{
			if(c>=16&&c<=19) bfs(g[i][j]);
			else Dijk(g[i][j]);
		}
	}
	int tim=1e9;
	while(q--)
	{
		int u=read(),v=read();
		int t=hl[u].size();
		for(int i=0;i<t;++i)
			f[hl[u][i].x]=tim,dis[hl[u][i].x]=hl[u][i].val;
		t=hl[v].size();
		LL res=4e18;
		for(int i=0;i<t;++i)
			if(f[hl[v][i].x]==tim)
				res=min(res,dis[hl[v][i].x]+hl[v][i].val);
		cout<<res+w[u]+w[v]<<'\n';
		++tim;
	}
	return 0;
}
