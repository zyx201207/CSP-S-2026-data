#include <bits/stdc++.h>
using namespace std;

struct ian {
	long long z, t;
};
vector<ian>a[505];
vector<long long>b[500005];
bool p[505];
long long c, n, m, d, q, w[500005], k[505], f[500005], x, y, ans;

long long find(long long x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}

void dfs(long long d, bool u, long long sum, long long l) {
	if (d == y) {
		if (!u) {
			ans = sum;
			return;
		}
	}
	for (int i = l; i < b[d].size(); i++) {
		if (p[b[d][i]] && !u) {
			continue;
		}
		for (int j = 0; j < a[b[d][i]].size(); j++) {
			if (u) {
				p[b[d][i]] = 1;
				dfs(a[b[d][i]][j].z, 0, sum + a[b[d][i]][j].t, i);
				sum += a[b[d][i]][j].t;
				p[b[d][i]] = 0;
			} else {
				if (d == a[b[d][i]][j].z) {
					continue;
				}
				p[b[d][i]] = 1;
				dfs(a[b[d][i]][j].z, 1, sum + a[b[d][i]][j].t, i);
				p[b[d][i]] = 0;
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) {
		scanf("%lld", &w[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &k[i]);
		scanf("%lld%lld", &x, &y);
		b[x].push_back(i);
		a[i].push_back({x, y});
		long long head = x;
		f[x] = head;
		for (int j = 2; j <= k[i]; j++) {
			scanf("%lld%lld", &x, &y);
			b[x].push_back(i);
			a[i].push_back({x, y});
			if (f[x] != 0) {
				head = f[x];
			} else {
				f[x] = head;
			}
		}
		printf("\n");
	}
	for (int i = 1; i <= q; i++) {
		ans = 0;
		scanf("%lld%lld", &x, &y);
		ans += w[x] + w[y];
//		dfs(x, 0, ans, 0);
		printf("%lld\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}