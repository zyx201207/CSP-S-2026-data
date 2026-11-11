#include <bits/stdc++.h>
using namespace std;
string s, a[200050];

void ze(string s, string &a) {
	string c = "";
	int n = s.size();
	reverse(s.begin(), s.end());
	while (s != "0") {
		if ((s[0] - '0') % 2 != 0) {
			a += "1";
		} else {
			a += "0";
		}
		for (int i = 0; i < n; i++) {
			c += (s[i] - '0') / 2 + '0';
			if (i != 0)
				c[i - 1] += (s[i] - '0') % 2 * 5 + '0';
		}
		s = c;

	}
}

void cf(string &s) {
	string c = "";
	int i = 0;
	int n = s.size();
	reverse(s.begin(), s.end());
	while (c[i] != '0') {

		c += ((s[i] - '0') * 2 + (c[i] - '0')) % 10 + '0';
		c[i + 1] += ((s[i] - '0') * 2) / 10 + '0';
		i++;
	}
	s = c;
	reverse(s.begin(), s.end());
}

void jf(string &s, string a) {
	string c = "";
	int i = 0;
	int n = s.size();
	reverse(s.begin(), s.end());
	reverse(a.begin(), a.end());
	while (c[i] != '0') {

		c += ((s[i] - '0') + (a[i] - '0') + (c[i] - '0')) % 10 + '0';
		c[i + 1] += ((s[i] - '0') + (a[i] - '0')) / 10 + '0';
		i++;
	}
	s = c;
	reverse(s.begin(), s.end());
}

void zs(string a, string &s) {
	s = "";
	int n = 0;
	for (int i = a.size() - 1; i >= 0; i--) {
		if (a[0] != '0') {
			n = i;
			break;
		}
	}
	for (int i = n; i >= 0; i--) {
		for (int j = i; j >= 0; j--) {
			cf(a);
		}
		jf(s, a);
	}

}






int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		ze(s, a[i]);
		reverse(a[i].begin(), a[i].end());
	}
	sort(a + 1, a + n + 1);
	zs(a[m], s);
	cout << s;
	return 0;
}