#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,dis[500005],rdis[500005];
struct node {
	int id,intim,transcnt,transtim[505];
} a[500005];
struct edge {
	int to,belline;
};
struct node1 {
	int cur,val,lastbel;
	bool operator < (const node c) const {
		return val>c.val;
	}
};
vector<edge> ve[500005];
bool vis[500005];
void dij(int s) {
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue<node1> q;
	q.push({s,0,0});
	while(!q.empty()) {
		int u=q.top().cur,lstbel=q.top().lastbel;
		q.pop();
		if(vis[u]) {
			continue;
		}
		vis[u]=1;
		for(auto nex:ve[u]) {
			int len=0,v=nex.to;
			if(lstbel!=nex.belline&&lstbel!=0) {
				len+=a[u].transtim[lstbel]+a[u].transtim[nex.belline];
			}
			if(dis[v]>dis[u]+len) {
				dis[v]=dis[u]+len;
				q.push({v,dis[v],nex.belline});
			}
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1; i<=m; i++) {
		scanf("%d",&a[i].intim);
	}
	for(int i=1,len; i<=n; i++) {
		scanf("%d",&len);
		for(int j=1,x,last; j<=len; j++) {
			scanf("%d%d",&x,&a[x].transtim[++a[x].transcnt]);
			if(j!=1) {
				ve[last].push_back({x,i});
			}
			last=x;
		}
	}
	for(int i=1,u,v; i<=q; i++) {
		scanf("%d%d",&u,&v);
		dij(u);
		printf("%d\n",dis[v]);
	}
	return 0;
}
