#include<bits/stdc++.h>
#define int long long
using namespace std;

//±©Á¦ 
typedef pair<int,int> pii;
const int N = 5e5 + 5;
const int M = 1e3 + 5;
const int INF = 1e18;
int c,n,m,d,q,w[N],k[N],a[N],t[N],dis[N];
int dist[M][M],l,r,st[N],tot;

set<pii> p;
vector<pii> g[N]; 
void dijkstra(int u){
	for(int i = 1;i <= m;i ++) dis[i] = INF;
	p.insert({0,u});
	dis[u] = 0;
	while(!p.empty()){
		pii now = *p.begin();
		int x = now.second;
		p.erase(now);
		if(st[x] == tot) continue;
		st[x] = tot;
		for(auto tx : g[x]) {
			int v = tx.first;
			int w = tx.second;
			if( dis[v] > dis[x] + w) {
				dis[v] = dis[x] + w;
				p.insert({dis[v],v});
			}
		}
	} 
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	if(m <= 600) {
		for(int i = 1;i <= m;i ++) {
			for(int j = 1;j <= m;j ++) {
				dist[i][j] = INF;
			} 
		}
		for(int i = 1;i <= m;i ++) scanf("%lld",&w[i]),dist[i][i] = 0;
		for(int i = 1;i <= n;i ++) {
			scanf("%lld",&k[i]);
			for(int j = 1;j <= k[i];j ++) scanf("%lld%lld",&a[j],&t[j]);
			for(int j = 1;j <= k[i];j ++) {
				for(int s = 1;s <= k[i];s ++) {
					if(j == s) continue;
					dist[a[j]][a[s]] = min(t[j] + t[s],dist[a[j]][a[s]]);
				}
			}
		}
		for(int k = 1;k <= m;k ++) {
			for(int i = 1;i <= m;i ++) {
				for(int j = 1;j <= m;j ++) {
					dist[i][j] = min(dist[i][k] + dist[k][j],dist[i][j]);
				}
			}
		}
		while(q --) {
			scanf("%lld%lld",&l,&r);
			printf("%lld\n",w[l] + w[r] + dist[l][r]);
		}
	} else {
		for(int i = 1;i <= n;i ++) {
			scanf("%lld",&k[i]);
			for(int j = 1;j <= k[i];j ++) scanf("%lld%lld",&a[j],&t[j]);
			for(int j = 1;j <= k[i];j ++) {
				for(int s = 1;s <= k[i];s ++) {
					if(j == s) continue;
					g[a[j]].push_back({a[s],t[j] + t[s]});
				}
			}
		}
		while(q --) {
			scanf("%lld%lld",&l,&r);
			++tot;
			dijkstra(l);
			printf("%lld\n",w[l] + w[r] + dist[r]);
		}
	}
	return 0;
}
