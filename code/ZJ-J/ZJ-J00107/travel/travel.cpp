#include<iostream>
#include<string>
#include<cmath>
using namespace std;
string s1,nu1,s2,nu2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>nu1>>s2>>nu2;
	if(s1==s2)
	{
		cout<<1;
	}
	else
	{
		for(int i=1;i<=4;i++)
		{
			cout<<0;
		}
		return 0;
	}
	if(nu1[0]==nu2[0]&&nu1[1]==nu2[1])
	{
		cout<<1;
	}
	else
	{
		for(int i=1;i<=3;i++)
		{
			cout<<0;
		}
		return 0;
	}
	if(nu1[2]<='C'&&nu2[2]<='C'||nu1[2]>'C'&&nu2[2]>'C')
	{
		cout<<1;
	}
	else
	{
		for(int i=1;i<=2;i++)
		{
			cout<<0;
		}
		return 0;
	}
	if(abs(nu1[2]-nu2[2])==1)
	{
		cout<<1;
	}
	else cout<<0;
	return 0;
}
