#include <bits/stdc++.h>
using namespace std;
int a[100000];

int main() {
	//freopen("subway.in", "r", stdin);
	//freopen("subway.out", "w", stdout);
	int c, n, d, q;
	cin >> c >> n >> d >> q;
	int m;
	cin >> m;

	int min = -99999;
	int max = 99999;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		int t = a[i] + m;
		cout << t << endl;
	}

	return 0;
}