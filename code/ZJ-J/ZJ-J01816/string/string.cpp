#include<bits/stdc++.h>
using namespace std;
long long n,a[200001],sum[200001],l,mid,fi,la,ans;
char c[200001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	fi=1;
	la=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
		cin>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		long long mi=min(a[fi],a[la]);
		
		if(c[fi]==c[la])
		{
			a[fi]-=mi;
			a[la]-=mi;
			if(a[fi]==0)
			{
				fi++;
				
				}
			if(a[la]==0)
			{
				la--;
				}	
				
		}
		else
		{
			a[fi]-=mi;
			a[la]-=mi;
			if(a[fi]==0)
			{
				fi++;
				
				}
			if(a[la]==0)
			{
				la--;
				}
				ans+=mi;
		}
		if(la==fi)break;
	}
	cout<<ans;
	
	
	return 0;
}
