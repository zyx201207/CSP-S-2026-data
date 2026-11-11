#include <bits/stdc++.h> 
using namespace std;
int main()
{
	foropen("travel.in","r",stdin);
	foropen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int da;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			if((s1[2]=='A'||'B'||'C'&&s2[2]=='A'||'B'||'C')||(s1[2]=='D'||'F'&&s2[2]=='D'||'F'))
			{
				if((s1[2]-1==s2[2])||(s1[2]+1==s2[2]))
				{
					if(s1[2]=='C'&&s2[2]=='D')
					{
						da=1100;
					}
					else if(s1[2]=='D'&&s2[2]=='C')
					{
						da=1100;
					}
					else
					{
						da=1111;
					}
				}
				else
				{
					da=1110;
				}
			}
			else
			{
				da=1100;
			}
		}
		else
		{
			da=1000;
		}
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	cout<<da<<"\n";
	return 0;
}


