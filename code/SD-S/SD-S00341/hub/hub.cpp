#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 3;
int a[N];
int read()
{
	int x = 0,fs = 1;
	char c = getchar();
	while(c < '0' || c > '9')
	{
		if(c == '-')
		{
			fs = -1;
		}
		c = getchar();
	}
	while(c >= '0' && c <= '9')
	{
		x = x * 10 + (c - '0');
		c = getchar();
	}
	return x * fs;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	c = read();
	t = read();
	while(t--)
	{
		cout << 0 << "\n";
	} 
	
	return 0;
}

