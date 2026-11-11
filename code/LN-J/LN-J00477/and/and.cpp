#include <bits/stdc++.h>
using namespace std;
const long long N = 200005;
long long n , m , a[N] , num[35] , p[35] , ans = 1;
bool flag[35];
void init()
{
	p[0] = 1;
	for (long long i = 1 ; i <= 30 ; i++)
	{
		p[i] = p[i - 1] * 2;
	}
}
bool cmp(long long A , long long B)
{
	if (A == B)
	{
		return A > B;
	}
	for (long long i = 29 ; i >= 0 ; i--)
	{
		if (flag[i])
		{
			continue;
		}
		long long now1 = A & p[i];
		long long now2 = B & p[i];
		if (now1 == now2)
		{
			continue;
		}
		return now1 > now2;
	}
	return 1;
}
int main()
{
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	init();
	cin >> n >> m;
	for (long long i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		for (long long j = 0 ; j < 30 ; j++)
		{
			if (a[i] & p[j])
			{
				num[j]++;
			}
		}
	}
	for (long long j = 0 ; j < 30 ; j++)
	{
		if (num[j] < m)
		{
			flag[j] = 1;
		}
	}
	sort(a + 1 , a + n + 1 , cmp);
	ans = a[1];
	for (long long i = 2 ; i <= m ; i++)
	{
		ans &= a[i];
	}
	cout << ans;
	return 0;
}
