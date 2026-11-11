#include <bits/stdc++.h>
using namespace std;
long long n, ans;
string s, q, h;
char a;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long p;
		cin >> p >> a;
		for (int j = 0; j < p; j++) {
			s += a;
		}
	}
	for (int i = 0; i < s.size() / 2; i++) {
		q += s[i] ;
	}
	for (int i =  s.size() - 1; i > s.size() / 2 ; i--) {
		h += s[i];
	}
	for (int i = 0; i < s.size(); i++) {
		if (q[i] != h[i]) {
			ans += 1;
		}
	}
	cout << ans;
	return 0;
}