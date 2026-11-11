#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int c;
long long a[N], t;
long long maxx;
long long sum, ans;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> a[i], sum += a[i];
		cout << sum;
	}
	return 0;
}
