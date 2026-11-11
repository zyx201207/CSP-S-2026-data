#include<bits/stdc++.h>
#define ll long long
#define N 1500005
#define M 3000005
using namespace std;
template<typename T>
inline void read(T &s){
	int f=1;
	char ch=getchar();
	s=0;
	while(!isdigit(ch)){
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=s*10+ch-'0';
		ch=getchar();
	}
	s*=f;
}
typedef struct node
{
	int v;
	ll w;
	bool operator < (const struct node &t) const
	{
		return w>t.w;
	}
}NODE;
priority_queue<NODE> pq;

int c,n,m,d,q;
int k[505];
int nxt[M],to[M],head[N],tot;
ll wei[M],W[500005];
ll dist[N];
int vis[N];

inline void add_edge(int u,int v,ll w){
	nxt[++tot]=head[u];
	to[tot]=v;
	wei[tot]=w;
	head[u]=tot;
}
void dijkstra(int index,int my_goal,int cur)
{
	while(!pq.empty())
		pq.pop();
	NODE tmp,tmp1;
	tmp.v=index; tmp.w=0;
	pq.push(tmp);
	while(!pq.empty())
	{
		tmp=pq.top();
		pq.pop();
		if(vis[tmp.v]>=cur)
			continue;
		vis[tmp.v]=cur;
		dist[tmp.v]=tmp.w;
		if(tmp.v==my_goal)
			break;
		for(int i=head[tmp.v];i;i=nxt[i])
		{
			tmp1.v=to[i]; tmp1.w=dist[tmp.v]+wei[i];
			if(vis[to[i]]>=cur)
				continue;
			pq.push(tmp1);
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(c); read(n); read(m); read(d); read(q);
	ll w;
	int v;
	for(int i=1;i<=m;++i){
		read(W[i]);
	}
	for(int i=1;i<=n;++i){
		read(k[i]);
		for(int j=1;j<=k[i];++j){
			read(v); read(w);
			add_edge(v,i+m,w);
			add_edge(i+m,v,w);
		}
	}
	for(int x,y,i=1;i<=q;++i)
	{
		read(x); read(y);
		dijkstra(x,y,i);
		printf("%lld\n",dist[y]+W[x]+W[y]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
