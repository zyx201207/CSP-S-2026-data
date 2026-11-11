#include <bits/stdc++.h>
using namespace std;
int a[1000005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}