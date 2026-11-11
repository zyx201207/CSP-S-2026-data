#include<bits/stdc++.h>
using namespace std;
char c,s;
int c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c>>c2>>s2>>s;
	if(c1!=c2)
	{
		cout<<"0000";
	}
	else if(s1!=s2)
	{
		cout<<"1000";
	}
	else
	{
		if(((c>='A'&&c<='C')&&(s>='A'&&s<='C'))||(c=='D'&&s=='F')||(c=='F'&&s=='D'))
		{
			if(((int)c+1==s)||((int)s+1==c)||((c=='D'&&s=='F')||(c=='F'&&s=='D')))
			{
				cout<<"1111";	
			}
			else
			{
				cout<<"1110";
			}
		}
		else
		{
			cout<<"1100";
		}
	}
	return 0;
}
