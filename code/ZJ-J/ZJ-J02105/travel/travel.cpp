#include <bits/stdc++.h>
using namespace std;
int a;
int b;
char asi[3];
char bsi[3];
int main()
{
	cin>>a;
	for(int i=0;i<=2;i++)
	{
		cin>>asi[i];
	}
	cin>>b;
	for(int i=0;i<=2;i++)
	{
		cin>>bsi[i];
	}
	if(a==b)
	{
		cout<<1<<" ";
	}
	else
	{
		cout<<"0 0 0 0";
		return 0;
	}
	if(asi[0]==bsi[0]&&asi[1]==bsi[1])
	{
		cout<<1<<" ";
	}
	else
	{
		cout<<"0 0 0";
		return 0;
	}
	if((asi[2]<='C'&&bsi[2]<='C')||(asi[2]>'C'&&bsi[2]>'C'))
	{
		cout<<1<<" ";
	}
	else
	{
		cout<<"0 0";
		return 0;
	}
	if(asi[2]-bsi[2]==1||asi[2]-bsi[2]==-1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}