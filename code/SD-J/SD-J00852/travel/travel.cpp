#include<iostream>
#include<string>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(nullptr);
	
	string a,b,aa,bb;
	cin>>a>>b>>aa>>bb;
	if(a!=aa)
	{
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(!(b[0]==bb[0]&&b[1]==bb[1]))
	{
		cout<<"000";
		return 0;
	}
	else
	{
		cout<<"1";
	}
	if(!((b[2]=='A'&&bb[2]=='B')||(b[2]=='B'&&bb[2]=='A')||
	     (b[2]=='A'&&bb[2]=='C')||(b[2]=='C'&&bb[2]=='A')||
	     (b[2]=='B'&&bb[2]=='C')||(b[2]=='C'&&bb[2]=='B')||
	     (b[2]=='D'&&bb[2]=='E')||(b[2]=='E'&&bb[2]=='D') )  )
	{
		cout<<"00";
		return 0;
	}
	else
	{
		cout<<"1";
	}
	if(!((b[2]=='A'&&bb[2]=='B')||(b[2]=='B'&&bb[2]=='A')||
	     (b[2]=='B'&&bb[2]=='C')||(b[2]=='C'&&bb[2]=='B')||
	     (b[2]=='D'&&bb[2]=='E')||(b[2]=='E'&&bb[2]=='D') )  )
	{
		cout<<"0";
		return 0;
	}
	else
	{
		cout<<"1";
	}
	return 0;
} 
