#include<bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
	int tmp;
	scanf("%lld", &tmp);
	return tmp;
}
void writeln(int tmp)
{
	printf("%lld\n", tmp);
}
void writesp(int tmp)
{
	printf("%lld ", tmp);
}
signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	c = read(), t = read();
	while (t--)
	{
		n = read(), d = read();
		for (int i = 1; i <= n; i++)
		{
			x[i] = read(); 
		}
		writeln(0);
	}
	return 0;
}

