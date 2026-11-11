#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m,n1,m1;
	char a,b;
	cin>>n>>m>>a>>n1>>m1>>b;
	if(n==n1)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(m==m1)
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if((a=='D'||a=='F')&&(b=='D'||b=='F'))
	{
		cout<<11;
		return 0;
	}
	else if((a=='A'||a=='B'||a=='C')&&(b=='A'||b=='B'||b=='C'))
	{
		cout<<1;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(abs(a-b)==1)
	{
		cout<<1;
		return 0;
	}
	else
	{
		cout<<0;
	}
	return 0;
 }
