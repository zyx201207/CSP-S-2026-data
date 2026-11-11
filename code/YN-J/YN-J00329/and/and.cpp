#include <bits/stdc++.h>
using namespace std;
int a[10000];

int main() {

	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		int x = max(a[i] & a[i - 1], a[i] & a[i + 1]);
		int y = max(x, a[i - 1] & a[i + 1]);
		int z = max(x, y);
		cout << z;
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}