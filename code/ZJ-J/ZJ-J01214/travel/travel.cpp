#include<bits/stdc++.h>
using namespace std;
char a1,a2,a3,a4,b1,b2,b3,b4;
char c1,c2;
char bin1,bin2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>a3>>a4>>c1>>b1>>b2>>b3>>b4>>c2;
	if(a1==b1&&a2==b2)
		cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	if(a3==b3&&a4==b4)
		cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	int x=int(c1),y=int(c2);
	if(y<x)	swap(c1,c2);
	if(c1=='A'&&c2=='B'||c1=='A'&&c2=='C'||c1=='B'&&c2=='C'||c1=='D'&&c2=='F')
		cout<<1;
	else
	{
		cout<<"00";
		return 0;
	}
	if(c1=='A'&&c2=='B'||c1=='B'&&c2=='C'||c1=='D'&&c2=='F')
		cout<<1;
	else
		cout<<0;
	return 0;
}
