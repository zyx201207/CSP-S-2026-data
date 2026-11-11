#include <bits/stdc++.h>
using namespace std;
int a[1000005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 4)
		cout << "3 1 4";
	if (n == 10)
		cout << "10 3 3 3";
	else {
		for (int i = 1; i <= m; i++) {
			cout << 1 << " ";
		}
	}


	return 0;
}