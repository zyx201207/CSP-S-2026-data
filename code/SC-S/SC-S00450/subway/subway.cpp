#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5,M=5e5+5;

int t;
int n,m,d,q;
int dis[N],vis[N];
int dist[505][M];
int head[N],cnt;
int tot=0;
struct node{
	int u,to,w,next;
}e[N*3];

namespace Flower{
	inline ll read(){
		ll x=0,f=1;char c=getchar();
		while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
		while (c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
		return x*f;
	}
	
	inline void write(ll x){
		if (x<0) {putchar('-');x=-x;}
		if (x>9) write(x/10);
		putchar(x%10+'0');
		return ;
	}
}using namespace Flower;

inline void adde(int u,int v,int w){
	e[++cnt].u=u;
	e[cnt].to=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}

inline void dijkstra(int s){
	for (int i=0;i<=tot;i++)
		dis[i]=0x3f3f3f3f,vis[i]=0;
	typedef pair<int,int> pii;
	priority_queue<pii,vector<pii>,greater<pii> > q;
	dis[s]=0;
	q.push({dis[s],s});
	while (!q.empty()){
		int u=q.top().second;
		q.pop();
		if (vis[u])
			continue;
		vis[u]=1;
		for (int i=head[u];i!=-1;i=e[i].next){
			int v=e[i].to;
			int val=e[i].w;
			if (dis[v]>dis[u]+val){
				dis[v]=dis[u]+val;
				q.push({dis[v],v});
			}
		}
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(head,-1,sizeof head);
	t=read();
	n=read(),m=read(),d=read(),q=read();
	for (int i=1;i<=m;i++){
		int w=read();
		adde(i,i+m,w);
		adde(i+m,i,w);
	}
	for (int i=1;i<=n;i++){
		int k=read();
		for (int j=1;j<=k;j++){
			int su=read(),tim=read();
			adde(su+m,2*m+i,tim);
			adde(2*m+i,su+m,tim);
		}
	}
	tot=2*m+n;
	for (int i=1;i<=n;i++){
		dijkstra(2*m+i);
		for (int j=1;j<=m;j++)
			dist[i][j]=dis[j];
	}
	while (q--){
		int x=read(),y=read();
		int maxx=0x3f3f3f3f;
		for (int i=1;i<=n;i++){
			maxx=min(maxx,dist[i][x]+dist[i][y]);
		}
		write(maxx),puts("");
	}
	return 0;
}