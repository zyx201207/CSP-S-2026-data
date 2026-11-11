#include <bits/stdc++.h>
using namespace std;
long long n;
long long L, R, sum;
int a[200001];
char b[200001];
string s;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		for (int j = 1; j <= a[i]; j++) {
			s += b[i];
		}
	}
	L = 0, R = s.size() - 1;
	while (L <= R) {
		if (s[L] != s[R]) {
			sum++;
			L++;
			R--;
		} else if (s[L] == s[R]) {
			L++;
			R--;
		}
	}
	cout << sum;
	return 0;
}