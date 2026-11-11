#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int t[1000][1000];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c, n, m, d, q;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> t[i][j];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}