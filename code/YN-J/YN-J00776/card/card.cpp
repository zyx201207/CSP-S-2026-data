#include <bits/stdc++.h>
using namespace std;
int a[10000005], sum[10000005], js[10000005], wz[100000005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, a1, a2;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	a2 = a[n];
	for (int i = 1; i <= n; i++) {
		a1 = i;
		for (int j = 1; j <= m; j++) {
			js[j] = 0;
		}
		for (int j = n; j >= i; j--) {
			if (js[a[j]] == -1) {
				a1 = a[j];
				break;
			}
			if (js[a[j]] == 0) {
				js[a[j]] = -1;
				wz[a[j]] = j;
			}
		}
		for (int j = n; j > wz[a1]; j--) {
			sum[a[j]]++;
		}
	}
	sum[a2] = n;
	for (int i = 1; i <= m; i++) {
		cout << sum[i] << " ";
	}
	return 0;
}