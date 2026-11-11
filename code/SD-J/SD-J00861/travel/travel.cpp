#include<bits/stdc++.h>
using namespace std;

string a,b,c,d;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>a>>b>>c>>d;
	bool fl=false;
	
	for(int i=0;i<2;i++)if(a[i]!=c[i])fl=true;
	if(fl)cout<<"0";
	else cout<<"1";
	
	fl=false;
	for(int i=0;i<2;i++)if(b[i]!=d[i])fl=true;
	if(fl)cout<<"0";
	else cout<<"1";
	
	fl=false;
	if((b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D'))cout<<"1";
	else
	{
		if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='C')||(b[2]=='B'&&d[2]=='A')||(b[2]=='C'&&d[2]=='B')||(b[2]=='A'&&d[2]=='C')||(b[2]=='C'&&d[2]=='A'))cout<<"1";
		else cout<<"0";
	}
	
	fl=false;
	if((b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D'))cout<<"1";
	else
	{
		if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='C')||(b[2]=='B'&&d[2]=='A')||(b[2]=='C'&&d[2]=='B'))cout<<"1";
		else cout<<"0";
	}
	
	
	return 0;
 } 
