#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,f1=0,f2=0,f3=0,f4=0;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=1||c1!=16||c2!=1||c2!=16)
	{
	    if(c1==c2)
	    f1=1;
	    else
	    {
	    	cout<<"0000";
	    	return 0;
		}
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	f2=1;
	else
	{
		cout<<"1000";
		return 0;
	}
	if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='A'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='E')||(s2[2]=='A'&&s1[2]=='B')||(s2[2]=='B'&&s1[2]=='C')||(s2[2]=='A'&&s1[2]=='C')||(s2[2]=='D'&&s1[2]=='E'))
	f3=1;
	else
	{
		cout<<"1100";
		return 0;
	}
	if(s1[2]+1==s2[2]||s2[2]+1==s1[2])
	f4=1;
	else
	{
		cout<<"1110";
		return 0;
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
}