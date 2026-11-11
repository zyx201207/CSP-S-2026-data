#include<bits/stdc++.h>
using namespace std;
long long int a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long int n,m;
	cin>>n>>m;
	long long int x=0,y=0,sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==i) sum++;
		x=min(a[i],x);
		y=max(a[i],y);
	}
	if(sum==n)
	{
		long long int l=1,r=n;
		while(l<r)
		{
			long long int mid=(l+r)>>1;
			long long int x=mid*(mid+1)/2;
			if(x<=m) l=mid+1;
			else r=mid;
		}
		cout<<l;
		return 0;	
	} 
	sort(a+1,a+n+1);
	for(int i=x;i<=y;i++)
	{
		long long int k=m,t=0;
		for(int j=n;j>=1;j--)
		{
			if(a[j]<=i && i-a[j]<=k)
			{
				t++;
				k-=(i-a[j]);
			}
			if(i-a[j]>m) break;
		}
		sum=max(sum,t);
	}
	cout<<sum;
	return 0;
}
