#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005],ans,n,m,cnt;
int sum[200005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int js=m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	int ll=1,rr=n;
	for(int i=1;i<=n;i++)
	{
		if((i-1)*a[i]-sum[i-1]<m&&i*a[i+1]-sum[i]<m&&ll<rr)
		{
			ll++;
		}
		int j=n+i-1;
		if((j-1)*a[j]-sum[j-1]>m&&(j-2)*a[j-1]-sum[j-1]>m&&ll<rr)
		{
			rr--;
		}
	}
	for(int i=ll;i<=rr;i++)
	{
		cnt=1;
		m=js;
		for(int j=i-1;j>=1;j--)
		{
			if(a[i]-a[j]<=m)
			{
				m=m-a[i]+a[j];
				cnt++;
			}
			else
			{
				break;
			}
		}
		ans=max(ans,cnt);
	}
	cout <<ans;
	return 0;
} 


//Oct31==Dec25?