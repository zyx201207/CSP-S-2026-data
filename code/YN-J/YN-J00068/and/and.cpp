#include <bits/stdc++.h>
using namespace std;


bool num[2005][100000] = {0};

int endn[1000000] = {};

int a[10000] = {};

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int cnt = 0, maxn = 0, maxnn = 0;
	for (int i = 1; i <= n; i++) {
		cnt = 0;
		if (maxnn < a[i])
			maxnn = a[i];
		int j = 1;
		while (a[i] != 0) {
			if (a[i] % 2 == 1)
				num[i][j] = 1;
			a[i] /= 2;
			j++;
			cnt++;
		}
		if (cnt > maxn)
			maxn = cnt;
	}
	if (m == 1)
		cout << maxnn;
	else {
		for (int i = 1 ; i <= maxn; i++) {
			int same = 1;
			for (int j = 2; j <= n; j++) {
				if (num[i][j - 1] != num[i][j])
					same = 0;
			}
			if (same == 1)
				endn[i] = 1;
		}
		int x = 0;
		for (int i = 1; i <= maxn; i++) {
			for (int j = 0; j < i; j++)
				endn[i] *= 2;
			x += endn[i];
		}
		cout << x / 2;
	}
	return 0;
}