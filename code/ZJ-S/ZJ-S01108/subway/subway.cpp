#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,T,w,k,a,t,x,y,fx,fb,sx,sb;
int dis[2000510],vis[2000510];
vector<int> f[2000510],g[2000510];
priority_queue<pair<int,int>,vector<pair<int,int> >,
greater<pair<int,int> > > q;
void spfa(int st) {
	memset(dis,127,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[st]=0;q.push(make_pair(0,st));vis[st]=1;
	while (!q.empty()) {
		fx=q.top().second;fb=dis[fx];q.pop();vis[fx]=0;
		for (int i=0;i<f[fx].size();i++) {
			sx=f[fx][i];sb=fb+g[fx][i];
			if (sb<dis[sx]) {
				dis[sx]=sb;
				if (vis[sx]==0) {
					q.push(make_pair(sb,sx));vis[sx]=1;
				}
			}
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>T;
	for (int i=1;i<=m;i++) {
		cin>>w;
		x=i;y=m+i;
		f[x].push_back(y);f[y].push_back(x);
		g[x].push_back(w);g[y].push_back(w);
	}
	for (int i=1;i<=n;i++) {
		cin>>k;
		for (int j=1;j<=k;j++) {
			cin>>a>>t;
			x=m+a;y=2*m+i;
			f[x].push_back(y);f[y].push_back(x);
			g[x].push_back(t);g[y].push_back(t);
		}
	}
	while (T--) {
		cin>>x>>y;
		spfa(x);
		cout<<dis[y]<<"\n";
	}
	return 0;
}
