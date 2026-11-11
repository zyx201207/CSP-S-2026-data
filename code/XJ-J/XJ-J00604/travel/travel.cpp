#include<bits/stdc++.h>
using namespace std;
long long int i,flag=0;
string c1,c2,s1,s2,s;
char c[4];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	c[0]='1';
	else
	c[0]='0';
	if(s1.substr(0,2)==s2.substr(0,2)&&c[0]=='1')
	c[1]='1';
	else
	c[1]='0';
	if(c[1]=='1'&&(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'&&s1[2]!='E'&&s2[2]!='E')&&c[0]=='1')
	c[2]='1';
	else
	c[2]='0';
	
	for(i=0;i<4;i++)
	{
		s=s1;
		if(s[2]!='C'&&s[2]!='D')
		{
		if(i==0)
		s[2]+=1;
	    }
	    if(s[2]=='D')
	    {
	    	if(i==0)
	    	s[2]+=2;
		}
	    if(s[2]!='D')
	    {
		if(i==1)
		s[2]-=1;
	    }
		if(i==2)
		s[1]-=1;
		if(i==3)
		s[1]+=1;
		if(s==s2)
		{
			flag=1;
			break;
		}
	}
	if(flag==1&&c[0]==1)
	c[3]='1';
	else
	c[3]='0';
	for(i=0;i<4;i++)
	cout<<c[i];
	return 0;
}