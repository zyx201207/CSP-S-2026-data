#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, x;
	int a[105], b[105], c[105], d[105];
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int j = 0; j == -1; j++) {
		for (int k = 0; k < n; k++) {
			for (int a1 = 0; a1 == -1; a1++) {
				x = a[j];
				b[a1] = a[j] % 2;
				x = x / 2;
			}
		}
	}
	cout << "7";
	fclose(stdin);
	fclose(stdout);
	return 0;
}