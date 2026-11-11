#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c)
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		cout<<"1";
		if(b[0]!=d[0]||b[1]!=d[1])
		{
			cout<<"000";
			return 0;
		}
		else
		{
			cout<<"1";
			if(b[2]=='D'||b[2]=='F')
			{
				if(d[2]=='A'||d[2]=='B'||d[2]=='C')
				{
					cout<<"00";
				}
				else
				{
					cout<<"11";
				}
			}
			else
			{
				if(d[2]=='D'||d[2]=='F')
				{
					cout<<"00";
				}
				else
				{
					cout<<"1";
					if(b[2]=='A'&&d[2]=='C')
					{
						cout<<"0";
					}
					else if(b[2]=='C'&&d[2]=='A')
					{
						cout<<"0";
					}
					else 
					{
						cout<<"1";
					}
				}
			}
		}
	}
	
	
	return 0;
}
