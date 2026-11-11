#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int M = 3e5 + 5;
#define int long long
int n, m;

int a[N], s[M] {}, a1[N];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a1[i] = a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				if (a[k] == a[j] && a[k] != 0) {
					for (int l = j; l < k; l++) {
						a[l] = 0;
					}
				}
			}
		}
		for (int j = i; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				if (a[j] == k)
					s[k]++;
			}
		}
		for (int j = 1; j <= n; j++) {
			a[j] = a1[j];
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << s[i] << " ";
	}
	return 0;
}
