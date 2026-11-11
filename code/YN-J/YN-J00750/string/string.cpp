#include <bits/stdc++.h>
using namespace std;
string s;
int n, m;
int sum = 0;
char c;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;

	while (n--) {
		cin >> m >> c;

		while (m--)
			s += c;
	}

	int len = int(s.size()) ;

	if (len % 2 != 0) {

		len = len / 2 + 1;

	} else
		len /= 2;
	string s1 = s;
	reverse(s.begin(), s.end());

	for (int i = 1; i <= len; i++) {

		if (s[i] != s1[i]) {
			sum++;
		}
	}

	cout << sum;

	return 0;
}
