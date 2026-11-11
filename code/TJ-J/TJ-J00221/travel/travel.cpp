#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int ans=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		for(int i=0;i<=1;i++)
		{
			if(s1[i]==s2[i])
			{
				ans++;
			}
			else
			{
				cout<<"1000";
				return 0;
			}
		}
		if(ans==2)
		{
			if(s1[2]=='A'&&s2[2]=='C')
			{
				cout<<"1110";
				
			}
			if(s1[2]=='C'&&s2[2]=='A')
			{
				cout<<"1110";
				
			}
			if(s1[2]=='A'&&s2[2]=='B')
			{
				cout<<"1111";
				
			}
			if(s1[2]=='B'&&s2[2]=='A')
			{
				cout<<"1111";
				
			}
			if(s1[2]=='B'&&s2[2]=='C')
			{
				cout<<"1111";
				
			}
		    if(s1[2]=='C'&&s2[2]=='B')
			{
				cout<<"1111";
				
			}
			if(s1[2]=='D'&&s2[2]=='F')
			{
				cout<<"1111";
				
			}
			if(s1[2]=='F'&&s2[2]=='D')
			{
				cout<<"1111";
				
			}
			if(s1[2]=='C'&&s2[2]=='D')
			{
				cout<<"1100";
				
			}
			if(s1[2]=='C'&&s2[2]=='F')
			{
				cout<<"1100";
				
			}
			if(s1[2]=='A'&&s2[2]=='D')
			{
				cout<<"1100";
				
			}
			if(s1[2]=='B'&&s2[2]=='D')
			{
				cout<<"1100";
				
			}
			if(s1[2]=='F'&&s2[2]=='A')
			{
				cout<<"1100";
				
			}
			if(s1[2]=='F'&&s2[2]=='B')
			{
				cout<<"1100";
				
			}
		}
	}
	else
	{
		cout<<"0000";
	
	}
	return 0;
}



