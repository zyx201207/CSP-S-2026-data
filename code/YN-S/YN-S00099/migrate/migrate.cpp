#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
long long n, d, c, t, dp, dvis, cnt, ans;
long long a[N];
vector<long long> box[N];

struct node {
	long long p, vis;
};
queue<node> q;
node num;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;

	while (t--) {
		cin >> n >> d;
		ans = 0;

		for (int i = 1; i <= n; i++) {

			box[i].clear();
			cin >> a[i];
		}

		q.push({1, 0});

		while (!q.empty()) {
			num = q.front();
			q.pop();
			dp = num.p;
			dvis = num.vis;

			for (int i = 1; i <= n + 1; i++) {

				if (dp + i <= n && a[dp + i] - a[dp] <= d) {
					q.push({dp + i, dvis + 1});
					box[dp + i].push_back(dvis + 1);
				} else {
					break;
				}
			}
		}

		for (int i = 1; i <= n; i++) {

			cnt = 0;
			sort(box[i].begin(), box[i].end());

			for (int j = 1; j < box[i].size(); j++) {

				if (box[i][0] == box[i][j]) {
					cnt++;
				} else {
					break;
				}
			}

			if (cnt == 1) {
				ans++;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
