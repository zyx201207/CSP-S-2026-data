#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,ans,fx,fb,sx,sb;
int x[2000010],dis[2000010],line[2000010];
bool vis[2000010];
vector<int> f[200010],g[200010];
priority_queue<pair<int,int>,vector<pair<int,int> >,
greater<pair<int,int> > > q;
void spfa(int x) {
	memset(dis,127,sizeof(dis));
	memset(line,0,sizeof(line));
	memset(vis,0,sizeof(vis));
	dis[x]=0;line[x]=1;q.push(make_pair(0,x));vis[x]=1;
	while (!q.empty()) {
		fx=q.top().second;fb=dis[fx];q.pop();vis[fx]=0;
		for (int i=0;i<f[fx].size();i++) {
			sx=f[fx][i];sb=fb+g[fx][i];
			if (sb==dis[sx]) line[sx]+=line[fx];
			if (sb<dis[sx]) {
				dis[sx]=sb;
				line[sx]=line[fx];
				if (vis[sx]==0) {
					q.push(make_pair(sb,sx));vis[sx]=1;
				}
			}
		}
	}
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while (t--) {
		cin>>n>>d;
		for (int i=1;i<=n;i++) {
			cin>>x[i];
			f[i].clear();g[i].clear();
			for (int j=1;j<=i-1;j++) {
				if (x[i]-x[j]<=d) {
					f[i].push_back(j);f[j].push_back(i);
					g[i].push_back(1);g[j].push_back(1);
				}
			}
		}
		ans=0;
		for (int i=1;i<=n;i++) {
			spfa(i);
			for (int j=1;j<=n;j++) if (line[j]==2) ans++;
		}
		cout<<ans/2<<"\n";
	}
	return 0;
}
