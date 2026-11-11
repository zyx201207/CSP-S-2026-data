#include<bits/stdc++.h>
using namespace std;
int a2,a1,b1,b2,num=0;
char c1,c2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>a1>>b1>>c1;
	cin>>a2>>b2>>c2;
	if(a1==a2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(a1==a2&&b1==b2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(b1==b2) 
	{
		if(c1=='A'&&c2=='B'||c2=='A'&&c1=='B'||c1=='B'&&c2=='C'||c2=='B'&&c1=='C'||c1=='A'&&c2=='C'||c2=='A'&&c1=='C'||c1=='D'&&c2=='E'||c2=='D'&&c1=='E')
		{
			cout<<"1"; 
			num=1;
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
	if(num==1&&c1=='A'&&c2=='B'||c1=='B'&&c2=='C'||c1=='D'&&c2=='F')
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
