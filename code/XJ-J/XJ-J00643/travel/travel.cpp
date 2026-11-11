#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2,s;
int k;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		s=s+'1';
		k++;
	}
	else
	{
		s=s+'0';
	}
	if(s1[0]==s2[0] && s1[1]==s2[1] && k==1)
	{
		s=s+'1';
		k++;
	}
	else
	{
		s=s+'0';
	}
	if(((s1[3]<='C' && s2[3]<='C')||(s1[3]>'C' && s2[3]>'C')) && k==2)
	{
		s=s+'1';
	}
	else
	{
		s=s+'0';
	}
	if(((s1[3]>s2[3] && s1[3]-s2[3]==1) || (s2[3]>s1[3] && s2[3]-s1[3]==1)) && k==3)
	{
		s=s+'1';
	}                                                                 
	else
	{
		s=s+'0';
	}
	cout<<s;
	return 0;
}
         