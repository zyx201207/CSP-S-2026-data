#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 * 2 + 10;
int a[M][40];
queue <int> b, c, e;
int d[M];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, max = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		long long x;
		scanf("%d", &x);
		d[i] = x;
		int cnt = 0;
		while (x) {
			int t = x % 2;
			x /= 2;
			a[i][cnt] = t;
			cnt++;
		}
		if (cnt > max) {
			max = cnt;
		}
		b.push(i);
	}
	int l = n;
	for (int i = max - 1; i >= 0; i--) {
		int cnt = 0;
		for (int j = 0; j < l; j++) {
			int t = b.front();
			if (a[t][i] == 1) {
				cnt++;
				c.push(t);
			} else {
				e.push(t);
			}
			b.pop();
		}
		if (cnt >= m) {
			l = m;
			while (c.empty() == 0) {
				int t = c.front();
				c.pop();
				b.push(t);
			}
			if (cnt == m) {
				break;
			}
		} else {
			while (c.empty() == 0) {
				int t = c.front();
				c.pop();
				b.push(t);
			}
			while (e.empty() == 0) {
				int t = e.front();
				e.pop();
				b.push(t);
			}
		}
	}
	int z;
	for (int i = 0; i < m; i++) {
		if (i == 0) {
			int t1 = b.front();
			z = d[t1];
			//cout << t1 << " ";
			b.pop();
		} else {
			int t = b.front();
			int t1 = d[t];
			b.pop();
			//cout << t << " ";
			z = z & t1;
		}
	}
	//cout << endl;
	cout << z;
	return 0;
}