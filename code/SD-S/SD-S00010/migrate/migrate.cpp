#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<bitset>
#include<deque>
using namespace std;
const int N = 2e6 + 5;
#define ll long long
#define endl '\n'
ll n, d, x[N], dis[N], cnt[N];
vector<int> e[305];
deque<int> q;
int N3() {
	int ans = 0;
	for(int i = 1; i < n; i++)
		e[i].clear();
	for(int i = 1; i < n; i++)
		for(int j = n; j > i; j--)
			if(x[j] - x[i] <= d)
				e[i].push_back(j);
	for(int s = 1; s < n-1; s++) {
		for(int i = 1; i <= n; i++) dis[i] = 0, cnt[i] = 0;
		q.push_back(s); cnt[s] = 1;
		while(!q.empty()) {
			int u = q.front(); q.pop_front();
			for(auto v : e[u]) {
				if(!dis[v] || dis[v] == dis[u]+1) {
					dis[v] = dis[u] + 1;
					if((++cnt[v]) <= 3) q.push_back(v);
				}
			}
		}
		for(int i = 1; i <= n; i++)
			ans += cnt[i] == 2;
	}
	cout << ans << endl;
	return 0;
}

int Ed() {
	ll D = x[2] - x[1];
	if(2*D <= d) cout << max(n - d / D * 2 + 1, 0ll) << endl;
	else cout << 0 << endl;
	return 0;
}


int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t; cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		for(int i = 1; i <= n; i++)
			cin >> x[i];
		if(n == 1) cout << 0 << endl;
		else if(x[n] - x[1] <= d) cout << 0 << endl;
		else if(c <= 6) N3();
		else if(c == 11 || c == 12) Ed();
		else cout << 0 << endl;
	}
	return 0;
}

