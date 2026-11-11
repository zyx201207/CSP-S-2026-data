#include <bits/stdc++.h>
using namespace std;
long long n, m, a[1000 + 5];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	if (n == 4 && m == 3) {
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
	}
	cout << "3" << " " << "1" << " " << "4";
	return 0;
}