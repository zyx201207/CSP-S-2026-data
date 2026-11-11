#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10,N=510,M1=2e4+10;
long long dist[1010][M1];
long long dist2[M];
int w[M],k[N],a[M],t[M];
int c,n,m,d,q;
vector<pair<int,int> >g[M];
int vis[M];
bool vt[M];
priority_queue<pair<long long ,int> >pq;
void dij(int x) {
	memset(vt,0,sizeof(vt));
	if(c<=11)dist[x][x+d*m]=0;
	else {
		memset(dist2,0x3f,sizeof(dist2));
		dist2[x+d*m]=0;
	}
	pq.push({0,x+d*m});
	while(!pq.empty()) {
		int u=pq.top().second;
		pq.pop();
		if(vt[u])continue;
		vt[u]=1;
		for(auto t:g[u]) {
			int v=t.first,w=t.second;
			if(c<=11) {
				if(dist[x][v]>dist[x][u]+w) {
					dist[x][v]=dist[x][u]+w;
					pq.push({-dist[x][v],v});
				}
			} else {
				if(dist2[v]>dist2[u]+w) {
					dist2[v]=dist2[u]+w;
					pq.push({-dist2[v],v});
				}
			}
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1; i<=m; i++) {
		scanf("%d",&w[i]);
	}
	for(int i=1; i<=n; i++) {
		scanf("%d",&k[i]);
		for(int j=1; j<=k[i]; j++) {
			scanf("%d%d",&a[j],&t[j]);
			int u=a[j];
			a[j]=(vis[a[j]]++)*m+a[j];
			if(j!=1) {
				g[a[j-1]].push_back({a[j],0});
				g[a[j]].push_back({a[j-1],0});
			}
			g[u+d*m].push_back({a[j],t[j]});
			g[a[j]].push_back({u+d*m,t[j]});
		}
	}
	memset(dist,0x3f,sizeof(dist));
	if(c<=11) {
		for(int i=1; i<=m; i++) {
			dij(i);
		}
	}
	int x,y;
	while(q--) {
		scanf("%d%d",&x,&y);
		long long k=0;
		if(c<=11)
			k=dist[x][y+d*m];
		else {
			dij(x);
			k=dist2[y+d*m];
		}
		printf("%lld\n",w[x]+k+w[y]);
	}
	return 0;
}
