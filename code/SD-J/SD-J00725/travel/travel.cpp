#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e5+10;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool fg1=true;
	bool fg2=true;
	bool fg3=true;
	bool fg4=true;
	if(c1!=c2)
	{
		fg1=false;
	}
	if(s1[0]!=s2[0]||s1[1]!=s2[1])
	{
		fg2=false;
	}
	map<char,int> mp; 
	mp['A']=1;
	mp['B']=3;
	mp['C']=5;
	mp['D']=2;
	mp['F']=4;
	if((mp[s1[2]]%2)!=(mp[s2[2]])%2)
	{
		fg3=false;
	}
	if(mp[s1[2]]+2!=mp[s2[2]])
	{
		fg4=false;
	}
	if(fg1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(fg2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(fg3)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(fg4)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
return 0;
}
//fc travel3.ans travel.out
//Trick||Treat!
