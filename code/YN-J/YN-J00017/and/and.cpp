#include <bits/stdc++.h>
using namespace std;
long long C = 2 * pow(10, 5);

int main() {

	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	long long n, m, max_x = INT_MIN;
	cin >> n >> m;
	while (n--) {
		int x;
		cin >> x;
		if (x > max_x)
			max_x = x;
	}
	cout << max_x;
	return 0;
}