#include<bits/stdc++.h>
using namespace std;
#define MAXN 10020
int ccc,n,m,d,T,w[MAXN],k[MAXN];
// 0վ̨,1~nվ̨,n+1~2nվ�� 

inline void read(int& x){
	char ch=getchar();int f=1;x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+(ch^48);
	x*=f;
}

struct edge{
	int to,cost;
	edge(int _t=0,int _c=0):to(_t),cost(_c){}
	const bool operator<(const edge& o)const{
		return cost>o.cost;
	}
};
vector<edge> g[MAXN],rg[MAXN];

void init(){
	read(ccc);read(m);read(n);read(d);read(T);
	for(int i=1;i<=n;i++){
		read(w[i]);
		g[0].push_back(edge(i+n,w[i]));
		g[i].push_back(edge(0,w[i]));
		rg[i+n].push_back(edge(0,w[i]));
		rg[0].push_back(edge(i,w[i]));
	}
	int tot=2*n;
	for(int i=1;i<=m;i++){
		read(k[i]);
		int lst=0;
		for(int i=1;i<=k[i];i++){
			int a,t;
			read(a);read(t);++tot;
			g[a].push_back(edge(tot,t));
			rg[tot].push_back(edge(a,t));
			g[tot].push_back(edge(a+n,t));
			rg[a+n].push_back(edge(tot,t));
			if(lst){
				g[lst].push_back(edge(a,0));
				g[a].push_back(edge(lst,0));
				rg[lst].push_back(edge(a,0));
				rg[a].push_back(edge(lst,0));
			}
			lst=a;
		}
	}
}


priority_queue<edge> q;
int dis[MAXN];
bool vis[MAXN];
void dijkstra1(){
	memset(dis,0x3f,sizeof(dis));
	dis[0]=0;q.push(edge(0,0));
	while(!q.empty()){
		int u=q.top().to;q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto cur:g[u])
		    if(dis[cur.to]>dis[u]+cur.cost){
		    	dis[cur.to]=dis[u]+cur.cost;
		    	q.push(edge(cur.to,dis[cur.to]));
			}
	}
}

int rdis[MAXN];
bool rvis[MAXN];
void dijkstra2(){
	memset(rdis,0x3f,sizeof(rdis));
	rdis[0]=0;q.push(edge(0,0));
	while(!q.empty()){
		int u=q.top().to;q.pop();
		if(rvis[u])continue;
		rvis[u]=1;
		for(auto cur:rg[u])
		    if(rdis[cur.to]>rdis[u]+cur.cost){
		    	rdis[cur.to]=rdis[u]+cur.cost;
		    	q.push(edge(cur.to,rdis[cur.to]));
			}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	init();
	dijkstra1();dijkstra2();
	while(T--){
		int x,y;
		read(x);read(y);
		printf("%d\n",dis[x+n]+dis[y]);
	}
	return 0;
}
