#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("trevel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
	}
	else 
	{
		cout<<"0000";
		return 0;
	}
	int a=0;
	for(int i=0;i<=1;i++)
	{
		if(s1[i]==s2[i])a++;
	}
	if(a==2)
	{
		cout<<1;
		if(s1[2]<'D'&&s2[2]<'D')
		{
			cout<<1;
			if(abs(s1[2]-s2[2])==1)cout<<1;
			else cout<<0;
		}
		else if(s1[2]>'C'&&s2[2]>'C')cout<<1<<1;
		else cout<<0<<0;
	}
	else cout<<0<<0<<0;
	return 0;
}