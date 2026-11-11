#include<bits/stdc++.h>
using namespace std;
int a1,a2,x1,x2;
char y1,y2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>x1>>y1>>a2>>x2>>y2;
	if(a1==a2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(a1==a2 && x1==x2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(a1==a2 && x1==x2 && (int(y1-'A'))/3==(int(y2-'A'))/3)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(a1==a2 && x1==x2 && (int(y1-'A'))/3==(int(y2-'A'))/3 && max(int(y1-'A'),int(y2-'A'))-min(int(y1-'A'),int(y2-'A'))==1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
