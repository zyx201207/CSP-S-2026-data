#include<bits/stdc++.h>
using namespace std;
char c1[105],c2[105],s1[105],s2[105];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	int a=0,b=0;
	for(int i=0;i<=1;i++)
	{
		a=(c1[i]-'0')+a*10;
		b=(s1[i]-'0')+b*10;
	}
	if(a!=b)
	{
		cout<<0000;
	}
	else
	{
		cout<<1;
		a=0,b=0;
		for(int i=0;i<=1;i++)
		{
		a=(c2[i]-'0')+a*10;
		b=(s2[i]-'0')+b*10;
		}
		if(a!=b)
		{
			cout<<000;
		}
		else
		{
			cout<<1;
			a=c2[2]-'A',b=s2[2]-'A';
			if(!(a<3&&b<3)||(a>=3&&b>=3))
			{
				cout<<00;
			}
			else
			{
				cout<<1;
				if((a<3&&b<3)&&abs(a-b)==1)
				{
					cout<<1;
				}
				else if((a>=3&&b>=3)&&abs(a-b)==2)
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
		}
	}
	return 0;
} 
