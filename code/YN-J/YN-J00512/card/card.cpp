#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("card.in", "r", stdin);
	//freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n + 1];
	int vis[n + 1] = {};
	int res[m + 1] = {}, t[m + 1] = {};
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		t[a[i]]++;
	}
	for (int l = 0; l < n; l++) {
		for (int i = l; i < n; i++) {
			for (int j = l; j <= i; j++) {
				if (a[i] == a[j] && vis[i] == 0) {
					for (int k = j; k < i; k++) {
						vis[k] = 1;
						i += i - j  ;
						t[a[k]]--;
					}
				}
			}
		}
		for (int p = 0; p < m; p++) {
			res[p] += t[a[p]];
		}
		for (int i = 0; i < n; i++)
			vis[i] = 0;
	}
	for (int q = 0; q < m; q++) {
		cout << res[q] << " ";
	}

	return 0;
}