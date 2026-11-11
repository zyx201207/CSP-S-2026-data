#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n;
long long a[N], m;
long long maxx;
long long sum, ans;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxx = max(a[i] - a[i - 1], maxx);
	}
	sort(a + 1, a + 1 + n);
	for (int i = n; i >= 1; i--) {
		if (sum + (a[n] - a[i]) <= m)
			sum += (a[n] - a[i]), ans++;//cout << a[i] << endl;
	}
	cout << ans;
	return 0;
}
