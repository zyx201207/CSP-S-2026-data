#include<bits/stdc++.h>
using namespace std;
string c1,c2;
string s1,s2;
bool f=true;
bool ff(char,char);
bool fff(char,char);
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2&&f==true)
	{
		cout<<1;
	}
	else
	{
		f=false;
		cout<<0;
	}
	
	char t1=s1[0];	
	char t2=s1[1];
	char t3=s2[0];	
	char t4=s2[1];
	if(t1==t3&&t2==t4&&f==true)
	{
		cout<<1;
	}
	else
	{
		f=false;
		cout<<0;
	}
	
	char x=s1[2];
	char y=s2[2];
	if(f==true&&ff(x,y)==true)
	{
		cout<<1;
	}
	else
	{
		f=false;
		cout<<0;
	}
	
	if(f==true&&fff(x,y)==true)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	
	
	return 0;
}
bool ff(char i,char j)
{
	if(i=='A'&&j=='B')return true;
	else if(i=='B'&&j=='A')return true;
	else if(i=='A'&&j=='C')return true;
	else if(i=='C'&&j=='A')return true;
	else if(i=='B'&&j=='C')return true;
	else if(i=='C'&&j=='B')return true;
	else if(i=='D'&&j=='F')return true;
	else if(i=='F'&&j=='D')return true;
	
	return false;
}
bool fff(char i,char j)
{
	if(i=='A'&&j=='B')return true;
	else if(i=='B'&&j=='C')return true;
	else if(i=='D'&&j=='F')return true;
	
	return false;
}