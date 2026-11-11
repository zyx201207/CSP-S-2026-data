#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long n , m , cnt , maxn;
long long a[N] , t[N];
bool check1()
{
	for (int i = 1 ; i <= n ; i ++)
	{
		if (a[i] != i)
		{
			return false;
		}
	}
	return true;
}
bool check2()
{
	long long x = a[2] - a[1];
	for (int i = 1 ; i < n ; i ++)
	{
		if (a[i + 1] - a[i] != x)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i ++)
	{
		cin >> a[i];
	}
	if (n <= 5000)
	{
		sort(a + 1 , a + n + 1);
		long long c = 1 , p = m;
		for (int i = 1 ; i <= n ; i ++)
		{
			c = i;
			p = m;
			cnt = 0;
			while (a[c + 1] == a[c])
			{
				c ++;
				cnt ++;
			}
			while (a[c] == a[c - 1])
			{
				c --;
			}
			while (p > 0 && c >= 1)
			{
				p -= a[i] - a[c];
				c --;
				cnt ++;
			}
			if (p < 0)
			{
				cnt --;
			}
			maxn = max(maxn , cnt);
		}
		cout << maxn;
	}
	else if (check1())
	{
		long long sum = 0 , cnt = 0;
		for (int i = 0 ; sum <= m && i < n ; i ++)
		{
			sum += i;
			cnt ++;
		}
		if (sum > m)
		{
			cnt --;
		}
		cout << cnt;
	}
	else if (check2())
	{
		long long x = a[2] - a[1];
		long long sum = 0;
		for (int i = 0 ; sum <= m && i < n ; i ++)
		{
			sum += i * x;
			cnt ++;
		}
		if (sum > m)
		{
			cnt --;
		}
		cout << cnt;
	}
	else
	{
		for (int i = 1 ; i <= n ; i ++)
		{
			t[a[i] + 101] ++;
		}
		long long c = 1 , p = m;
		for (int i = 1 ; i <= 201 ; i ++)
		{
			c = i;
			p = m;
			cnt = 0;
			while (p > 0 && c >= 1)
			{
				if ((i - c) * t[c] >= p)
				{
					cnt += p / (i - c);
					break;
				}
				cnt += t[c];
				p -= (i - c) * t[c];
				c --;
			}
			maxn = max(maxn , cnt);
		}
		cout << maxn;
	}
	return 0;
}
