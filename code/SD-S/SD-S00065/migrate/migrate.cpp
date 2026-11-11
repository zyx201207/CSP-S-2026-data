#include <iostream>
#include <vector>
#include <queue>
#define ll long long
using namespace std;
const ll MAXN = 2e6 + 10, INF = 1e18;
ll c, T, n, d, arr[MAXN], res = 0;
const int MAXN1 = 5010;
ll dis[MAXN1], cnt[MAXN1];
vector<int> edge[MAXN1];
queue<int> q;
void solve1() {
	for(int i = 1; i <= n; i++) edge[i].clear();
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			if(arr[j] - arr[i] <= d) 
				edge[j].push_back(i);
	res = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= i; j++)
			dis[j] = INF, cnt[j] = 0;
		q.push(i), dis[i] = 0, cnt[i] = 1;
		while(!q.empty()) {
			int u = q.front(); q.pop();
			for(int v : edge[u]) {
				if(dis[v] == INF) {
					dis[v] = dis[u] + 1;
					cnt[v] = cnt[u];
					q.push(v);
				}
				else if(dis[v] == dis[u] + 1) cnt[v] += cnt[u];
			}
		}
		for(int j = 1; j < i; j++)
			if(cnt[j] == 2) res++;
	}
	cout << res << "\n";
}
void solve2() {
	if(n <= 2) {
		cout << "0\n";
		return;
	}
	ll k = d / (arr[2] - arr[1]);
	if(k <= 1) {
		cout << "0\n";
		return;
	}
	cout << max(0ll, n - 2 * k + 1) << "\n";
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while(T--) {
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> arr[i];
		if(c <= 10) solve1();
		else if(c <= 12) solve2();
	}
	return 0;
}
