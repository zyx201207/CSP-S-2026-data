#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, s, ss, ans, a[200005], b[200005];
char ch[200005];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> a[i] >> ch[i];
		b[i] = a[i];
		s += a[i];
	}

	s /= 2;
	int j = n;

	for (int i = 1; i <= n; i++) {

		bool flag = 0;

//		cout << i << " " << a[i] << " " << b[i] << " " << ss << '\n';

		int cnt = a[i];

		if (ss + a[i] > s) {
			flag = 1;
			cnt = s - ss;
//			cout << i << " " << a[i] << " " << b[i] << " " << ss << '\n';
		}

		ss += cnt;
//		cout << i << " " << a[i] << " " << b[i] << " " << ss << '\n';

		while (b[j] <= cnt) {
			if (ch[i] != ch[j]) {
				ans += b[j];
			}

			cnt -= b[j];
			b[j] = 0;
			j--;
		}

		if (ch[i] != ch[j]) {
			ans += cnt;
		}

		b[j] -= cnt;


		if (flag) {
			break;
		}
	}

	cout << ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/