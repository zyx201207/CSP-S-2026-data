#include <bits/stdc++.h> 
using namespace std;
const int sb = 1e9;
int n,m,a[sb],mid,k[sb],sum,num,p,x;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	mid = a[n / 2 + 1];
	for(int i = 1;i <= n;i++)
	{
		k[i] = a[i] - mid;
	}
	for(int i = 1;i <= n / 2;i++) 
	{
        sum += k[i];
	}
	for(int i = n - n / 2;i <= n;i++)
	{
		num += k[i];
	}
	if(abs(sum) <= abs(num))
	{
		for(int i = n - n / 2;i >= 1;i--)
		{
			a[i] += mid - a[i];
			if(p >= m)
			{
				break;
			}
			p += mid - a[i];
		}
		x = 1;
		for(int i = 1;i <= n / 2;i++)
		{
			if(a[i] == a[i + 1])
			{
				x++;
			}
		}
	}
	else
	{
		for(int i = n;i >= n - n / 2;i++)
		{
			mid += a[i] - mid;
			if(p >= m)
			{
				break;
			}
			p += a[i] - mid;
		}
		x = 1;
		for(int i = n - n / 2;i <= n;i++)
		{
			if(a[i] == a[i + 1])
			{
				x++;
			}
		}
	}
	cout << x;
	return 0;
}
