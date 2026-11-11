#include<bits/stdc++.h>
using namespace std;
char a1[3],a2[4],b1[3],b2[4],flag1,flag2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1[0]==b1[0]&&a1[1]==b1[1])
	{
		cout<<1;
		flag1=1;
	}
	else
	 cout<<0;
	
	if(flag1==1&&a2[0]==b2[0]&&a2[1]==b2[1])
	{
		cout<<1;
		flag2=1;
	}
	else
	 cout<<0;
	
	if(flag2==1&&flag1==1&&(a2[2]>='A'&&a2[2]<='C'&&b2[2]>='A'&&b2[2]<='C'||a2[2]>='D'&&a2[2]<='E'&&b2[2]>='D'&&b2[2]<='E'))
	 cout<<1;
	else
	 cout<<0;
	
	if(flag2==1&&flag1==1&&(a2[2]=='A'&&b2[2]=='B'||a2[2]=='B'&&b2[2]=='A'||a2[2]=='B'&&b2[2]=='C'||b2[2]=='B'&&a2[2]=='C'||a2[2]=='D'&&b2[2]=='E'||b2[2]=='E'&&a2[2]=='D'))
	 cout<<1;
	else
	 cout<<0;
	return 0;
 } 
