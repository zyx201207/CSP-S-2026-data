#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2;
	cin>>s1>>s2;
	for(int i=0;i<2;i++)
	{
		if(c1[i]!=s1[i])
		{
			cout<<"0000";
			return 0;
		}
	}
	for(int i=0;i<2;i++)
	{
		if(c2[i]!=s2[i])
		{
			cout<<"1000";
			return 0;
		}
	}
	if(c2[2]=='A'||c2[2]=='B'||c2[2]=='C')
	{
		if(s2[2]=='D'||s2[2]=='F')
		{
			cout<<"1100";
			return 0;
		}
	}
	else
	{
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
			cout<<"1100";
			return 0;
	}
	if((c2[2]=='D'&&s2[2]=='F')||(c2[2]=='F'||s2[2]=='D'))
	{
		cout<<"1111";
		return 0;
	}
	if((c2[2]==s2[2]+1||s2[2]==c2[2]+1)&&(c2[2]!='C'&&s2[2]!='D'&&(c2[2]!='D'&&s2[2]!='C')))
	{
		cout<<"1111";
		return 0;
	}
	cout<<"1110";
}