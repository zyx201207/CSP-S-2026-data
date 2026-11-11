#include<bits/stdc++.h>
using namespace std;
const int Inf=1e9;
const int N=505,M=5e5+5;
vector<int> w(M);
vector<int> k(N);
vector<array<int,3> > edg[N][M];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int C,n,m,d,q;
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) {
		cin>>k[i];
		if(k[i]==0) continue;
		int f,x;cin>>f>>x;
		edg[0][f].push_back({i,f,x});
		edg[i][f].push_back({0,f,x});
		for(int j=1;j<k[i];j++) {
			int a,t;cin>>a>>t;
			edg[0][a].push_back({i,a,t});
			edg[i][a].push_back({0,a,t});
			edg[i][f].push_back({i,a,0});
			edg[i][a].push_back({i,f,0});
		} 
	}
	while(q--) {
		int u,v;cin>>u>>v;
		vector<vector<int>> dis(n+7,vector<int>(m+7,Inf));
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
		pq.push({0,u});
		dis[0][u]=0;
		while(!pq.empty()) {
			pair<int,int> x=pq.top();
			int h=x.first,nw=x.second;
			if(h==0&&nw==v) break;
			pq.pop();
			for(array<int,3> s:edg[h][nw]) {
				int a=s[0],b=s[1],c=s[2];
				if(dis[a][b]>dis[h][nw]+c) {
					dis[a][b]=dis[h][nw]+c;
					pq.push({a,b});
				}
			}
		}
		cout<<dis[0][v]+w[u]+w[v]<<"\n";
	}
	return 0;
}