#include <bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	if (a == c)
	{
		if (b == d)
		{
			cout << "1111";
		}
		else
		{
			cout << "1011";
		}
	}
	else
	{
		cout << "0111";
	}
	return 0;
}





















