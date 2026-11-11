//王悦霖 西安市第二十六中学 SN-J00687 
#include <iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int a1=0,a2=0,a3=0,a4=0;
	int x1=0,x2=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		a1=1;
		
	}
	
	
	if(a1==1&&s1[0]==s2[0]&&s1[1]==s2[1])
	{
		a2=1;
	}
	
	
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
	{
		x1=1;
	}
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
	{
		x2=1;
	}
	if(s1[2]=='F'||s1[2]=='D')
	{
		x1=0;
	}
	if(s2[2]=='F'||s2[2]=='D')
	{
		x2=0;
	}
	if(a1==1&&a2==1&&x1==x2)
	{
		a3=1;
	}
	
	
	if(a1==1&&a2==1&&a3==1)
	{
		if(x1==1)
		{
			if(s1[2]=='A'&&s2[2]=='B')
			{
				a4=1;
			}
			if(s1[2]=='B'&&s2[2]=='A'||s2[2]=='C')
			{
				a4=1;
			}
			if(s1[2]=='C'&&s2[2]=='B')
			{
				a4=1;
			}
		}
		if(x1==2)
		{
			if(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D')
			{
				a4=1;
			}
		}
	}
	cout<<a1<<a2<<a3<<a4;;
	return 0;
}
