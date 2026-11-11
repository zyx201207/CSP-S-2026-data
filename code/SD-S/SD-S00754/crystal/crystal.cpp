#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
ll n,m,l,r,mid,ans=0,a[500005];
bool sa=1,sb=1,sm=1;
void force()
{
	ll ti,sum;
	for(int i=n;i>=1;i--)
	{
		ti=m;
		sum=0;
		for(int j=i;j>=1;j--)
		{
			if(a[i]-a[j]>ti)
			{
				break;
			}
			else
			{
				ti=ti-(a[i]-a[j]);
				sum++;
			}
		}
		if(sum>ans)
		{
			ans=sum;
		} 
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(100<abs(a[i]))
		{
			sm=0;
		}
		if(a[i]!=i)
		{
			sa=0;
		}
		if(i!=1)
		{
			if(a[i]-a[i-1]!=a[2]-a[1])
			{
				sb=0;
			}
		}
	}
	sort(a+1,a+n+1);
	if(sa)
	{
		for(int i=n;i>=1;i--)
		{
			m-=(a[n]-a[i]);
			if(m<0)
			{
				break;
			}
			ans++;
		}
		cout<<ans<<endl;
		return 0;
	}
	if(sb)
	{
		ll cha=a[2]-a[1];
		for(int i=n;i>=1;i--)
		{
			m-=cha*(n-i);
			if(m<0)
			{
				break;
			}
			ans++;
		}
		cout<<ans<<endl;
		return 0;
	}
	if(sm&&n>5000)
	{
		ll sum,ti;
		for(int i=a[n];i>=a[1];i--)
		{
			int j=(int)(upper_bound(a+1,a+n+1,i)-a-1);
			sum=0,ti=m;
			for(;j>=1;j--)
			{
				ti-=(i-a[j]);
				if(ti<0)
				{
					break;
				}
				sum++;
			}
			if(sum>ans)
			{
				ans=sum;
			}
		}
		cout<<ans<<endl;
		return 0;	
	} 
	force();
	return 0;
}
