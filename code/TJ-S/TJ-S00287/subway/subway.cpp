#include<bits/stdc++.h>
using namespace std;

namespace subway {
	typedef long long ll;
	const int N=505,M=5e5+5;
	const ll INF=0x3f3f3f3f3f3f3f3f;
	int c,n,m,d,q,l_cnt;
	int w[M],k[N],subt[M],subl[N],t[N][M],g[N+M];
	int head[M+N],head2[N];
	vector<int> kk[M+N];
	int e_cnt,e2_cnt;
	struct E{
		int nxt,to,val;
	}e[(M+N)*2],e2[(M+N)*2];
	void add_edge(int u,int v,int w){
		e[++e_cnt] = {head[u],v,w},head[u] = e_cnt;
	}
	void add_edge2(int u,int v,int w){
		e2[++e2_cnt] = {head2[u],v,w},head2[u] = e2_cnt;
	}
	int get_cnt(int x) {
		++l_cnt;
		if(x)
			g[l_cnt] = x;
		return l_cnt;
	}
//	/*
	ll dis[N][N];
	bool vis[N];
	struct Q{
		int v;
		ll w;
		bool operator <(const Q &y) const{
			return w>y.w;
		}
	};
	void dij(int p){
		for(int i=1;i<=n;i++)
			dis[p][i] = INF,vis[i] = 0;
		priority_queue<Q> q;
		q.push({p,0});
		while(!q.empty()){
			int u=q.top().v;
			ll val=q.top().w;
			q.pop();
			if(vis[u])
				continue;
			dis[p][u] = val;
			vis[u] = 1;
			for(int i=head2[u];~i;i=e2[i].nxt){
				int v=e2[i].to,w=e2[i].val;
				if(!vis[v])
					q.push({v,val+w});
			}
		}
	}
//	*/
	/*
	int len[M+N];
	ll dis[M+N][N+M];
	bool vis[N+M];
	bool SPFA(int p){
		queue<int> q;
		for(int i=0;i<=l_cnt;i++)
			vis[i] = 0,len[i] = 0,dis[p][i] = INF;
		dis[p][p] = 0;
		vis[p] = 1;
		q.push(p);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			vis[p] = 0;
			for(int i=head2[u];~i;i=e2[i].nxt){
				int v=e2[i].to,w=e2[i].val;
				if(dis[p][v]>dis[p][u]+w){
					dis[p][v] = dis[p][u]+w;
					len[v] = len[u]+1;
					if(len[v]>=n)
						return 0;
					if(!vis[v]){
						q.push(v);
						vis[v] = 1;
					}
				}
			}
		}
		return 1;
	}
//	*/
	void solve() {
		int u,v;
		ll val;
		cin>>c>>n>>m>>d>>q;
		memset(head,-1,sizeof(head));
		memset(head2,-1,sizeof(head2));
		for(int i=1;i<=m;i++) {
			subt[i] = get_cnt(0);
			cin>>w[i];
		}
		for(int i=1;i<=n;i++) {
			subl[i] = get_cnt(i);
			cin>>k[i];
			for(int j=1;j<=k[i];j++) {
				cin>>v>>val;
				t[i][v] = val;
				kk[v].push_back(i);
				add_edge(subl[i],subt[v],t[i][v]);
				add_edge(subt[v],subl[i],t[i][v]);
			}
		}
		for(int i=1;i<=m;i++) {
			for(int j=head[subt[i]];~j;j=e[j].nxt) {
				u=e[j].to;
				for(int j2=head[subt[i]];~j2;j2=e[j2].nxt) {
					if(j==j2) continue;
					v=e[j2].to;
//					cout<<g[u]<<' '<<g[v]<<'\n';
					add_edge2(g[u],g[v],e[j].val+e[j2].val);
					add_edge2(g[v],g[u],e[j].val+e[j2].val);
				}
			}
		}
		for(int i=1;i<=n;i++)
			dij(i);
//		for(int i=1;i<=n;i++) {
//			for(int j=1;j<=n;j++)
//				cout<<dis[i][j]<<' ';
//			cout<<'\n';
//		}
		for(int i=1;i<=q;i++) {
			cin>>u>>v;
			ll ans=INF;
			for(int a:kk[u])
				for(int b:kk[v])
					if(dis[a][b]<ans)
						ans = min(ans,1ll*t[a][u]+t[b][v]+dis[a][b]+w[u]+w[v]);
			cout<<ans<<'\n';
		}
	}
}

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	subway::solve();
	return 0;
} 
