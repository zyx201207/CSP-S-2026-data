#include <bits/stdc++.h>
using namespace std;
using tt = pair<long long, long long>;
using ttt = pair<long long, tt>;
const long long INF = LLONG_MAX / 10;
long long n, d;
long long bfs(long long u, vector<vector<tt>> g) {
	long long ans = 0;
	vector<vector<long long>> dist(n + 1, vector<long long>(d + 1, INF));
	dist[u][d] = 0;
	vector<long long> cur(n + 1);
	priority_queue<ttt, vector<ttt>, greater<ttt>> q;
	q.push({0, {u, d}});
	while (!q.empty()) {
		auto tmp0 = q.top();
		q.pop();
		long long sum_fly = tmp0.first;
		long long cur_u = tmp0.second.first;
		long long last_fly = tmp0.second.second;
		if (dist[cur_u][d] != sum_fly) continue;
		for (auto tmp1 : g[cur_u]) {
			long long next_l = tmp1.first;
			long long v = tmp1.second;
			if (d < next_l) break;
			if (dist[v][d] > sum_fly + 1) {
				dist[v][d] = sum_fly + 1;
				cur[v] = cur[cur_u] + 1;
				q.push({sum_fly + 1, {v, d}});
			} else if (dist[v][d] == sum_fly + 1) {
				cur[v]++; 
			}
			if (last_fly - next_l >= 0) {
				q.push({sum_fly, {v, last_fly - next_l}});
			}
		}
	}
	for (long long i = u + 3; i <= n; i++) {
		long long tmp3 = *min_element(dist[i].begin(), dist[i].end());
		if (tmp3 != INF && cur[i] == 3) ans++;
	}
	return ans;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	long long c, t;
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		vector<long long> x(n + 1);
		for (long long i = 1; i <= n; i++) cin >> x[i];
		if (n < 4) {
			cout << 0 << "\n";
			continue;
		}
		vector<vector<tt>> g(n + 1);
		for (long long i = 2; i <= n; i++) {
			long long l = abs(x[i] - x[i - 1]);
			g[i - 1].push_back({l, i});
		}
		long long sum = 0;
		for (long long i = 1; i + 3 <= n; i++) {
			sum += bfs(i, g);
		}
		cout << sum << "\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}