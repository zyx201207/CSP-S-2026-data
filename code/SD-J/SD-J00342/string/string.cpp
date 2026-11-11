#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline ll read() {
	ll k = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		k = k * 10 + (c - '0');
		c = getchar();
	}
	return k * f;
}

const int N = 2e5 + 5;

int n;
ll a[N];
ll sum1[N], sum2[N];
char c[N];


int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	n = read();
	for (int i = 1; i <= n; ++ i) {
		a[i] = read();
		cin >> c[i];
		sum1[i] = sum1[i - 1] + a[i];
	}
	
	for (int i = n; i >= 1; -- i) {
		sum2[i] = sum2[i + 1] + a[i];
	}
	
	int L = 1, R = n;
	ll ans = 0, l = 0, r = 0;
	while (L < R) {
		int len1 = sum1[L] - l, len2 = sum2[R] - r;
		//cout << L << ' ' << R << ' ' << l << ' ' << r << ' ' << '\n';
		if (len1 == len2) {
			if (c[L] != c[R]) ans += len1;
			l = sum1[L];
			r = sum2[R];
			L ++, R --;
		} else {
			if (len1 > len2) {
				if (c[L] != c[R]) ans += len2;
				l += len2;
				r += len2;
				R --;
			} else {
				if (c[L] != c[R]) ans += len1;
				l += len1;
				r += len1;
				L ++;
			}
		}
	} 
	
	printf("%lld", ans);
	
	return 0;
}	
