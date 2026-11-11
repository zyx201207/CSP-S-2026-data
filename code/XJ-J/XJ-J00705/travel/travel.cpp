#include<bits/stdc++.h>
using namespace std;
string sr1,sr2,sx1,sx2;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>sr1>>sr2>>sx1>>sx2;
	if(sr1==sx1)
	{
		cout<<1;
	}
	else
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(sr2[1]==sx2[1]&&sr2[0]==sx2[0])
	{
		cout<<1;
	}
	else
	  	cout<<0;
	if(((sr2[2]>='D'&&sx2[2]>='D')||(sx2[2]<='C'&&sr2[2]<='C'))&&(sr2[1]==sx2[1]&&sr2[0]==sx2[0]))
		cout<<1;
	else
	  	cout<<0;
 	int a=sr2[2]-'A',b=sx2[2]-'A';
	if((a-b==1||b-a==1)&&(sr2[2]>='D'&&sx2[2]>='D')||(sx2[2]<='C'&&sr2[2]<='C')&&(sr2[1]==sx2[1]&&sr2[0]==sx2[0]))
	{
		cout<<1;
	}
	else
	  	cout<<0;
	return 0;
}