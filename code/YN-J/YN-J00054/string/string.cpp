#include <bits/stdc++.h>
using namespace std;
int len;
string s1;

bool hw(string s) {
	s1 = "\0";
	len = s.size();

	for (int i = len - 1; i >= 0; i--) {

		s1 =  s1 + s[i];
	}

	if (s1 == s)
		return true;
	return false;
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	int n, a1;
	string c1, s = "\0";
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> a1 >> c1;

		for (int j = 1; j <= a1; j++) {

			s = s + c1;
		}
	}

	if (hw(s))
		cout << 0;
	return 0;
}