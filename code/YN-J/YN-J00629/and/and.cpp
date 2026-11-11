#include <bits/stdc++.h>
using namespace std;
int a[2000005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cout << a[n];
	return 0;
}