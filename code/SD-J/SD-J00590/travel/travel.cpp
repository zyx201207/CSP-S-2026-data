#include<bits/stdc++.h>
using namespace std;int y,u;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	string n,s,k,l;
	bool q=0;
	cin>>n>>k>>s>>l;
	if(n[0]=='0')
	{
		
		y=n[1]-'0';
	}
	else
	{
		y=(n[0]-'0')*10+n[1]-0;
	}
	if(s[0]=='0')
	{
		
		u=s[1]-'0';
	}
	else
	{
		u=(s[0]-'0')*10+s[1]-0;
	}
	if(u==y)
	{
		cout<<1;
		q=1;
	}
	else
	{
		cout<<0;
	}
	if(k[0]=='0')
	{
		
		y=k[1]-'0';
	}
	else
	{
		y=(k[0]-'0')*10+k[1]-0;
	}
	if(l[0]=='0')
	{
		
		u=l[1]-'0';
	}
	else
	{
		u=(l[0]-'0')*10+l[1]-0;
	}
	if(u==y&&q==1)
	{
		cout<<1;
		q=1;
	}
	else
	{
		cout<<0;
		q=0;
	}
	if((k[2]=='D'&&l[2]=='F'||k[2]=='F'&&l[2]=='D')&&(q==1))
	{
		cout<<1<<1;
		return 0;
	}
	else if((k[2]=='A'||k[2]=='B'||k[2]=='C')&&(l[2]=='A'||l[2]=='B'||l[2]=='C')&&(q==1))
	{
		cout<<1;
		q=1;
		if(k[2]==l[2]-1||k[2]-1==l[2])
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	else
	{
		cout<<0<<0;
		return 0;
	}
}
