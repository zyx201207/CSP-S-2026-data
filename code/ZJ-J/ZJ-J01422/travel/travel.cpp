#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
using namespace std;
string cxh1,zwh1,cxh2,zwh2;
string z1,z2;
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cxh1>>zwh1>>cxh2>>zwh2;
	if(cxh1==cxh2)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	for(long long i=0;i<=1;i++)
	{
		z1+=zwh1[i];
		z2+=zwh2[i];
	}
	if(z1==z2)
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if((zwh1[2]=='A'||zwh1[2]=='B'||zwh1[2]=='C')&&(zwh2[2]=='A'||zwh2[2]=='B'||zwh2[2]=='C'))
	{
		cout<<1;
	}
	else if((zwh1[2]=='D'||zwh1[2]=='E')&&(zwh2[2]=='D'||zwh2[2]=='E'))
	{
		cout<<1;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(abs((zwh1[2]-'0')-(zwh2[2]-'0'))==1&&!(zwh1[2]=='C'&&zwh2[2]=='D')&&!(zwh1[2]=='D'&&zwh2[2]=='C'))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
/*
8:32 kan ti
8:34 kan wan le
8:44 wan jie sa hua
you dian man le
wo qu cha dian mei shan //freopen

CCF I LOVE YOU
*/