#include<bits/stdc++.h>
using namespace std;
string c1,c2;
char s1[5],s2[5],a[6]={0,'A','B','C','D','F'};
bool b1,b2,aa[6]={0,0,0,0,1,1};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	for(int i=1;i<=3;i++)
	{
		cin>>s1[i];
	}
	cin>>c2;
	for(int i=1;i<=3;i++)
	{
		cin>>s2[i];
	}
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		cout<<"1";
		if(s1[1]!=s2[1]||s1[2]!=s2[2])
		{
			cout<<"000";
			return 0;
		}
		else
		{
			cout<<"1";
			for(int i=1;i<=5;i++)
			{
				if(s1[3]==a[i])
				{
					b1=aa[i];
				}
				if(s2[3]==a[i])
				{
					b2=aa[i];
				}
			}
			if(b1!=b2)
			{
				cout<<"00";
				return 0; 
			}
			else
			{
				cout<<"1";
				if(b1==1&&b2==1)
				{
					cout<<"1";
					return 0;
				}
				else
				{
					if((s1[3]=='A'&&s2[3]=='C')||(s2[3]=='A'&&s1[3]=='C'))
					{
						cout<<"0";
						return 0;
					}
					else
					{
						cout<<"1";
						return 0;
					}
				}
			}
		}
	}
	return 0;	
} 
