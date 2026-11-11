#include<bits/stdc++.h>
#define int long long
using namespace std;
/*
思路:if判断
*/
int n,m,ra,xa;
char rz,xz;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>ra>>rz>>m>>xa>>xz;//n m是车厢 ra xa是排数 rz xz是座位字母 
	if(n==m)
	{
		cout<<1;
	
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(ra==xa)//同一排
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(rz=='A')
	{
		if(xz=='B'||xz=='C')
		{
			cout<<1;
		}
		else
		{
			cout<<"00";
			return 0;
		}
	}
	if(rz=='B')
	{
		if(xz=='A'||xz=='C')
		{
			cout<<1;
		}
		else
		{
			cout<<"00";
			return 0;
		}
	}
	if(rz=='C')
	{
		if(xz=='B'||xz=='A')
		{
			cout<<1;
		}
		else
		{
			cout<<"00";
			return 0;
		}
	}
	if(rz=='D')
	{
		if(xz=='F')
		{
			cout<<1;
		}
		else
		{
			cout<<"00";
			return 0;
		}
	}
	if(rz=='F')
	{
		if(xz=='D')
		{
			cout<<1;
		}
		else
		{
			cout<<"00";
			return 0;
		}
	}
	if(xz+1==rz||xz-1==rz)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
