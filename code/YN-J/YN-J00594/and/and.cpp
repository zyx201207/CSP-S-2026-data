#include <bits/stdc++.h>
using namespace std;
int n, m, c = 0, j = 1;
int a[100010];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == a[i + 1]) {
			cout << a[i];
			break;
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}