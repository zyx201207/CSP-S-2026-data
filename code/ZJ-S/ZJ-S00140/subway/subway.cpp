#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> Pii;
struct node{
	int v,w;
};
vector<node> g[5010];
int c,n,m,d,q;
int x,y;
int dis[5010][5010];
int w[5010];
bool vis[5010];
int sum ;
priority_queue<Pii,vector<Pii>,greater<Pii> > pq;
void dij(int s,int t){
	pq.push({dis[s][s],s});
	
	for(int i = 1;i <= sum;i++) vis[i] = false; 
	
	while(!pq.empty()){
		auto P = pq.top();	
		int u = P.second;
		pq.pop();
		if(vis[u]) continue;
		vis[u] = true;
		for(node PII:g[u]){
			int v = PII.v,w = PII.w;
		//	cout <<u <<" "<< v <<"\n";
			if(dis[s][u] + w < dis[s][v]){
			
				dis[s][v] = dis[s][u] + w;	
				//cout << s<<" "<<v <<" "<<dis[s][v]<<"\n";
				pq.push({dis[s][v],v});
			}
		}
	}
	//cout << dis[s][t] <<" \n";
	cout << dis[s][t] + w[s] + w[t]<<"\n";
	return ;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	if(c <= 25){
		
		
		for(int i = 1;i <= m;i++){
			cin >> w[i];
			
		}
		int tot = m;
		for(int i = 1;i <= n;i++){
			int k;
			cin >> k;
			sum += k;
			tot++;
			for(int j = 1;j <= k;j++){
				int v,w;
				cin >> v  >> w;
				g[v].push_back({tot,w});
				g[tot].push_back({v ,w});
			}
		}
		sum += m;
		for(int i = 1;i <= sum;i++){
			for(int j = 1;j <= sum;j++){
				dis[i][j] = 1e9;
			}
			dis[i][i] = 0;
		}
		while(q--){
			cin >> x >> y;
			if(dis[x][y] < 1e9) cout <<dis[x][y] + w[x] + w[y]<<"\n";
			else dij(x,y);
		}	
	}
	return 0;
}
