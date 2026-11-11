#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 10;
struct edge{
	int v,w;
};
struct node{
	int uid,dist;
	bool operator < (const node &ly) const{
		return dist < ly.dist;
	}
};
int a[N];
vector <edge> g[N];
bool vis[N];
int dist[N];
void dij(int s){
	priority_queue<node>q;
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	q.push({s,0});
	dist[s] = 0;
	vis[s] = 1;
	while(!q.empty()){
		node u = q.top();q.pop();
		if(vis[u.uid] == 1){
			continue;
		}
		vis[u.uid] = 1;
		for(auto e : g[u.uid]){
			if(dist[e.v] > dist[u.uid] + e.w){
				dist[e.v] = dist[u.uid] + e.w;
				q.push({e.v,dist[u.uid] + e.w});
			}		
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	int c,t;
	cin >> c >> t;
	if(c == 0){
		while(t--){
			int n,d;
			cin >> n >> d;
			memset(a,0,sizeof(a));
			bool falg = true;
			for(int i = 1;i <= n;i++){
				cin >> a[i];
				if(i != 1){
					if(a[i] - a[i - 1] == a[2] - a[1]){
						falg = false;
					}
				}
			}
//			if(!falg){
//				int cha = a[2] - a[1];
//				if(cha < d)
//				{
//					int k = d / cha + 1;
//					int w = n % k;
//					
//				}
//			}
			for(int i = 1;i <= n;i++){
				for(int j = i;j <= n;j++){
					if(a[j] - a[i] <= d){
						g[i].push_back({j,a[j] - a[i]});
						g[j].push_back({i,a[j] - a[i]});
					}
				}
			}  
			int ans = 0;
			for(int i = 1;i <= n;i++){
				dij(a[i]);
				
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
