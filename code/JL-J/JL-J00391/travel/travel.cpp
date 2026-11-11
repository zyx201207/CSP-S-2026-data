#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1,s1,c2,s2;
	
	cin>>c1>>s1>>c2>>s2;
	if(c1-'0'==c2-'0')
	{
		cout<<"1"<<"1"<<"1"<<"1";
	}
	else if(c1-'0'!=c2-'0')
	{
		cout<<"0"<<"0"<<"0"<<"0";
	}
	return 0;
}
