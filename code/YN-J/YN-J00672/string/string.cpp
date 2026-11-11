#include <bits/stdc++.h>
using namespace std;
string s, s1, s2, s3;
long long n, x, i, j, c;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;

	for (i = 0; i < n; i++) {

		cin >> x;
		cin >> s1;

		for (j = 0; j < x; j++) {

			s += s1;
		}
	}

	for (i = 0; i < s.size() / 2; i++) {

		s2 += s[i];
	}

	for (i = s.size() / 2 + 1; i <= s.size(); i++) {

		s3 += s[i];
	}

	for (i = 0; i < s2.size(); i++) {

		if (s2[i] != s3[i])
			c++;
	}

	if (n == 1)
		cout << 0;
	else {
		cout << c;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}