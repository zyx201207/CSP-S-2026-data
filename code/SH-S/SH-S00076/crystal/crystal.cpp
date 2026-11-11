#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long LL;
LL n,m,a[1000005],ans;
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	bool flag = false,flag2 = false;
	sort(a+1,a+n+1);
	int x = a[n] - a[n-1];
	for(int i=1;i<=n;i++)
	{
		if(a[i] != i) flag = true;
	}
	for(int i=2;i<=n;i++)
	{
		if(a[i] - a[i-1] != x) flag2 = true;
	}
	if(!flag)
	{
		int num = 0,ans = 1;
		for(int i=1;i<=n;i++)
		{
			num += i;
			if(num > m) break;
			ans ++;

		}
		cout << ans;
		return 0;
	}
	if(!flag2)
	{
		int num = 0,ans = 1;
		for(int i=1;i<=n;i++)
		{
			num += x*i;
			if(num > m) break;
			ans ++;

		}
		cout << ans;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		LL use = m,sum = 1;
		for(int j=i+1;j<=n;j++)
		{
			use -= (a[i] - a[j]);
			if(use < 0) break;
			sum += 1;
		}
		ans = max(ans,sum);
	}
	cout << ans;
	return 0;
}
