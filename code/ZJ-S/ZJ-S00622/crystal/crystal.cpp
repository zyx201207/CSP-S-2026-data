#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,m,nl[N];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll cj,zx=inf;
	char tf=1;
	for(int i=1;i<=n;i++)
	{
		cin>>nl[i];
		zx=min(zx,nl[i]);
		if(i==2)
		{
			cj=nl[i]-nl[i-1];
		}
		if(i>2)
		{
			if(nl[i]-nl[i-1]!=cj)
			{
				tf=0;
			}
		}
	}
	if(tf==1)
	{
		ll xh=0;
		for(int i=1;i<=n;i++)
		{
			xh+=(i-1)*cj;
			if(m<xh)
			{
				cout<<i-1;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			nl[i]-=zx;
		}
		sort(nl+1,nl+1+n);
		int cd=0;
		ll xh=0;
		for(int i=1,j=1;i<=n;)
		{
			if(m>=xh)
			{
				cd=max(cd,i-j+1);
				i++;
				xh+=(i-j)*(nl[i]-nl[i-1]);
			}
			else
			{
				j++;
				xh-=nl[i]-nl[j];
			}
		}
		cout<<cd;
	}
	return 0;
}
