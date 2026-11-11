#include <bits/stdc++.h> 
using namespace std;
char c1[3];
char c2[3];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	int a=1,b=1,c=1,d=1;
	int s1,s2;
	cin>>s1;
	for(int i=1;i<=3;i++)
	{
		cin>>c1[i];
	}
	for(int i=1;i<=3;i++)
	{
		cin>>c2[i];
	}
	cin>>s2;
	if(s1==s2)
	{
	}
		a=1;
	if(c1[3]=='A' or  c1[3]=='D')
	{
		d=0;
	}
	if(c2[3]=='B' or c2[3]=='C' or c2[3]=='02')
	{
		c=1;
	}
	cout<<a<<b<<c<<d;	
	return 0;
}
