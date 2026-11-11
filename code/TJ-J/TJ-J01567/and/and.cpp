#include <bits/stdc++.h>
using namespace std;
int n, m, a[200000];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cout << a[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}