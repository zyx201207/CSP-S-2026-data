#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string n,m;
	cin>>a>>n>>b>>m;
	if(a==b)
		cout<<1;
	else
		cout<<0;	
	if(a==b&&n[1]==m[1]&&n[0]==m[0])
		cout<<1;
	else
		cout<<0;
	if(a==b&&n[1]==m[1]&&n[0]==m[0])
	{
		if(((n[2]<=67&&n[2]>=65)&&(m[2]<=67&&m[2]>=65))||((n[2]<=69&&n[2]>=68)&&(m[2]<=69&&m[2]>=68)))
			cout<<1;
		else
			cout<<0;
	}
	else
		cout<<0;
	if(a==b&&n[1]==m[1]&&n[0]==m[0]&&abs(n[2]-m[2])==1)
	{
		if((n[2]=='A'&&m[2]=='C')||(n[2]=='C'&&m[2]=='D')||(n[2]=='A'&&m[2]=='C')||(n[2]=='D'&&m[2]=='C'))	
			cout<<0;
		else if((n[2]=='A'&&m[2]=='B')||(n[2]=='B'&&m[2]=='C')||(n[2]=='B'&&m[2]=='A')||(n[2]=='C'&&m[2]=='B'))
			cout<<1;
	}
	else
		cout<<0;
	return 0;
}
