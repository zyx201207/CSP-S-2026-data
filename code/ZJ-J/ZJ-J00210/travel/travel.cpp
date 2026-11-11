#include<bits/stdc++.h>
using namespace std;
string c,s,r,x;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>s>>r>>x;
	bool p=false;
	if(c!=r)
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		cout<<"1";
	}
	if(s[0]==x[0]&&s[1]==x[1])
	{
		cout<<"1";
		p=true;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(p)
	{
		if((int(s[2])<=67&&int(x[2])<=67)||(int(s[2])>=68&&int(x[2])>=68))
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	}
	else
	{
		cout<<"0";
	}
	if((int(s[2])==65&&x[2]==66)||(int(x[2])==65&&int(s[2])==66)||
	(int(s[2])==66&&int(x[2])==67)||(int(s[2])==67&&int(x[2])==66)||
	(int(s[2])==68&&int(x[2])==69)||(int(s[2])==69&&int(x[2])==68))
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
