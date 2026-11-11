#include <bits/stdc++.h>
using namespace std;

int c, m, n, d, q, k[1000005], l;
int w[10005];

struct p {
	int a;
	int t;
} 	p[100000005];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> n >> m >> d >> q;
	for (int i = 0; i < m; i++) {
		cin >> w[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> p[j].a >> p[j].t;
		}
	}
	for (int i = 0; i < q; i++) {
		int s, f,, s1, f1, time = time + w[s] + w[f];
		cin >> s >> f;
		for (int j = 1; j <= n; j++) {
			if (s == p[j].a) {
				s1 = j;
			}
			if (f == p[j].a) {
				f1 = j;
			}
		}
		if (s1 = f1) {

		} else {
			int pq == s;
			while (pq == f) {

			}
		}
		cout << time << endl;
	}

	return 0;
}
