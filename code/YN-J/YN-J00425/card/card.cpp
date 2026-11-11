#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[5010];
int cnt[3010];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int  i = 1; i <= n; i++) {
		bool dc[3010] = {0};
		for (int j = i; j <= m; j++) {
			if (dc[a[j]] == 1) {
				for (int k = j - 1; k >= 1; k--) {
					dc[a[k]] = 0;
				}
			}
			dc[a[j]] = 1;
		}
		for (int j = 1; j <= m - 1; j++) {
			if (dc[j] == 1) {
				cnt[j]++;
			}
		}
		cnt[m] = n;
	}
	for (int i = 1; i <= m; i++) {
		cout << cnt[i] << " ";
	}
	return 0;
}