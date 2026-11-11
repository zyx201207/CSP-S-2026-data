#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	for(int i=0;i<s1.size();i++)
	{
		for(int j=0;j<s2.size();j++)
		{
			if(i!=2&&j!=2)
			{
				if(s1[i]==s2[j])
				{
					cout<<"1";
					break;
				}
				else
				{
					cout<<"0";
					break;
				}
			}
			else
			{
				if(s1[i]=='C'&&s2[j]=='D')
				{
					cout<<"0";
					break;
				}
				else
				{
					if(s1[i]=='A'||s1[i]=='B'||s1[i]=='C'&&s2[j]=='A'||s2[j]=='B'||s2[j]=='C')
					{
						cout<<"1";
						break;
					}
					else
					if(s1[i]=='D'||s2[i]=='F'&&s2[j]=='D'||s2[j]=='F')
					{
						cout<<"1";
						break;
					}
					else
					{
						cout<<"0";
						break;
					}
				}
			}
		}
	}
	return 0;
}
