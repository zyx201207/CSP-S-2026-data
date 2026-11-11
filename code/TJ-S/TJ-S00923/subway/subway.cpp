#include<bits/stdc++.h>

using namespace std;

struct uu{
	int v;
	long long w;
};
struct uu2{
	int x,y,i,h;
}a[100010];
int c,n,m,d,q;
long long w[500010];
vector<uu> g[500010];
long long dis[500010];
int vis[500010];
bool operator<(uu x,uu y) {
	return x.w>y.w;
} 
bool cmp(uu2 x,uu2 y) {
	if(x.x==y.x) return x.y<y.y;
	return x.x<y.x;
}
bool cmp2(uu2 x,uu2 y) {
	return x.i<y.i;
}
void dij(int s) {
	memset(dis,0x3f3f3f3f,sizeof dis);
	memset(vis,0,sizeof vis);
	priority_queue<uu> q;
	q.push({s,0});
	dis[s]=0;
	while(!q.empty()) {
		int u=q.top().v;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto e:g[u]) {
			if(dis[e.v]>dis[u]+e.w) {
				dis[e.v]=dis[u]+e.w;
				q.push({e.v,dis[e.v]});
			}
		}
	}
}
int bfs(int x,int y) {
	memset(vis,0,sizeof vis);
	queue<uu> qp;
	qp.push({x,0});
	while(!qp.empty()) {
		uu u=qp.front();qp.pop();
		if(u.v==y) return u.w;
		vis[u.v]=1;
		for(auto e:g[u.v]) {
			if(vis[e.v]) continue;
			qp.push({e.v,u.w+1});
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	int tt1=1e9+2778,tt2=0;
	for(int i=1;i<=n;i++) {
		int u=m+i,k;
		cin>>k;
		while(k--) {
			int v,w;
			cin>>v>>w;
			tt1=min(tt1,w);
			tt2=max(tt2,w);
			g[u].push_back({v,w});
			g[v].push_back({u,w});
		}
	}
//	if(d==2) {
//		dfs(i)
//	}
//cout<<tt1<<' '<<tt2;
	if(tt1==tt2) {
		for(int i=1;i<=q;i++) {
			int x,y;
			cin>>x>>y;
			long long h=bfs(x,y)*tt1+w[x]+w[y];
			cout<<h<<'\n';
		}
		return 0;
	}
//	for(int i=1;i<=m;i++) {
//		for(auto e:g[i]) cout<<i<<' '<<e.v<<' '<<e.w<<'\n';
//	}
	for(int i=1;i<=q;i++) {
		cin>>a[i].x>>a[i].y;
		int t=min(a[i].x,a[i].y);
		a[i].y=max(a[i].x,a[i].y);
		a[i].x=t;
		a[i].i=i;
	}
	sort(a+1,a+q+1,cmp);
	for(int i=1;i<=q;i++) {
		int x=a[i].x,y=a[i].y;
		if(a[i-1].x==x) {
			a[i].h=dis[y]+w[x]+w[y];
			continue;
		}
		dij(x);
		a[i].h=dis[y]+w[x]+w[y];
	}
	sort(a+1,a+q+1,cmp2);
	for(int i=1;i<=q;i++) {
		cout<<a[i].h<<'\n';
	}
	return 0;
} 
