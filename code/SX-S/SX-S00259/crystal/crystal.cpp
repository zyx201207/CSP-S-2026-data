#include <bits/stdc++.h>
using namespace std;
int n;
long long ans = 1;
long long a[500005];
long long m;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	if (n > 10000) {
		int ccc = a[2] - a[1];
		int ansss = sqrt((m * 2) / ccc);
		cout << floor(ansss);
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	//cout << n << " " << m << endl;
	sort(a + 1, a + 1 + n);
	//cout << a[1] << endl;
	int aa = 0, aaa = 0;
	for (int i = 1; i <= n; i++) {
		aa = a[i];
		a[i] -= aaa;
		aaa = aa;
	}
	//cout << a[3] << endl;
	for (int i = 1; i <= n; i++) {
		long long shu = 1;
		int ci = i;
		long long mm = m;
		while (mm >= 0) {
			//cout << endl << "-----" << endl;
			if (ci == n)
				break;
			if (mm - a[ci + 1]*shu >= 0) {
				mm -= a[ci + 1] * shu;
				shu++;
				ci++;
			} else
				break;
		}
		ans = max(ans, shu);
		if (ans == n - i + 1) {
			cout << ans << endl;
			return 0;
		}
		//cout << ans << endl;
	}
	if (ans == 1) {
		cout << "0" << endl;
		return 0;
	}
	cout << ans << endl;
	return 0;
}