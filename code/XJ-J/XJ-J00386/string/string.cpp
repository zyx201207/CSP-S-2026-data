#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll n,a,num,ans;
string s="";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		string c;
		cin>>a>>c;
		num+=a;
		for(ll j=1;j<=a;j++)
		{
			s+=c;
		}
	}

    ll l=0,r=num-1;
	while(l<r)
	{
		if(s[l]!=s[r])
		{
			ans++;
		}
		l++,r--;
	}
	cout<<ans;
	return 0;
}