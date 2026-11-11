#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500001],cnt=1,b[500001];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++)
	{
		b[i-1] = a[i] - a[i-1];
	}
	for(int i = 1;i <= n;i++)
	{
		//cout << b[i] << " ";
		m -= b[i] * i;
		cnt++;
		if(m <= 0 and b[i+1] != 0)
		{
			cout << cnt;
			return 0;
		}
	}
	//cout << cnt;
	return 0;
}
