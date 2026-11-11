#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1])
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	unordered_map<char,long long> mapp;
	mapp['A']=1;
	mapp['B']=1;
	mapp['C']=1;
	mapp['D']=2;
	mapp['E']=2;
	if(mapp[s1[2]]==mapp[s2[2]])
	{
		cout<<1;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(abs(s1[2]-s2[2])==1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		return 0;
	}
	return 0;
}