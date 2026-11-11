#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(f=='-')
			f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
ll a[500010],n,m,ans,h[500010];
bool cheak(ll l,ll mid)
{
	while(l<=mid)
	{
		if(a[mid]*(mid-l)-(h[mid-1]-h[l-1])<=m&&ans<mid-l)
		{
			return true;
		}
		else
			l++;
	}
	return false;
}
int f(ll l,ll r)
{
	ll mid;
	while(l<r)
	{
		mid=(l+r)/2;
		if(cheak(1,mid))
		{
			ans=max(ans,mid-l);
			l=mid+1;
		}
		else
		{
			r=mid;
		}
	}
	return l;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n;
	m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		h[i]=h[i-1]+a[i];
	cout<<f(1,n)-1;
	return 0;
}