#include <bits/stdc++.h>
using namespace std;

const long long N = 5e5 + 10;

long long c, n, m, d, q, w[N], t[N], buc[N];

struct node {
	long long to, val;
	node(long long a, long long b) : to(a), val(b) {}
};
vector<node>e[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c;
	if (c == 20 || c == 21) {
		vector<long long>num;
		long long ans = 0x3f3f3f3f3f3f3f3f;
		cin >> n >> m >> d >> q;
		for (long long i = 1; i <= m; i++)
			cin >> w[i];
		if (n == 1) {
			for (long long i = 1; i <= n; i++) {
				long long ki;
				cin >> ki;
				long long a, b;
				for (long long j = 1; j <= 2 * ki; j++) {
					cin >> e[i][j].to >> e[i][j].val;
				}
			}
			while (q--) {
				int a, b;
				cin >> a >> b;
				cout << w[a] + w[b] << '\n';
			}
			return 0;
		}
		queue<long long>qu;
		for (long long i = 1; i <= m; i++)
			cin >> w[i];
		for (long long i = 1; i <= n; i++) {
			long long ki;
			cin >> ki;
			long long a, b;
			for (long long j = 1; j <= 2 * ki; j++) {
				cin >> e[i][j].to >> e[i][j].val;
				buc[e[i][j].to]++;
				if (buc[e[i][j].to] == 2)
					qu.push(e[i][j].to);
			}
		}
		while (q--) {
			long long x, y;
			cin >> x >> y;
			while (!qu.empty()) {
				int u = qu.front();
				qu.pop();
				for (long long j = 1; j <= N; j++) {
					if (e[u][j].val + e[j][u].val == 0)
						continue;
					ans = min(e[u][j].val + e[j][u].val, ans);
				}
				cout << ans + w[x] + w[y] << '\n';
			}
		}

		return 0;
	}
	vector<long long>num;
	long long ans = 0x3f3f3f3f3f3f3f3f;
	cin >> n >> m >> d >> q;
	for (long long i = 1; i <= m; i++)
		cin >> w[i];
	if (n == 1) {
		for (long long i = 1; i <= n; i++) {
			long long ki;
			cin >> ki;
			long long a, b;
			for (long long j = 1; j <= 2 * ki; j++) {
				cin >> e[i][j].to >> e[i][j].val;
			}
		}
		while (q--) {
			int a, b;
			cin >> a >> b;
			cout << w[a] + w[b];
		}
		return 0;
	}
	queue<long long>qu;
	for (long long i = 1; i <= m; i++)
		cin >> w[i];
	for (long long i = 1; i <= n; i++) {
		long long ki;
		cin >> ki;
		long long a, b;
		for (long long j = 1; j <= 2 * ki; j++) {
			cin >> e[i][j].to >> e[i][j].val;
			buc[e[i][j].to]++;
			if (buc[e[i][j].to] == 2)
				qu.push(e[i][j].to);
		}
	}
	while (q--) {
		long long x, y;
		cin >> x >> y;
		while (!qu.empty()) {
			int u = qu.front();
			qu.pop();
			for (long long j = 1; j <= N; j++) {
				if (e[u][j].val + e[j][u].val == 0)
					continue;
				ans = min(e[u][j].val + e[j][u].val, ans);
			}
			cout << ans + w[x] + w[y] << '\n';
		}
	}

//	if(c < 6){
//
//	}
	return 0;
}