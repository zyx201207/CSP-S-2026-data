#include<bits/stdc++.h>
using namespace std;
long long int a,b,s,d;
string a1,b1,c;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>a1>>b>>d>>b1;
	if(a==b)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(s==d)
	{
		cout<<1;
		if(a1=="A"&&b1<="C"||a1=="D"&&b1=="F"||b1=="A"&&a1<="C"||b1=="D"&&a1=="F")
		{
			cout<<"1";
		}
		else
		{
			cout<<"00";
			return 0;
		}
		if(a1=="A"&&b1=="B"||a1=="B"&&b1=="A"||a1=="B"&&b1=="C"||a1=="C"&&b1=="B"||a1=="D"&&b1=="F"||a1=="F"&&b1=="D")
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	}
	else
	{
		cout<<"000";
	}
	return 0;
}