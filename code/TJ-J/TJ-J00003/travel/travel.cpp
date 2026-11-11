//100%
#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int a[10][20];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int i,j;
	cin>>c1>>s1>>c2>>s2;
	int  p1=0,p2=0,t1=0,t2=0,x1,x2;
	for(i=0;i<=1;i++) 
		p1=p1*10+(c1[i]-'0');
	for(i=0;i<=1;i++) 
		p2=p2*10+(c2[i]-'0');
	for(i=0;i<=1;i++) 
		t1=t1*10+(s1[i]-'0');
	for(i=0;i<=1;i++) 
		t2=t2*10+(s2[i]-'0');
	if(s1[2]=='A')	x1=1;
	else if(s1[2]=='B')	x1=2;
	else if(s1[2]=='C')	x1=3;
	else if(s1[2]=='D')	x1=6;
	else if(s1[2]=='F')	x1=7;
	
	if(s2[2]=='A')	x2=1;
	else if(s2[2]=='B')	x2=2;
	else if(s2[2]=='C')	x2=3;
	else if(s2[2]=='D')	x2=6;
	else if(s2[2]=='F')	x2=7;
	
	if(p1==p2)	cout<<1;
	else
	{
		cout<<0;cout<<0;cout<<0;cout<<0;
		return 0;
	}
	if(t1==t2)	cout<<1;
	else
	{
		cout<<0;cout<<0;cout<<0;
		return 0;
	}
	if(abs(x1-x2)<=2)	cout<<1;
	else
	{
		cout<<0;cout<<0;
		return 0;
	}
	if(abs(x1-x2)<=1)	cout<<1;
	else	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
