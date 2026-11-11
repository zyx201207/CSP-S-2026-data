#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
long long a[maxn],b[maxn];
long long n,m,ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a+1,a+1+n);
	for(int i = 1;i <= n;i++)
		b[i] = a[i + 1] - a[i];
	b[n] = 0;
	long long pd = 0;
	for(int i = 1;i <= n;i++)
	{
		if(b[i] == 0)
			pd++;
	}
	if(pd == n)
	{
		cout << n;
		return 0;
	}
	for(int i = 1;i <= n;i++)
	{
		long long k = 0;
		int cnt = 1;
		for(int j = i;j < n;j++)
		{
			k += b[j] * cnt;
			if(k <= m)
			{
				cnt++;
				continue;
			}
			else
			{
				if(cnt > ans)
					ans = cnt;
				break;
			}
		}
		if(cnt > ans)
			ans = cnt;
	}
	cout << ans;
	return 0;
}
//Oct31==Dec25 
