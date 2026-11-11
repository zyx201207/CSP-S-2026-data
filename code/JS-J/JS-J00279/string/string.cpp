#include <bits/stdc++.h>
using namespace std;
long long n;
long long num , ans;
struct Node
{
	long long t;
	char s;
} a[100005];
int main()
{
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i].t >> a[i].s;
		num += a[i].t;
	}
	long long left = 0 , right = num - 1;
	long long m1 = 1 , z1 = 0 , m2 = a[n - 1].t , z2 = n - 1;
	long long so = 0, chan = 0;
	while (left <=
	 right)
	{
		if (z1 == z2)
		{
			break;
		}
		if ((a[z1].t - m1 + 1) > m2)
		{
			if (a[z1].s != a[z2].s)
			{
				ans += so;
			}
			so = m2;
			chan = 2;
			m1 += so;
		}
		else if ((a[z1].t - m1 + 1) < m2)
		{
			if (a[z1].s != a[z2].s)
			{
				ans += so;
			}
			so = a[z1].t - m1 + 1;
			chan = 1;
			m1 -= so;
		}
		else
		{
			if (a[z1].s != a[z2].s)
			{
				ans += so;
			}
			so = m2;
			chan = 0;
			z1++;
			m1 = 1;
			z2--;
			m2 = a[z2].t;
		}
		left += so;
		right -= so;
		if (chan == 1)
		{
			z1++;
			m1 = 1;
		}
		if (chan == 2)
		{
			z2--;
			m2 = a[z2].t;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
