#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[200005];
	char c[200005];
	long long sum = 0;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
	}
	for (int i = 1;i <= (n + 1) / 2;i++)
	{
		if(c[i] != c[n - i + 1])
		{
			sum += min(a[i],a[n - i + 1]);
			if(a[i] >= a[n - i + 1])
			{
				a[i] -= a[n - i + 1];
				n--;
				i--;
			}
			else
			{
				a[n - i + 1] -= a[i];
				n++;
			}
		}
	}
	cout << sum;
	return 0;
}
