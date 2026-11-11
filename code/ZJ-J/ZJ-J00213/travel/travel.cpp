#include <bits/stdc++.h>
using namespace std;
struct str
{
	int c;
	string s;
};
str s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s1.c>>s1.s>>s2.c>>s2.s;
	if(s1.c==s2.c)
	{
		cout<<"1";
		if(s1.s[0]==s2.s[0]&&s1.s[1]==s2.s[1])
		{
			cout<<"1";
			if((s1.s[2]=='A'||s1.s[2]=='B'||s1.s[2]=='C')&&(s2.s[2]=='A'||s2.s[2]=='B'||s2.s[2]=='C'))
			{
				cout<<"1";
				if((s1.s[2]=='A'&&s2.s[2]=='C')||(s2.s[2]=='A'&&s1.s[2]=='C'))
				{
					cout<<"0";
				}
				else
				{
					cout<<"1";
				}
			}
			else if((s1.s[2]=='D'||s1.s[2]=='F')&&(s2.s[2]=='D'||s2.s[2]=='F'))
			{
				cout<<"11";
			}
			else
			{
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}