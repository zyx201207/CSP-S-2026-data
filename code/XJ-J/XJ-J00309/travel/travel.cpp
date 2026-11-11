#include<bits/stdc++.h>
using namespace std;
int a,b,k=67,m,n;
string x,y;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>x>>b>>y;
	if(a!=b)
	{
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(x[0]!=y[0]||x[1]!=y[1])
	{
		cout<<"000";
		return 0;
	}
	cout<<"1";
	if((x[2]<=k&&y[2]<=k)||(x[2]>k&&y[2]>k))
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	m=x[2]-'A'+1,n=y[2]-'A'+1;
	if((m+1==n&&n!=4||m-1==n&&n!=3))
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
}