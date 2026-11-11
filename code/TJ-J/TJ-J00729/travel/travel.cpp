#include<bits/stdc++.h>
using namespace std;
char s[10],t[10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	for(int i=1;i<=5;i++)
	{
		cin>>s[i]>>t[i];
	}
	if(s[1]!=t[1])
	{
		cout<<"0000";
		return 0;
	}
	if(s[2]!=t[2])
	{
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(s[3]!=t[3])
	{
		cout<<"000";
		return 0;
	}
	if(s[4]!=t[4])
	{
		cout<<"000";
		return 0;
	}
	cout<<1;
	return 0;
}
