#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	bool f1,f2,f3,f4;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) 
	{
		f1=1;
	}
	else 
	{
		cout<<"0000";
		return 0;
	}
	if(s1.substr(0,2)==s2.substr(0,2))
	{
		f2=1;
	}
	else 
	{
		cout<<"1000";
		return 0;
	}
	int len1=s1.size()-1,len2=s2.size()-1;
	if(s1[len1]>='A'&&s1[len1]<='C'&&s2[len2]>='A'&&s2[len2]<='C'||s1[len1]=='D'&&s2[len2]=='F'||s1[len1]=='F'&&s2[len2]=='D')
	{
		f3=1;
		
	}
	else
	{
		cout<<"1100";
		return 0;
	}
	if(s1[len1]=='D'&&s2[len2]=='F'||s1[len1]=='F'&&s2[len2]=='D'||s1[len1]>='A'&&s1[len1]<='C'&&s2[len2]>='A'&&s2[len2]<='C'&&abs(s1[len1]-s2[len2])==1)
	{
		f4=1;
	}
	else
	{
		cout<<"1110";
		return 0;
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
 } 
