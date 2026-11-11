#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+6;
ll n,m,a[N],s,maxn,flag=1,flag2=1;
map<ll,ll> c;
void f()
{
	cout<<a[n];
}
void f1()
{
	ll ans=a[1];
	for(int i=1;i<=n;i++)
	{
		ans &=a[i];
	}
	cout<<ans;
}
void f3()
{
	ll ans=a[n] & a[n-1];
	cout<<ans;
}
void f4()
{
	ll ans=a[n-m+1];
	for(int i=n-m+1;i<=n;i++)
	{
		ans &=a[i];
	}
	cout<<ans;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll w=1;
	c[w]++;
	for(int i=1;i<=18;i++)
	{
		w*=2;
		c[w]++;
	}
	cin>>n>>m;
	if(c[n] == 0) flag2=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(c[a[i]+1]==0)
		{
			flag=0;
		}
		if(a[i] != i-1)
		{
			flag2=0;
		}
	}
	sort(a+1,a+n+1);
	if(m==1)
	{
		cout<<a[n];
	}
	else if( m==n)
	{
		f1();
	}
	else if(m==2)
	{
		f3();
	}
	else if(flag==1)
	{
		cout<<1;
	}
	else if(flag2==1)
	{
		f4();
	}
	else
	{
		
		for(int i=1;i<=n;i++)
		{
			
			s=a[i];
			for(int j=i;j<=i+m-1;j++)
			{
				s &= a[j];
			}
			maxn=max(maxn,s);
		}
		cout<<maxn;
	}
	return 0;
}
