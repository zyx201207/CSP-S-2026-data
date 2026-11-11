#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char s1,s2,s3,s4;
	long long c1,c2,c3,c4;
	long long n1=0,n2=0,n3=0,n4=0;
	long long a=0,b=0,c=0,d=0;
	cin>>s1>>s2>>s3>>s4;
	c1=s1;
	c2=s2;
	c3=s3;
	c4=s4;
	n1=c2/100;
	n2=c2%100;
	n3=c4/100;
	n4=c4%100;
	
	if(c1==c3)
	a=1;
	else;
	a=0;
	if(n1==n3)
	b=1;
	else;
	b=0;
	if(((n2=='A'||n2=='B'||n2=='C')&&(n4=='A'||n4=='B'||n4=='C'))||((n2=='D'||n2=='E')&&(n4=='D'||n4=='E')))
	c=1;
	else
	c=0;
	if(n2-n4<=1)
	d=1;
	else
	d=0;
	cout<<a<<b<<c<<d;
	return 0;
}
