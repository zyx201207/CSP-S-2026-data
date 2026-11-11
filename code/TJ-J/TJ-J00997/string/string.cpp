#include <bits/stdc++.h>
using namespace std;
long long a[2000005][10];
int n;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out","w", stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		char x;
		
		cin >> a[i][1] >> x;
		a[i][2] = x;
	}
	int l = 1, r = n;
	long long sum = 0;
	while (l < r)
	{
		if (a[l][2] != a[r][2])
		{
			if (a[l][1] > a[r][1])
			{
				a[l][1] -= a[r][1];
				sum += a[r][1];
				r--;
			}
			else if (a[l][1] < a[r][1])
			{
				a[r][1] -= a[l][1];
				sum += a[l][1];
				l++;
			}
			else
			{
				sum += a[l][1];
				l++;
				r--;
			}
		}
		else
		{
			if (a[l][1] > a[r][1])
			{
				a[l][1] -= a[r][1];
				r--;
			}
			else if (a[l][1] < a[r][1])
			{
				a[r][1] -= a[l][1];
				l++;
			}
			else
			{
				l++;
				r--;
			}
		}
	}
	cout << sum;
	return 0;
}
