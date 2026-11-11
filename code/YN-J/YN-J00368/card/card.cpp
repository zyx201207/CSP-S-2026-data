#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
long long n, m, k = 1, l[maxn];
char a[maxn];
string s, s2;

int main() {

	freopen("card.in", "r", stdin);
	freopen("card.out,", "w", stdout);
	scanf("%lld", &n);
	scanf("%lld", &m);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}

	long long h = 0;
	long long u = 0;
	long long int len = (n + 1) * n / 2;
	for (int i = 1; i <= len + 1; i ++) {
		if (u == n - h) {
			u = 0;
			for (int j = 0; j < s.size(); j++) {
				l[s[j] - 48]++;
			}
			s = "";
		}
		s2 = "";
		if (k == n + 1) {
			h++;
			k = 1;
			for (int j = 1; j <= h; j++) {
				k++;
			}
		}

		s += a[k];
		k++;
		int le = s.size();
		if (i != 1) {
			for (int j = 0; j < le - 1; j++) {
				if (s[j] == s[le - 1]) {
					for (int o = j; o < le - 1; o++) {
						s[o] = ' ';
					}
				}
			}
		}
		for (int j = 0; j < s.size(); j++) {
			if (s[j] != ' ') {
				s2 += s[j];
			}
		}
		s = s2;

		u++;
	}

	for (int i = 1; i <= m; i++) {
		cout << l[i] << ' ';
	}

	return 0;
}