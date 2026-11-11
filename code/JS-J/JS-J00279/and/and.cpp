#include <bits/stdc++.h>
using namespace std;
long long m , n ,a[10000000] , t , p;
bool b[10000000];
long long d(long long ans , long long num)
{
	long a1 , a2 , maxn = ans;
	if (num > m)
	{
		return ans;
	}
	for (int j = 1;j <= n;j++)
	{
		if (b[j])
		{
			continue;
		}
		b[j] = 1;
		a1 = d(ans &= a[j], num++);
		maxn = max(maxn , a1);
		b[j] = 0;
		a2 = d(ans , num);
		maxn = max(maxn , a2);
	}
	return maxn;
}
int main()
{
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		b[i] = 1;
		p = max(d(a[i] , 2) , p);
		b[i] = 0;
	}
	cout << p;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
