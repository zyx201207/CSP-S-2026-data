#include <bits/stdc++.h> 
using namespace std;
string c1,s1,c2,s2; 
map<char,int> m1;
map<char,int> m2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	m1['A']=1;
	m1['B']=1;
	m1['C']=1;
	m1['D']=2;
	m1['F']=2;
	m2['A']=1;
	m2['B']=2;
	m2['C']=3;
	m2['D']=5;
	m2['F']=6;
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
	if((s1[0]==s2[0])&&(s1[1]==s2[1]))
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(m1[s1[2]]==m1[s2[2]])
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(abs(m2[s1[2]]-m2[s2[2]])==1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
