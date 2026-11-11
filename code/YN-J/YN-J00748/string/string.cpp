#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long a[N];
char s[N];
long long b[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	long long n, cnt = 0;
	long long sum = 0;
	cin >> n;
	for (long long i = 1; i <= n; i++ ) {
		cin >> a[i] >> s[i];
		b[i] += a[i] + b[i - 1];
		sum += a[i];
	}
	long long mid;
	if (sum % 2 == 0) {
		mid = sum / 2;
	} else {
		mid = sum / 2 + 1;
	}
	long long midi;
	for (long long i = 1; i <= n; i++) {
		if (b[i] >= mid) {
			midi = i;
		}
	}
	if (sum % 2 == 0) {
		cnt = abs((mid - b[midi - 1] ) - (b[midi] - mid ));
	} else {
		cnt = abs((mid - b[midi - 1] + 1) - (b[midi] - mid ));
	}

	for (long long l = midi + 1, r = midi + 1; r < n && l >= 1;) {
		if (a[l] > a[r]) {
			a[l] -= a[r];
			cnt += a[r];
			r++;
		} else if (a[l] < a[r]) {
			a[r] -= a[l];
			cnt += a[l];
			l--;
		} else {
			cnt += a[l];
			r++, l--;
		}
	}
	cout << cnt;
	return 0;
}