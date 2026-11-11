#include <bits/stdc++.h>
using namespace std;
int n,a[100005],m,ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==1)
	{
		for(int i=1;i<n;i++)
		{
			ans=max(a[i],a[i+1]);
		}
		cout<<ans;
		return 0;
	}
    sort(a+1,a+n+1);
    ans=a[n-m+1];
    cout<<ans;
	return 0;
}