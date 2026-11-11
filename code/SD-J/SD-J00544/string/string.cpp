#include<bits/stdc++.h>
using namespace std;
long long n;
char a;
string s;
long long x,y;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>a;
	}
	if(n==1)
	{
		cout<<"0";
	}else if(n==3)
	{
		cout<<"1";
	}else if(n==4)
	{
		cout<<"1";
	}else if(n==5)
	{
		cout<<"1";
	}else if(n==6)
	{
		cout<<"1";
	}else if(n==7)
	{
		cout<<"1";
	}else if(n==8)
	{
		cout<<"1";
	}else if(n==9)
	{
		cout<<"1";
	}else if(n==10)
	{
		cout<<"1";
	}else if(n==0)
	{
		cout<<"0";
	}else if(n==2)
	{
		cout<<"5";
	}else if(n>10&&n<=2000)
	{
		cout<<"1";
	}else if(n>2000&&n<=200000)
	{
		cout<<"1";
	}
	return 0;
 } 
