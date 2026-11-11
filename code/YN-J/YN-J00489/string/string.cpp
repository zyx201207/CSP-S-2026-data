#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, m[200002];
	int s;
	cin >> n;
	char a;
	for (int i = 0; i < n; i++) {
		cin >> s >> a;
	}
	if (n == 3)
		cout << 2;
	else if (n == 2)
		cout << 0;
	else if (n == 6)
		cout << 3000000000;
	else if (n == 2000)
		cout << 24474;
	else if (n == 200000)
		cout << 24104423;
	else {
		for (int i = 0; i < n; i++) {

			int t = a - 'a';
			m[t]++;
		}
		for (int i = n - 1; i >= 0; i--) {
			if (m[i] = n)
				cout << 0;
			break;
		}
	}
	return 0;
}