#include<bits/stdc++.h>
using namespace std;
int cx1,cx2,zw1,zw2,si1,si2;
char zwf1,zwf2;
string se1,se2;
bool Exllent(char a,char b)
{
	if(a=='A'&&b=='B')
		return true;
	if(a=='B'&&b=='C')
		return true;
	if(a=='D'&&b=='E')
		return true;
	if(a=='B'&&b=='A')
		return true;
	if(a=='C'&&b=='B')
		return true;
	if(a=='E'&&b=='D')
		return true;
	return false;	
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx1>>se1>>cx2>>se2;
	if(cx1!=cx2)
	{
		cout<<"0000";
		return 0;
	}
	zw1+=int(se1[0]-'0');
	zw1*=10;
	zw1+=int(se1[1]-'0');
	zwf1=se1[2];
	if(zwf1=='A'||zwf1=='B'||zwf1=='C')
		si1=1;
	else
		si1=2;
	zw2+=int(se2[0]-'0');
	zw2*=10;
	zw2+=int(se2[1]-'0');
	zwf2=se2[2];
	if(zwf2=='A'||zwf2=='B'||zwf2=='C')
		si2=1;
	else
		si2=2;	
	if(zw1!=zw2)
	{
		cout<<"1000";
		return 0;
	}
	if(si1!=si2)
	{
		cout<<"1100";
		return 0;
	}
	if(Exllent(zwf1,zwf2)==false)
		cout<<"1110";
	else
		cout<<"1111";
	return 0;
}
