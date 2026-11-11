#include <bits/stdc++.h>

using namespace std;

const int Maxn = 5e5 + 5;
long long n, m, a[Maxn], s[Maxn];

bool check(long long val) {
	for (int i = 1; i + val - 1 <= n; i++) {
		int j = i + val - 1;
		long long sum = s[j] - s[i - 1];
		long long tmp = a[j] * (val) - sum;
		if (tmp <= m)
			return true;
	}
	return false;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	}
	
	long long l = 1, r = n;
	long long ans = 1;
	while (l <= r) {
		long long mid = (l + r) >> 1;
		if (check(mid)) ans = mid, l = mid + 1ll;
		else r = mid - 1ll;
	}
	
	cout << ans << endl;
	
	return 0;
}