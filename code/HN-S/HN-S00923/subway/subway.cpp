#include <bits/stdc++.h>
#define int long long
#define Pii pair<long long,long long>
using namespace std;
const int N=5e5+5;
int C,n,m,d,q,c[N],t[N],w[N],vis2[N];
vector<int>dis[505];
struct node{
	int u,w;
};
vector<node>g[N+505];
void dijk(int s) {
	priority_queue<Pii,vector<Pii>,greater<Pii> >q;
	memset(vis2,0,sizeof(vis2));
	q.push({0,s});
	dis[s][s]=0;
	while (!q.empty()) {
		Pii x=q.top();
//		cout <<x.second<<" "<<x.first<<"\n";
		q.pop();
		if (vis2[x.second]) continue;
		vis2[x.second]=1;
		for (int i=0;i<g[x.second].size();i++) {
			int u=g[x.second][i].u,w=g[x.second][i].w;
			if (dis[s][u]>dis[s][x.second]+w) {
				dis[s][u]=dis[s][x.second]+w;
				q.push({dis[s][u],u});
			}
		}
	}
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >>C>>m>>n>>d>>q;
	for (int i=1;i<=n;i++){
		cin >>w[i];
	}
	for (int i=1;i<=m;i++) {
		int k;
		cin >>k;
		for (int j=1;j<=k;j++) {
			cin >>c[j]>>t[j];
			g[c[j]+m].push_back({i,t[j]});
			g[i].push_back({c[j]+m,t[j]});
		}
	}
	for (int i=1;i<=m;i++) {
		for (int j=1;j<=n+m+1;j++) dis[i].push_back(1e18);
	}
	for (int i=1;i<=m;i++) {
		dijk(i);
	}
	while (q--) {
		int x,y;
		cin >>x>>y;
		int sum=1e18;
		for (int i=1;i<=m;i++) {
			sum=min(sum,dis[i][x+m]+dis[i][y+m]);
		}
		cout <<sum+w[x]+w[y]<<"\n";
	}
	return 0;
}

