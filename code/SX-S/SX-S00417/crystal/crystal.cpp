#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long a[N];

int main() {
	long long n, m, s = 0, ans = 1, sum = 1, tot = 1, maxx = -1;
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) {
		s = s + (a[i] - a[i - 1]) * sum;
		sum++;
		ans++;
		while (s > m) {
			s = s - (a[i] - a[tot]);
			tot++;
			sum--;
			ans--;
		}
		maxx = max(maxx, ans);
	}
	cout << maxx;
	return 0;
}
