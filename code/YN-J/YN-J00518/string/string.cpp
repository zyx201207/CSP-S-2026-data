#include <bits/stdc++.h>
using namespace std;
const long long A = 1e9;
char s[A + 10];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, w = 0, q = 0;
	cin >> n;
	for (int i = 1; i <= n ; i++) {
		int a;
		char b;
		cin >> a >> b;
		for (int j = w + 1; j < a + w + 1; j++) {
			s[j] = b;
		}
		w = w + a;
	}
	for (int i = 1; i <= w / 2; i++) {
		if (s[i] != s[w + 1 - i]) {
			q++;
		}
	}
	cout << q;
	return 0;
}