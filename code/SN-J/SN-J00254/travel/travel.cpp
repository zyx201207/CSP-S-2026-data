#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a,zz[5];
int main ()
{

	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
		zz[0]=1;
	else
	{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		zz[1]=1;
	}
	else
	{
		cout<<"1000";
		return 0;
	}
	if((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))
	{
		zz[2]=1;
		a=1;
	}
	else if((s1[2]>='D'&&s1[2]<='F')&&(s2[2]>='D'&&s2[2]<='F')) 
	{
		zz[2]=1;
		a=0;
	}
	else 
	{
		cout<<"1100";
		return 0;	
	}
	if(a==1)
	{
		if((s1[2]=='A'&&s2[2]=='B')||(s2[2]=='A'&&s1[2]=='B')||(s1[2]=='C'&&s2[2]=='B')||(s2[2]=='C'&&s1[2]=='B'))
			zz[3]=1;
		else
		{
			cout<<"1110";
			return 0;
		}	
	}
	else if(a==0)
	{
		if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))
			zz[3]=1;
		else
		{
			cout<<"1110";
			return 0; 
		}
	}
	for(int i=0;i<4;i++)
	{
		cout<<zz[i];
	}
	

	return 0;
}
