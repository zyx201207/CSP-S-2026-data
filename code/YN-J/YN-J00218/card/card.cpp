#include <bits/stdc++.h>
using namespace std;
int a[58], num[14];

bool fg(int n, int m) {
	for (int j = n + 1; j < m; j++) {
		if (a[n] == a[j]) {
			return true;
		}
	}
	return false;
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = n; i >= 1; i--) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		num[a[1]]++;
		for (int j = i + 1; j < n; j++) {
			if (fg(j, n)) {
				num[a[j]]++;
			} else
				for (int k = j + 1; k <= n; k++)
					num[a[k]]++;
		}

	}
	for (int i = 1; i <= m; i++)
		cout << num[i] << " ";
	return 0;
}