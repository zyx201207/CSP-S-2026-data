#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],num[500005],ssum,sum[500005],hum=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ssum=m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-1;j++)
		if(a[j]>a[j+1])
		{
			swap(a[j],a[j+1]);
		}
	}
	for(int i=2;i<=n;i++)
	{
		num[i-1]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		int x=0;
		ssum=m;
		sum[i]=1;
		for(int j=1;j<=n;j++)
		{
			ssum-=num[j]*j;
			if(ssum>=0)
			{
				sum[i]++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		hum=max(sum[i],hum);
	}
	cout<<hum;
	return 0;
}