#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int a, b, c, d, f, n;
	cin >> a >> b >> c;
	for (int i = 0; i < f; i++) {
		cin >> a >> b;

	}
	n = (a + b) * (a + b) - (c * d) + (d * f) / (f / a);
	cout << n << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}