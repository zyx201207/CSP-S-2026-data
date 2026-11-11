#include <iostream>
#include <cstdio>

char st[200000005];

using namespace std;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;
	cin >> n;
	long long cnt = 0, ans = 0;
	for (long long i = 1; i <= n; i++) {
		long long k;
		char ch;
		cin >> k >> ch;
		for (long long j = 1; j <= k; j++) {
			st[++cnt] = ch;
		}
	}
	for (long long i = 1; i <= cnt / 2; i++) {
		if (st[i] != st[cnt - i + 1]) {
			++ans;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}