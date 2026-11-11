#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2; 
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	bool f=true;
	if(c1==c2)
		cout<<'1';
	else
	{
		cout<<'0';
		f=false;
	}
	if(f&&s1[0]==s2[0]&&s1[1]==s2[1])
		cout<<'1';
	else
	{
		cout<<'0';
		f=false;
	}
	int a=s1[2]-'A',b=s2[2]-'A';
	if(f&&((a<=2&&b<=2)||(a>2&&b>2)))
		cout<<'1';
	else
	{
		cout<<'0';
		f=false;
	}
	if(f&&((a>2&&b>2)||(a<=2&&b<=2&&abs(a-b)<=1)))
		cout<<'1';
	else
	{
		cout<<'0';
		f=false;
	}
	return 0;
}

