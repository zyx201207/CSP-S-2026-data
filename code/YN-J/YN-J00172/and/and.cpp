#include <bits/stdc++.h>
using namespace std;

int main() {
	preopen("and.in", "r", stdin)
	preopen("and.out", "w", stdout)
	int x, a;
	cin >> x >> a;
	int y[x];
	for (int i = 0; i < x; i++) {
		cin >> y[i];
	}
	sort(y, y + x);
	cout << y[x - a];
}