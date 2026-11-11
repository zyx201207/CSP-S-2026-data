#include <bits/stdc++.h>
using namespace std;
int n,ans=1,h,maxa=1;
long long m,a[500005],cnt=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	a[0]=0;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1;
	for (int r=2;r<=n;r++)
	{
		ans++;
		cnt+=(a[r]-a[r-1])*(ans-1);
		while (r-l>=1 && cnt>m)
		{
			ans--;
			l++;
			cnt-=(a[l+1]-a[l])*ans;
		}
		maxa=max(maxa,ans);
	}
	cout<<maxa;
	return 0;
}
