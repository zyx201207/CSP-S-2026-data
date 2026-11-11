#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 550005;
const int M = 505;
const int INF = 1e9;
const int mod = 998244353;
struct node{
	int v, w;
	bool operator < (const node &x) const{
		return x.w < w;
	}
};
vector<node> g[N];
unordered_map<int, int> dis, vis, mp;
int n, m, d, w[N], k[M], f = 1;
unordered_map<int, int> dis_[150005];
int get_id(int x){
	return mp[x];
}
vector<int> a[M], t[M];
set<int> st;
void dijkstra(int s){
	priority_queue<node> que;
	for(auto it : st){
		dis[it] = INF;
		vis[it] = 0;
	}
	que.push({s, 0});
	dis[s] = 0;
	while(!que.empty()){
		node u = que.top();
		que.pop();
		if(vis[u.v]) continue;
		vis[u.v] = 1;
		for(auto it : g[u.v]){
			if(dis[u.v] + it.w < dis[it.v]){
				dis[it.v] = dis[u.v] + it.w;
				que.push({it.v, dis[it.v]});
			}
		}
	}
	return ;
}
void work(){
	int s, t;
	cin >> s >> t;
	if(m <= 1e3){
		cout << dis_[get_id(s)][t] + w[s] + w[t] << "\n";
		return ;
	}
	dijkstra(s); 
//	for(int i = 1; i <= 3 * m; i++){
//		cout << i << " " << dis[i] << "\n";
//	}
//	for(int i = 1; i <= 3 * m; i++){
//		for(auto it : g[i]){
//			if(i > it.v) continue;
//			cout << i << " " << it.v << " " << it.w << "\n";
//		}
//	}
	cout << dis[t] + w[s] + w[t] << "\n"; 
	return ;
}
void add_edge(int v, int u, int w){
	g[u].push_back({v, w});
	g[v].push_back({u, w});
}
void build(){
	for(int i = 1; i <= n; i++){
		for(int j = 2; j <= k[i]; j++){
			add_edge(a[i][j] + i * m, a[i][j - 1] + i * m, 0);
		}
		for(int j = 1; j <= k[i]; j++){
			add_edge(a[i][j] + i * m, a[i][j], t[i][j]);
			st.insert(a[i][j] + i * m);
			st.insert(a[i][j]);
		}
	}
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c;
	int t_ = 1;
	cin >> c >> n >> m >> d >> t_;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		a[i].resize(k[i] + 5);
		t[i].resize(k[i] + 5);
		for(int j = 1; j <= k[i]; j++){
			cin >> a[i][j] >> t[i][j];
			if(t[i][j] != t[1][1]){
				f = 0;
			}
		}
	}
	build();
	if(m <= 1e3){
		int cnt = 0;
		for(auto s : st){
			mp[s] = ++cnt;
			dijkstra(s);
			for(auto it : st){
				dis_[cnt][it] = dis[it];
			}
		}
	}
	while(t_--){
		work();
	} 
	return 0;
} 
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
//luogu uid 910628 Luna_From_Starry 球上神人共赏 
