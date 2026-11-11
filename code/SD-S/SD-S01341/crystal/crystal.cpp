#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int a[N];
int sum[N], cnt[N];
inline int read()
{
	int x = 0, c = getchar(), k = 1;
	while (c != '-' && (c < '0' || c > '9')) c = getchar(); 
	if (c == '-') k = -1, c = getchar();
	do x = x * 10 + (c ^ 48), c = getchar();
	while('0' <= c && c <= '9');
	return x * k;
}
inline void write(int x)
{
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 ^ 48);
}
inline void write(int x, char c)
{
	write(x), putchar(c);
}
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n = read(), m = read();
	for (int i = 1; i <= n; i ++)
		a[i] = read();
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++)
	{
		sum[i] = sum[i - 1] + (a[i] - a[i - 1]) * (i - 1);
	}
	int ans = upper_bound(sum + 1, sum + n + 1, m) - sum - 1;
	write(ans);
	return 0;
}

