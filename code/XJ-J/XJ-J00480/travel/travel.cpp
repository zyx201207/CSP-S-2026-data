#include<bits/stdc++.h>
using namespace std;
long long int n;
string sa,sb,sc,sd;
int main()
{
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>sa>>sb;
	cin>>sc>>sd;
	
	if(sa==sc)
	{
		cout<<'1';
	}
	else 
	{
		cout<<"0000";
		return 0;
	}
	if(sb[0]==sd[0]&&sb[1]==sd[1])
	{
		cout<<'1';
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(sd[2]>='A'&&sb[2]>='A'&&sd[2]<='C'&&sb[2]<='C')
	{
		cout<<'1';
	}
	else if(sd[2]=='F'&&sb[2]=='D'||sd[2]=='D'&&sb[2]=='F')
	{
		cout<<"11";
		return 0;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(sd[2]=='A'&&sb[2]=='C'||sd[2]=='C'&&sb[2]=='A')
	{
		cout<<'0';
	}
	else
	{
		cout<<'1';
	}
	// 0000 1000 1100 1110 1111
	//
    return 0;
}
