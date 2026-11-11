#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,p1,p2,t1,t2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
		cout<<1;
	else
		cout<<0;
	for(char i:s1)
	{
		if(i>='A'&&i<='Z')
		{
			p2=i;
		}   
		else
		{
			p1+=i;
		}   
	}
	for(char u:s2)
	{
		if(u>='A'&&u<='Z')
		{
			t2=u;
		}
		else
		{
			t1+=u;
		}
	}
	if(c1==c2&&p1==t1)
		cout<<1;
	else
		cout<<0;  
	if(c1==c2&&p1==t1)
	{
		if(p2>='A'&&p2<='C'&&t2>='A'&&t2<='C')
			cout<<1;
		else if(p2>='D'&&p2<='E'&&t2>='D'&&t2<='E')
			cout<<1;
		else
			cout<<0;
	}
	if(p2>='A'&&p2<='C'&&t2>='A'&&t2<='C'&&c1==c2&&p1==t1)
	{
		if(p2==t2+1||p2==t2-1)
			cout<<1;   
		else
			cout<<0; 
	}
	else if(p2>='D'&&p2<='F'&&t2>='D'&&t2<='F'&&c1==c2&&p1==t1)
	{
		cout<<1;   
	}
	else
		cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
