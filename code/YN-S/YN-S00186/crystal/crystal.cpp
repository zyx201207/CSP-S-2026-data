#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m, cnt, a[N], sum, b[N], ans, b1[N], tmp, tmpn, cnta;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		int x = abs(a[i] - a[i + 1]);
		b1[i] = b1[i - 1] + x;
//		cout << b1[i] << " ";
	}
	int lst = 1;
	for (int i = 2; i <= n; i++) {
		int x = abs(a[i] - a[i - 1]);
		b[i] = b[i - 1] + ((i - (cnta + 1)) * x);
		sum = b[i] - tmpn;
//		cout << "#" << i << " " << tmpn << " " << sum << "\n";
		if (sum <= m)
			cnt++;
		else {
			tmp = 0;
//			cout << i << " " << sum << " " << cnt << "\n";
			ans = max(ans, cnt);
			int sum1 = sum;
			while (sum1 > m && cnt > 0) {
				cnt--;
				cnta++;
				sum1 = sum1 - b1[i - 1] + b1[lst - 1];
				lst++;
			}
			tmpn += (sum - sum1);
			sum = sum1;
//			cout << i << " " << sum << " " << cnt << "\n";
			if (sum <= m)
				cnt++;
		}
	}
	cout << ans + 1;
	return 0;
}
//ToonoHanna