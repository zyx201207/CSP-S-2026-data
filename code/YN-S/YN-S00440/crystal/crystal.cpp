#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500000], p[500000], s, maxx = 1;

void hc(int x) {
	if (m < (x - s + 1) * p[x + 1] || x + 1 > n) {
		return;
	}
	p[s] += p[x + 1];
	p[x + 1] = 0;
	m -= (x - s + 1) * p[x + 1];
	hc(x + 1);
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		p[i] = a[i] - a[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		s = 1;
		hc(s);
		int h = 1;
		for (int j = s + 1; j <= n; j++) {
			if (p[j]) {
				break;
			}
			h++;
		}
		if (maxx < h) {
			maxx = h;
		}
	}
	cout << maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}