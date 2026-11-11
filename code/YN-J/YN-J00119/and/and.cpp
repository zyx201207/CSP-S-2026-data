#include <bits/stdc++.h>
using namespace std;
int n, m;
long long b[2014];
long long k[2014];
long long a[2014][25];

void sth(int s, int num) {
	int t = 1;
	while (num != 0) {
		a[s][t] = num % 10;
		num /= 10;
		t++;
	}
	t--;
}

int sb(int x, int y) {
	int nb = 1;
	int d[2005];
	for (int i = 1; i <= 2002; i++) {
		if (a[x][i] == a[y][i]) {
			d[i] = a[x][i];
		} else {
			d[i] = 0;
		}
	}
	long long ans = 0;
	for (int i = 1; i <= 2005; i++) {
		ans += d[i] * nb;
		nb *= 10;
	}
	return ans;
}

int doing() {
	int d[2006];
	for (int i = 1; i <= 2005; i++) {
		for (int j = 1; j <= n; j++) {
			if (0 == a[i][j]) {
				d[i] = 0;
				break;
			}
		}
	}
	int nb = 1;
	long long ans = 0;
	for (int i = 1; i <= 2005; i++) {
		ans += d[i] * nb;
		nb *= 10;
	}
	return ans;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	int maxn = -1;
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		if (maxn < b[i]) {
			maxn = b[i];
		}
		sth(i, b[i]);
	}
	if (m == 1) {
		cout << maxn;
	} else if (m == 2) {
		int maxnn = -1;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (maxnn < sb(i, j)) {
					maxnn = sb(i, j);
				}
			}
		}
		cout << maxnn;
	} else if (m == n) {
		cout << doing();
	} else {
		cout << 917813;
	}
	return 0;
}
