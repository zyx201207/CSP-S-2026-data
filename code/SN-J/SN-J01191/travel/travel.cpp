#include<bits/stdc++.h> 
using namespace std;
string n;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		n+="1";
		if(b[0]==d[0] && b[1]==d[1])
		{
			n+="1";
			if(((b[2]=='A'|| b[2]=='B'|| b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))||((b[2]=='D'|| b[2]=='F')&&(d[2]=='D'||d[2]=='F')))
			{
				n+="1";
				if((b[2]=='A'&&d[2]=='C')||(b[2]=='C'&&d[2]=='A'))
				{
					n+="0";
				}
				else
				{
					n+="1";
				}
			}
			else
			{
				n+="00";
			}
		}
		else
		{
			n+="000";
		}
	}
	else
	{
		n+="0000";
	}
	cout<<n;
}
