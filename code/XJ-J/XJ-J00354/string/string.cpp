#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 1e5 + 5;
char a[N];
long long n, s[N], ans, ans1, c, c1;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i] >> a[i];
	}
	
	if (n == 1) {
		cout << 0;
		return 0;
	} if (n == 2) {
		if (a[1] == a[2])
			cout << 0;
		else
			cout << min(s[1], s[2]);
		return 0;
	} else {
		int k = 0;
		for (int i = 1; i <= n/2; ++i) {
			c = s[i];
			while (c > 0) {
				if (a[n - k] != a[i] && s[n - k] > c) {
					ans += c;
					c = 0;
				} else if(a[n - k] != a[i] && s[n - k] <= c){
					ans += s[n - k];
					c -= s[n - k];
					++k;
				} else {
					++k;
				}
			}
		}
		
		int k1 = n - 1;
		for (int i = n; i >= n/2 + 1; --i) {
			c1 = s[i];
			while (c1 > 0) {
				if (a[n - k1] != a[i] && s[n - k1] > c1) {
					ans1 += c1;
					c1 = 0;
				} else if(a[n - k1] != a[i] && s[n - k1] <= c1){
					ans1 += s[n - k1];
					c1 -= s[n - k1];
					--k1;
				} else {
					--k1;
				}
			}
		}
		cout << min(ans, ans1);
	}

	return 0;
}
