#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int c,n,m,d,q;
const int N=5e5+5;
ll w[N];
vector<pair<int,ll>>G1[N];
ll dis[505][505],ans[505][505];
priority_queue<pair<ll,int>>pq;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j) dis[i][j]=ans[i][j]=4e18;
		}
	}
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int u; ll v;
			cin>>u>>v;
			G1[u].push_back({i,v});
		}
	}
	for(int i=1;i<=m;i++){
		int len=G1[i].size();
		for(int x=0;x<len;x++){
			for(int y=x+1;y<len;y++){
				int u=G1[i][x].first,v=G1[i][y].first;
				ll w=G1[i][x].second+G1[i][y].second;
				dis[u][v]=min(dis[u][v],w);
				dis[v][u]=dis[u][v];
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans[i][i]=0;
		pq.push({0,i});
		while(!pq.empty()){
			int u=pq.top().second;pq.pop();
			for(int v=1;v<=n;v++){
				if(v==u||dis[u][v]==4e18) continue;
				if(ans[i][v]>ans[i][u]+dis[u][v]){
					ans[i][v]=ans[i][u]+dis[u][v];
					pq.push({-ans[i][v],v});
				}
			}
		}
	}
	while(q--){
		int u,v; cin>>u>>v;
		ll now=w[u]+w[v],mn=4e18;
		int len1=G1[u].size(),len2=G1[v].size();
		for(int x=0;x<len1;x++){
			for(int y=0;y<len2;y++){
				mn=min(mn,G1[u][x].second+G1[v][y].second+ans[G1[u][x].first][G1[v][y].first]);
			}
		}
		cout<<now+mn<<'\n';
	}
	return 0;
}
