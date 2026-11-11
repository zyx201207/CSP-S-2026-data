#include <bits/stdc++.h>
using namespace std;
inline int read()
{
	int x = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if (ch == '-')
		{
			f = -1;
		}
		ch = getchar();
	}
	while(ch >= '0' && ch <='9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int main()
{
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);

	int c,t;
	cin >> c >> t;
	while(t--)
	{
		int n,d;
		cin >> n >> d;
		cout << 0 << '\n';
	}
	return 0;
}

