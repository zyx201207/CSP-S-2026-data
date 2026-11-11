#include <bits/stdc++.h>

#define rep(i, start, end) for (int i = start; i <= end; i++)
#define rev(i, start, end) for (int i = start; i >= end; i--)

using namespace std;

const int N = 2000010;

long long n, d;
vector<long long> x;
vector<long long> g[N];

int bfs(int st) {
	queue<pair<long long, long long>> q;
	q.push({st, 0});
	
	vector<long long> mi(n + 1, 0x3f3f3f3f3f3f3f3f), cnt(n + 1, 0);
	
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		
		if (mi[t.first] > t.second) {
			mi[t.first] = t.second;
			cnt[t.first] = 1;
		}
		else if (mi[t.first] == t.second) {
			cnt[t.first] ++ ;
		}
		
		if (mi[t.first] < t.second) continue;
		
		for (auto e : g[t.first]) {
			if (e <= t.first) continue;
			q.push({e, t.second + 1});
		} 
	}
	
	long long res = 0;
	rep(i, st + 1, n) {
		if (cnt[i] == 2) res ++ ;
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	 
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout); 
	 
	int c, _;
	cin >> c >> _;
	
	while (_ -- ) {
		cin >> n >> d;
		
		x.assign(n + 1, 0);
		
		rep(i, 1, n) cin >> x[i];
		
		rep(i, 1, n) {
			rep(j, i + 1, n) {
				if (x[j] - x[i] <= d) {
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		} 
		
		long long ans = 0;
		
		rep(i, 1, n) ans += bfs(i);
		cout << ans << '\n';
		
		rep(i, 1, n) g[i].clear(); 
	}
	
	return 0;
} 
