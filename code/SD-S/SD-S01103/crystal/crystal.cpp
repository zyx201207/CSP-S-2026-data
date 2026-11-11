#include <bits/stdc++.h>
using namespace std;
long long read() {
	long long x = 0 , f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
void print(long long x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x < 10) {
		putchar(x + '0');
		return ;
	}
	print(x / 10);
	putchar(x % 10 + '0');
	return ;
}
long long a[500005];
long long maked[500005];
long long s[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n = read() , m = read();
	for (int i = 1 ; i <= n ; i ++) {
		a[i] = read();
	}
	sort(a + 1 , a + n + 1);
	for (int i = 1 ; i < n ; i ++) {
		maked[i] = a[i + 1] - a[i];
		s[i] = s[i - 1] + maked[i];
	}
	long long l = 1 , r = 2 , ans = 1 , sum = maked[1] , k = 2;
	while (l <= n && r <= n) {
		if (l == r) {
			sum = maked[r ++];
			k = 2;
			continue;
		}
		int need = maked[r] * k;
		if (sum + need <= m) {
			r ++;
			ans = max(r - l + 1 , ans);
			sum += need;
			k ++;
		}
		else {
			l ++;
			sum -= (s[r - 1] - s[l - 1]);
			k --;
		}
	}
	print(ans);
	return 0;
}

