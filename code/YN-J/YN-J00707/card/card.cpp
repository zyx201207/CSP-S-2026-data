#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin.tie(0), cout.tie(0);
	ll n, m, p;
	cin >> n >> m;
	p = n;
	ll cnt[m + 1] = {0}, a[n + 1], b[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	int s = 1;
	while (p--) {
		for (int i = s; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				if (b[i] == b[j] && i != j) {
					for (int k = i; k <= j - 1; k++) {
						b[k] = 0;
					}
				}
			}
		}
		for (int i = s; i <= n; i++) {
			if (b[i] != 0) {
				cnt[b[i]]++;
			}
			b[i] = a[i];
		}
		s++;
	}

	for (int i = 1; i <= m; i++) {
		cout << cnt[i] << ' ';
	}
	return 0;
}
