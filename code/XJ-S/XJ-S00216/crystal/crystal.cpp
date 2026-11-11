#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,i,j,sum,ans=0,flag=0,gc,cnt=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(i=2;i<n;i++)
	{
		if(a[i]-a[i-1]!=a[i+1]-a[i])
		{
			flag=1;
		}
	}
	if(flag==0)
	{
		gc=a[2]-a[1];
		for(i=2;i<=n;i++)
		{
			cnt=i*(i+1)/2*gc;
			if(cnt>m)
			{
				break;
			}
		}
		cout<<i;
	}
	else
	{
		for(i=n;i>=1;i--)
		{
			sum=0;
			for(j=i-1;j>=1;j--)
			{
				sum+=a[i]-a[j];
				if(sum>m)
				{
					break;
				}
				ans=max(ans,i-j+1);
			}
		}
		cout<<ans;
	}
	return 0;
}
