#include<bits/stdc++.h>
using namespace std;
int n;
bool flag=false;
long long m,cnt,tot,maxx=1,sum[500005],a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=2;i<=n;i++)
	{
		sum[i]=a[i]-a[i-1];
	}
	for(int i=3;i<=n;i++)
	{
		if(sum[i]!=sum[i-1])flag=true;
	}
	if(flag==false)
	{
		cnt=m;
		tot=1;
		for(int i=n-1;i>=1;i--)
		{
			int t=a[n]-a[i];
			if(cnt>=t)
			{
				cnt-=t;
				tot++;
			}
			else
			{
				break;
			}
		}
		cout<<tot;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
	{
		cnt=m;
		tot=1;
		for(int j=i-1;j>=1;j--)
		{
			int t=a[i]-a[j];
			if(cnt>=t)
			{
				cnt-=t;
				tot++;
			}
			else
			{
				break;
			}
		}
		maxx=max(maxx,tot);
	}
	cout<<maxx;
	return 0;
} 