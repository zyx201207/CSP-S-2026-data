#include<bits/stdc++.h>
#define MX 1000000
using namespace std;
long long ans;
long long a[MX + 10],f[MX + 10];
long long n,m;
int check(int x,int t)
{
	int i;
	int L = 1,R = t;
	while(L < R)
	{
		int mid = (L + R) / 2;
		if ((t - mid + 1) * x - f[t] + f[mid - 1] <= m)
		{
			R = mid;
		}
		else
		{
			L = mid + 1;
		}
	}
	return L;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	long long i;
	cin >> n >> m;
	for (i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for (i = 1;i <= n;i++)
	{
		f[i] = f[i - 1] + a[i];
	}
	for (i = 2;i <= n;i++)//假定ai是那个最终合成的水晶能量值 
	{
		ans = max(ans,i - check(a[i],i) + 1); 
	}
	cout << ans << endl;
	return 0;
}
/*
容易发现,可以最终的合成水晶可以枚举a中的所有数
考虑二分
*/







