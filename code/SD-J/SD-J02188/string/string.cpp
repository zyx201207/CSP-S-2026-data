#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	string b;
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ll num;
		cin>>num;
		string s;
		cin>>s;
		for(ll i=1;i<=num;i++)
		{
			b+=s;
		}
	}
	string q,h;
	ll c=b.size();
	int p=0;
	for(int i=1;i<c;i++)
	{
		if(b[i]==b[i-1])
		{
			p++;
		}
	}
	if(p+1==c)
	{
		cout<<0;
		return 0;
	}
	if(c%2!=0)
	{
		for(ll i=0;i<c/2;i++)
		{
			q[i]=b[i];
		}
		ll x=0;
		for(ll i=c-1;i>=c/2;i--)
		{
			
			h[x]=b[i];
			x++;
		}
		for(ll i=0;i<c/2;i++)
		{
			if(q[i]!=h[i])
				ans++;
		}
	}
	else if(c%2==0)
	{
		for(ll i=0;i<=c/2-1;i++)
		{
			q[i]=b[i];
		}
		ll y=0;
		for(ll i=c-1;i>=c/2;i--)
		{
			
			h[y]=b[i];
			y++;
		}
		for(ll i=0;i<=c/2-1;i++)
		{
			if(q[i]!=h[i])
				ans++;
		}
	}
	cout<<ans;
	return 0;
}
