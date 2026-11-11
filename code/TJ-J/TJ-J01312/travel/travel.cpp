#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int a1,a2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a1=(s1[0]-48)*10+s1[1]-48;
	a2=(s2[0]-48)*10+s2[1]-48;
	s1=s1[2];
	s2=s2[2];
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	if(a1!=a2)
	{
		cout<<"1000";
		return 0;
	}
	if(s1<="C"&&s2<="C")
	{
		if(abs(s1[0]-s2[0])==1)
		{
			cout<<"1111";
		}
		else
		{
			cout<<"1110";
		}
	}
	else if(s1>"C"&&s2>"C")
	{
		cout<<"1111";
	}
	else
	{
		cout<<"1100";
	}
	return 0;
}
