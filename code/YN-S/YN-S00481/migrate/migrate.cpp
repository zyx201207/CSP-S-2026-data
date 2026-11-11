#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

struct node {
	int nowi, nows;
};
long long x[N];
int mins[N], routes[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, d, ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		int maxi = 1;
		for (int i = 1; i <= n; i++) {
			if (x[i] + d >= x[n])
				break;
			maxi = i;
		}
		queue< node > q;
		for (int i = 1; i <= maxi; i++) {
			q.push( node{i, 0} );
			memset(mins, 0, sizeof(mins));
			memset(routes, 0, sizeof(routes));
			while (!( q.empty() )) {
				auto pos = q.front();
				q.pop();
				int idx = pos.nowi, s = pos.nows;
				if (mins[idx] == 0)
					mins[idx] = s;
				if (s > mins[idx])
					continue;
				routes[idx]++;
				for (int j = idx + 1; (x[j] - x[idx] <= d && j <= n) ; j++) {
					q.push(node{j, s + 1});
				}
			}
			for (int j = 1; j <= n; j++) {
				if (routes[j] == 2)
					ans++;
			}
		}
		cout << ans << '\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}