#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b >> c >> d;
	if(a == c)
	{
		cout << "1111";
	}
	else if(a == c && b == d)
	{
		cout << "1000";
	}
	else if(a != c && b != d)
	{
		cout << "0111";
	}
	else if(a != c && b == d)
	{
		cout << "0000";
	}
	return 0;
} 
