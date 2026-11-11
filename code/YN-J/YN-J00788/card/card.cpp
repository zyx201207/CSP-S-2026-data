#include <bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int d[300005];

int main() {
	freopen("card.in", "w", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	for (int e = 1; e <= n; e++) {
		for (int i = e; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (a[j] == a[i]) {
					for (int k = i; k < j; k++) {
						a[k] = 0;
					}
					break;
				}
			}
		}
		for (int i = e; i <= n; i++) {
			d[a[i]]++;
			a[i] = b[i];
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << d[i] << " ";
	}

	return 0;
}