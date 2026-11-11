#include <bits/stdc++.h>
using namespace std;
int w[100000005], sum;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
		sum += w[i];
	}
	cout << sum;
	return 0;
}