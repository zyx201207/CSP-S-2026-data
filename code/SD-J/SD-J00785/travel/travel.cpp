#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,t,x,y;
	cin>>s>>t>>x>>y;
	if(s==x)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	//////////////////////////////////////////////////////
	if(t[0]==y[0]&&t[1]==y[1])
	{
		cout<<"1";
	}
	else
	{
		cout<<"000";
		return 0;
	}
	//////////////////////////////////////////////////////
	if(((t[2]=='D'||t[2]=='F')&&(y[2]=='A'||y[2]=='B'||y[2]=='C'))||(y[2]=='D'||y[2]=='F')&&(t[2]=='A'||t[2]=='B'||t[2]=='C'))
	{
		cout<<"00";
		return 0;
	}
	else
	{
		cout<<"1";
	}
	if((t[2]=='A'&&y[2]=='B')||(t[2]=='B'&&y[2]=='A'))
	{
		cout<<"1";
	}
	else
	{
		if((t[2]=='C'&&y[2]=='B')||(t[2]=='B'&&y[2]=='C'))
		{
			cout<<"1";
		}
		else
		{
			if((t[2]=='D'&&y[2]=='C')||(t[2]=='C'&&y[2]=='D'))
			{
				cout<<"1";
			}
			else
			{
				cout<<"0";
			}
		}
	}
	return 0;
}
