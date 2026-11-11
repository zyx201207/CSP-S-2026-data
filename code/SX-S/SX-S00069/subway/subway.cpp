#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 5e5+5;
ll c, n, m, d, q, w[N], t, k, a[N], asd, ch;
string s;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	t = w[1];
	for (int i = 0; i < n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[ch + j] >> w[i];
			//cout << endl << a[i * k + j] << " ";
		}
		ch += k;
	}
	ll er = ch;
	stable_sort(a + 1, a + 1 + er);
	//for (int i = 1; i <= n * k; i++)
	//	cout << a[i] << " ";
	for (int i = 1; i <= ch; i++) {
		if (a[i] == a[i - 1]) {
			a[i] = 0;
			asd++;
		}
	}
	stable_sort(a + 1, a + 1 + er);
	for (int i = asd + 1; i <= ch; i++) {
		s += char(a[i] + '0');
	}
	for (int i = 1; i <= q; i++) {
		char x, y;
		cin >> x >> y;
		ll qw1 = s.find(y), qw2 = s.find(x);
		ll ans = abs(qw1 - qw2);
		//cout << t << endl;
		ans *= t;
		ans *= 4;
		cout << ans << "\n";
		ans = 0;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/