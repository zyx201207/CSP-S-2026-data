#include<bits/stdc++.h>
using namespace std;
#define ll long long 
bool is_huiwen(string &s)
{
	string a=s;
	reverse(s.begin(),s.end());
	if(a==s)
	{
		return true;
	}
	return false;
}
ll check_wei(string s)
{
	ll cnt=0;
	ll mid=s.size()/2;
	if(s.size()%2==0)
	{
		for(size_t i=mid+1;i<=s.size();i++)
		{
			cnt++;
		}
	}
	else
	{
		for(size_t i=mid+2;i<=s.size();i++)
		{
			cnt++;
		}
	}
	return cnt;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++)
	{
		ll x;
		char ch;
		cin>>x>>ch;
		for(ll j=0;j<x;j++)
		{
			s.push_back(ch);
		}
	}
	if(!is_huiwen(s))
	{
		cout<<check_wei(s)<<endl;
	}
	else
	{
		cout<<0<<endl;
	}
	
	return  0;
}
