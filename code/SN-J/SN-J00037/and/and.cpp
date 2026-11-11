#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5+10;
int n,m,cnt;
int a[N];

signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	if (n > 2000)
	{ 
		sort(a+1,a+n+1);
		cnt = a[n];
		for (int i = 2;i <= m;i++)
			cnt &= a[n-i+1];
	}
	else
	{
		if (m == n)
		{
			cnt = a[1];
			for (int i = 2;i <= n;i++)
				cnt &= a[i];
		}
		else if (m == 1)
		{
			cnt = -1;
			for (int i = 1;i <= n;i++)
				cnt = max(cnt,a[i]);
		}
		else if (m == 2)
		{
			cnt = -1;
			for (int i = 1;i <= n;i++)
				for (int j = i+1;j <= n;j++)
					cnt = max(cnt,a[i]&a[j]);
		}
	}
	cout << cnt;
	return 0;
}
