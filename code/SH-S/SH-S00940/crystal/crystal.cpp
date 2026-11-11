#include <bits/stdc++.h>
using namespace std;
#define LL long long

const int N = 5e5 + 10;
LL a[N];
LL n, m;
LL ans, cnt, sum, maxa, last;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	last = n;
	for (int i = n; i > 0; i--) {
		sum += a[last] - a[i]; cnt++;
		if (sum > m) {
			cnt--;
			last--;
			ans = max(ans, cnt);
			sum -= (a[last+1] - a[last]) * cnt;
		}
	}
	cout << max(ans, cnt);
	return 0;
}
