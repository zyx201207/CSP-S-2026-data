#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string Rcxhh,Rzwhh,Xcxhh,Xzwhh;
	cin>>Rcxhh>>Rzwhh>>Xcxhh>>Xzwhh;
	if(Rcxhh==Xcxhh)
	cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	if(Rzwhh[0]==Xzwhh[0]&&Rzwhh[1]==Xzwhh[1])
	{
		cout<<1;
	}
	else 
	{
		cout<<"000";
		return 0;
	}
	if((Rzwhh[2]>='A'&&Rzwhh[2]<='C'&&Xzwhh[2]>='A'&&Xzwhh[2]<='C')||(Rzwhh[2]>='D'&&Rzwhh[2]<='F'&&Xzwhh[2]>='D'&&Xzwhh[2]<='F'))
	{
		cout<<1;
	}
	else 
	{
		cout<<"00";
		return 0;
	}
	if((Rzwhh[2]=='A'&&Xzwhh[2]=='C')||(Rzwhh[2]=='C'&&Xzwhh[2]=='A'))
	{
		cout<<0;
		return 0;
	}
	else cout<<1;
	return 0;
}
