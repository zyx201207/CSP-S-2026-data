#include<bits/stdc++.h>//baolixiefa
using namespace std;
#define ll long long
string s="";
ll a[200005];
char c;
ll n;
bool pd(string s)
{
	for(ll i=0;i<s.size()/2;i++)
		if(s[i]!=s[s.size()-i-1]) return 0;
	return 1;
}
ll xl(string s)
{
	ll n=s.size(),ans=0;
	for(ll i=0;i<n/2;i++)
		if(s[i]!=s[n-i-1])
		{
			s[n-i-1]=s[i];
			ans++;
		}
	return ans;
}
ll xr(string s)
{
	ll n=s.size(),ans=0;
	for(ll i=n-1;i>=n/2;i--)
		if(s[i]!=s[n-i-1])
		{
			s[n-i-1]=s[i];
			ans++;
		}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i]>>c;
		for(ll j=1;j<=a[i];j++)
			s+=c;	
	}
	if(pd(s))
	{
		cout<<0;	
	}
	else
	{
		ll x=xl(s),y=xr(s);
		if(x<y) cout<<x;
		else cout<<y;
	}
	return 0;
}