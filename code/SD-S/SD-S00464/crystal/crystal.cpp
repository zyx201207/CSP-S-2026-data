#include <bits/stdc++.h>

#define rep(i, st, ed) for (int i = st; i <= ed; i++)
#define rev(i, st, ed) for (int i = st; i >= ed; i--)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout); 
	
	long long n, m;
	cin >> n >> m;
	
	vector<long long> a(n + 1, 0), pre(n + 1, 0);
	
	rep(i, 1, n) {
		cin >> a[i];
	}
	
	sort(a.begin() + 1, a.end());
	rep(i, 1, n) {
		pre[i] = pre[i - 1] + (i - 1) * (a[i] - a[i - 1]);
	} 
	
	long long res = 0;
	
	rep(i, 1, n) {
		long long l = -1, r = i;
		while (l + 1 < r) {
			long long mid = l + r >> 1;
			if (pre[i] - pre[mid] - mid * (a[i] - a[mid]) <= m) r = mid;
			else l = mid;
		}
		res = max(res, i - r);
	}
	cout << res << '\n';
	
	return 0;
}
