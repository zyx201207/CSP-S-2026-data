#include<bits/stdc++.h>
using namespace std;
int n,ans=1;
long long a[500010],m,b[500010];
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
		b[i]=b[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,t=i;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(a[i]*(i-mid+1)-(b[i]-b[mid-1])<=m)
			{
				t=mid;
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
		ans=max(ans,i-t+1);
	}
	cout<<ans;
	return 0;
}