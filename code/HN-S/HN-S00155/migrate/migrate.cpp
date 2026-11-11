#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e6 + 2;
int n;
ll d, x[N];
ll ans;

priority_queue <pair <ll, int>> q;
ll dis[N], cnt[N];
bool vis[N];

inline void bfs(int st){
	q.push({0, st});

	while(!q.empty()){
		int u = q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;

		for(int v = u + 1; v <= n; ++ v){
			if(x[v] - x[u] > d) break;

			if(dis[u] + 1 < dis[v]){
				dis[v] = dis[u] + 1;
				cnt[v] = 1;
				q.push({-dis[v], v});
			}
			else if(dis[u] + 1 == dis[v]){
				cnt[v] ++;
			}
		}
	}
}

inline void solve(){
	cin >> n >> d;
	for(int i = 1; i <= n; ++ i){
		cin >> x[i];
	}
	ans = 0;

	for(int st = 1; st <= n; ++ st){
		for(int i = 1; i <= n; ++ i){
			dis[i] = 1e18, cnt[i] = 0;
			vis[i] = 0;
		}
		bfs(st);
		for(int i = 1; i <= n; ++ i){
			ans += cnt[i];
		}
	}
	cout << ans << '\n';
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int _C, _T_;
	cin >> _C >> _T_;
	while(_T_ --){
		solve();
	}

	return 0;
}

/*

g++ migrate.cpp -o migrate -std=c++14 -O2 -Wall
./migrate

*/