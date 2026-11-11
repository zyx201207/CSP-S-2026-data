#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long i,j,k,n,m,ans,sum,nu;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	ans=1;
	sum=0;
	for(i=2;i<=n;i++)
	{
		sum+=nu*(a[i]-a[i-1]);
		if(sum>m)
		{
			while(sum>m)
			{
				sum-=(a[i]-a[i-nu]);
				nu--;
			}
		}
		nu++;
		ans=max(ans,nu);
	}
	cout<<ans;
	return 0;
}
