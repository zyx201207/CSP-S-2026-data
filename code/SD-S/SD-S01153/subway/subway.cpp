#include <bits/stdc++.h>
#define INF (0x7FFFFFFF)
#define LL_INF (4e18)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
const int N=5e2+50,TOT=1e3+5,M=5e5+50,Q=1e5+50;
int w[M],c,n,m,d,q; 
vector<pil> gragh[TOT];
vector<int> station[M]; 
bool vis[TOT];
ll dist[TOT][TOT],dist1[N][N]; 
void dijkstra(int s){
	for (int i=1;i<=n+m;i++){
		dist[s][i]=LL_INF,vis[i]=false;
	}
	priority_queue<pli,vector<pli>,greater<pli>> pq;
	dist[s][s]=0,pq.push({0,s});
	while (!pq.empty()){
		int u=pq.top().second;
		ll dis=pq.top().first;
		pq.pop();
		if (vis[u]){
			continue; 
		}
		vis[u]=true;
		for (auto edge:gragh[u]){
			int v=edge.first;
			ll W=edge.second;
			if (dis+W<dist[s][v]){
				dist[s][v]=dis+W,pq.push({dis+W,v});
			}
		}
	} 
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0); 
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	if (c<=11){
		for (int i=1;i<=n;i++){
			int cnt;
			cin>>cnt;
			while (cnt--){
				int idx,cost;
				cin>>idx>>cost;
				gragh[idx].push_back({m+i,cost}),gragh[m+i].push_back({idx,cost}); 
			}
		}
		for (int i=1;i<=m;i++){
			dijkstra(i);
		}
		while (q--){
			int u,v;
			cin>>u>>v;
			cout<<(dist[u][v]+w[u]+w[v])<<endl;
		}
	}
	else if (c>=12&&c<=19){
		int T;
		for (int i=1;i<=n;i++){
			int cnt;
			cin>>cnt; 
			while (cnt--){
				int idx;
				cin>>idx>>T;
				station[idx].push_back(i); 
			}
		}
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				dist1[i][j]=INF; 
			}
			dist1[i][i]=0;
		}
		for (int i=1;i<=m;i++){
			for (auto l1:station[i]){
				for (auto l2:station[i]){
					if (l1!=l2){
						dist1[l1][l2]=2;
					}
				}
			}
		}
		for (int k=1;k<=n;k++){
			for (int i=1;i<=n;i++){
				for (int j=1;j<=n;j++){
					dist1[i][j]=min(dist1[i][j],dist1[i][k]+dist1[k][j]); 
				}
			}
		}
		while (q--){
			int x,y;
			cin>>x>>y;
			ll ans=LL_INF;
			for (auto l1:station[x]){
				for (auto l2:station[y]){
					ans=min(ans,w[x]+w[y]+(dist1[l1][l2]+2)*1ll*T);
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

