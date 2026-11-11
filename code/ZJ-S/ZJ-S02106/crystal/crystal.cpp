#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],b[N],x=1,maxn,k;
bool flag;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	k=a[2]-a[1];
	for(int i=2;i<=n;i++)
	{
		if(k!=a[i]-a[i-1])
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		m/=k;
		m*=2;
		long long sq=sqrt(m)*(1ll);
		if(sq*(sq+1)<=m)
		{
			cout<<sq+1;
			return 0;
		}
		else if(sq*(sq-1)<=m)
		{
			cout<<sq;
			return 0;
		}
	}
	for(int i=n;i>=2;i--)
	{
		if(i<=maxn)
		{
			break;
		}
		if(a[i]-a[i-1]>m)
		{
			continue;
		}
		long long ans=0;
		for(x=i-1;x>=1;x--)
		{
			ans+=(a[i]-a[x]);
			if(ans>m)
			{
				break;
			}
		}
		maxn=max(maxn,i-x);
	}
	cout<<maxn;
	return 0;
}
