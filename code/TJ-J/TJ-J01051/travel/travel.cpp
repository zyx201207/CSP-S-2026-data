#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int t1,t2;
	string ta,tb;
	cin>>t1>>ta>>t2>>tb;
	if(t1==t2)cout<<1;
	else cout<<0;
	if(t1==t2)
	{
		if(ta[0]==tb[0] && ta[1]==tb[1])cout<<1;
	}
	else cout<<0;
	if(t1==t2)
	{
		if(ta[0]==tb[0] && ta[1]==tb[1])
		{
			if(ta[2]-tb[2]==1 && ta[2]=="D")cout<<0;
			if(tb[2]-ta[2]==1 && tb[2]=="D")cout<<0;
		}
	}
	else cout<<0;
	if(t1==t2)
	{
		if(ta[0]==tb[0] && ta[1]==tb[1])
		{
			if(ta[2]-tb[2]==1 && ta[2]=="D")cout<<0;
			if(tb[2]-ta[2]==1 && tb[2]=="D")cout<<0;
			if(ta[2]-tb[2]!=1 && tb[2]-ta[2]!=1)cout<<0;
		}
	}
	else cout<<1;
	return 0;
}
