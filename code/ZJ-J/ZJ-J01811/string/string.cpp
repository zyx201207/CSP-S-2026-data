#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,ans;
string s;
char ch;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	for(ll i=1;i<=t;i++)
	{
		cin>>n>>ch;
		for(ll j=1;j<=n;j++)s+=ch;
	}
	ll l=s.size();
	for(ll i=1;i<=l/2;i++)
	{
		if(s[i-1]!=s[l-i])ans++;
	}
	cout<<ans<<'\n';
	return 0;
}

