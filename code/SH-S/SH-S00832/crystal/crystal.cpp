#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],j=1,k=1,sum[500005],ned[500005],s,ans;
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
		sum[i]=sum[i-1]+a[i];
	}
    while(j<=k&&k<=n)
    {
    	if((k-j+1)*a[k]<=sum[k]-sum[j-1]+m)
    	{
    		k++;
    		ans=max(ans,k-j);
		}
		else j++;
	}
	cout<<ans;
	
	return 0;
} 
