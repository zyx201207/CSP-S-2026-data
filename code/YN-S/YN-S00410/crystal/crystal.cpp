#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 5e5 + 5;
LL a[N];
LL qzh[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	LL n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];

	}



	LL ans = 0;
	sort(a + 1, a + 1 + n);

	for (int i = 1; i <= n; i++) {

		qzh[i] = qzh[i - 1] + a[i];
	}

	LL l = 1;

	for (int i = 1; i <= n; i++) {



		int fl = 0;

		while (l * a[i] - (qzh[i] - qzh[max((LL)0, i - l )]) > m) {

			fl = 1;
			l--;
		}

		l = max((LL)0, l);
		ans = max(ans, l);
		l++;
	}

	cout << ans;

	//system("fc a.txt b.txt");



	return 0;
}
//
//