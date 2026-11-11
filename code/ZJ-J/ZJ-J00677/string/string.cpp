#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	unsigned long long n;
	string S = "";
	cin >> n;
	for (unsigned long long i = 1; i <= n; i++) {
		unsigned long long a;
		char c;
		cin >> a >> c;
		for (unsigned long long j = 1; j <= a; j++) {
			S += c;
		}
	}
	unsigned long long cnt = 0;
	unsigned long long l = S.size();
	for (unsigned long long i = 0; i < l / 2; i++) {
		if (S[i] != S[l - i - 1]) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
