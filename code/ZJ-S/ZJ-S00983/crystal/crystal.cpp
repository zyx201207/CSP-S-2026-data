#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n,l,r,mid,ans;
long long m,mi=1e18,mx=-1e18,a[N];
bool check(int x)
{
	int j;
	long long i,c,s;
	for(i=mi;i<=mx;i++)
	{
		c=0;
		s=0;
		for(j=1;j<=n;j++)
		{
			if(i>=a[j])
			{
				c+=i-a[j];
				s++;
			}
		}
		if(c<=m&&s>=x) return 1;
	}
	return 0;
}
bool check1()
{
	int i;
	for(i=2;i<n;i++)
	{
		if(a[i]-a[i-1]!=a[i+1]-a[i]) return 0;
	}
	return 1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int i;
	long long s=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		mi=min(mi,a[i]);
		mx=max(mx,a[i]);
	}
	if(n==1)
	{
		cout<<"1\n";
		return 0;
	}
	if(check1())
	{
		for(i=1;i<=n;i++)
		{
			s+=i*(a[2]-a[1]);
			if(m>=s) ans=i+1;
		}
		cout<<ans<<"\n";
		return 0;
	}
	l=1;
	r=n;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	cout<<ans<<"\n";
	return 0;
}
