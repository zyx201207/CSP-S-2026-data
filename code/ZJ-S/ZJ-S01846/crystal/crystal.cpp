#include<bits/stdc++.h>
using namespace std;
void read(long long &x)
{
	int O = 0; char c; x = 0;
	for(c = getchar(); c < '0' || c > '9'; c = getchar()) O |= c == '-';
	for(; '0' <= c && c <= '9'; c = getchar()) x = (x << 3) + (x << 1) + (c ^ '0');
	x = (O? -x : x);
}
long long n, m, a[500002], ans = 0, sum[500002];
long long check(int k)
{
	long long cnt = 1, sum = 0;
	for(int i = k - 1; i >= 1; i--)
	{
		if(sum + a[k] - a[i] <= m)
		{
			sum += a[k] - a[i];
			cnt++;
		}
		else break;
	}
	return cnt;
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	read(n); read(m);
	for(int i = 1; i <= n; i++)
	{
		read(a[i]);
	}
	sort(a + 1, a + n + 1);
	for(int i = 2; i <= n; i++)
	{
		ans = max(ans, check(i));
	}
	cout << ans;
	return 0;
}