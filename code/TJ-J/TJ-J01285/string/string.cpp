#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	if (n == 1)
	{
		cout << 0;
		return 0;
	}
	else if (n == 2)
	{
		int a,b;
		string c,d;
		cin >> a >> c >> b >> d;
		if (c == d)
		{
			cout << 0;
			return 0;
		}
		else
		{
			cout << b;
			return 0;
		}
	}
	return 0;
 } 
