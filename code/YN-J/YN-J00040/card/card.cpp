#include <bits/stdc++.h>
using namespace std;
int a[50005];
int d[50005];
int b[30005];
int c[30005];
int cnt = 0;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {

		cin >> a[i];
		b[a[i]]++;
	}

	for (int j = 1; j <= n; j++) {
		if (b[j] == 1)
			cnt++;
	}
	if (cnt == n)
		for (int i = 0; i < n; i++) {
			cout << n - i << " ";
		} else {
		for (int s = 1; s <= n; s++) {
			d[s] = a[s];
		}
		for (int i = 1; i <= n ; i++) {

			for (int j = i; j <= n; j++) {
				if (a[i] == a[j] && i != j) {
					for (int s = i ; s <= j - 1; s++) {
						d[s] = 0;
					}
				}
			}
			for (int i = 1; i <= n; i++)	{
				c[d[i]]++;
			}

		}




		for (int i = 1; i <= m; i++)
			cout << c[i] << " ";
	}
	return 0;
}