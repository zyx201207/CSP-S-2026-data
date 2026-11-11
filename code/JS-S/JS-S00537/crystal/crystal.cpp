#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n;
long long m,a[maxn],sum[maxn],sig[maxn],d[maxn],cmp;
bool flag=true;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i)
			flag=false;

	}
	if(n<=5000)
	{
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				sum[i]+=a[i]-a[j];
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(sum[i]>m)
			{
				cout<<i-1;
				return 0;
			}
		}
	}
	else if(flag) 
	{
		sig[1]=0;
		for(int i=1;i<n;i++)
		{
			sig[i+1]=sig[i]+i;
		}
		for(int i=1;i<=n;i++)
		{
			if(sig[i]>m)
			{
				cout<<i-1;
				return 0;
			}
		}
	}
	else
	{
		cmp=a[2]-a[1];
		for(int i=1;i<=n;i++)
		{
			d[i]=i*(i-1)/2*cmp;
		}
		int p=lower_bound(d+1,d+n+1,m)-d;
		cout<<p-1;
		return 0;
	}
	cout<<n;
	return 0;
}