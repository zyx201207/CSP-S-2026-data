#include <bits/stdc++.h>
using namespace std;
int a[200005];
bool b[20005];
int to[200005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, d;
	bool f = 1;
	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		cout << b[i];
//	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] < a[i - 1]) {
			f = 0;
		}
	}
	if (f == 1) {
		for (int i = 1; i <= n; i++) {
			if (a[i] != a[i + 1]) {
				cout << i << ' ';
			}
		}
	} else {
		for (int i = 1; i <= n; i++) {
			for (int j = i ; j <= n; j++) {
				for (int k = i; k < j; k++) {
					if (a[j] == a[k]) {
						for (int l = k; l < j; l++) {
							b[l] = 1;
							//cout << l << "\n";
						}
						//cout << k << ' ' << j << "\n";
					}
				}
			}
//			for (int j = 1; j <= m; j++) {
//				cout << a[j] << ' ';
//			}
			//cout << "\n";
			for (int j = i; j <= n; j++) {
				if (b[j] == 0) {
					to[a[j]]++;
					//cout << a[j] << "\n";
				}
				//cout << b[j] << ' ' << a[j] << ' ' << j << "\n";
			}
			for (int j = 1; j <= n; j++) {
				b[j] = 0;
			}
		}
		for (int i = 1; i <= m; i++) {
			cout << to[i] << ' ';
		}
	}

	return 0;
}