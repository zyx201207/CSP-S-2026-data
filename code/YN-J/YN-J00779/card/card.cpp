#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int ca[500001] = {};
	for (int i = 1; i <= n; i++) {
		cin >> ca[i];
	}
	int ct[500001] = {};
	for (int i = 1; i <= n; i++) {
		int t[500001] = {};
		int f[500001][3] = {};
		int cnt = i, j = 1;
		while (cnt <= n) {
			int x = ca[cnt];
			if (f[x][1] == 0) {
				f[x][1] = 1;
				f[x][2] = j;
				t[j] = x;
			} else {
				for (int k = f[x][2] + 1; k <= j; k++) {
					f[t[k]][1]--;
					f[t[k]][2] = 0;
					t[k] = 0;
				}
				j = f[x][2];
			}
			j++;
			cnt++;
		}
		for (int j = 1; j <= m; j++) {
			if (f[j][1] == 1) {
				ct[j]++;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ct[i] << ' ';
	}
	return 0;
}