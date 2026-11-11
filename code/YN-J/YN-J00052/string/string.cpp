#include <bits/stdc++.h>
using namespace std;
long long n;
const int N = 1e14 * 2 + 10;
string s;
long long sum = 1;
long long cnt = 0;

void pj(long long t, char x) {
	for (long long i = sum; i <= sum + t - 1; i++) {
		s[i] = x;
	}
}

bool check_hw(string x, long long sum) {
	for (long long i = 1; i <= sum / 2; i++) {
		if (x[sum - i] != x[i])
			return false;
	}
	return true;
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (long long i = 1; i <= n; i++) {
		long long t;
		char x;
		cin >> t >> x;
		pj(t, x);
		sum = sum + t;
	}
	if (check_hw(s, sum)) {
		cout << 0;
		return 0;
	} else {
		for (long long i = 1; i <= sum / 2; i++) {
			if (s[sum - i] != s[i]) {
				s[sum - i] = s[i];
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
