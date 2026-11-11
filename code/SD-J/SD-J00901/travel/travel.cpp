#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int a,b;
int same(char x,char y)
{
	if(x<='C'&&y<='C')
	{
		if((x+1==y)||(x-1)==y)
			return 1;
		else
			return 0;
	}
	else if(x>='D'&&y>='D')
	{
			if((x+1==y)||(x-1)==y)
			return 1;
		else
			return 0;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
		cout<<"1";
	else
	{
		cout<<"0000";
		return 0;
	}
	a=s1[0]*10+s1[1];
	b=s2[0]*10+s2[1];
	if(a==b)
		cout<<"1";
	else
	{
		cout<<"000";
		return 0;
	}
	if(s1[2]<='C'&&s2[2]<='C'||s1[2]>='D'&&s2[2]>='D')
		cout<<"1";
	else
	{
		cout<<"00";
		return 0;
	}
	if(same(s1[2],s2[2]))
		cout<<"1";
	else
		cout<<"0";
	return 0;	
} 
