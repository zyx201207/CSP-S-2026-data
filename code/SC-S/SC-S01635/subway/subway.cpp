#include <queue>
#include <cstdio>
#include <vector>
using namespace std;
#define ll long long

const int M=5e5+9;
const ll INF=1e18+7;
int n,m,d,q,w[509];
ll dis[M+500];
vector<pair<ll,ll>> g[M+500];

inline ll read() {
	ll ret=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9') {if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0' && ch<='9') {ret=ret*10+ch-'0'; ch=getchar();}
	return ret*f;
}

void write(ll x) {
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);
	char cur=x%10+'0';
	putchar(cur);
}

inline void dij(int s) {
	for(int i=1;i<=n+m;i++) dis[i]=INF;
	dis[s]=0;
	priority_queue<pair<ll,int>> q;
	q.push({0,s});
	while(!q.empty()) {
		pair<ll,int> cur=q.top();
		q.pop();
		int u=cur.second;
		for(pair<ll,ll> nxt:g[u]) {
			ll v=nxt.second,w=nxt.first;
			if(dis[v]>dis[u]+w) {
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
}

inline void solve() {
	n=read(); m=read(); d=read(); q=read();
	for(int i=1;i<=m;++i) w[i]=read();
	for(int i=1;i<=n;++i) {
		int k=read();
		for(int j=1;j<=k;++j) {
			ll v=read(),w=read();
			g[v].push_back({w,m+i});
			g[m+i].push_back({w,v});
		}	
	}
	for(int i=1;i<=q;++i) {
		int u=read(),v=read();
		dij(u);
		write(dis[v]+w[u]+w[v]);
		putchar('\n');
	}
}

void dfs(int u,int from) {
	for(pair<int,int> nxt:g[u]) {
		int w=nxt.first,v=nxt.second;
		if(v==from) continue;
		dis[v]=dis[u]+w;
		dfs(v,u);
	}
}

inline void solve_for_A() {
	n=read(); m=read(); d=read(); q=read();
	for(int i=1;i<=m;++i) w[i]=read();
	for(int i=1;i<=n;++i) {
		int k=read();
		if(k==1) continue;
		for(int j=1;j<=k;++j) {
			int v=read(),w=read();
			g[v].push_back({w,m+i});
			g[m+i].push_back({w,v});
		}	
	}
	int start=-1;// !!!
	for(int i=1;i<=n;++i) {
		if(g[i].size()==1) {
			start=i;
			break;
		}
	}
	dfs(start,start);
	for(int i=1;i<=q;++i) {
		int u=read(),v=read();
		ll ans=dis[u]>dis[v]? dis[u]-dis[v]:dis[v]-dis[u];
		write(ans+w[u]+w[v]);
		putchar('\n');
	}
}

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=read();
	if(9<=c && c<=11) solve_for_A();
	else solve();
	return 0;
}