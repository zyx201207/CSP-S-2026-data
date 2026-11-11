#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
char c[200005];
int cnt[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int i,j=n;
	int num=0,sum=0;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		num+=a[i];
		cnt[i]=cnt[i-1]+a[i];
	}
	for(i=1;i<=n;i++)
	{
		if(cnt[i+1]>num&&cnt[i]<=num)
		{
			break;
		}
		for(;j>=1;j--)
		{
			if(i==j)break;
			if(c[i]!=c[j])
			{
				if(a[i]-a[j]>=0)
				{
					a[i]-=a[j];
					sum+=a[j];
					a[j]=0;
				}
				else
				{
					a[j]-=a[i];
					sum+=a[i];
					a[i]=0;
				}
			}
			else
			{
				if(a[i]-a[j]>=0)
				{
					a[i]-=a[j];
					a[j]=0;
				}
				else
				{
					a[j]-=a[i];
					a[i]=0;
				}
			}
			if(a[i]==0)break;
		}
	}
	cout<<sum;
	return 0;
}