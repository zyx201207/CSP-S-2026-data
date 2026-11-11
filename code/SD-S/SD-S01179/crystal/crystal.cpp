#include <bits/stdc++.h>

#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;

constexpr int MaxN = 5e5 + 10; 

int n;
ll m, a[MaxN], s[MaxN];

bool check(int k) { 
//	debug(" check %d\n", k); 
	for (int i = k; i <= n; i++) {
		ll t = a[i] * k - s[i] + s[i - k];
//		debug(" [%d, %d] -> %lld\n", i - k + 1, i, t);
		if (t <= m) return true;
	}
	return false;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1, less<>());
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	
	int l = 1, r = n, res = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			res = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	} 
	
	cout << res << '\n';
}

/*
sort 
二分答案，维护 k * a[x] - sum_(i = x - k + 1)^k a[x] <= m
*/

/*
坐落于大都市顶点空想构筑的理想乡
将这一切湮灭的将是谁的愿望 
*/
