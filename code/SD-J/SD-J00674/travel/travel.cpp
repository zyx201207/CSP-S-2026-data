#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,b1,a2,b2;
	cin>>a1>>b1>>a2>>b2;
	if(a1==a2) cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	int b3=b1[0]*10+b1[1];
	int b4=b2[0]*10+b2[1];
	if(b3==b4) cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
		 if(b1[2]=='A'&&b2[2]=='B') cout<<1;
	else if(b1[2]=='A'&&b2[2]=='C') cout<<1;
	else if(b1[2]=='B'&&b2[2]=='A') cout<<1;
	else if(b1[2]=='B'&&b2[2]=='C') cout<<1;
	else if(b1[2]=='C'&&b2[2]=='A') cout<<1;
	else if(b1[2]=='C'&&b2[2]=='B') cout<<1;
	else if(b1[2]=='D'&&b2[2]=='F') cout<<1;
	else if(b1[2]=='F'&&b2[2]=='D') cout<<1;
	else
	{
		cout<<"00";
		return 0;
	}
	if(b1[2]=='A'&&b2[2]=='C'||b1[2]=='C'&&b2[2]=='A') cout<<"0";
	else cout<<1;
	return 0;
}
