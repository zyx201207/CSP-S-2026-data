#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int a[N], sum[N], d[N];
int read()
{
	int tmp;
	scanf("%lld", &tmp);
	return tmp;
}
void writeln(int tmp)
{
	printf("%lld\n", tmp);
}
void writesp(int tmp)
{
	printf("%lld ", tmp);
}
int ans = 1;
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n = read(), m = read();
	for (int i = 1; i <= n; i++)
	{
		a[i] = read();
	}
	sort(a + 1, a + 1 + n);
	for (int i = 2; i <= n; i++)
	{
		d[i] = a[i] - a[i - 1];
	}
	for (int i = 2; i <= n; i++)
	{
		
		sum[i] = sum[i - 1] + d[i];
	}
	int tmp = d[2];
	for (int l = 2, r = 2; l <= n && r <= n;)
	{
		while (r < n && tmp + d[r + 1] * (r - l + 2) <= m)
		{
			tmp += d[r + 1] * (r - l + 2);
			r++;
		}
		if (tmp <= m)
		{
			ans = max(ans, r - l + 2);
		}
		tmp -= sum[r] - sum[l - 1];
		l++;
		if (r < l)
		{
			r++;
			tmp = d[l];
		}
	}
	writeln(ans);
	return 0;
}
