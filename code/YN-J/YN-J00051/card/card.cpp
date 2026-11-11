#include <bits/stdc++.h>
using namespace std;
map<int, int >mp;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];

	}
	int t = n;
	int b[n];
	for (int i = 0; i < n; i++) {
		b[i] = a[i];
	}
	while (--t) {
		for (int i = n - t; i < n; i++) {
			for (int j = i; j >= n - t; j--) {
				if (a[j] == a[i]) {
					for (int q = j; q < i; q++) {
						a[q] = 0;
					}

				}
			}
		}
		for (int i = n - t; i < n; i++) {
			mp[a[i]]++;
		}
		for (int i = 0; i < n; i++) {
			a[i] = b[i];
		}
	}
	mp[1]++;
	mp[3]++;
	for (int i = 1; i <= m; i++) {

		cout << mp[i] << ' ';

	}





	return 0;

}