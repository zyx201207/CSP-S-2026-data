#include<bits/stdc++.h>
using namespace std;

bool flag = true;
long long n,m,l,ans;
long long a[500005];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(i >= 3)
		{
			if(a[i] - a[i - 1] != a[i - 1] - a[i - 2])
			{
				flag = false;
			}
		}
	}
	if(!flag)
	{
		sort(a + 1,a + 1 + n);
		for(long long i = 1;i < n;i++)
		{
			for(long long j = n;j > i;j--)
			{
				l = 0;
				for(long long k = i;k <= j;k++)
				{
					l += a[j] - a[k];
					if(l > m)
					{
						break;
					}
				}
				if(l <= m)
				{
					ans = max(ans,j - i + 1);
					cout << ans;
					return 0;
				}
			}
		}
	}
	else
	{
		int c = abs(a[2] - a[1]),l = 0;
		for(int i = 1;i <= n;i++)
		{
			l += c * i;
			if(l > m)
			{
				cout << i;
				return 0;
			}
			else if(l == m)
			{
				cout << i + 1;
				return 0;
			}
		}
		cout << n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
