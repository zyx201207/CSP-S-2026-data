#include<bits/stdc++.h>
using namespace std;
string c_1,s_1,c_2,s_2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1==c_2)
	{
		int x=(s_1[0]-'0')*10+s_1[1]-'0',y=(s_2[0]-'0')*10+s_2[1]-'0';
		if(x==y)
		{
			char a=s_1[2],b=s_2[2];
			if( (a=='A'&&b=='B') || (a=='A'&&b=='C') || (a=='B'&&b=='A') || (a=='B'&&b=='C') || (a=='C'&&b=='A') || (a=='C'&&b=='B') || (a=='D'&&b=='F') || (a=='F'&&b=='D') )
			{
				if( (a=='A'&&b=='B') || (a=='B'&&b=='A') || (a=='B'&&b=='C') || (a=='C'&&b=='B') || (a=='D'&&b=='F') || (a=='F'&&b=='D'))
				{
					cout<<"1111";
				}
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
}
