#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX = 10000010;
const int INF = 1000000010;
long long n, m, a[MAX], b[MAX], ans, mm, s[MAX];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ll mi = INF, ma = -INF;
	scanf("%lld%lld", &n, &m);
	bool f = true;
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		mi = min(mi, a[i]);
		ma = max(ma, a[i]);
		if (i >= 3) {
			if((a[i] - a[i - 1]) != (a[i - 1] - a[i - 2])) {
				f = false;
			}
		}
	}
	if (f == false) {
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; ++i) {
			s[i] = s[i - 1] + a[i];
		}
		for (int M = mi; M <= ma; ++M) {
			ans = 0;
			ll sum = 0;
			ll t;
			for (int i = n; i >= 1; --i) {
				if (a[i] <= M) {
					t = i;
					break;
				}
			}
			for (int j = t; j >= 1; --j) {
				if (sum + (M - a[j]) <= m) {
					if (sum + (M - a[j]) == m) {
						ans = max(t - j + 1, ans);
						break;
					} else {
						sum += M - a[j];
						ans = t - j + 1;
					}
				}
			}
			if (ans == 0)
				continue;
			for (int j = t + 1; j <= n; ++j) {
				int x = m - sum;
				int y = (m - sum) / ans;
				if (y >= a[j] - M) {
					ans++;
					sum += (a[j] - M) * ans;
				} else {
					break;
				}
			}
			mm = max(mm, ans);
		}
	} else {
		sort(a + 1, a + n + 1);
		ll sum = 0;
		ll N;
		if (n % 2 == 1) {
			N = (n + 1) / 2;
		} else {
			N = n / 2;
		}
		for (int i = N; i >= 1; --i) {
			if ((sum + (N - i)) <= m) {
				sum += N - a[i];
				if ((sum + (N - i)) == m) {
					ans++;
					break;
				} else {
					ans++;
					
				}
			}
		}
		if (ans != 0 && (m-sum) >= N) {
			for (int j = N + 1; j <= n; ++j) {
				int x = m - sum;
				int y = (m - sum) / ans;
				if (y >= a[j] - N) {
					ans++;
					sum += (a[j] - N) * ans;
				} else {
					break;
				}
			}
			mm = max(mm, ans);
		}
	}
	printf("%lld", mm);
}
