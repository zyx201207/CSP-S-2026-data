#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int a[N],c[5005][5005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int minn = 1e13;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		minn = min(a[i],minn);
	}
	sort(a + 1,a + n + 1);
	bool f = 1,f2 = 1;
	int num = a[2] - a[1];
	for(int i = 1;i <= n;i++)
	{
		if(a[i] != i)
			f = 0;
		if(i >= 2 && a[i] - a[i - 1] != num)
			f2 = 0;
	}
	if(f || f2)
	{
		int sum = 0,ans = 1;
		for(int i = 2;i <= n;i++)
		{
			sum = sum + (i - 1) * (a[i] - a[i - 1]);
			if(sum > m)
			{
				ans = i - 1;
				break;
			}
		}
		if(sum <= m)
			ans = n;
		cout << ans;
	}
	else
	{
		int ans = 0;
		for(int i = 1;i <= n;i++)
		{
			int sum = 0;
			for(int j = i;j <= n;j++)
			{
				sum = sum + (j - i) * (a[j] - a[j - 1]);
				if(sum > m)
				{
					if(j - i > ans)
					{
//						cout << j << " " << i << "\n";
						ans = max(ans,j - i);
					}
					break;
				}
			}
			if(sum <= m)
			{
				if(n - i + 1 > ans)
				{
//					cout << i << " " << n << "\n";
					ans = max(ans,n - i + 1);
				}
			}
		}
		cout << ans;
	}
	return 0;
 } 
