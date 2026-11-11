#include<bits/stdc++.h>
using namespace std;
bool st[4];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		for(int i=1;i<=4;i++) cout<<"0";
		return 0;
	}
	st[1]=true;
	string a=s1.substr(0,2);
	string b=s2.substr(0,2);
	string c=s1.substr(2,3);
	string d=s2.substr(2,3);
	if(a==b)
{
		st[2]=true;
	if(c=="A")
	{
		if(d=="B")
		{
			st[3]=true;
			st[4]=true;
		}
		if(d=="C")
		{
			st[3]=true;
			st[4]=false;
		}
	}
	if(c=="B")
	{
		if(d=="A" || d=="C")
		{
			st[3]=true;
			st[4]=true;
		}
	}
	if(c=="C")
	{
		if(d=="B")
		{
			st[3]=true;
			st[4]=true;
		}
		if(d=="A")
		{
			st[3]=true;
			st[4]=false;
		}
	}
	if(c=="D")
	{
		if(d=="F")
		{
			st[3]=true;
			st[4]=true;
		}
	}
	if(c=="F")
	{
		if(d=="D")
		{
			st[3]=true;
			st[4]=true;
		}
	}
}
	for(int i=1;i<=4;i++) cout<<st[i];
	return 0;
}
