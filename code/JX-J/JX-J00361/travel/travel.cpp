#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen(travel.in,"r",stdin);
	freopen(travel.out,"w",stdout);
	int f=0;
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2)
	{
		cout<<"1";
		f=1;
	}
	else
	{
		cout<<"0";
	}
	if (f==1 && s1[1]==s2[1])
	{
		cout<<"1";
		f=2;
	}
	else
	{
		cout<<"0";
	}
	if (f==2 && int(s1[2])<68 && int(s2[2])<68)
	{
		cout<<"1";
		f=3;
	}
	else if (f==2 && int(s1[2])>=68 && int(s2[2])>=68)
	{
		cout<<"1";
		f=3;
	}
	else
	{
		cout<<"0";
	}
	if (f==3 && s1[2]-s2[2]==1 && int(s1[2])!=68 && int(s2[2])!=67)
	{
		cout<<"1";
	}
	else
	if (f==3 && s2[2]-s1[2]==1 && int(s1[2])!=67 && int(s2[2])!=68)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
