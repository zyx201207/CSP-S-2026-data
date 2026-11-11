#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,c1,c2;
	int ss1,ss2,cc1,cc2;
	cin>>c1>>s1>>c2>>s2;
	cc1=(c1[0]-'0')*10+(c1[1]-'0');
	cc2=(c2[0]-'0')*10+(c2[1]-'0');
	ss1=(s1[0]-'0')*10+(s1[1]-'0');
	ss2=(s2[0]-'0')*10+(s2[1]-'0');
	if(cc1==cc2)
	{
		if(ss1==ss2)
		{
			if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')))
			{
				if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))
				{
					cout<<1111;
					return 0;
				}
				else
				{
					cout<<1110;
					return 0;
				}
			}	
			else
			{
				cout<<1100;	
				return 0;
			} 
		}
		else
		{
			cout<<1000;
			return 0;	
		}	
	} 
	else
	{
		cout<<"0000";
		return 0;
	}
	
	return 0;	
} 
