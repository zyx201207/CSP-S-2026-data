#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout<<"1";
			char a,b;
			a=s1[2];
			b=s2[2];
			if((a>='A'&&a<='C'&&b>='A'&&b<='C')||(a>='D'&&a<='F'&&b>='D'&&b<='F'))
			{
				cout<<"1";
				int c=int(b-a);
				if(c==1||c==-1)
				{
					cout<<"1";
				}
				else
				{
					cout<<"0";
				}
			}
			else
			{
				cout<<"0"<<"0";
			}
		}
		else
		{
			cout<<"0"<<"0"<<"0";
		}
	}
	else{
		cout<<"0"<<"0"<<"0"<<"0";
	}
	
	return 0;
} 
