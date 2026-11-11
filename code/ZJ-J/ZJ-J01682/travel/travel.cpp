#include<bits/stdc++.h> 
using namespace std;
char opa,opb;
string ida,idb;
string pa,pb;
bool check(char x,char y)
{
	if(x=='A'&&y=='B')
		return 1;
	if(x=='A'&&y=='C')
		return 1;
	if(x=='B'&&y=='C')
		return 1;
	if(x=='D'&&y=='F')
		return 1;
	swap(x,y);
	if(x=='A'&&y=='B')
		return 1;
	if(x=='A'&&y=='C')
		return 1;
	if(x=='B'&&y=='C')
		return 1;
	if(x=='D'&&y=='F')
		return 1;
	return 0;
}
bool Check(char x,char y)
{
	if(x=='A'&&y=='B')
		return 1;
	if(x=='B'&&y=='C')
		return 1;
	if(x=='D'&&y=='F')
		return 1;
	return 0;
}
string x;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ida>>x;
	for (int i=0;i<2;i++)
		pa+=x[i];
	opa=x[2];
	cin>>idb>>x;
	for (int i=0;i<2;i++)
		pb+=x[i];
	opb=x[2];
	if(ida!=idb)
	{
		cout<<"0000";
		return 0;
	}
	if(pa!=pb)
	{
		cout<<"1000";
		return 0;
	}
	if(!check(opa,opb))
	{
		cout<<"1100";
		return 0;
	}
	if(!Check(opa,opb))
	{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
 } 
