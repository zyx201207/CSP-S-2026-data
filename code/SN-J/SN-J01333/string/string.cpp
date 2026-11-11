#include <bits/stdc++.h>
using namespace std;

long long cnt , l , r , tot , i1 , i2;
string s;

struct a_1
{
	long long b = 0 , c = 0;
	char v = 0;
};

a_1 a[100005] = {};

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n = 0;
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> a[i].b >> a[i].v;
		cnt += a[i].b;
		a[i].c = a[i].b + a[i - 1].c;
	}
	if (cnt % 2 == 0)
	{
		cnt /= 2;
		l = cnt;
		r = cnt + 1;
		char e , w;
		for (i1 = 1 ; i1 <= n ; i1++)
		{
			if (a[i1].c >= l)
			{
				e = a[i1].v;
				if (r <= a[i1].c)
				{
					w = a[i1].v;
					i2 = i1;
				}
				else
				{
					i2 = i1;
					i1++;
					w = a[i1].v; 
				}
				break;
			}
		}
		while (l >= 1)
		{
			if (e != w)
			{
				tot++;
			}
			l--;
			r++;
			if (l < a[i2].c)
			{
				i2--;
				e = a[i2].v;
			}
			if (r > a[i1].c)
			{
				i1++;
				w = a[i1].v;
			}
		}
	}
	else
	{
		cnt /= 2;
		l = cnt + 1;
		r = cnt + 1;
		char e , w;
		for (i1 = 1 ; i1 <= n ; i1++)
		{
			if (a[i1].c >= l)
			{
				e = a[i1].v;
				w = a[i1].v;
				i2 = i1;
				break;
			}
		}
		while (l >= 1)
		{
			if (e != w)
			{
				tot++;
			}
			l--;
			r++;
			if (l < a[i2].c)
			{
				i2--;
				e = a[i2].v;
			}
			if (r > a[i1].c)
			{
				i1++;
				w = a[i1].v;
			}
		}
	}
	cout << tot;
	return 0;
 } 
