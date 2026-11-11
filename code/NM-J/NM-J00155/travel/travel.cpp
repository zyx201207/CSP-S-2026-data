#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[2],s1[3],c2[2],s2[3],a=48,b=48,c=48,d=48;
	cin>>c1>>s1>>c2>>s2;
	int C11=c1[0],C12=c1[1],S11=s1[0],S12=s1[1],S13=s1[2],C21=c2[0],C22=c2[1],S21=s2[0],S22=s2[1],S23=s2[2];
	if(C11==C21&&C12==C22)
	{
		a=49;
		cout<<a;
	}
	else
	{
		cout<<a;
	}
	
	if(S11==S21&&S12==S22&&a==49)
	{
		b=49;
		cout<<b;	
	}
	else
	{
		cout<<b;
	}

	if(b==49)
	{
		if(S13==65||S13==66||S13==67)	
		{
			if(S23==65||S23==66||S23==67)	
			{
				c=49;
				cout<<c;
			}
			else
			{
				cout<<c;
			}
		}
		else if(S13==68||S13==69)
		{
			if(S23==68||S23==69)	
			{
				c=49;
				cout<<c;
			}
			else
			{
				cout<<c;
			}	
		}
	}
	else
	{
		cout<<c;
	}
	if(c==49)
	{
		if(S13==65&&S23==66)
		{
			d=49;
			cout<<d;
		}
		else if(S13==66&&S23==67)
		{
			d=49;
			cout<<d;
		}
		else if(S13==66&&S23==65)
		{
			d=49;
			cout<<d;
		}
		else if(S13==67&&S23==66)
		{
			d=49;
			cout<<d;
		}
		else if(S13==68&&S23==69)
		{
			d=49;
			cout<<d;
		}
		else if(S13==69&&S23==68)
		{
			d=49;
			cout<<d;
		}
		else
		{
			cout<<d;	
		}
	}
	else
	{
		cout<<d;
	}
	return 0;
 } 
