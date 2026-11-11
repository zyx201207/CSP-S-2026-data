#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e5+7;
struct
{
	ll s;
	char c;
}zd[N];
ll ans,ok,n;
ll l,r;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	l=1;
	r=n;
	for(int i=1;i<=n;i++)
	{
		cin>>zd[i].s>>zd[i].c;
	}
	while(ok!=n&&ok!=n-1&&!(ok>n)&&l<=r)
	{
		if(zd[l].c!=zd[r].c)
		{
			ll sq=min(zd[l].s,zd[r].s);
			ans+=sq;
			zd[l].s-=sq;
			zd[r].s-=sq;
		}
		else
		{
			ll sq=min(zd[l].s,zd[r].s);
			zd[l].s-=sq;
			zd[r].s-=sq;
		}
		if(zd[l].s==0)
		{
			l++;
			ok++;
		}
		if(zd[r].s==0)
		{
			r--;
			ok++;
		}
	}
	cout<<ans;
}
