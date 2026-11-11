#include <bits/stdc++.h>
using namespace std;
int a[100000], b;

int main() {

	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b;
		a[i] %= 10;
		a [i] /= 10;

	}
	cout << a;
	fclose(stdin);
	fclose(stdout);

	return 0;
}