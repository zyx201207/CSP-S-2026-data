#include<bits/stdc++.h>
using namespace std;
long long n,m,cry[500005],ans,a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> cry[i];
	}
	sort(cry+1,cry+n+1);
	for (int i = 1;i <= n;i++)
	{
		a[i] = a[i-1] + cry[i];
	}
	long long l=1,r=1;
	while(r <= n)
	{
		if (cry[r] * (r-l+1) - a[r] + a[l-1] > m) l++;
		ans = max(ans,r-l+1);
		r++;
	}
	cout << ans;
	return 0;
}
