#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2,cs1,cs2,csc1,csc2;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	cs1=s1[0]+s1[1];
	cs2=s2[0]+s2[1];
	if(c1==c2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(cs1==cs2)
	{
		cout<<"1";
		if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
		{
			if(s2[2]=='B'||s2[2]=='C'||s2[2]=='A')
			{
				cout<<"1";
			}
			else
			{
				cout<<"0"; 
			}
		}
		else if(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D')
		{
			cout<<"1" ;
		}
		else
		{
			cout<<"0";
		}
		if(s1[2]=='A'&&s2[2]=='B')
		{
			cout<<"1";
		}
		else if(s1[2]=='B'&&s2[2]=='C')
		{
			cout<<"1";
		}
		else if(s1[2]=='D'&&s2[2]=='F')
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
		cout<<"000"; 
	} 
	
	return 0;
}
