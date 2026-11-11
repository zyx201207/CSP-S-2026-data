#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
string s;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		ll a;
		char b;
		cin>>a>>b;
		for(ll j=1;j<=a;j++) 
		{
			s+=b;
		}
		
	}
	if(s.size()%2==0)
	{
		string left=s.substr(0,s.size()/2);
		string right=s.substr(s.size()/2,s.size()-1);
		if(left==right)
		{
			cout<<0;
			return 0;
		}
		string l2=left;
		reverse(l2.begin(),l2.end());
		string newstr=left+l2;
		ll cnt=0;
		for(ll i=0;i<s.size();i++)
		{
			if(s[i]!=newstr[i]) cnt++;
		}
		cout<<cnt;
		return 0;
	}
	else
	{
		string left=s.substr(0,(s.size()-1)/2);
		string right=s.substr((s.size()+1)/2,s.size());
		if(left==right)
		{
			cout<<0;
			return 0;
		}
		char mid=s[(s.size()-1)/2+1];
		string newstr="";
		string l2=left;
		reverse(l2.begin(),l2.end());
		newstr=left+mid+l2;
		ll cnt=0;
		for(ll i=0;i<=s.size();i++)
		{
			if(s[i]!=newstr[i]) cnt++;
		}
		cout<<cnt;
		return 0;
	}
	// TLE 
	return 0;
}
