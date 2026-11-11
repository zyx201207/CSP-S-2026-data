#include <bits/stdc++.h>
using namespace std;
int a[300005], b;

int main() {
//	freopen("and.in", "r", stdin);
//	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	b = a[1] and a[2];
	cout << b;
	return 0;
}