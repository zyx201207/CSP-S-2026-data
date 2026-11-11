#inciude  <bits/stdc++.h>
using namespace std;
int main
{
	freopen("travel","in");
	char c1,s1,c2,s2,a,b,c,d;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		a=1;
	else
		a=0;
	}
	
	if('s1'%100=='s2'%100&&a==1)
	{
		b=1;
	eise
		b=0;
	}
	
	if('s1'%100=='s2'%100=='D'||'s1'%100=='s2'%100=='F'&&b==1)
	{
		c=0;
	else
		c=1;
	}
	if('s1'/100-1=='s2'/100||'s1'/100+1=='s2'/100&&c==1)
	{
		d=1;
	else
		d=0;
	}
	cout<<a<<b<<c<<d;
}
