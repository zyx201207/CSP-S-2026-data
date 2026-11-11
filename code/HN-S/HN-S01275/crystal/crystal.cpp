#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 114;
__int128 read() {
	__int128 x = 0, f = 1;
	char c = getchar();
	for(;c < 48 || c > 57; c = getchar())
		if(c == '-')
			f = -1;
	for(;c >= 48 && c <= 57; c = getchar())
		x = x * 10 + c - 48;
	return x * f;
}
void write(__int128 x) {
	if(x < 0) x = -x, putchar('-');
	if(x > 9) write(x / 10);
	putchar(x % 10 + 48);
	return ;
}
__int128 m, sum, tmp;
__int128 a[N];
ll n, ans, l, len;
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n;
	m = read();
	for(int i = 1; i <= n; i++)
		a[i] = read();
	sort(a + 1, a + 1 + n);
	l = 1;
	for(int i = 1; i < n; i++) {
		len = i - l + 1;
		tmp = len * (a[i + 1] - a[i]) / m;
		while(sum + tmp * m > m + tmp * m - len * (a[i + 1] - a[i]) && l <= i)
			sum -= a[i + 1] - a[l], ++l;
		sum += len * (a[i + 1] - a[i]);
		ans = max(ans, i - l + 2);
	}
	cout << ans << endl;
	return 0;
}
