#include <bits/stdc++.h>
using namespace std;
//const int N = 1e6+5;
const int N = 1e5+5;
int c,t,n,k;
int flag[15],vis[15];
vector<int> vc[N];
void dfs(int x){
	vis[x] = 1;
	for(int i=0; i<vc[x].size(); i++){
		int u = vc[x][i];
		if(flag[u]&&!vis[u]){
			dfs(u);
		}
	}
} 
int dis[N];
priority_queue<pair<int,int> > q; 
int dij(){
	for(int i=1; i<=n; i++){
		dis[i] = 1e9;
		if(flag[i]){
			dis[i] = 0;
			q.push({-dis[i],i});
		}
	}
	while(q.size()){
		int w = -q.top().first,u = q.top().second;
		q.pop();
		if(w>dis[u]) continue;
		for(int i=0; i<vc[u].size(); i++){
			int v = vc[u][i];
			if(dis[v]>dis[u]+1){
				dis[v] = dis[u]+1;
				q.push({-dis[v],v});
			}
		}
	}
	int mx = 0;
	for(int i=1; i<=n; i++){
		mx = max(mx,dis[i]);
	}
	return mx;
}
int ans;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	if(c<=3){
		while(t--){
			cin >> n >> k;
			ans = 1e9;
			for(int i=1; i<=n; i++){
				vc[i].clear();
			}
			for(int i=1; i<n; i++){
				int x,y;
				cin >> x >> y;
				vc[x].push_back(y);
				vc[y].push_back(x);
			}
			for(int i=0; i<(1<<n); i++){
				int num = 0;
				for(int j=0; j<n; j++){
					vis[j+1] = 0;
					if(i&(1<<j)){
						flag[j+1] = 1;
						num++;
					}else{
						flag[j+1] = 0;
					}
				}
				if(num!=k) continue;
				int cnt = 0;
				for(int j=1; j<=n; j++){
					if(flag[j]&&!vis[j]){
						dfs(j);
						cnt++;
					}
				}
				if(cnt>2) continue;
				ans = min(ans,dij());
			}
			cout << ans << '\n';
		} 
	}else if(c==7){
		while(t--){
			cin >> n >> k;
			ans = 1e9;
			for(int i=1; i<=n; i++){
				vc[i].clear();
			}
			for(int i=1; i<n; i++){
				int x,y;
				cin >> x >> y;
				vc[x].push_back(y);
				vc[y].push_back(x);
			}
			for(int i=1; i<=n; i++){
				flag[i] = 1;
				for(int j=i+1; j<=n; j++){
					flag[j] = 1;
					ans = min(ans,dij());
					flag[j] = 0;
				}
				flag[i] = 0;
			}
			cout << ans << '\n';
		}
	}
	return 0;
} 