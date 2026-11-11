#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	int s1[3],s2[3];
	int a,s;
	for(int i=0;i<2;i++)
	{
		cin>>c1;
		cin>>s1[i];
		cin>>c2;
		cin>>s2[i];
		a=s1[2];
		s=s2[2];
	}
	if(c1!=1&&c2!=16)
	{
		if(c1!=c2)
		{
			cout<<"0000";
		}
		else
		{
			for(int i=0;i<2;i++)
			{
				if(s1[i]==s2[i])
				{
					if(a=='A'&&s=='B'||a=='B'&&s=='A')
					{
						cout<<"1111";
					}
					else if(a=='C'&&s=='B'||s=='C'&&a=='B')
					{
						cout<<"1111";
					}
					else if(a=='D'&&s=='F'||a=='F'&&s=='D')
					{
						cout<<"1111";
					}
					else
					{
						cout<<"1110";
						break;
					}
				}
				else
				{
					cout<<"1100";
					break;
				}
			}
			cout<<"1000";
		}
	}
	return 0;
}
