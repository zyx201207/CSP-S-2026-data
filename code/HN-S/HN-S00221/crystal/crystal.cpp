#include <bits/stdc++.h>
using namespace std;

long long m, a[500001], s[500001];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin.tie(NULL);
	
	int n, ans = 0; cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];
	
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (s[i] - s[mid-1] + m >= (i-mid+1) * a[i]) r = mid-1;
			else l = mid+1;
		}
		ans = max(ans, i-l+1);
	}
	
	cout << ans;
	return 0;
}
