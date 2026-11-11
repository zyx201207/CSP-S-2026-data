#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
string ans="";
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		ans+='1';
		if(b[0]==d[0]&&b[1]==d[1])
		{
			ans+='1';
			if(b[2]=='A'||b[2]=='B'||b[2]=='C')
			{
				if(d[2]=='A'||d[2]=='B'||d[2]=='C')
				{
					ans+='1';
					if(int(b[2]-d[2])<=1&&int(b[2]-d[2])>=-1) ans+='1';
					else ans+='0';
				}
				else ans+="00";
			}
			else if(b[2]=='F'||b[2]=='D')
			{
				if(d[2]=='D'||d[2]=='F')
				{
					ans+="11";
				}
				ans+="00";
			}
		}
	}
	else ans+="0000";
	cout<<ans;
	return 0;
}
