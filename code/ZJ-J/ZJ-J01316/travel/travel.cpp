#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
bool a=0,b=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(s[2]=='A'||s[2]=='B'||s[2]=='C')
		a=1;
	if(ss[2]=='A'||ss[2]=='B'||ss[2]=='C')
		b=1;
	getchar();
	if(c==cc)
	{
		if(s[0]==ss[0]&&s[1]==ss[1])
		{
			if(a==b)
			{
				if(abs(int(s[2]-ss[2]))==1)
				{
					cout<<"1111";
					return 0;
				}
				else
				{
					cout<<"1110";
					return 0;
				}
			}
			else
			{
				cout<<"1100";
				return 0;
			}
		}
		else
		{
			cout<<"1000";
			return 0;
		}
	}
	else
	{
		cout<<"0000";
		return 0;
	}
}