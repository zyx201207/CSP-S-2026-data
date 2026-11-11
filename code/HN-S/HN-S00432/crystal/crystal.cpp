#include <bits/stdc++.h>
using namespace std;
long long a[100001];
long long b[100001];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i]-a[i-1];
	}
	sort(b+1,b+n+1);
	
	
	int l=1,r=n;
	long long ans=0;
	long long sum=0;
	long long mid=(r+l)/2+1;
	for(int i=1;i<=mid;i++)
	{
		if(b[mid]>b[i])
		{
			b[i]+=1;
			sum++;
			ans+=3;
		}
		if(b[mid]-b[i]>0&&ans<=m)
		{
			sum=ans-sum;
		}
		
	}
	cout<<sum;
	
	return 0;
}
