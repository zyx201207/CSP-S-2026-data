#include<bits/stdc++.h>
using namespace std;
int a,b;
string a1,b1;
bool pd(char x)
{
	if(x=='D'||x=='F')return 1;
	else return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	if(a!=b)
	{
		cout<<"0000";
		return 0;
	}
	if(a1[0]!=b1[0]||a1[1]!=b1[1])
	{
		cout<<"1000";
		return 0;
	}
	if(pd(a1[2])!=pd(b1[2]))
	{
		cout<<"1100";
		return 0;
	}
	if(a1[2]=='A'&&b1[2]=='C'||a1[2]=='C'&&b1[2]=='A')
	{
		cout<<"1110";
		return 0;
	}
	cout<<1111;
	return 0;
}
