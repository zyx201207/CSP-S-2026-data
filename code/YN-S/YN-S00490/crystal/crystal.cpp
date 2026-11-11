#include <bits/stdc++.h>
using namespace std;
int n, m, y;
int a[50000];

int find(int d, int v) { //d=a[n]
	int  y = 0, r[d];
	for (int i = 0; i < d; i++) {
		r[i] = a[i];
	}
	for (int i = d + v; i >= 1; i--) {
		int b = i, g = 0, l = v;
		for (int j = d - 1; j >= 0; j--) {
			if (l > 0 && b <= r[j] + l && l >= r[j] && b >= r[j]) {
				l -= b - r[j];
				if (l > 0)
					g++;
			} else {
				if (g > y)
					y = g;
				continue;
			}
		}
	}
	return y;
}



int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << find(a[n - 1], m) - 1 ;
	fclose(stdin);
	fclose(stdout);
	return 0;
}