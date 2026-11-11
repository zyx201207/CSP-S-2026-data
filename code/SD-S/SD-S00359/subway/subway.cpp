#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<utility>
#include<bitset>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
const int N=1e3+10,N1=2e4+10;
int c,n,m,d,q,k,x,y,scc;
ll w[N];
ll T;
struct Statioon{
	ll t;
	int a;
}s[N1];
struct Graph{
	vector<pii> g[N1];
	void add(int u,int v,ll w){
		g[u].emplace_back(make_pair(w,v));
		g[v].emplace_back(make_pair(w,u));
	}
	ll d[N][N],dep[N];
	bitset<N>vis;
	priority_queue<pii,vector<pii>,greater<pii> >q;
	void init(int s){
		vis.reset();
		for(int j=1;j<=m;++j){
			d[s][j]=0x3f3f3f3f3f3f3f3f;
		}
	}
	void deb(){
		for(int i=1;i<=m;++i){
			for(int j=1;j<=m;++j){
				printf("%lld ",d[i][j]);
			}
			puts("");
		}
	}
	void dijkstra(int s){
		d[s][s]=0;
		q.push(make_pair(0,s));
		while(!q.empty()){
			int x=q.top().second;
			q.pop();
			if(vis[(unsigned long long)x]){
				continue;
			}
			vis[(unsigned long long)x]=1;
			int l=g[x].size();
			for(int i=0;i<l;++i){
				int j=g[x][(unsigned long long)i].second;
				ll w=g[x][(unsigned long long)i].first;
				if(d[s][j]>d[s][x]+w){
					d[s][j]=d[s][x]+w;
					q.push(make_pair(d[s][j],j));
				}
			}
		}
	}
	ll bfs(int s,int e){
		vis.reset();
		for(int i=1;i<=m;++i){
			dep[i]=0; 
		}
		queue<int> qu;
		qu.push(s);
		vis[(unsigned long long)s]=1;
		while(!qu.empty()){
			int u=qu.front();
			qu.pop();
			if(u==e){
				return dep[e];
			}
			int l=g[u].size();
			for(int i=0;i<l;++i){
				int j=g[u][(unsigned long long)i].second;
				ll w=g[u][(unsigned long long)i].first;
				if(!vis[(unsigned long long)j]){
					vis[(unsigned long long)j]=1;
					dep[j]=dep[u]+w;
					qu.push(j);
				}
			}
		}
		return -1;
	}
}G;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x;
}
ll readl(){
	ll x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(int i=1;i<=m;++i){
		w[i]=readl();
	}
	if(c<=11){
		for(int i=1;i<=n;++i){
			k=read();
			for(int j=1;j<=k;++j){
				s[j].a=read();
				s[j].t=readl();
			}
			for(int u=1;u<=k;++u){
				for(int v=u+1;v<=k;++v){
					G.add(s[u].a,s[v].a,s[u].t+s[v].t);
				}
			}
		}
		for(int i=1;i<=m;++i){
			G.init(i);
			G.dijkstra(i);
		}
		//G.deb();
		while(q--){
			x=read();
			y=read();
			printf("%lld\n",G.d[x][y]+w[x]+w[y]);
		}
	}
	else if(c<=15){
		for(int i=1;i<=n;++i){
			k=read();
			for(int j=1;j<=k;++j){
				s[j].a=read();
				s[j].t=readl();
				T=s[j].t;
			}
			for(int u=1;u<=k;++u){
				for(int v=u+1;v<=k;++v){
					G.add(s[u].a,s[v].a,s[u].t+s[v].t);
				}
			}
		}
		while(q--){
			x=read();
			y=read();
			printf("%lld\n",G.bfs(x,y)-T*2+w[x]+w[y]);
		}
	}
	return 0;
}
