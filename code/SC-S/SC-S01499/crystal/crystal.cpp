#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int maxn = 5e5 + 5;

int n;
ll m, a[maxn], ps[maxn];

bool check(int l, int r) {
	ll sum = ps[r] - ps[l - 1];
	return a[r] * (r - l + 1) - sum <= m;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) ps[i] = ps[i - 1] + a[i];
	int res = 1;
	for(int i = 2; i <= n; i++) {
		int l = 1, r = i;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(check(mid, i)) r = mid - 1, res = max(res, i - mid + 1);
			else l = mid + 1;
		}
	}
	cout << res << "\n";
	return 0;
}