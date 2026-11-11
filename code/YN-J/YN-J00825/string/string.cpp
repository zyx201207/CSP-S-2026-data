#include <bits/stdc++.h>
using namespace std;
long long n, m;
char h;
string s;
long long sum = 0;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;

	for (int i = 0; i < n; i++) {

		cin >> m >> h;

		for (int j = 0; j < m; j++)

			s += h;
	}

	long long t = s.size();

	for (int i = 0; i < t / 2; i++) {

		if (s[i] != s[t - i - 1]) {
			sum++;
		}
	}

	cout << sum;
	return 0;
}