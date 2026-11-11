#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],c[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int t=a[2]-a[1],f=1;
	for(int i=3;i<=n;i++)
	{
		if(a[i]-a[i-1]!=f)
		{
			f=0;
			break;
		}
	}
	if(f==1)
	{
		int cnt=1,sum=0;
		for(int i=1;i<=n;i++)
		{
			sum+=cnt*t;
			if(sum>m) break;
			cnt++;
		}
		cout<<cnt<<"\n";
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		c[i-1]=a[i]-a[i-1];
	}
	int ans=0;
	for(int i=1;i<n;i++)
	{
		int cnt=1,sum=0;
		for(int j=i;j<=n;j++)
		{
			sum+=cnt*c[j];
			if(sum>m)
			{
				ans=max(ans,cnt);
				break;
			}
			cnt++;
		}
		if(sum==m)
		{
			ans=max(ans,cnt);
		}
		if(sum<m)
		{
			for(int j=i-1;j>=1;j--)
			{
				sum+=(a[n]-a[j]);
				if(sum>m)
				{
					ans=max(ans,cnt);
					break;
				}
				cnt++;
			}
			if(sum==m)
			{
				ans=max(ans,cnt);
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
