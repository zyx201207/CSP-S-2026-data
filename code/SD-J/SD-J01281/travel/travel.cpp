#include <bits/stdc++.h>
using namespace std;
string c,s,v,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>v>>d;
	if (c!=v)
	{
		cout<<"0000";
	}
	else
	{
		cout<<'1';
		if (s.substr(0,2)!=d.substr(0,2))
		{
			cout<<"000";
		}
		else
		{
			cout<<'1';
			if ('A'<=s[2]<='C'&&(d[2]=='D'||d[2]=='F'))
				cout<<"00";
			else if('A'<=d[2]<='C'&&(s[2]=='D'||s[2]=='F'))
				cout<<"00";
			else
			{
				cout<<'1';
				if((s[2]=='A'&&d[2]=='B')||(s[2]=='B'&&d[2]=='C')||(s[2]=='D'||d[2]=='F'))
					cout<<'1';
				else if ((d[2]=='A'&&s[2]=='B')||(d[2]=='B'&&s[2]=='C')||(d[2]=='D'||s[2]=='F'))
					cout<<'1';
				else
					cout<<'0';
			} 
		}
	}
	return 0;
}
