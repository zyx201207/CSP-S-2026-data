#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c,c1;
	cin>>c;
	string s,s1;
	cin>>s;
	cin>>c1;
	cin>>s1;
	if(c==c1)
	{
		cout<<"1";
		if(s[0]==s1[0]&&s[1]==s1[1])
		{
			cout<<"1";
			if(s[2]=='A'||s[2]=='B'||s[2]=='C')
			{
				if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
				{
					cout<<"1";
					if(s1[2]-s[2]==1)
					cout<<"1";
					else
					cout<<"0";
				}
				
				else
				cout<<"00";
			}
			if(s[2]=='D'||s[2]=='F')
			{
				if(s1[2]=='D'||s1[2]=='F')
				{
					cout<<"11";
				}
				
				else
				cout<<"00";
			}
		}
		
		else
		cout<<"000";
	}
	else
	cout<<"0000";
	return 0;
 } 
