//This problem is ctystal
//This problem is ctystal
//This problem is ctystal
//This problem is ctystal
//This problem is ctystal
//This problem is ctystal
//This problem is ctystal
//This problem is ctystal
//This problem is ctystal
//This problem is ctystal
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[5000005];
ll s[5000005];
int main()
{
	freopen("ctystal.in","r",stdin);
	freopen("ctystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin>>n>>m;
	//cout<<n;
	ll answer=LLONG_MIN;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		ll k=abs(a[i]);
		if(k>answer)answer=k;
	}
	int kb=a[2]-a[1];
	if(n<=16)
	{
		ll maxx=LLONG_MIN;
		for(ll i=1;i<=n;i++)
		{
			ll b[60]={};
			for(ll j=1;j<=n;j++)
			{
				b[abs(a[i]-a[j])]++;
			}
			ll mm=m;
			ll cnt=0;
			for(ll j=0;j<=40;j++)
			{
				if(j*b[j]<=mm)
				{
					mm-=(j*b[j]);
					cnt+=b[j];
				}
				else
				{
					for(ll k=0;k<b[j];k++)
					{
						if(k*j<=mm&&(k+1)*j>mm)
						{
							mm-=(k*j);
							cnt+=k;
							break;
						}
					}
				}
				
			}
			if(cnt>maxx)maxx=cnt;
		}
		cout<<maxx;
		return 0;
	}
	if(answer<=100)
	{
		ll maxx=LLONG_MIN;
		for(ll i=-100;i<=100;i++)
		{
			ll b[205]={};
			for(ll j=1;j<=n;j++)
			{
				b[abs(i-a[j])]++;
			}
			ll mm=m;
			ll cnt=0;
			for(ll j=0;j<=200;j++)
			{
				if(j*b[j]<=mm)
				{
					mm-=(j*b[j]);
					cnt+=b[j];
				}
				else
				{
					for(ll k=0;k<b[j];k++)
					{
						if(k*j<=mm&&(k+1)*j>mm)
						{
							mm-=(k*j);
							cnt+=k;
							break;
						}
					}
				}
				
			}
			maxx=max(maxx,cnt);
		}
		cout<<maxx;
		return 0;
	}
	cout<<(floor(sqrt(n))*2+1)*b;
	return 0;
}
