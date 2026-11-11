#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct edge{
	int v,w;
};
int x[2000010];
vector<edge> e[2000010];
int dis[2000010],vis[2000010],cnt[2000010];
struct node{
	int u,d;
	bool operator < (const node &a) const{
		return d > a.d;
	}
};
void bfs(int s){
	for(int i = 1;i <= n;i++){
		dis[i] = 1e18;
		vis[i] = 0;
		cnt[i] = 0;
	}
	queue<int> q;
	q.push(s);
	dis[s] = 0;
	cnt[s] = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = 0;i < e[u].size();i++){
			int v = e[u][i].v;
			if(dis[v] > dis[u] + 1){
				dis[v] = dis[u] + 1;
				cnt[v] = cnt[u];
				q.push(v);
			}
			else if(dis[u] + 1 == dis[v]){
				cnt[v] += cnt[u];
			}
		}
	}
}
void solve(){
	int d;
	cin >> n >> d;
	for(int i = 1;i <= n;i++){
		cin >> x[i];
	}
	int tmp = d / (x[2] - x[1]);
	int ans = 0;
	for(int i = 1;i <= n;i++){
		if(i + 2 * tmp - 1 <= n) ans++;
	}
	cout << ans << endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin >> c >> t;
	if(c == 11 || c == 12){
		solve();
	}
	while(t--){
		int CNT = 0;
		int d;
		cin >> n >> d;
		for(int i = 1;i <= n;i++){
			cin >> x[i];
			e[i].clear();
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(i != j && abs(x[i] - x[j]) <= d){
					e[i].push_back({j,1});
					e[j].push_back({i,1});
				}
			}
		}
		for(int i = 1;i <= n;i++){
			bfs(i);
			for(int j = 1;j <= n;j++){
				if(cnt[j] == 2){
					CNT++;
				}
			}
		}
		cout << CNT << '\n'; 
	}
	return 0;
}
