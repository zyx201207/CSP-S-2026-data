#include <bits/stdc++.h>
using namespace std;
long long n,m,a[100001],b[100001],zong[100001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(long long i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(long long i = 1;i <= n;i++)
	{
		if(i == n)
		{
			zong[a[i]]++;
			break;
		}
		if(i == n - 1 && a[n - 1] != a[n])
		{
			zong[a[i]]++;
			zong[a[i + 1]] += 2;
			break;
		}
		for(long long g = 1;g <= n;g++)
		{
			b[g] = a[g];
		}
		long long o = 0;
		bool p = 0;
		for(long long k = i;k <= n;k++)
		{
			if(b[i] == b[k])
			{
				p = 1;
				o = k;
				break;
			}
		}
		if(p)
		{
			for(long long u = i;u <= o;u++)
			{
				b[u] = 0;
			}
		}
		for(long long j = i;j <= n;j++)
		{
			zong[b[j]]++;
		}
	}
	for(long long i = 1;i <= m;i++)
	{
		cout << zong[i] << " ";
	}
	return 0;
}