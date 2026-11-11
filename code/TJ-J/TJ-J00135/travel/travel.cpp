#include<bits/stdc++.h>
using namespace std;

bool flag=true;
int c1,c2;
string s1,s2;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		flag=false; 
	}
	int r1=(s1[0]-'0')*10+(s1[1]-'0');
	int r2=(s2[0]-'0')*10+(s2[1]-'0');
	if(r1==r2&&flag)
	{
		cout<<1;
	}
	else 
	{
		cout<<0;
		flag=false;
	}
	if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'&&flag)
	{
		cout<<1;
	}
	else 
	{
		cout<<0;
		flag=false;
	}
	if(abs(s1[2]-s2[2])==1&&flag)
	{
		if(!((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C')))
		{
			cout<<1;
		}
		else cout<<0;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
