#include <bits/stdc++.h>
#define int long long
#define INIT(a, n, v) for(int i = 1; i <= n; i++) a[i] = v
using namespace std;
const int N = 2e5 + 5;
int n, a[N], d, dis[N], f[N], ans;
vector<int> e[N];
void bfs(int s){
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(auto v : e[u]){
			if(dis[v] != 0 && dis[u] + 1 > dis[v]) continue;
			if(!dis[v]) dis[v] = dis[u] + 1, q.push(v);
			f[v] += f[u];
//			cout << s << " " << f[u] << " " << f[v] << " " << q.size()<< "\n";
		}
	}
}
void solve(){
	ans = 0;
	cin >> n >> d;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		e[i].clear();
		for(int j = i - 1; j >= 1; j--){
			if(a[i] - a[j] > d) break;
			e[i].push_back(j);
		}
	}
	for(int i = 1; i <= n; i++){
		INIT(dis, n, 0);
		INIT(f, n, 0);
		f[i] = 1;
		bfs(i);
		for(int j = 1; j <= i; j++){
			if(f[j] == 2) ans++;
		}
	}
	cout << ans << "\n";
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	int c, t;
	cin >> c >> t;
	while(t--){
		solve();
	}
	return 0;
}
//0 2
//5 3
//-2 -1 0 1 2
//6 2
//-4 -3 -2 -1 3 6

