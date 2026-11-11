#include<bits/stdc++.h>
using namespace std;
long long n,m,zz,a[500005],b[500005],c[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++) c[i]=a[i+1]-a[i];
	for(int i=1;i<=n;i++)
	{
		if(c[i]!=c[i+1]) zz=1;
		if(m<c[i])
		{
			cout<<0;
			return 0;
		}
		if(zz==0)
		{
			int ss=1,sum2=c[i];
			if(sum2+(ss+1)*c[i]<=m) ss++,sum2+=(ss+1)*c[i];
			cout<<ss+1;
			return 0;
			
		}
	}
	long long sum,j;
	for(long long i=n;i>=2;i--)
	{
		sum=0,j=i-1;	
		while(sum+a[i]-a[j]<=m && j>=1)
		{
			sum+=a[i]-a[j];
			b[i]++;
			j--;
		}
	}
	long long ans=0;
	for(long long i=1;i<=n;i++)
	{
		if(ans<b[i]) ans=b[i];
	}
	cout<<ans+1;
	return 0;
}
