#include <bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2,s="ABCDF";
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<'1';
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1])
	{
		cout<<'1';
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if((s1[2]>='A' && s1[2]<='C')&&(s2[2]>='A' && s2[2]<='C'))
	{
		cout<<'1';
		for(int i=0;i<2;i++)
		{
			if((s1[2]==s[i] && s2[2]==s[i+1]) || (s1[2]==s[i+1] && s2[2]==s[i]))
			{
				cout<<'1';
				return 0;
			}
		}
		cout<<'0';
	}
	else if((s1[2]=='D' && s2[2]=='F') || (s2[2]=='D' && s1[2]=='F'))
	{
		cout<<"11";
	}
	else
	{
		cout<<"00";
	}
	return 0;
} 
