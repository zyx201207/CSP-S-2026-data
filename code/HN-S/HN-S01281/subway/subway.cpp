#include<bits/stdc++.h>
using namespace std;

const int MAXN = 505;
const int MAXM = 500005;
const int INF = INT_MAX / 2;

int c,n,m,d,q;
vector<int> e[MAXM];
vector<int> fa[MAXM];
int w[MAXM];
int t[MAXN][MAXM];
 
bool find(vector<int>& k,int p){
	for(int i=0;i<k.size();i++){
		if(k[i] == p) return 1;
	}
	return 0;
}

int dist[MAXM][25];
int dijkstra(int s,int y){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=d;j++){
			dist[i][j] = INF;
		}
	}
	
	priority_queue<pair<int,pair<int,int> > > pq;
	
	for(int i = 0;i < fa[s].size();i++){
		int p = fa[s][i];
		dist[s][p] = t[p][s];
		pq.push({-dist[s][p], {s,p}});
	}
	
	while(!pq.empty()){
		auto ed = pq.top().second;
		int u = ed.first, p = ed.second;
		pq.pop();
		for(int i = 0;i < e[u].size();i++){
			int v = e[u][i], w = INF;
			
			for(int ik = 0;ik < fa[u].size();ik++){
				int p2 = fa[u][ik];
				if(find(fa[v],p2)){
					
					if(p2 == p) w = 0;
					else w = t[p][u] + t[p2][u]; 
					
					if(dist[u][p] + w < dist[v][p2]){
						dist[v][p2] = dist[u][p] + w;
						pq.push({-dist[v][p2], {v,p2}});
					}
				}
			}
		}
	}
	
	int ans = INF;
	for(int i = 0;i < fa[y].size();i++){
		if(dist[y][i] == INF) continue;
		ans = min(ans,dist[y][i] + t[i][y]);
	}
	return ans;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k,a,la = -1;
		cin>>k;
		la = -1;
		for(int j=1;j<=k;j++){
			cin>>a>>t[i][a];
			fa[a].push_back(i);
			if(la != -1){
				e[la].push_back(a);
				e[a].push_back(la);
			}
			la = a;
		}
	}
	
	for(int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		cout<<dijkstra(x,y) + w[x] + w[y]<<"\n"; 
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
