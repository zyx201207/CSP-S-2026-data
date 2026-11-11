#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	bool vis1,vis2;
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
	{
		vis1=0;
	}
	else
	{
		vis1=1;
	}
	
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
	{
		vis2=0;
	}
	else
	{
		vis2=1;
	}
	
	for(int i=0;i<=1;i++)
	{
		if(c1[i]!=c2[i])
		{
			cout<<"0000";
			return 0;
		}
	}
	
	cout<<1;
	
	for(int i=0;i<=1;i++)
	{
		if(s1[i]!=s2[i])
		{
			cout<<"000";
			return 0;
		}
	}
	
	cout<<1;
	
	if(vis1!=vis2)
	{
		cout<<"00";
		return 0;
	}
	
	cout<<1;
	
	if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))||(s1[2]=='C'&&s2[2]=='B'))
	{
		cout<<1;
		return 0;
	}
	
	if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))
	{
		cout<<1;
		return 0;
	}
	
	cout<<0;
	return 0;
}
