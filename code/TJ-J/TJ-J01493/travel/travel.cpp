#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int s=0,c=0;
	if(c1==c2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if((c1[1]-'0')*10+c1[2]-'0'==(c2[1]-'0')*10+c2[2]-'0')
	{
		c=1;
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(c==1&&s1[3]!='B'&&s2[3]!='C'||c==1&&s1[3]!='C'&&s2[3]!='B')
	{
		s=1;
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(s==1&&s1[3]!='C'&&s2[3]!='E'||s==1&&s1[3]!='E'&&s2[3]!='C')
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
 } 
