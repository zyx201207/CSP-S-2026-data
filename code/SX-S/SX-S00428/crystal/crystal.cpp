#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,a[N],res[N];
map<long long,int> mp;
bool check_A()
{
	for(int i=1;i<=n;i++)
		if(a[i]!=i)
			return false;
	return true;
}
bool check_B()
{
	ll d=a[2]-a[1];
	for(int i=3;i<=n;i++)
		if(a[i]-a[i-1]!=d)
			return false;
	return true;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll maxx=LLONG_MIN,minn=LLONG_MAX;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mp[a[i]]++;
		maxx=max(maxx,a[i]);
		minn=min(minn,a[i]);
	}
	sort(a+1,a+n+1);
	if(minn>=1000 && maxx<=1000)
	{
		for(int i=maxx;i>=minn;i--)
		{
			for(int j=n;j>=1;j--)
			{
				if(a[j]<i)
				{
					res[i]=j;
					break;
				}
			}
		}
		ll ans=LLONG_MIN;
		for(int i=minn;i<=maxx;i++)
		{
			ll sum=0,cnt=0;
			for(int j=res[i];j>=1;j--)
			{
				if(sum+abs(i-a[j])>m)
				{
	   			    ans=max(ans,cnt+mp[i]);
					break;
				}
				if(a[j]<=i)
				{
					sum+=abs(i-a[j]);
					cnt++;
				}
			}
			ans=max(ans,cnt+mp[i]);
		}
		cout<<ans;
	}
	else if(check_A())
	{
		ll cnt=0;
		while(m>1)
		{
			cnt++;
			m=m-m/2;
		}
		cout<<cnt+1;
	}
	else if(check_B())
	{
		ll cnt=0,d=a[2]-a[1];
		while(m-d>=0)
		{
			m-=d;
			d*=2;
			cnt++;
		}
		cout<<cnt+1;
	}
	return 0;
}