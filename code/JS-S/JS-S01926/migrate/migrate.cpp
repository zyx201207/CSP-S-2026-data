#include<bits/stdc++.h>
using namespace std;
long long m,a[500005],ans=1,fbz,sum;
int n;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	sum=0;
	for(int i=1;i<n;i++)
	{
		sum+=a[n]-a[i];
	}
	if(sum<=m)
	{
		cout<<n;
		return 0;
	}
	if(a[2]-a[1]==a[3]-a[2]==a[10]-a[9])
	{
		long long v=a[2]-a[1];
		cout<<min(n,(int)sqrt((m*2)/v)+1);
		return 0;	
	}
	for(int i=2;i<=n;i++)
	{
		sum=0;fbz=1;
		for(int j=i-1;j>=1;j--)
		{
			sum+=a[i]-a[j];
			if(sum>m)
				break;
			fbz++;
		}
		ans=max(ans,fbz);
	}
	cout<<ans;
	return 0;
}