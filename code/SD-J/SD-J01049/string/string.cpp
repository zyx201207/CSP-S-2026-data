#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],num,sum;
char c[200005];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin >> n;
	num = 0;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
	}
	if (n == 1)
	{
		cout << 0;
		return 0;
	}
	if (n == 2)
	{
		if (c[1] == c[2])
		{
			cout << 0;
			return 0;
		}
		cout << min(a[1],a[2]);
		return 0;
	}
	int h = 1,t = n;
	while (h <= t)
	{
		if (c[h] != c[t])
		{
			if (a[h] == a[t])
			{
				sum += a[h];
				h++;
				t--;
			}
			else if (a[h] > a[t])
			{
				sum += a[t];
				a[h] = a[h] - a[t];
				t--;
			}
			else if (a[h] < a[t])
			{
				sum += a[h];
				a[t] = a[t] - a[h];
				h++;
			}
		}
		else 
		{
			if (a[h] == a[t])
			{
				h++;
				t--;
			}
			else if (a[h] > a[t])
			{
				a[h] = a[h] - a[t];
				t--;
			}
			else if (a[h] < a[t])
			{
				a[t] = a[t] - a[h];
				h++;
			}
		}
	}
	cout << sum;
	return 0;
}

