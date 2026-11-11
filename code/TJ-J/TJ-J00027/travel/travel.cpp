#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1;
	string c2;
	string s1;
	string s2;
	cin>>c1>>s1>>c2>>s2;
	#1
	if (c1==c2)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	
	#2
	string temp1="";
	temp1+=s1[0];
	temp1+=s1[1];
	string temp2="";
	temp2+=s2[0];
	temp2+=s2[1];
	if (temp1==temp2)
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	#3
	
	char a=s1[2];
	char b=s2[2];
	if ((a>='A' && a<='C' && b>='A' && b<='C') || (a>='D' && a<='F' && b>='D' && b<='F'))
	{
		cout<<1;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	#4
	if (a+1==b || b+1==a)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
