#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2,ans;
int main()
{
	ans="";
	s1="";
	s2="";
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		ans+="1";
	}
	else if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	if(s1[1]==s2[1] and s1[0]==s2[0])
	{
		ans+="1";
	}
	else 
	{
		cout<<ans;
		cout<<"000";
		return 0;
	}
	if(s1[2]=='A' or s1[2]=='B' or s1[2]=='C')
	{
		if(s2[2]=='D' or s2[2]=='E')
		{
			cout<<ans;
			cout<<"00";
			return 0;
		}
		if(s2[2]=='A' or s2[2]=='B' or s2[2]=='C')
		{
			ans+="1";
			if(s2[2]==s1[2]+1 or s1[2]==s2[2]+1)
			{
				ans+="1";
			}
			else
			{
				cout<<ans;
				cout<<"0";
				return 0;
			}
		}
		else
		{
			cout<<ans;
			cout<<"00";
		}
	}
	if(s1[2]=='D' or s1[2]=='E')
	{
		if(s2[2]=='A' or s2[2]=='B' or s2[2]=='C')
		{
			cout<<ans;
			cout<<"00";
			cout<<endl;
		}
		if(s2[2]=='D' or s2[2]=='E')
		{
			ans+="1";
			ans+="1";
		}
		else
		{
			cout<<ans;
			cout<<"00";
		}
	}
	cout<<ans;
	return 0;
}