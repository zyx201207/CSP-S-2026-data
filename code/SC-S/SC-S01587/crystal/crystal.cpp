#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,a[1000005],b,c;
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i ++)
	{
		b+= a[i];
	}
	b= b/2;
	for(int i = 1;i <= n;i ++)
	{
		if(a[i] > b)
		{
			c[i] = a[i] - b;
		}
		if(a[i] < b)
		{
			c[i] = 0 - a[i];
		}
		else
		{
			c[i] = a[i];
		}
		
	}
		int n,m,a[1000005],b,c;
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i ++)
	{
		b+= a[i];
	}
	b= b/2;
	for(int i = 1;i <= n;i ++)
	{
		if(a[i] > b)
		{
			c[i] = a[i] - b;
		}
		if(a[i] < b)
		{
			c[i] = 0 - a[i];
		}
		else
		{
			c[i] = 0l
		}
		
	}	int n,m,a[1000005],b,c;
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i ++)
	{
		b+= a[i];
	}
	b= b/2;
	for(int i = 1;i <= n;i ++)
	{
		if(a[i] > b)
		{
			c[i] = a[i] - b;
		}
		if(a[i] < b)
		{
			c[i] = 0 - a[i];
		}
		else
		{
			c[i] = a[i];
		}
		
	}	int n,m,a[1000005],b,c;
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i ++)
	{
		b+= a[i];
	}
	b= b/2;
	for(int i = 1;i <= n;i ++)
	{
		if(a[i] > b)
		{
			c[i] = a[i] - b;
		}
		if(a[i] < b)
		{
			c[i] = 0 - a[i];
		}
		else
		{
			c[i] =a[i];
		}
		
	}
	return 0;
}