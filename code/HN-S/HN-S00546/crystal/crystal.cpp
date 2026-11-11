#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;
long long b[500010], num[500010];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n, m, a[500010],c = 99999, f;
	long long sum = 0;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int g = 1;g <= n;g++)
	{
		sum = a[g];
		f = m;
		for(int j = 1;j <= n;j++)
		{
			b[j] = sum - a[j];
		}
		int k = 0;
		for(int i = 0;i < n;i++)
		{
			for(int j = 2;j <= n - i;j++)
			{
				if(b[j] <= b[j - 1])
				{
					k = b[j - 1];
					b[j - 1] = b[j];
					b[j] = k;
				}
			}
		}
		for(int i = 1;i <= n;i++)
		{
			if(b[i] >= 0)
			{
				f -= b[i];
				if(f >= 0)
				{
					num[g] += 1;
				}
				else
				{
					break;
				}
			}
		}
	}
	int h;
	for(int i = 0;i < n;i++)
	{
		for(int j = 2;j <= n - i;j++)
		{
			if(num[j] <= num[j - 1])
			{
				h = num[j - 1];
				num[j - 1] = num[j];
				num[j] = h;
			}
		}
	}
	cout << num[n] << endl; 
	return 0;
 } 
