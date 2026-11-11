#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500005],sum[500005];

bool check(int k)
{
	for(int i=1;i+k-1<=n;i++)
	{
		int j=i+k-1;long long maxv=-1e12;
		for(int x=i;x<=j;x++) maxv=max(maxv,a[x]);
		if(k*maxv-sum[j]+sum[i-1]<=m) return true;
	}
	return false;
}


int main()
{
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=n,mid;
	while(l<r)
	{
		mid=(l+r+1)/2;
		if(check(mid))
		{
			l=mid;
		}
		else r=mid-1;
		cout<<mid<<"\n";
	}
	cout<<l;
	return 0;
 } 
