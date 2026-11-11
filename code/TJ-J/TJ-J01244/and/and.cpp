#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long maxa = 0, n, m, a[200005], b;
	cin >> n >> m;
	int i = 1;
	while (cin >> a[i]) {
		i++;
	}
	for (i = 1; i <= n; i++) {
		b = a[i];
		for (int j = i; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				b = b & a[j];
			}
		}if (b > maxa) maxa = b;
	}cout << maxa;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
