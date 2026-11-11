#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int a, b, c, max;
	cin >> a, b;
	int d[a];
	for (int i = 0; i <= a; i++) {
		cin >> d[i];
		if (d[i]&d[i + 1] <= max);
		max = d[i];
	}
	cout << max;
	return 0;
}