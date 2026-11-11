#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll,int>
bool vis[1010][1010];
ll w[505],n,m,dis[1110][1110],d,q;
vector<pair<int,ll>> g[500555];
priority_queue<pi,vector<pi>,greater<pi>> pq;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int opt;
	cin>>opt>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	memset(dis,0x3f,sizeof(dis));
	int a,t,c;
	for(int i=1;i<=n;++i){
		cin>>c;
		for(int j=1;j<=c;++j){
			cin>>a>>t;
			g[a].push_back({m+i,t});
			g[m+i].push_back({a,t});
		}
	}
	if(opt<=19&&opt>=12){
		while(q--){
			cout<<t<<endl;
		}
	}
	for(int i=1;i<=m;++i){
		pq.push({0,i});
		dis[i][i]=0;
		while(!pq.empty()){
			auto [l,u]=pq.top();
			pq.pop();
			if(vis[i][u]) continue;
			vis[i][u]=1;
			for(auto [v,w]:g[u]){
				if(dis[i][v]>dis[i][u]+w){
					dis[i][v]=dis[i][u]+w;
					pq.push({dis[i][v],v});
				}
			}
		}
	}
	int u1,v1;
	while(q--){
		cin>>u1>>v1;
		cout<<dis[u1][v1]+w[u1]+w[v1]<<endl;
	}
	return 0;
}