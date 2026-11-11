#include<bits/stdc++.h>
using namespace std;
int main()
{
	char a,s,d,f;
	cin>>a>>d>>s>>f;
	if(a==s)
	{
		cout<<"1";
	}else
	{
		cout<<"0000";
		return 0;
	}
	if(d-f<=5&&f-d<=5)
	{
		cout<<"1";
	}else
	{
		cout<<"100";
		return 0;
	}
	if(d-f==1||f-d==1)
	{
		cout<<"1";
	}else
	{
		cout<<"10";
		return 0;
	}
	if(d-f==1||f-d==1)
	{
		cout<<"1";
	}else
	{
		cout<<"0";
		return 0;
	}
}
