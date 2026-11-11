#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.cpp","r",stdin);
	freopen("string.cpp","w",stdout);
	int n, a[100005];
	char c[100005];
	long long sum = 0;
	cin >> n;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i] >> c[i];
	}
	int l = 1, r = n;
	while(l < r)
	{
		if(c[l] != c[r])
		{
			if(a[l] > a[r])
			{
				sum += a[r];
				a[l] -= a[r];
				r --;
			}
			else
			if(a[l] < a[r])
			{
				sum += a[l];
				a[r] -= a[l];
				l ++;
			}
			else
			{
				sum += a[r];
				l ++;
				r --;
			}
		}
		else
		{
			if(a[l] > a[r])
			{
				a[l] -= a[r];
				r --;
			}
			else
			if(a[l] < a[r])
			{
				a[r] -= a[l];
				l ++;
			}
			else
			{
				l ++;
				r --;
			}
		}
	}
	cout << sum;
	return 0;
}
