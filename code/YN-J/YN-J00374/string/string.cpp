#include <bits/stdc++.h>
using namespace std;
char s[100000005];
char s1[100000005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, sum = 0, j = 1, bt = 0, xb = 0;
	int a;
	char b;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		sum += a;
		for (int k = 1; k <= a; k++) {
			s[xb + k] = b;
		}
		xb = xb + a;
	}
	for (int i = sum ; i > 0; i--) {
		s1[j] = s[i];
		j++;
	}
	for (int i = 1; i <= sum; i++) {
		if (s1[i] != s[i]) {
			bt++;
		}
	}
//	cout << endl;
//	for (int i = 1; i <= sum; i++) {
//		cout << s1[i];
//	}
	cout << bt / 2;
	return 0;
}