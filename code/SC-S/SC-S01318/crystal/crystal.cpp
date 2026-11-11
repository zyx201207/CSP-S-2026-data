#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],ans=0LL;
long long x;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	x=1LL;
	for(int i=1;i<=n;i++)
	{
		for(int j=x;j<i;j++)
		{
			long long v=(i-j+1)*a[i]-(s[i]-s[j-1]);
			if(v<=m)
			{
				x=(long long)j;
				ans=max(ans,(long long)(i-j+1));
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}