#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<queue>
using namespace std;
priority_queue<pair<long long ,int> ,vector<pair<long long ,int> >,greater<pair<long long ,int> > > q;
vector<pair<long long,int> > edge[505];
int c,n,m,d,qu;
long long w[15050],a[550][15050],t[550][15050],k[550],dist[15050][15050];
void build_edge() {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=k[i]; j++) {
			for(int c=j+1; c<=k[i]; c++) {
				int u=a[i][j],v=a[i][c],val1=t[i][j],val2=t[i][c];
				edge[u].push_back({val1+val2,v});
				edge[v].push_back({val1+val2,u});
			}
		}
	}
	return;
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>qu;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	int flag1=1;
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		if(k[i]>2) {
			flag1=0;
		}
		for(int j=1; j<=k[i]; j++) {
			cin>>a[i][j]>>t[i][j];
		}
	}
	build_edge();
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=m; j++) {
			if(j!=i) {
				dist[i][j]=1e18;
			}
		}
		q.push({0,i});
		while(!q.empty()) {
			int u=q.top().second,w=q.top().first;
			q.pop();
			if(dist[i][u]!=w) {
				continue;
			}
			for(int j=0; j<edge[u].size(); j++) {
				int v=edge[u][j].second,val=edge[u][j].first;
				if(dist[i][u]+val<dist[i][v]) {
					dist[i][v]=dist[i][u]+val;
					q.push({dist[i][v],v});
				}
			}
		}
	}
	for(int i=1; i<=qu; i++) {
		int x,y;
		cin>>x>>y;
		cout<<dist[x][y]+w[x]+w[y]<<"\n";
	}
	return 0;
}