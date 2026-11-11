//闫思涵;
//SN-J00775;
//西安市莲湖第二学; 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","r",stdout);
	int c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2&&s1==s1)
	{
		cout<<1111;
	}
	else if(c1==c2&&s1!=s2)
	{
		cout<<1110;
	}
	else if(c1==c2&&s1!=s2)
	{
		cout<<1100;
	}
	else if(c1==c2&&s1!=s2)
	{
		cout<<1000;
	}
	else if(c1!=c2&&s2!=s1)
	{
		cout<<0000;
	}
	return 0;
}
