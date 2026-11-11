#include <bits/stdc++.h>
using namespace std;
int a[500005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, cyrene = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {

		cin >> a[i];
		cyrene++;

		if (a[i] != a[i - 1]) {
			cyrene--;
		} else if (a[i - cyrene] > a[i] && a[i - cyrene] > a[i = 3] && a[i - cyrene] > a[i - 1] && a[i - cyrene] > a[i - 2]
		           && a[i - cyrene] > a[i - 4] && a[i - cyrene] > a[i - 5]) {
			cyrene -= i;
		}

	}

	for (int i = 0; i < m; i++) {

		cout << cyrene;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}