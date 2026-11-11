#include <bits/stdc++.h>
using namespace std;
string x[10000], y[10000];

int main() {

	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		if (x[i] = x[i + 1] || y[i] = y[i + 1]) {
			cout << "0";
		}
		int a = x += y;
		a += a;
		cout << a - n;
	}
	fclose(stdin);
	fclose(stdout);

	return 0;
}