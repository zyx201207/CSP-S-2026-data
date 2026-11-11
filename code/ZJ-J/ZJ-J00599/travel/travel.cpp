#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1,s1,c2,s2;
map<char,ll> mp;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	mp['D']=1;
	mp['F']=1;
	mp['A']=2;
	mp['B']=2;
	mp['C']=2;
	if(c1==c2)
	{
		cout<<'1';
	}
	else
	{
		cout<<"0000\n";
		return 0;
	}
	
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		cout<<'1';
	}
	else
	{
		cout<<"000\n";
		return 0;
	}
	
	if(mp[s1[2]]==mp[s2[2]])
	{
		cout<<'1';
	}
	else
	{
		cout<<"00\n";
		return 0;
	}
	
	if(s1[2]=='D'||s2[2]=='D')
	{
		cout<<'1';
	}
	else if(s1[2]!='C'&&s2[2]!='C')
	{
		cout<<'1';
	}
	else if(s1[2]!='A'&&s2[2]!='A')
	{
		cout<<'1';
	}
	else
	{
		cout<<'0';
	}
	cout<<"\n";
	return 0;
}

