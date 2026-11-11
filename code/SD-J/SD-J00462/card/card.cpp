#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 3;
const int M = 1e5 + 3;
int a[N];
int b[M];
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
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	n = read();
	m = read();
	bool flag = 1;
	for(int i = 1;i <= n;i++)
	{
		a[i] = read();
		if(a[i] < a[i - 1])
		{
			flag = 0;
		}
	}
	if(flag == 0)
	{
		for(int i = 1;i <= m;i++)
		{
			cout << n << " ";
		}
	}
	cout << b[1];
	for(int i = 1;i <= n;i++)
	{
		for(int j = i;j <= n;j++)
		{
			cout << a[j] << " ";
			b[a[j]] ++;
		}
	}
	for(int i = 1;i <= m;i++)
	{
		cout << b[i] << " ";
	}
	return 0;
} 

