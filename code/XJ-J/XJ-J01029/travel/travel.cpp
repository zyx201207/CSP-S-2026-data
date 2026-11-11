#include<bits/stdc++.h>
using namespace std;
int main()
{
	int c1,c2;
	char s1[10],s2[10];
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2&&c1!=1&&c1!=16)
	{
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout<<"1";
			if(s1[2]<='C'&&s2[2]<='C'||s1[2]>='D'&&s2[2]>='D')
			{
				cout<<"1";
				if(s1[2]+1==s2[2]||s1[2]-1==s2[2]||s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D')
				{
					cout<<"1";
					return 0;
				}
				else
				{
					cout<<"0";
					return 0;
				}
			}
			else
			{
				cout<<"00";
				return 0;
			}
		}
		else
		{
			cout<<"000";
			return 0;
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}