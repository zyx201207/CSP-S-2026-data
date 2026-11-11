#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1000000], b[1000000];
int ans[1000000];
int a2[1000000];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "r", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a2[i] = a[i];
	}
	int u = 0;
	int n2 = n;
	while (n2--) {
		u++;
		for (int i = 1; i <= n; i++) {
			b[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			b[i] = a2[i];
			for (int j = i - 1; j >= 1; j--) {
				if (b[j] == b[i]) {
					for (int k = j; k < i; k++) {
						b[k] = 0;
						a2[k] = -1;
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (b[i] == a[u]) {
				ans[a[u]]++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[a[i]] << " ";
	}
	return 0;
}