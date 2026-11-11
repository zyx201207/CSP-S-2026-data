#include <bits/stdc++.h>
using namespace std;
int n, m, a, t = 0, mans = -1, ans, x, v, y = 0;

int e[35] = {0};

int u[35] = {0};

struct num {
	int r;
	int w;
	int s[35] = {0};
	bool operator <(const num &c1) const {
		return r > c1.r;
	}
} p[200005];
int xuan[200005];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a;
		p[i].r = a;

		while (a != 0) {
			if (a % 2 == 1)
				p[i].s[t] = 1;
			else
				p[i].s[t] = 0;
			a /= 2;
			t++;
		}

		p[i].w = t;
		t = 1;
	}

	sort(p + 1, p + n + 1);

	for (int i = 1; i <= p[1].w; i++) {

		for (int j = 1; j <= n; j++) {

			if (p[j].s[i] == 1)
				e[i]++;
		}
	}

	for (int i = p[1].w; i >= 1; i--) {

		if (y == m)
			break;

		if (e[i] < m)
			continue;

		for (int j = 1; j <= n; j++) {

			if (y == m)
				break;

			if (p[j].s[i] == 1) {
				if (y == m)
					break;
				y++;
				xuan[y] = j;

			}
		}
	}

	for (int i = 1; i <= p[xuan[1]].w; i++) {

		for (int j = 1; j <= m; j++) {

			if (p[xuan[j]].s[i] == 1)
				u[i]++;
		}
	}

	for (int i = 1; i <= p[xuan[1]].w; i++) {

		if (u[i] == m) {
			v = 1;

			for (int j = 1; j < i; j++) {

				v *= 2;
			}

			ans += v;
		}
	}

	cout << ans << endl;
	return 0;
}
