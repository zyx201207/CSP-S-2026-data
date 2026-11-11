#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,ss,sss,num1,num2;
	cin>>c1>>s1>>c2>>s2;
	int n=s1.size();
	int nn=s2.size();
	for(int i=0;i<n;i++)
	{
		if(s1[i]>='A'&&s1[i]<='Z')
		{
			ss+=s1[i];
		}
		else if(s1[i]>='0'&&s1[i]<='9')
		{
			num1+=s1[i];
		}
	}
	for(int i=0;i<nn;i++)
	{
		if(s2[i]>='A'&&s2[i]<='Z')
		{
			sss+=s2[i];
		}
		else if(s2[i]>='0'&&s2[i]<='9')
		{
			num2+=s2[i];
		}
	}
	if(c1==c2)
	{
		if(num1==num2)
		{
			if(ss=="A"||ss=="B"||ss=="C")
			{
				if(sss=="A"||sss=="B"||sss=="C")
				{
					cout<<111;
				}
				else
				{
					cout<<1100;
					return 0;
				}
			}
			else if(ss=="D"||ss=="F")
			{
				if(sss=="F"||sss=="D")
				{
					cout<<1111;
					return 0;
				}
				else 
				{
					cout<<1100;
					return 0;
				}
			}
		}
		else
		{
			cout<<1000;
			
		}
	}
	else
	{
		cout<<0000;
		return 0;
	} 
	if(ss=="A")
	{
		if(sss=="B")
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	else if(ss=="B"||sss=="B")
	{
		cout<<1;
		return 0;
	}
	else if(ss=="C")
	{
		if(sss=="A")
		{
			cout<<1;
			return 0;
		}
	}
	else if(sss=="A")
	{
		if(ss=="B")
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	else if(sss=="C")
	{
		if(ss=="A")
		{
			cout<<1;
			return 0;
		}
	}
	return 0;
}