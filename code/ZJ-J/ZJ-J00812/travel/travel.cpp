#include<bits/stdc++.h>
using namespace std;

string st1,ch1,st2,ch2;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>st1>>ch1>>st2>>ch2;
	if(st1==st2) cout<<1;
	else
	{
		cout<<"0000\n";
		return 0;
	}
	string line1=ch1.substr(0,2),line2=ch2.substr(0,2);
	if(line1==line2) cout<<1;
	else
	{
		cout<<"000\n";
		return 0;
	}
	map<char,int> mp;
	mp['A']=1;mp['B']=1;mp['C']=1;
	mp['D']=2;mp['F']=2;
	if(mp[ch1[2]]==mp[ch2[2]]) cout<<1;
	else
	{
		cout<<"00\n";
		return 0;
	}
	mp['A']=1;
	mp['B']=2;
	mp['C']=3;
	mp['D']=5;
	mp['F']=6;
	if(abs(mp[ch1[2]]-mp[ch2[2]])==1) cout<<1<<"\n";
	else cout<<0<<"\n";
	return 0;
}
