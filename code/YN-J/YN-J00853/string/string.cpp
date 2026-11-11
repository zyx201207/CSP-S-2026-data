#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[200001];
char b[200001];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%lld", &n);
	for (long long i = 0; i < n; i++) {
		scanf("%lld %c", &a[i], &b[i]);
	}
	string s = "";
	for (long long i = 0; i < n; i++) {
		for (long long j = 0; j < a[i]; j++) {
			s += b[i];
		}
	}
	long long l = 0;
	for (long long i = 0; i <= n; i++) {
		l += a[i];
	}
	//cout << s << endl;

	if (n == 1) {
		cout << 0;
		return 0;
	}

	long long cnt = 0;
	for (long long i = 0; i < l / 2; i++) {
		if (s[i] != s[l] + 1 - i) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}