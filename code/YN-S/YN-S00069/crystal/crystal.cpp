#include <bits/stdc++.h>
using namespace std;
int n, m, a[10000005], b;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		a[i] = i;
		cin >> a[n];
		if (a[n] == a[i])
			b++;
	}
	cout << b;
	return 0;
}