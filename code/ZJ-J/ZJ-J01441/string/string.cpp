#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	long long a[n + 1];
	string b[n + 1];
	string c;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i] >> b[i];
		string w;
		for(long long j = 1;j <= a[i];j++)
		{
			w += b[i];
		}
		c += w;
	}
	long long ans = 0;
	for(long long i = 0;i < c.size() / 2;i++)
	{
		if(c[i] == c[c.size() - i - 1])
		{
			continue;
		}
		else
		{
			ans++;
		}
	}
	/*int q = 0;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i] >> b[i];
		q += a[i];
	}
	int t = 0;
	int ans = 0;
	for(int i = 1;i <= n;i++)
	{
		if(t == q / 2)
		{
			break;
		}
		else if(t + a[i] <= q / 2)
		{
			int w = t;
			bool v = 0;
			for(int j = n;j >= 1;j--)
			{
				if(w - a[j] >= 0)
				{
					w -= a[j];
					continue;
				}
				else if(w - a[j] < 0 && b[j] != b[i] && a[i] >= a[j])
				{
					ans += (a[j] - w);
					a[i] -= (a[j] - w);
					w = 0;
					break;
				}
				else if(a[i] <= a[j] && b[i] != b[j])
				{
					ans += a[i];
					a[j] -= a[i];
					v = 1;
					break;
				}
				else if (a[i] >= a[j] && b[i] != b[j])
				{
					ans += a[j];
					a[i] -= a[j];
				}
			}
			if(v = 1)
			{
				continue;
			}
			t += a[i];
		}
		else if(t + a[i] >= q / 2)
		{
			ans += q / 2 - t;
			break;
		}
	}*/
	cout << ans ;
	return 0;
}
