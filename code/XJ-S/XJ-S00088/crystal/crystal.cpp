#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans[500005],cnt=0;
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
		ans[i]=ans[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(ans[i]+m>=a[i]*i)
		{
			cnt=i;
		}
	}
	cout<<cnt;
	return 0;
}
