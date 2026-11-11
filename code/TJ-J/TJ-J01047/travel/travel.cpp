#include<bits/stdc++.h>
using namespace std;
string ac,as,bc,bs;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ac>>as>>bc>>bs;
	if(ac!=bc)
	{
		cout<<"0000";
		return 0;
	}
	if(as[0]!=bs[0] || as[1]!=bs[1])
	{
		cout<<"1000";
		return 0;
	}
	char ar,br;
	ar=as[2];
	br=bs[2];
	if(ar=='D'&&br=='F' || ar=='F' && br=='D')
	{
		cout<<"1111";
		return 0;
	}
	if(ar=='A' || ar=='B' || ar=='C' && br=='A' || br=='B' || br=='C')
	{
		if(!(ar=='A' && br=='C' || ar=='C' && br=='A'))
		{
			cout<<"1111";
			return 0;
		}
		else
		{
			cout<<"1110";
			return 0;
		}
	}
	cout<<"1100";
	return 0;
}
