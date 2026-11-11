#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans,cha,l,r;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (long long i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a,a+n+1);
	l=1;
	for (long long r=2;r<=n;r++)
	{
		cha+=(r-l)*(a[r]-a[r-1]);
		while (cha>m)
		{
			l++;
			cha-=a[r]-a[l-1];
		}
		ans=max(ans,r-l+1);
	}
	cout << ans;
	return 0;
}
