#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Max_n = 2e6 + 10;
int c, T, n, d;
int a[Max_n], ma[Max_n], vis[Max_n];
long long dis[Max_n], cnt[Max_n];
vector<int>G[Max_n];
struct S{
	int v, w;
	operator <(const S& x)const{return x.w < w;}
};
void dij(int s){
	priority_queue<S> q;
	q.push({s, 0});
	for(int i = 1; i <= n; i++) dis[i] = 1e18 + 10, vis[i] = 0, cnt[i] = 0;
	dis[s] = 0;
	cnt[s] = 1;
	while(q.size()){
		int u = q.top().v; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto v : G[u]){
			if(dis[u] + 1 == dis[v]){
				cnt[v]+=cnt[u];
			}
			if(dis[u] + 1 < dis[v]){
				dis[v] = dis[u] + 1;
				cnt[v] = cnt[u];
				q.push(S{v, dis[v]});
			}
		}
	}
}
void doo(){
	for(int i = 1; i <= n; i++)G[i].clear();
	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= ma[i]; j++){
			G[i].push_back(j);
			G[j].push_back(i);
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		dij(i);
		for(int j = 1; j <= n; j++){
			if(cnt[j] == 2) ans++;
		}
	}
	cout << ans/2 << "\n";
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while(T--){
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		if(c == 11 || c == 12){
			int dd = d /(a[2] - a[1]);
			if(dd == 0 || dd == 1) cout << "0\n" ;
			else cout << max(n - 2 * dd + 1, 0ll) << '\n';
			continue ;
		}
		for(int i = 1, j = 1; i <= n; i++){
			while(a[j+1] - a[i] <= d && j <= n) j++;
			ma[i] = j;
		}
		doo();
	}
	return 0;
}