#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500010], ans, sum[500010];
long long px = LLONG_MIN, pm = LLONG_MAX;

long long read() {
	long long num = 0;
	char ch;
	int k = 1;
	ch = getchar();
	if (isdigit(ch)) {
		num = ch - '0';
	} else {
		k = -1;
	}
	ch = getchar();
	while (isdigit(ch)) {
		num = num * 10 + ch - '0';
		ch = getchar();
	}
	return num * k;
}

long long diff() {
	long long k = 1;
	for (int i = 1; i * px * (1 + i) / 2 <= m; i ++) k ++;
	return min(k, n);
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(); 
	m = read();
	for (int i = 1; i <= n; i ++) {
		a[i] = read();
		px = max(px, a[i] - a[i - 1]);
		pm = min(pm, a[i] - a[i - 1]);
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i ++) {
		sum[i] = sum[i - 1] + a[i];
	}
	
	if (px == pm) {
		cout << diff();
		return 0;
	}
	int l, r, mid;
	for (int i = 1; i <= n; i ++) {
		l = 1, r = i;
		while (l <= r) {	
			mid = (l + r) / 2;
			if (a[i] * (i - mid + 1) - (sum[i] - sum[mid - 1]) <= m) {
				ans = max(ans, (long long)i - mid + 1);
				r = mid - 1;
			} else {
				l = mid + 1;    
			}
		}
	}
	cout << ans;
	return 0;
}

// 5 8 -3 -1 2 2 7