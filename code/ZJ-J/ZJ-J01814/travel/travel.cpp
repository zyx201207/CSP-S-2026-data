#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
	}
	else
	{
		cout<<"1";
		int x=(s1[0]-'0')*10+(s1[1]-'0'),y=(s2[0]-'0')*10+(s2[1]-'0');
		if(x!=y)
		{
			cout<<"000";
		}
		else
		{
			cout<<"1";
			char a=s1[2],b=s2[2];
			if(a=='A'||a=='B'||a=='C')
			{
				if(b=='D'||b=='E')
				{
					cout<<"00";
				}
				else
				{
					cout<<"1";
					if(a=='B'||b=='B')
					{
						cout<<"1";
					}
					else
					{
						cout<<"0";
					}
				}
			}
			else if(a=='D'||b=='E')
			{
				if(b=='A'||b=='B'||b=='C')
		    	{
					cout<<"00";
				}
				else
				{
					cout<<"11";
		    	}
			}
		}
	}
	return 0;
} 
