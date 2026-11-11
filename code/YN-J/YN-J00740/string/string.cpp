#include <bits/stdc++.h>
using namespace std;
string s;
long long n, sum[200005];
long long m, u = 0;
char l;

struct zfc {
	long long cd, sum;
	char c;
} a[200005];

int main() {

	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	a[0].cd = INT_MIN;
	cin >> n;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i].cd >> a[i].c;
		a[i].sum = a[i - 1].sum + a[i].cd;
		if (a[i].cd > a[u].cd)
			u = i;
	}
	long long p = a[n].sum / 2, o;
	if (n % 2 == 1)
		p++;
	for (long long i = 1; i <= n; i++) {
		if (a[i].sum >= p && a[i - 1].sum <= p) {
			o = i;
			break;
		}
	}
	for (long long i = 1; i <= n; i++) {
		if (i != o) {
			if (a[i].c != a[u].c) {
				m += a[i].cd;
				//	cout << a[i].cd << " " << a[i].c << '\n';
			}
		}
	}
//	cout << a[o].c;
	if (a[o - 1].sum == a[n].sum - a[o + 1].sum) {
		cout << m;
		return 0;
	} else {
		m += a[o].cd - 1;
		cout << m;
		exit(0);
	}
//fengexian
//	long long n = s.size();
//	a = 0;
//	n--;
//	for (long long i = 1; i <= n; i++) {
//		if (n % 2 == 0) {
//			if (i == n / 2)
//				break;
//		} else if (i == n - i + 1)
//			break;
//		if (s[i] != s[n - i + 1]) {
//			//cout << i << " " << s[i] << " " << s[n - i + 1] << '\n';
//			a++;
//		}
//	}
//	cout << a << '\n';

	return 0;
}
