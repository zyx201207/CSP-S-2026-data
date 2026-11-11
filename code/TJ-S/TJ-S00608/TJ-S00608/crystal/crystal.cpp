#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace crystal {
	const int MAXN = 5e5 + 5;
	int n, m;
	int a[MAXN], s[MAXN];
	void read() {
		scanf("%lld%lld", &n, &m);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
		}
	}
	namespace force {
		bool check() {
			return n <= 5000;
		}
		void solve() {
			sort(a + 1, a + n + 1);
			for (int i = 1; i <= n; i++) {
				s[i] = s[i - 1] + a[i];
			}
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = i; j <= n; j++) {
					int sum = a[j] * (j - i) - (s[j - 1] - s[i - 1]);
					if (sum <= m) {
						ans = max(ans, j - i + 1);
					}
				}
			}
			printf("%lld", ans);
		}
	}
	namespace correct {
		bool check(int x) {
			for (int i = 1; i + x - 1 <= n; i++) {
				int j = i + x - 1;
				int sum = a[j] * (j - i) - (s[j - 1] - s[i - 1]);
				if (sum <= m) return true;
			}
			return false;
		}
		void solve() {
			sort(a + 1, a + n + 1);
			for (int i = 1; i <= n; i++) {
				s[i] = s[i - 1] + a[i];
			}
			int l = 1, r = n;
			while (l < r) {
				int mid = (l + r + 1) / 2;
				if (check(mid)) {
					l = mid;
				} else {
					r = mid - 1;
				}
			}
			printf("%lld", l);
		}
	}
	void solve() {
		if (force::check()) force::solve();
		else correct::solve();
	}
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	crystal::read();
	crystal::solve();
	return 0;
}

