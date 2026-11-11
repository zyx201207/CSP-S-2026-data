#include <bits/stdc++.h>
using namespace std;

long long en[500010], n, m, qzh[500010], ans = 0;
long long jishu[500010];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> en[i];
	}
	sort(en + 1, en + 1 + n);
	bool spe = 1;
	long long cha = en[2] - en[1];
	for (long long i = 1; i <= n; i++) {
		qzh[i] = qzh[i - 1] + en[i];
		if (en[i] != en[i - 1])
			jishu[i] = 1;
		else
			jishu[i] = jishu[i] + 1;
		if (i > 2 && en[i] - en[i - 1] != cha)
			spe = 0;
	}
	if (spe) {
		//cout << "aaa";
		long long i = 0;
		while (m >= i) {
			m -= i;
			ans++;
			i += cha;
		}
		cout << ans;
		return 0;
	}
	long long l = 0, lm = 0;
	for (long long i = 1; i <= n; i++) {
		long long ans0 = 0;
		l = lm;
		for (long long j = l; j <= i - 1; j++) {
			long long he = qzh[i] - qzh[j];
			if (en[i] * (i - j) - he <= m) {
				ans0 = i - j;
				long long p = 0;
				lm = max(j - jishu[i], p);
				break;
			}
		}
		ans = max(ans, ans0);
	}
	cout << ans;
	return 0;
}
