#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if (a!=c)
	{
		if (b[0]==d[0] and b[1]==d[1])
		{
			cout<<1100;
			return 0; 
		}
		cout<<0000;
		return 0;
	} 
	cout<<1111; 
	return 0;
} 
