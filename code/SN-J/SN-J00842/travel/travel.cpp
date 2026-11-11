//西安翱翔中学 张奕纬 SN-J00842 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,s;
	bool g=1;
	int d,f;
	cin>>d>>a>>f>>s;
	if(d==f)
	{
		cout<<1;
		
	}
	else{
		cout<<0;
		g=0;
	}
	if((a[0]+a[1]==s[0]+s[1])&&g==1)
	{
		cout<<1;
		
	}
	else
	{
		cout<<0;
		g=0;
	}
	if(((a[2]<'D'&&s[2]<'D')||(a[2]>'C'&&s[2]>'C'))&&g==1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		g=0;
	}
	if((a[2]+1==s[2]||a[2]-'1'==s[2])&&g==1)
	{
		cout<<1;
		
	}
	else
	{
		cout<<0;
	}
	return 0;
}
		
