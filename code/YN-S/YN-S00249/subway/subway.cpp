#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n;
long long a[N], m;
long long maxx;
long long sum, ans;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = n; i >= 1; i--) {
		if (sum + (a[n] - a[i]) <= m)
			sum += (a[n] - a[i]), ans++;
	}
	cout << n;
	return 0;
}
