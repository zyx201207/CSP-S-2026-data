#include <bits/stdc++.h>
using namespace std;
int k[500005];

struct dy {
	int w;
	int a, t;
};
dy hh[500005];
int c, n, m, d, q;

bool pd(int x, int y) {
	for (int j = 0; j < n; j++) {

		for (int i = 0; i < k[j]; i++) {

			if (x == hh[i].a) {
				return 1;
			}
		}
	}

	return 0;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> n >> m >> d >> q;
	q--;
	int x, y;

	for (int i = 0; i < n; i++) {

		cin >> hh[i].w;
	}

	for (int i = 0; i < n; i++) {

		cin >> k[i];

		for (int j = 0; j < k[i]; j++) {

			cin >> hh[j].a >> hh[j].t;
		}
	}

	while (q--) {
		cin >> x >> y;
		cout << hh[x].w + hh[x].a + hh[x].t + hh[y].a + hh[y].w;
	}

	return 0;
}
