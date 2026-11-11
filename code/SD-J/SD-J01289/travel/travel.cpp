#include<bits/stdc++.h>
using namespace std;

string a1,a2,b1,b2;
	
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(a1[0]==b2[0] && a2[1]==b2[1] && a1==b1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	int a=a2[2]-'A'+1;
	int b=b2[2]-'A'+1;
	if((abs(a-b)<=1 || (a==1 && b==3) || (a==3 && b==1)) && (!(a==3 && b==4) && a1[0]==b2[0] && a2[1]==b2[1]) && a1==b1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(abs(a-b)<=1 && !(a==3 && b==4) && (a1[0]==b2[0] && a2[1]==b2[1]) && a1==b1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
