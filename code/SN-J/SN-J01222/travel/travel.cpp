#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	int a1=(s1[0]-'0')*10+(s1[1]-'0');
	int a2=(s2[0]-'0')*10+(s2[1]-'0');
	if(a1==a2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"000";
		return 0;
	}
	int z1=s1[2]-'@';
	int z2=s2[2]-'@';
	int c1,c2;
	if(z1==1||z1==2||z1==3)
	{
		c1=1;
	}
	else
	{
		c1=0;
	}
	if(z2==1||z2==2||z2==3)
	{
		c2=1;
	}
	else
	{
		c2=0;
	}
	if(c1==c2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(max(z1,z2)-min(z1,z2)==1)
	{
		if(z1==3&&z2==4)
		{
			cout<<"0";
			return 0;
		}
		if(z1==4&&z2==3)
		{
			cout<<"0";
			return 0;
		}
		cout<<"1";
	}
	else cout<<"0";
	return 0;
} 
