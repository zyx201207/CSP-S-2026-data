#include <bits/stdc++.h>
using namespace std;
long long a[200005];
string s;
char b[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, sum = 0, ans = 0, cnt = 0;
	cin >> n;
	for (long long i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		sum += a[i];
	}
	for (long long i = 0; i < n; i++) {
		for (long long j = 0; j < a[i]; j++) {
			s[j + cnt] = b[i];
		}
		cnt += a[i];
	}
	if (sum % 2 == 0) {
		long long c = sum / 2;
		for (long long i = 0; i < c; i++) {
			if (s[i] != s[i + c])
				ans++;
		}
	} else {
		long long c = (sum - 1) / 2;
		for (long long i = 0; i < c; i++) {
			if (s[i] != s[i + c])
				ans++;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}