#include<bits/stdc++.h>
using namespace std;
long long int a[500005],k[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long int n,i,j,flag;
	long long int m,ans,sum1,sum2,max;
	ans=1;
	flag=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		k[i]=a[i]-a[i-1];
		if(i>=3&&k[i]!=k[i-1]) flag=1;
	}
	if(flag==0)
	{
		sum1=0;
		ans=1;
		while(m>=0)
		{
			sum1=sum1+k[3];
			if(m-sum1>=0)
			{
				ans++;
				m=m-sum1;
			}
			else
			{
				cout<<ans;
				return 0;
			}
		}
	}
	max=0;
	for(i=n;i>=1;i--)
	{
		sum1=0;
		sum2=0;
		ans=1;
		for(j=1;j<i;j++)
		{
			sum1=sum1+k[i-j+1];
			sum2=sum2+sum1;
			if(sum2<=m)
			{
				ans++;
			}
			else
			{
				break;
			}
		}
		if(ans>=max) max=ans;
	}
	cout<<max;
	return 0;
 } 
