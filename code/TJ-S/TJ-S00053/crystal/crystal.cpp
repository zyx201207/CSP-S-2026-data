#include <bits/stdc++.h> 
using namespace std;
long long n,m,k=0,sum=0,ans=0,tle=0,ac=0;
int aw=(n+1)/2,j=1;
long long x[10000005],a[10000005],uzi=m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	
	
	for(long long i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	
   	for(int i=1;i<=n;i++)
	{
		if(x[i]==x[i+1])
		{
			k++;
		}
	}
	if(k==n-1)
	{
		cout<<n;
		return 0;
	}
	sort(x+1,x+1+n);
	for(int i=1;i<=n;i++)
	{
		sum+=x[n]-x[i];
	}
    if(sum<=m)
    {
    	cout<<n;
    	return 0;
	}
	
	while(m>=x[aw]-x[j])
	{
			m=m-x[aw]-x[j];
			ans++;
			j++;
			if(ans==aw)
			{
				break;
			}
	}
		
	m=uzi;
	j=m;
		
    while(m>=x[j]-x[aw])
	{
			m=m-x[j]-x[aw];
			tle++;
			j--;
			if(tle==uzi)
			{
				break;
			}
	}
	int ak=max(ans,tle);
	cout<<ak-1;
	return 0;
} 
