#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdin);
	string c1,c2,s1,s2;
	cin>>c1>>c2>>s1>>s2;
	int e,t,sum=0,sum1=0;
	if(c1==s1)
	{
		cout<<1;
		for(int i=1;i<=c2.size();i++)
		{
			sum=sum+c2[i];
			e=sum/10;
		}
		for(int i=1;i<=s2.size();i++)
		{
			sum1=sum1+s2[i];
			t=sum1/10;
		}
		if(e==t)
		{
			cout<<1;
			if(sum%10==4||sum%10==5||sum%10==6)
			{
				if(sum1%10==4||sum1%10==5||sum1%10==6)
				{
					cout<<1;
					if(sum%10==4&&sum1%10==5||sum1%10==6&&sum%10==5||sum1%10==4&&sum%10==5||sum%10==6&&sum1%10==5)
					{
						cout<<1;
					}
					else if(sum%10==6&&sum1%10==7||sum%10==7&&sum1%10==6)
					{
						cout<<1;
					}
					else
					{
						cout<<0;
					}
				}
			}
			else if(sum%10==7&&sum1%10==9||sum%10==9&&sum1%10==7)
			{
				cout<<1;
				if(sum%10==7&&sum1%10==9||sum%10==9&&sum1%10==7)
				{
					cout<<1;
				}
				else 
				{
					cout<<0;
				}
			}
			else
			{
				cout<<0;
			}	
		}
		else 
		{
			cout<<0;
		}
	}
	else
	{
		cout<<0;
	}
}