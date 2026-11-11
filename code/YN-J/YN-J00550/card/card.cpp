#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[500005];
int b[300005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int sum = 0;
	for (int k = 1; k <= n; k++) {
		int t = k;
		for (int i = k; i <= n; i++) {
			int j1;
			for (int j = i + 1; j <= n; j++) {
				if (a[i] == a[j]) {
					j1 = j;
					i = j1;
					t = i;
					break;
				}
			}
		}
		for (int i = t; i <= n; i++) {
			b[a[i]]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << b[i] << ' ';
	}


	return 0;
}