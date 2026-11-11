#include <bits/stdc++.h>
using namespace std;
int dis[503][500007];
int c,n,m,d,q,vis[500007],www[500007];
struct node{
	int to,val;
};
struct f{
	int to,val;
	bool operator >(const f&other)const{
		return val>other.val;
	}	
};
priority_queue<f,vector<f>,greater<f> > pq;
vector <node> e[500007];
void dijkstra(int s){
	while(!pq.empty()) pq.pop();
	memset(vis,0,sizeof(vis));
	dis[s-m][s]=0;
	vis[s]=1;
	pq.push({s,0});
	while(!pq.empty()){
		int u=pq.top().to;
		pq.pop();
		for(auto it:e[u]){
			int v=it.to;
			if(vis[v]) continue;
			if(dis[s-m][u]+it.val<dis[s-m][v]){
				dis[s-m][v]=dis[s-m][u]+it.val;
				pq.push({v,dis[s-m][v]});
			}
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> www[i];
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
			int u,w;
			cin >> u >> w;
			e[m+i].push_back({u,w});
			e[u].push_back({m+i,w}); 
		}
	}
	for(int i=1;i<=n;i++){
		dijkstra(m+i);
	}		
	for(int i=1;i<=q;i++){
		long long aa,bb,ret=1e18;
		cin >> aa >> bb;
		for(int i=1;i<=n;i++){
			ret=min(ret,(long long)dis[i][aa]+dis[i][bb]);
		}
		cout << ret+www[aa]+www[bb] << "\n";
	}
	return 0;
}
