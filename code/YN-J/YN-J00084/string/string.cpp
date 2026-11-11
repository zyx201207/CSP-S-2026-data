#include <bits/stdc++.h>
using namespace std;

struct str {
	long long bg, ed;
	char vl;
} s[200010];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, a;
	long long l = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		s[i].bg = l + 1;
		cin >> a;
		l += a;
		s[i].ed = l;
		cin >> s[i].vl;
	}
	long long i = 1, j = l, I = 1, J = n, ans = 0, dl, dr;
	while (I < J) {
		dl = s[I].ed;
		dr = l + 1 - s[J].bg;
		if (dr == dl) {
			long long x = dl - i + 1;
			i += x;
			j -= x;
			if (s[I].vl != s[J].vl) {
				ans += x;
			}
			I++;
			J--;
		} else if (dl < dr) {
			long long x = dl - i + 1;
			i += x;
			j -= x;
			if (s[I].vl != s[J].vl) {
				ans += x;
			}
			I++;
		} else {
			long long x = j - s[J].bg + 1;
			i += x;
			j -= x;
			if (s[I].vl != s[J].vl) {
				ans += x;
			}
			J--;
		}
//		cout << "i:" << i << " j:" << j << " I:" << I << " J:" << J << " ans:" << ans << endl;
	}
	cout << ans << endl;
	return 0;
}