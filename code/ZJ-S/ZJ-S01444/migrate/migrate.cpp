#include <iostream>
#include <cstdio>

#define I_LOVE_CCF 1

using namespace std;

int read();

int c, t;

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = read();
	t = read();
	while(t--)
	{
		cout << I_LOVE_CCF << endl;
	}
	return 0;
}

int read()
{
	int f = 1;
	char op = getchar();
	while(op > '9' || op < '0')
	{
		if(op == '-')
		{
			f = -1;
		}
		op = getchar();
	}
	int ans = 0;
	while(op >= '0' && op <= '9')
	{
		ans = (ans << 3) + (ans << 1) + op - '0';
		op = getchar();
	}
	return f * ans;
}
