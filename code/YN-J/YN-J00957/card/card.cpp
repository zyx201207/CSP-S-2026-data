#include <bits/stdc++.h>
using namespace std;
int n = 0, m, a[500005], v[500005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= i; j++) {
				if (a[j] == a[i]) {
					for (int l = i; l >= j; l--) {
						a[l] = 0;
					}
					break;
				}
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		if (i == a[i]) {
			for (int j = 1; j <= m; i++) {
				if (i == a[i]) {
					v[i]+=1;
				}
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << v[i] << " ";
	}
	return 0;
}
