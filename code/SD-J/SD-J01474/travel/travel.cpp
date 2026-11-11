#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
bool is(string a,string b)
{
	if(((a=="A"||a=="B")||a=="C")&&((b=="A"||b=="B")||b=="C"))
	{
		return true;
	}
	else if((a=="D"||a=="F")&&(b=="D"||b=="F"))
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	string s11,s12,s21,s22;
	cin>>c1>>s1>>c2>>s2;
	s11=s1[0]+s1[1];
	s12=s1[2];
	s21=s2[0]+s2[1];
	s22=s2[2];
	if(c1==c2)
	{
		if(s11==s21)
		{
			if(is(s12,s22))
			{
				if(s12[0]-s22[0]==1||s22[0]-s12[0]==1)
				{
					cout<<"1111";
				}
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
