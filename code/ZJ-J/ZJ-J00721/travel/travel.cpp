#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,x,y;
	cin>>a>>b>>x>>y;
	if(a==x) cout<<"1";
	else 
	{
		cout<<"0000";
		return 0;
	}
	if(b[0]==y[0] && b[1]==y[1]) cout<<"1";
	else
	{
		cout<<"000";
		return 0;
	}
	int m=b[2]-'A'+1,n=y[2]-'A'+1;
	if((m>=1 && m<=3) && (n>=1 && n<=3))
	{
		cout<<"1";
		if((m>=4 && m<=6) && (n>=4 && n<=6)) cout<<"1";
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(abs(m-n)==1)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
}

