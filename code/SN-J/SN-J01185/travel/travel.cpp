#include<bits/stdc++.h>
using namespace std;
#define ll long long
string sa1,sa2,sb1,sb2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>sa1>>sa2>>sb1>>sb2;
	if(sa1==sb1)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	//////////////////////////////////////
	string ans1="";
	for(int i=0;i<(sa2.size()-1);i++)
	{
		ans1+=sa2[i];
	}
	string ans2="";
	for(int i=0;i<(sb2.size()-1);i++)
	{
		ans2+=sb2[i];
	}
	if(ans1==ans2)
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	///////////////////////////////////
	bool sta=0;
	char q1=sa2[2];
	char q2=sb2[2];
	if(q1=='D' && q2=='F')
	{
		cout<<1;
		sta=1;
	}
	else if((q1=='A' && q2=='B') || (q1=='B' && q2=='A'))
	{
		cout<<1;
		sta=1;
	}
	else if((q1=='A' && q2=='C') || (q1=='C' && q2=='A'))
	{
		cout<<1;
	}
	else if((q1=='B' && q2=='C') || (q1=='C' && q2=='B'))
	{
		cout<<1;
		sta=1;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	//////////////////////////////////
	if(sta==1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
}
