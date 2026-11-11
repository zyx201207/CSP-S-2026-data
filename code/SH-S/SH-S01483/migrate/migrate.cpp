#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e6+5;
int c, t, n, d, x[MAX], ans = 0;

int gcdd(int a, int b) {
	int c;
	while (a % b != 0) {
		a %= b;
		swap(a, b);
	}
	return min(a, b);
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> d;
		for (int j = 0; j < n; j++) {
			cin >> x[j];
		}
		int dis = x[1] - x[0];
		int route = x[n-1] - x[0];
		int real = d * dis / gcdd(d, dis);
		int num = floor(route/real);
		cout << num << endl;
	}
	return 0;
}
