#include<bits/stdc++.h>
using namespace std;
long long sum[500100];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,i,j=1,ans=1;
	cin>>n>>m;
	for(i=1;i<=n;++i) cin>>sum[i];
	sort(sum+1,sum+n+1);
	j=1;
	for(i=1;i<=n;++i) 
	{
		if(sum[i]*i-(sum[i]+sum[i-1])<=m) ans=max(ans,i);
		else 
		{
			for(;j<=i;++j)
			{
				if(sum[i]*(i-j)-(sum[i-1]-sum[j-1])<=m) 
				{
					ans=max(ans,i-j+1);
					break;
				}
			}
			if(j>i) j=i;
		}
		sum[i]+=sum[i-1];
	}
	cout<<ans;
	return 0;
}
