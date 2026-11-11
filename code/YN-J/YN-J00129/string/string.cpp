#include <bits/stdc++.h>
using namespace std;
char s[20000005];

int main() {

	//TEST
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	//READ
	long long n, a, b = 1, ans = 0;
	char c;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a >> c;
		for (int j = b; j <= b + a; j++) {
			s[j] = c;
		}
		b += a;
	}
	for (int i = 1; i <= (b / 2); i++) {
		if (s[i] != s[b - i + 1]) {
			ans++;
		}
	}
	cout << ans ;
	return 0;
}