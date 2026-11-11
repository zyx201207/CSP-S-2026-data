#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long n, m;
long long a[500005], ans = 0, maxn = 0;
struct node
{
	long long x, l, r;
}s[500005]; 
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin>>n>>m;
	for (int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1, a+n+1);
	while (m>0)
	{
		ans = 0;
		for (int i = 2;i<=n;i++)
		{
			long long b = a[i]-a[i-1];
			if (m>=b&&b!=0)
			{
				a[i-1] = a[i];
				m-=b;
				break;
			}
		}
		for (int i = 2;i<=n;i++)
		{
			
			long long b = a[i]-a[i-1];
			if (b==0) ans++;
		}
		 
		maxn = max(maxn, ans+1);
	}
	cout<<maxn<<endl;
	return 0;
}
/*
duya
………… 
别了吧，这阵风
把我带走
像一片落叶
在旋转中 
*/
