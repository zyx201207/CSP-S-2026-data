#include <bits/stdc++.h>
#include <queue>
using namespace std;
long long n, m;
const long long N = 1e5 + 5;
long long a[N];
long long ansa, ans;
long long bj;
long long bja;
long long bjb;

bool cmp(long long x, long long y) {
	return x > y;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	ans = 1;
	ansa = 1;
	for (int i = 1; i < n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			bj += a[i] - a[j];
			if (bj <= m) {
				ansa++;
			} else {
				break;
			}
		}
		ans = max(ans, ansa);
		bj = 0;
		ansa = 1;
	}
	cout << ans;
	return 0;
}