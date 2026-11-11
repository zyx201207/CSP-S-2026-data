#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000"<<endl;
		return 0;
	}
	string ss1=s1.substr(0,2);
	string ss2=s2.substr(0,2);
	if(ss1!=ss2)
	{
		cout<<"1000"<<endl;
		return 0;
	}
	if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')
	{
		cout<<"111";
	}
	else if(s2[2]!='E'&&s1[2]!='E'&&s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')
	{
		cout<<"111";
	}
	else
	{
		cout<<"1100"<<endl;
		return 0;
	}
	char cc1=s1[2],cc2=s2[2];
	if((cc1=='A'&&cc2<='B')||(cc1=='C'&&cc2=='B')||(cc1=='D'&&cc2=='F'))
	{
		cout<<"1"<<endl;
	}
	else if((cc1=='B'&&cc2=='A')||(cc1=='B'&&cc2=='C')||(cc1=='F'&&cc2=='D'))
	{
		cout<<"1"<<endl;
	}
	else
	{
		cout<<"0"<<endl;
	}
	return 0;
}
