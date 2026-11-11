#include <bits/stdc++.h>
#define int long long

using namespace std;

int c, t, n, d, ans, a[3000005], rdd[3000005], ldd[3000005], rdm[3000005], ldm[3000005];

struct node {
	int ld1, ld2, rd1, rd2;
};

struct node2 {
	int x, y;
};

queue<node2> q;
vector<node> slv;

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld%lld", &c, &t);
	while (t --) {
		scanf("%lld%lld", &n, &d);
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", &a[i]);
			//cout << a[i] - a[i - 1] << endl;
			//a[i] += 1000000000000000000ll;
		}
		while (!q.empty()) q.pop();
		slv.clear();
		for (int i = n; i > 0; --i) {
			while (!q.empty() && q.front().x - a[i] > d) q.pop();
			if (!q.empty()) rdd[i] = q.front().y;
			else rdd[i] = i;
			q.push({a[i], i});
		}
		while (!q.empty()) q.pop();
		for (int i = 1; i <= n; ++i) {
			while (!q.empty() && a[i] - q.front().x > d) q.pop();
			if (!q.empty()) ldd[i] = q.front().y;
			else ldd[i] = i;
			q.push({a[i], i});
		}
		a[n + 1] = a[n] + d + 1;
		for (int i = 1, lst = 1; i <= n; ++i) {
			if (a[i + 1] - a[i] > d) {
				for (int j = lst; j <= i; ++j) {
					ldm[j] = lst;
					rdm[j] = i;
				}
				lst = i + 1;
			}
		}
		slv.push_back({0, 0, 0, 0});
		for (int i = 2; i <= n - 2; ++i) {
			int ld1, ld2, rd1, rd2, l, r, mid;
			rd2 = rdd[i];
			if (rd2 <= i + 1) continue;
			rd1 = i + 2;
			l = rd1, r = rd2;
			while (l <= r) {
				mid = (l + r) >> 1;
				if (ldd[mid] != i) {
					l = mid + 1;
					rd1 = mid + 1;
				} else {
					r = mid - 1;
					rd1 = mid;
				}
			}
			if (rd1 > rd2) continue;
			ld1 = ldd[i + 1];
			if (ld1 >= i) continue;
			ld2 = i - 1;
			l = ld1, r = ld2;
			while (l <= r) {
				mid = (l + r) >> 1;
				if (rdd[mid] != i + 1) {
					r = mid - 1;
					ld2 = mid - 1;
				} else {
					l = mid + 1;
					ld2 = mid;
				}
			}
			if (ld1 > ld2) continue;
			slv.push_back({ld1, ld2, rd1, rd2});
		}
		slv.push_back({n + 1, n + 1, n + 1, n + 1});
		ans = 0;
		for (int i = 1; i < slv.size() - 1; ++i) {
			ans += (slv[i].ld2 - max(slv[i - 1].ld2, ldm[slv[i].ld2] - 1)) * (min(slv[i + 1].rd1, rdm[slv[i].rd1] + 1) - slv[i].rd1);
			//assert((slv[i].ld2 - max(slv[i - 1].ld2, ldm[slv[i].ld2] - 1)) * (min(slv[i + 1].rd1, rdm[slv[i].rd1] + 1) - slv[i].rd1) > 0);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
