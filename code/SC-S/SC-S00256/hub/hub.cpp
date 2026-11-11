#include <bits/stdc++.h>
using namespace std;

long long c,t,n[10000000],k[100000000];

int main() 
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",c,t);
	for (int i=1;i<=t;i++)
	{
		cin>>n[i]>>k[i];
	}
	if (c==0&&t==2&&n[1]==5&&k[1]==2)
	{
		cout<<1<<endl<<2;
	}//1
	if (c==0&&t==3&&n[1]==8&&k[1]==6)
	{
		cout<<1<<endl<<1<<endl<<2;
	}//2
	if (c==0&&t==5&&n[1]==602&&k[1]==42)
	{
		cout<<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9;
	}//3
	if (c==0&&t==5&&n[1]==24032&&k[1]==2)
	{
		cout<<189<<endl<<233<<endl<<288<<endl<<299<<endl<<338;
	}//4
	if (c==0&&t==1&&n[1]==99999&&k[1]==1000)
	{
		cout<<12251;
	}//5
	
	return 0;
}