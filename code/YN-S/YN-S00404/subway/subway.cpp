#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct node {
	int a, t;
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	ll c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	vector<ll> w(m + 1);

	vector<node> z(505);
	vector<int> kk;

	for (int i = 1; i <= m; i++) {

		cin >> w[i];
	}

	for (int i = 1; i <= n; i++) {

		int k;
		cin >> k;
		kk.push_back(k);

		for (int j = 1; j <= k; j++) {

			cin >> z[i].a >> z[i].t;
		}
	}

	int tz;
	bool  f = 0;

	for (int i = 0; i < kk.size(); i++) {

		for (int j = 0; j < kk.size(); j++) {

			if (z[i].a == z[j].a) {
				tz = z[i].a;
				f = 1;
			}
		}

		if (f)
			break;
	}


	int xi, ix, yi, iy;
	bool fx = 0, fy = 0;

	for (int i = 1; i <= q; i++) {

		int sum = 0;
		int x, y;
		cin >> x >> y;

		for (int j = 0; j < kk.size(); j++) {

			for (int l = 1; l <= kk[j]; l++) {

				if (x == z[l].a && !fx) {
					xi = kk[j];
					ix = l;
					fx = 1;
					continue;
				}

				if (y == z[kk[j]].a && !fy) {
					yi = kk[j];
					iy = l;
					fy = 1;
					continue;
				}
			}

			if (fx && fy)
				break;
		}

		sum += w[z[ix].a];

		if (xi != yi) {

			for (int j = iy; j <= tz; j++) {

				sum += z[j].t;
			}

			for (int j = ix; j <= iy; j++) {

				sum += z[j].t;
			}
		} else {
			int up, und;

			if (ix > iy) {
				up = ix;
				und = iy;
			} else {
				up = iy;
				und = ix;
			}

			for (int j = und; j <= up; j++) {

				sum += z[j].t;
			}
		}

		sum += w[z[iy].t];
		cout << sum << "\n";
	}


	return 0;
}