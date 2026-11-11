#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
string s;
int n;
unsigned long long cnt;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		char a;
		long long w;
		cin >> w >> a;
		for (long long j = 1; j <= w; j++) {
			s += a;
		}
	}
	unsigned long long l = 0, r = s.size() - 1;
	for (unsigned long long i = 1; i <= (s.size() / 2); i++) {
		if (s[l] != s[r]) {
			cnt++;
		}
		l++;
		r--;
	}
	cout << cnt;
	return 0;
}

