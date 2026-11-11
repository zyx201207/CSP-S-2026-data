#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, ans, ans1;
long long m, a[N], maxn = -1e12 + 1, minn = 1e12 + 1;
int ton1[105], ton2[105];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	if (n <= 5000) {
		cout << 1;
		long long c = m;
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
			int t2 = a[i] * (-1);
			if (a[i] >= 0)
				ton1[a[i]]++;
			else
				ton2[t2]++;
		}
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++) {
			int j;
			c = m;
			ans1 = 0;
			if (a[i] < 0) {
				int t2 = a[i] * (-1);
				j = t2 ;
				for (; j < 105; j++) {
					if (c < ton2[j] * (a[i] + j))
						break;
					c -= ton2[j] * (a[i] + j);
					ans1 += ton2[j];
				}
				if (c)
					ans1 += c / (a[i] + j);
				ans = max(ans, ans1);
			} else {
				j = a[i];
				for (; j >= 0; j--) {
					if (c < ton1[j] * (a[i] - j))
						break;
					c -= ton1[j] * (a[i] - j);
					ans1 += ton1[j];
				}
				if (j == -1) {
					for (; j > -105; j--) {
						int t = j * (-1);
						if (c < ton2[t] * (a[i] - j))
							break;
						c -= ton2[t] * (a[i] - j);
						ans1 += ton2[t];
					}
					if (c)
						ans1 += c / (a[i] - j);
					ans = max(ans, ans1);
				} else {
					if (c)
						ans1 += c / (a[i] - j);
					ans = max(ans, ans1);
				}
			}
		}
		cout << ans;
	} else {
		for (int i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		int num = m / (a[2] - a[1]);
		int h = 1;
		for (int i = 1; i <= num; i += h * (a[2] - a[1])) {
			ans++;
			h++;
		}
		cout << ans;
	}
	return 0;
}