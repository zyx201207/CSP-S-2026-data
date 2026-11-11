#include <bits/stdc++.h>
using namespace std;


char s1[100000000] = {}, s2[100000000] = {};

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, a, longn = 0;
	char c;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		cin >> c;
		for (int j = 1; j <= a; j++) {
			s1[longn + 1] = c;
			longn++;
		}
	}
	int num = 0;
	if (longn % 2 == 0) {
		for (int i = longn; i >= longn / 2 + 1; i--)
			s2[longn - i + 1] = s1[i];
		for (int i = 1; i <= longn / 2; i++) {
			if (s1[i] != s2[i])
				num++;
		}
	} else {
		for (int i = longn; i >= longn / 2 + 2; i--)
			s2[longn - i + 1] = s1[i];
		for (int i = 1; i <= longn / 2; i++) {
			if (s1[i] != s2[i])
				num++;
		}
	}
	cout << num;
	return 0;
}