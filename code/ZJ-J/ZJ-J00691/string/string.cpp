#include <bits/stdc++.h>
using namespace std;
long long x[200005];
char c[200005];
string s;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> x[i] >> c[i];
		for (int j = 1; j <= x[i]; j ++) {
			s += c[i];
		}
	}
	long long cnt = 0;
	for (long long i = 0; i <= s.size() / 2 - 1; i ++) {
		long long r = s.size() - i + 1;
		if (s[i] != s[r]) cnt ++;
	}
	cout << cnt;
	return 0;
}
