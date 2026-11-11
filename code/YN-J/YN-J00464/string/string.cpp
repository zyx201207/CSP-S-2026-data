#include <bits/stdc++.h>
using namespace std;
string s;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {

		int a;
		char b;
		cin >> a >> b;

		for (int j = 0; j < a; j++) {

			s += b;
		}
	}

	long long m = 0;

	for (int i = 0; i < s.size() / 2; i++) {

		if (s[i] != s[s.size() - 1 - i]) {
			m++;
		}
	}

	cout << m ;
	return 0;
	fclose(stdin);
	fclose(stdout);
}