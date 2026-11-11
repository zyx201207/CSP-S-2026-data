#include <bits/stdc++.h>
using namespace std;

int v[500005] = {};

bool cmp(int a, int b) {
	return a < b;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int q = 1; q <= n; q++)
		cin >> v[q];
	sort(v + 1, v + n + 1, cmp);
	long long w1 = -1;
	for (int w = v[0]; w <= v[n] + m; w++) {
		long long sum = 0, num = m;
		for (int q = 1; q <= n; q++) {
			if (w >= v[q]) {
				if (num >= w - v[q]) {
					num -= (w - v[q]);
					sum++;
				}
			}
		}
		w1 = max(w1, sum);
	}
	cout << w1;
	return 0;
}