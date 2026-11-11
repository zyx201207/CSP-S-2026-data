#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
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
	
	string s11,s22;
	s11=s1;
	s22=s2;
	s1.erase(2);
	s2.erase(2);
	if(s1==s2)
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	
	if((s11[2]<='C'&&s22[2]<='C')||(s11[2]>='D'&&s11[2]>='D'))
	{
		cout<<1;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	
	if(s11[2]==s22[2]-1||s11[2]==s22[2]+1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
