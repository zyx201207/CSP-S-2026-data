#include <bits/stdc++.h>
using namespace std;
long long n,a[500005],s[500005],ans,m;
int main()
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
		s[i] = a[i]-a[i-1];
	}
	for(int i = 1;i <= n;i++)
	{
		m -= s[i] * (i-1);
		ans++;
		if(m < 0)
		{
			cout << ans - 1<< endl;
			return 0;
		}
	}
	cout << n << endl;
	return 0;
}
