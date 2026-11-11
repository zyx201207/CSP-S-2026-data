#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')))
	{
		cout<<1;
		if(abs(s1[2]-'A'-(s2[2]-'A'))==1)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		cout<<"00";
	}
	return 0;
}
//luogu user 1760542
