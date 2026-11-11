#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string s1,s2;
	cin>>a>>s1>>b>>s2;
	if(a!=b)
	{
		cout<<"0000";
	}
	else
	if(s1[0]!=s2[0]||s1[1]!=s2[1])
	{
		cout<<"1000";
	}
	else
	if((s1[2]=='D'||s1[2]=='F')&&(s2[2]!='D'&&s2[2]!='F')||(s1[2]!='D'&&s1[2]!='F')&&(s2[2]=='D'||s2[2]=='F'))
	{
		cout<<"1100";
	}
	else
	{
		if(s1[2]>s2[2])
		{
			swap(s1[2],s2[2]);
		}
		if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='D'&&s2[2]=='F')
		cout<<"1111";
		else
		cout<<"1110";
	}
	return 0;
}
