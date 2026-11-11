#include<bits/stdc++.h>
using namespace std;
#define PII pair<long long,int>
const int N=510,M=5e5+10;
int c,n,m,d,qe,k[N],a,x,y;
long long w[M],t,dis[N+M];
vector<PII> g[N+M];
priority_queue<PII,vector<PII>,greater<PII> > q;
void dijkstra(int s) {
	dis[s]=0;
	q.push({0,s});
	while(!q.empty()) {
		auto it=q.top();q.pop();
		long long val=it.first;
		int v=it.second;
		if(dis[v]<val) continue;
		for(int i=0;i<g[v].size();++i) {
			
			if(g[v][i].second+val<dis[g[v][i].first]) {
				dis[g[v][i].first]=g[v][i].second+val;
				q.push({dis[g[v][i].first],g[v][i].first});
			}
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>qe;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i) {
		cin>>k[i];
		for(int j=1;j<=k[i];++j) {
			cin>>a>>t;
			g[n+m+i].push_back({a,t});
			g[a].push_back({n+m+i,t});
		}
	}
	while(qe--) {
		memset(dis,0x3f,sizeof(dis));
		cin>>x>>y;
		dijkstra(x);
		cout<<w[x]+w[y]+dis[y]<<endl;
	}
	return 0;
}
