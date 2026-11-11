#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long b[500010];
long long maxn(long long x,long long y)
{
	if(x>=y)
	{
		return x;
	}
	return y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i]-a[i-1];
	}
	long long ans=-1E9+7;
	for(int i=1;i<n;i++)
	{
		int j=i+1;
		long long all[500010];
		a[j-1]=0;
		while(true)
		{
			all[j]=0;
			all[j]=all[j-1]+b[j]*(j-i);
			if(all[j]>m)
			{
				break;
			}
			if(j>=n)
			{
				break;
			}
			j++;
		}
		ans=maxn(ans,j-i);
		
	}
	cout<<ans;
}
