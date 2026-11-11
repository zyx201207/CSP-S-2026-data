#include<bits/stdc++.h>
using namespace std;
long long c1,c2;
string x1,x2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>x1>>c2>>x2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	long long a=(x1[0]-'0')*10+x1[1]-'0';
	long long b=(x2[0]-'0')*10+x2[1]-'0';
	char c=x1[2],d=x2[2];
	if(a==b) 
	{
		cout<<"1";
		if(c>='D'&&d>='D') 
		{
			cout<<"11";
		}
		else if(c<'D'&&d<'D')
		{
			cout<<"1";
			if(c-1==d||d-1==c) cout<<"1";
			else cout<<"0";
		}
		else return cout<<"00",0;
	}
	else return cout<<"000",0;
	return 0;
}