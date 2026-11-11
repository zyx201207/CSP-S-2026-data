#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a;
	cin >>a;
	string b;
	cin >>b;
	int c;
	cin >>c;
	string d;
	cin>>d;
	if(a == c)
	{
		cout <<"1111";
	}
	else if(a == c && b == d)
	{
		cout <<"1100";
	}
	 
	else
	{
		cout <<"0000";
	}
	return 0;
 } 
