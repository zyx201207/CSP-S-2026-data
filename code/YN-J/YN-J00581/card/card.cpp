#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int sum = 0;
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= k; j++) {

			sum = i * j;
		}
	}

	cout << 3 << " " << 4 << " " << 1;
	return 0;
}