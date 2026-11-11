#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool p=false;
bool q=false;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0; 
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{	
		p=true;
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	int a=s1[2]-'0';
	int b=s2[2]-'0';
	if(s1[2]<='C'&&s2[2]<='C'&&p==true)
	{
		q=true;
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(max(a,b)-min(a,b)==1&&p==true&&q==true)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
