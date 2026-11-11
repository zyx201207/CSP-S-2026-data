#include <bits/stdc++.h>
using namespace std;

int n, a[200067];

char s[200067];

long long ans = 0;
long long cnt = 0;

int main() {
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i ++ ) {
		scanf("%d %c", &a[i], &s[i]);
		cnt += a[i];//awa
	}
	
	long long l = 1, r = cnt;
	
	for (long long i = 1, j = n;l <= r &&i <= j;) {
		if (1) {
			int x = min(a[i], a[j]);
			if (s[j] != s[i]) ans += 0LL + x;
			l += 0LL +x;
			r -= x + 0LL;
			a[i] -= x, a[j] -= x;
			if (a[i] == 0) i += 0LL + 1;
			if (a[j] == 0) j --;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
