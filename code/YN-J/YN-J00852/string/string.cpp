#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
char b[200005];
long long sum = 0;
string k;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	long long cnt = 0;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		sum += a[i];
		for (long long j = 1; j <= a[i]; j++) {
			k[cnt] = b[i];
			cnt++;
		}
	}
	long long ans = 0;
	for (long long i = 0, j = sum - 1; i < sum / 2; i++, j--) {
		if (k[i] != k[j]) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}