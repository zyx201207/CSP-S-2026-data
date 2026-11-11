#include <bits/stdc++.h>
using namespace std;
long long a[200005];
char s[200005] = "0", s1[200005];
bool hw(int n) {
	for (int i = 0; i < n; i ++) {
		if (a[i + 1] != a[n - i]) {
			return 0;
		}
		if (s[i + 1] != s[n - i]) {
			return 0;
		}
	}
	return 1;
}
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n, nn = 1;
    cin >> n >> a[1];
    int lk = a[1], k;
    char lc, c;
    cin >> s[nn];
    lc = s[nn];
    s1[nn] = s[nn];
    for (int i = 2; i <= n; i ++) {
    	cin >> k >> c;
    	if (c != lc) {
    		s[nn] = lc;
    		s1[nn] = lc;
    		a[nn] = lk;
    		lk = 0;
    		lc = c;
    		nn ++;
		}
		lk += k;
	}
	if (n >= 2) {
		s[nn] = lc;
		s1[nn] = s[nn];
		a[nn] = lk;
	}
	n = nn;
	if (hw(n)) {
		cout << 0;
		return 0;
	}
	if (n == 2) {
		cout << min(a[1], a[2]);
		return 0;
	}
	/*
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; i ++) {
			char K = s[i];
			s[i] = s1[j];
			if(hw(n)) {
				cout << 1;
				return 0;
			}
			s[i] = K;
		}
	}
	*/
	return 0;
}
