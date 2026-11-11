#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
long long a[maxn], sum[maxn];
int n;
long long m;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	sum[1] = 1;
	for (int i = 2; i <= n; i++) {
		sum[i] = __gcd(abs(a[i]), abs(a[i - 1])) * min(abs(a[i]), abs(a[i - 1]));
	}
	for (int i = 1; i <= n; i++) {
		if ( sum[i] >= m) {
			cout << i - 1 << endl;
			return 0;
		}
	}
	return 0;
}
